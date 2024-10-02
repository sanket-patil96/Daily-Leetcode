class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // algo:
        // sort the array 
        // store rank as value of key in map
        // traverse original array and store its ranks in answer

        vector<int> a(arr.begin(), arr.end());

        sort(a.begin(),a.end());
        unordered_map<int, int> m;

        int cnt = 1;
        for(int i = 0; i < a.size(); i++) {
            if(!m.count(a[i])) {
                m[a[i]] = cnt;
                cnt++;
            }
        }

        vector<int> ans;
        for(auto i: arr)
            ans.push_back(m[i]);

        return ans;
    }
};