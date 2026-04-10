class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // same as word Ladder

        unordered_set<string> s(bank.begin(), bank.end());
        vector<char> choices = {'A', 'C', 'G', 'T'};
        
        if(!s.count(endGene))
            return -1;

        queue<string> q;
        q.push(startGene);
        s.erase(startGene);     // remove starting string from set (if in bank), as we have inserted it in queue

        int mutations = 0;      

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                string str = q.front();
                q.pop();

                if(str == endGene)
                    return mutations;

                for(int i = 0; i < str.size(); i++) {
                    // changing choices are only 4
                    char originalChar = str[i];

                    for(int j = 0; j < 4; j++) {
                        str[i] = choices[j];

                        if(s.count(str)) {
                            q.push(str);
                            s.erase(str);
                        }
                    }

                    // reseat the changes made in original str, so we can use it for next changing chars
                    str[i] = originalChar;
                }
            }

            mutations++;
        }

        // couldn't mutate to endGene
        return -1;
    }
};