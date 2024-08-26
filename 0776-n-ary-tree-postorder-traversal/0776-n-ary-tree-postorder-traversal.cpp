/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        // create stack push root into it
        // run loop while stack is not empty
        // get top node and push all of its childrens into stack 
        // after pushing all childrens push the top node's value into result
        // at last return the reverse of result list
        if(!root)   
            return {};

        vector<int> res;
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty()) {
            Node* top = s.top();
            s.pop();

            for(int i = 0; i < top->children.size(); i++)
                s.push(top->children[i]);

            res.push_back(top->val);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};