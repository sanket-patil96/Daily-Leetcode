class Solution {
public:
    int findLHS(vector<int>& nums) {
        // algo 1:
        // since we have to find the numbers of exact 1 difference, means we can sort the array
        // as we are allowed to delete any number of element, which means we can sort the array 
        // and order also not matters
        // ex: [1,3,2,2,5,2,3,7] if we sort these [1,"2,2,2,3,3",5,7], then also we get 5 as answer and we only need to find the 1 diffrence most occurences
        // so here we are finding the successor of 2 which is 3 & occurences addition of both are 5
        
        // Easy Algo 2:
        // store the occurences of each number
        // and find the successor(+1 of it) of each number in array and count both numbers occurances 
        // so it will give the ansewr to the question
        // why it works????
        // as we want only 2 unique numbers (then only we get 1 difference)
        // so we can choose  that 2 element in array and can delete others (its allowed in subsequence)
        // exp: [2,2,2,3,3] we deleted 1, 5, 7 from these array
        
        unordered_map<int, int> m;

        for(int i = 0; i  < nums.size(); i++)
            m[nums[i]]++;


        int lhs = 0;
        for(auto i: m) {
            // find its successor
            if(m.count(i.first+1)) 
                lhs = max(lhs, i.second+m[i.first+1]);
        }

        return lhs;
    }
};