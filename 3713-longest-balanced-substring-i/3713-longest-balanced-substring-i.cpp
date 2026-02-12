class Solution {
public:
    int longestBalanced(string s) {
        // brute force:
        // try each substring

        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            vector<int> v(27, 0);
            for(int j = i; j < s.size(); j++) {
                v[s[j]-'a']++;

                // check for balanced
                int cnt = -1;
                bool flag = false;
                for(int c: v) {
                    if(c != 0 && (cnt != -1 && c != cnt))  {
                        flag = true;
                        break;
                    }

                    if(c != 0 && cnt == -1)
                        cnt = c;
                }

                if(!flag)
                    ans = max(ans, j-i+1);
            }
        }

        return ans;
    }
};