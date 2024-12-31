class Solution {
public:
    void dfs(string node, unordered_set<string> &vis, vector<string> &mails, unordered_map<string, vector<string>> &adj) {
        vis.insert(node);
        mails.push_back(node);

        // visit adjacents mails of the current mail
        for(auto i: adj[node]) {
            if(!vis.count(i))
                dfs(i, vis, mails, adj);
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {      
        // hint: for every pair of emails of same account, draw an edge between those  emails(undirected graph)
        // at last  traverse from all accounts first  mails & push the entire connected mails to its current account name

        unordered_map<string, vector<string>> adj;
        int n = accounts.size();
        for(int i = 0; i < n; i++) {
            // put the first mail & start from 2nd ind
            for(int j = 2; j < accounts[i].size(); j++) {
                adj[accounts[i][1]].push_back(accounts[i][j]);
                adj[accounts[i][j]].push_back(accounts[i][1]);
            }
        }

        // visited array for mails
        unordered_set<string> vis;
        vector<vector<string>> ans;

        // now perform dfs from each account's first mail
        for(int i = 0; i < n; i++) {
            // as per format store the name first, then sorted mails
            vector<string> mails;
            mails.push_back(accounts[i][0]);        // add name

            if(!vis.count(accounts[i][1])) {
                dfs(accounts[i][1], vis, mails, adj);
                sort(mails.begin()+1, mails.end());

                // push sorted entry at end 
                ans.push_back(mails);
            }
        }

        return ans;
    }
};