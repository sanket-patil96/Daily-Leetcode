class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // use 2 min heaps, 1 for acquired room & other for free rooms
        // we have to always take less numbered free room (top),
        // if at current time there any meeting is ending, pop that room from
        // acquired and push room number in free rooms

        // add duration in the current time and push it in aquired heap

        // sort meetings by starting time
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>>
            freeRooms; // store room numbers
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            aquiredRooms; // store busy till Time, and room Number

        for (int i = 0; i < n; i++)
            freeRooms.push(i);

        int t = meetings[0][0]; // start from first meeting's starting time
        int i = 0;              // iterator for array

        unordered_map<int, int> usedCnt; // used count for each room

        for (int i = 0; i < meetings.size(); i++) {
            int start = meetings[i][0];
            int end = meetings[i][1];

            // check if any meeting ends at current time
            while (aquiredRooms.size() && aquiredRooms.top().first <= start) {
                freeRooms.push(aquiredRooms.top().second);
                aquiredRooms.pop();
            }

            // if free rooms are available, then take current meeting in smalllest numbered room
            if (freeRooms.size()) {
                int room = freeRooms.top();
                freeRooms.pop();
                aquiredRooms.push({end, room});
                usedCnt[room]++;
                // cout << i << " " << room <<" " << usedCnt[room] << endl;
            } 
            // else check the earliest meeting's ending timing & add currnet meeting duration in that timing in that room
            else {
                auto [freeTime, room] = aquiredRooms.top();
                aquiredRooms.pop();
                long long duration = (long long)end - start;
                aquiredRooms.push({freeTime + duration, room});
                usedCnt[room]++;
                // cout << i << " " << room <<" " << usedCnt[room] << endl;
            }

        }

        // get the max used room
        int maxUseCnt = 0;
        int roomNo = 0;
        for (auto [room, used] : usedCnt) {

            // cout << "room: " << room << " used: " << used << endl;

            if (maxUseCnt == used) {
                roomNo = min(roomNo, room);
            } else if (maxUseCnt < used) {
                maxUseCnt = used;
                roomNo = room; // take the minimum numbered room if equal count
            }
        }

        return roomNo;
    }
};