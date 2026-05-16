class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // algo:
        // sort the projects according to their captial requirement
        // use maxHeap to store the current projects that can be done with current capital
        // add the profit of top project to total capital, do this for max k projects

        int n = profits.size();
        priority_queue<int> pq;
        vector<pair<int, int>> projects;

        for(int i = 0; i < n; i++)
            projects.push_back({capital[i], profits[i]});

        sort(projects.begin(), projects.end());

        int totalCap = w;       // keeep track of total capital
        int i = 0;              // points to project indexes



        while(k--) {
            // we can't stop immedietly inside loop when projects[i].first > totalCap coz
            // we can take out multiple smaller projects from previously inserted heap and then with that profit we can again check this condition
            while(i < n && projects[i].first <= totalCap) {
                pq.push(projects[i].second);        // push direct the profit, we don't reqire its capital now
                i++;
            }

            if(pq.empty())  break;
        
            totalCap += pq.top();
            pq.pop();
        }

        return totalCap;
    }
};