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
    int sumRootToLeaf(TreeNode* root) {
        // traverse each path to leaf node & store binary value & add to total answer
        return solve("", root);
    }

    int solve(string binary, TreeNode* root) {
        if(!root)
            return 0;
        
        // stop if leaf node occures
        if(!root->left && !root->right) {
            binary += to_string(root->val);
            return binaryVal(binary);
        }


        int left = solve(binary + to_string(root->val), root->left);
        int right = solve(binary + to_string(root->val), root->right);

        return left + right;
    }

    int binaryVal(string b) {
        int val = 0;
        int power = 0;

        for(int i = b.size()-1; i >= 0; i--) {
            if(b[i] == '1') 
                val += pow(2, power);
            power++;
        }

        return val;
    }
};