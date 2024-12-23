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

    int getSwaps(vector<int> a) {
        vector<int> cpy = a;
        sort(cpy.begin(), cpy.end());
        unordered_map<int, int> m;

        // map the original values with indexes
        for(int i = 0; i < cpy.size(); i++) 
            m[a[i]] = i;

        // now check with original array that how many swaps we require
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            // check if index is same in original & sorted ordered array,
            // if not then swap with the index it should belong to
            if(a[i] != cpy[i]) {
                int targetInd = m[cpy[i]];
                m[a[i]] = targetInd;
                swap(a[i], a[targetInd]);
                cnt++;
            }
        }

        return cnt;
    }

    int minimumOperations(TreeNode* root) {
        // just start by bfs & a counting swaps function
        // which will tell which values are apart from their original indexes using map
        // and then we swap them with their original index values

        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        while(!q.empty()) {
            int n = q.size();
            vector<int> arr;

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                arr.push_back(node->val);

                if(node->left) 
                    q.push(node->left);
                
                if(node->right) 
                    q.push(node->right);   
            }

            if(arr.size() > 1)
                res += getSwaps(arr);
        }

        return res;
    }
};