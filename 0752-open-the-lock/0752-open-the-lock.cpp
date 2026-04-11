class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // we can try word ladder approach
        // but here we can't randomly change '0' to '7', have to go throughg the middle numbers (1,2,.. 6, 7),
        // and the smallest path can be from backside also ('0'-'9'-'8'-'7') so there are different choices in this P.S
        // for each character position there are 2 choices either increment current number or decrement it by 1

        // store the already used states
        // deadends are can be kept in seen as we cann't make new combinations from it
        unordered_set<string> seen(deadends.begin(), deadends.end());     
        queue<string> q;

        // initial state is invalid can't go further!
        if(seen.count("0000"))
            return -1;

        q.push("0000");     // starting state
        seen.insert("0000");

        int turns = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string state = q.front();
                q.pop();

                if(state == target)
                    return turns;

                for(int i = 0; i < 4; i++) {
                    // at every slot, there are 2 options- we can either increment by 1 or decrement by 1
                    // rotate the wheel:-
                    string state1 = state;
                    string state2 = state;

                    if(state[i] == '9')  state1[i] = '0';
                    else                 state1[i] = state[i]+1;

                    if(state[i] == '0')  state2[i] = '9';
                    else                 state2[i] = state[i]-1;

                    if(!seen.count(state1)) {
                        q.push(state1);
                        seen.insert(state1);
                    }
                    
                    if(!seen.count(state2)) {
                        q.push(state2);
                        seen.insert(state2);
                    }
                }
            }

            turns++;
        }

        return -1;
    }
};