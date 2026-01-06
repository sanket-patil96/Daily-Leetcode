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
    int maxLevelSum(TreeNode* root) {
        // we use level order traversal 

        if(!root)
            return -1;

        queue<TreeNode*> q;
        q.push(root);

        int maxSum = root->val;
        int minLvl = 1;
        int lvl = 2;        // we starting from level-2

        while(!q.empty()) {
            int size = q.size();
            int lvlSum = 0;
            bool isThereNextLvl = false;

            for(int i = 0; i < size; i++) {
                TreeNode *node = q.front(); 
                q.pop();

                if(node->left) {
                    isThereNextLvl = true;
                    q.push(node->left);
                    lvlSum += node->left->val;
                }

                if(node->right) {
                    isThereNextLvl = true;
                    q.push(node->right);
                    lvlSum += node->right->val;
                }
            }

            // if there is no next level then lvlSum is same as initial 0, so it can break algo if all level values till now are negative
            // so to stop that we use flag to check if there is any next after current one then only consider lvlSum
            if(isThereNextLvl && lvlSum > maxSum) {
                // cout << lvl << " : " << lvlSum << " : " << maxSum << endl;
                maxSum = lvlSum;
                minLvl = lvl;
            }

            lvl++;
        }

        return minLvl;
    }
};