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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> v;
        v.push_back(root->val);     // level1 sum, which has only root element
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            long long sum = 0;

            for(int i = 0; i < size; i++) {
                TreeNode *node = q.front();

                if(node->left) {
                    q.push(node->left);
                    sum+= node->left->val;
                }
                if(node->right) {
                    q.push(node->right);
                    sum += node->right->val;
                }

                q.pop();
            }

            if(sum != 0)
                v.push_back(sum);
        }

        // if there are no k items present in array
        if(v.size() < k)
            return -1;

        sort(v.begin(), v.end(), greater<long long>());


        return v[k-1];
    }
};