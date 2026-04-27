/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int rob(TreeNode* root) {
        // its exactly same approach as its previous versions of house robbers
        // we can either rob the current house(root) or skip it & go for checking its 
        // children houses(root->left + root->right) and get the maximum from both choices

        // if flag = true then we rob current house, add the (current price + Left Area + Right Area) & go to its adjacents(left, right) while setting flag = false as we can't rob its adjacents now
        // and at current state if flag = false then we can't rob the current house So just take (left Area + Right Area) & while  calling set flag = true, as we  skipped current house so next can't be adjacent
        // and at last return max from both choices (max(rob, skip))

        // to avoid TLE lets use Memoization
        // changing states are root & flag
        // here we can't use vector coz we don't storing indexes here, we storing Nodes, so use hashmap
        unordered_map<TreeNode*, vector<int>> dp;

        return solve(root, true, dp);      // set initial flag to true, as we can start robbing from first root house
    }

    int solve(TreeNode *root, bool flag, unordered_map<TreeNode*, vector<int>> &dp) {
        if(!root)   return 0;

        // check memo
        if(dp.count(root) && dp[root][flag] != -1)
            return dp[root][flag];

        // initialize if first time
        if(!dp.count(root))
            dp[root] = vector<int>(2, -1);

        int rob = 0, skip = 0;

        // we can rob current house when flag = true
        if(flag) 
            rob = root->val + solve(root->left, false, dp) + solve(root->right, false, dp);

        skip = solve(root->left, true, dp) + solve(root->right, true, dp);

        return dp[root][flag] = max(rob, skip);
    }
};