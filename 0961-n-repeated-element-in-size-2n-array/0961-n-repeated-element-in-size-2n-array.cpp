class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // brute force: using hashmap
        // 2N size and n+1 unique elements, means there is only 1 element that is repeated

        unordered_set<int> s;

        for(int i: nums) {
            if(s.find(i) != s.end())
                return i;
            s.insert(i);
        }

        return -1;
    }
};