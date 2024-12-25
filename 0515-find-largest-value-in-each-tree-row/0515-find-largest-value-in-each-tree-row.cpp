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
    vector<int> largestValues(TreeNode* root) {
        // it can be done using simple level order traversal
        if(!root)
            return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        // create a max heap that stores max value of next row
        priority_queue<int> pq;
        ans.push_back(root->val);       

        while(!q.empty()) {
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                TreeNode *node = q.front();
                q.pop();

                if(node->left) {
                    q.push(node->left);
                    pq.push(node->left->val);
                }
                
                if(node->right) {
                    q.push(node->right);
                    pq.push(node->right->val);
                }
            }

            // store the top value of max heap
            if(!pq.empty()) {
                ans.push_back(pq.top());
                pq = {};
            }
        }

        return ans;
    }
};