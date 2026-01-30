class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // since here asked for subsets, we have to check all such possible subsets
        // all possibilities = recursion, OR 2 loops
        // this is similar to how we print LIS
        // so try 2 loops, i = 0 -> n & inner loop = j = i-1 -> 0
        // keep a hash[] that tells max len divisible subset that ends at i
        // ex: [1, 2, 4, 8] here i = ar[0] = 1, (no previous elements)
        // so it starts checking from 2, 2 % 1 = 0, so hash[2] = max(hash[2], 1+hash[1])
        // do same for all further i's
        // and if the maxLendgh got change for any i, then keep an array for storing its parent index, from where the max comes from

        // in some cases: like: [5,9,18,54,108,540,90,180,360,720], this solution gives wrong answer
        // as 54 can divisible to 540, 90 can divisible to 540, so 90 takes, the length from 540, but it will give wrong answer
        // as 54 not divisible to 90, so, to handle this, we need to sort the array
        // and for subsets, order doesn't matter
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> hash(n, 1);     // initially set to 1, as single length subsets is the number itself
        vector<int> parent(n);

        for(int i = 0; i < n; i++)
            parent[i] = i;

        int maxLen = 1;         // length of largest divisible subset
        int lastInd = 0;         // this store at what index, the max length recorded    

        for(int i = 1; i < n; i++) {
            for(int j = i-1; j >= 0; j--) {
                if(nums[i] % nums[j] == 0 && hash[i] < 1 + hash[j]) {
                    hash[i] = 1 + hash[j];
                    parent[i] = j;
                }
            }

            if(maxLen < hash[i]) {
                maxLen = hash[i];     
                lastInd = i;
            }
        }

        vector<int> ans;
        while(lastInd != parent[lastInd]) {
            ans.push_back(nums[lastInd]);
            lastInd = parent[lastInd];
        }

        // loop ends when last value equal its origin of subset, so push it in answer
        ans.push_back(nums[lastInd]);

        // don't need to sort as the subset, may not follow any order
        return ans;
    }
};