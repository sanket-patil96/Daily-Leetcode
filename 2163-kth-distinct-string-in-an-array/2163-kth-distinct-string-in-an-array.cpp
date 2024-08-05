class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // method 2: use unordered_map for storing freqeuncy
        // and after that again traverse array check if current elem is has frequency 1 & its maches kth occurance
        unordered_map<string, int> mp;

        for(int i = 0; i < arr.size(); i++) 
            mp[arr[i]]++;

        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(mp[arr[i]] == 1) {
                cnt++;
                if(cnt == k)
                    return arr[i];
            }
        }


        return "";
    }
};