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
        // k size min-heap, so top will contain kth largest sum
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        queue<TreeNode *> q;
        q.push(root);
        pq.push(root->val);         // sum of first level, which consist only root

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


            if(pq.size() < k) {
                // sum should not be repeted!
                // if no childs then sum will be 0, so don't add 0 also
                if(pq.size() > 0 && sum != 0){
                    pq.push(sum);
                }
            }
            else {
                if(pq.top() < sum) {
                    pq.pop();
                    pq.push(sum);
                }
            }   
        }

        if(pq.size() < k)
            return -1;

        return pq.top();
    }
};