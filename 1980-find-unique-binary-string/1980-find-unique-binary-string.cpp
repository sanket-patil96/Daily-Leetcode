class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // generate all possible binary numbers, and find if there anyone not present in nums
        string ans = "-1";
        backtrack("", 0, ans, nums);
        return ans;
    }

    void backtrack(string b, int i, string &ans, vector<string>& nums) {
        if(i == nums.size()) {
            if(find(nums.begin(), nums.end(), b) == nums.end())
                ans = b;

            return;
        }

        // add 0 or add 1 for current place
        backtrack(b+"0", i+1, ans, nums);
        backtrack(b+"1", i+1, ans, nums);
    }
};