class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        // we start from the base string as first string, as we have to match all prefixes so, it easy to make base as first string
        // then check all further string's previx, if they have any part same as of first string then we update the maxCommon with minimum one that we found common in both
        // as like this do for all string, so finally we get the lenght of the longest common prefix

        // consider first string as longest common prefix & then reduce the size as we check 
        // further strings common part


        string common = s[0];
        int minCommon = common.size();

        for(int j = 1; j < s.size(); j++) {
            int k = 0;
            for(k = 0; k < s[j].size() && k < minCommon; k++) 
                if(s[j][k] != common[k]) 
                    break;
            
            minCommon = min(minCommon, k);
        }

        return common.substr(0, minCommon);
    }
};