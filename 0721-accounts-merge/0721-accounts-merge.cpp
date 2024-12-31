class DSU {
    public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node;
        
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ult_pu = findUPar(u);
        int ult_pv = findUPar(v);

        if(ult_pu == ult_pv)
            return;

        if(size[ult_pu] < size[ult_pv]) {
            parent[ult_pu] = ult_pv;
            size[ult_pv] += size[ult_pu];
        }
        else {
            parent[ult_pv] = ult_pu;
            size[ult_pu] += size[ult_pv];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // approach 2: DSU
        // 1. Traverse over each account, and for each account, traverse over all of its emails. If we see an email for the first time, then set the group of the email as the index of the current account in emailGroup .
        // 2. Otherwise, if the email has already been seen in another account, then we will union the current group (i) and the group the current email belongs to (emailGroup[email]).
        // 3. After traversing over every account and merging the accounts that share a common email, we will now traverse over every email once more. Each email will be added to a map (components) where the key is the email's representative, and the value is a list of emails with that representative.
        // 4. Traverse over components, here the keys are the group indices and the value is the list of emails belonging to this group (person). Since the emails must be "in sorted order" we will sort the list of emails for each group. Lastly, we can get the account name using the accountList[group][0]. In accordance with the instructions, we will insert this name at the beginning of the email list.
        // 5. Store the list created in step 4 in our final result (mergedAccount).
        // Time complexity: O(NKlogNK)
        // Sace complexity: O(NK)

        int n = accounts.size();
        DSU ds(n);

        unordered_map<string, int> mailToNode;

        for(int i = 0; i < n; i++) {
            // first one contains name so start j from 1
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(!mailToNode.count(mail)) 
                    mailToNode[mail] = i;
                
                // else union the current account with existing account from mapping
                else {
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }

        vector<string> mergedMails[n];

        for(auto i: mailToNode) {
            string mail = i.first;
            int node = ds.findUPar(i.second);       // always get the ultimate parent
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            // if it doesn't have any mails means its already merged to other node
            if(mergedMails[i].size() == 0)      continue;       

            sort(mergedMails[i].begin(), mergedMails[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);         // push the account name first
            for(auto i: mergedMails[i])
                temp.push_back(i);

            ans.push_back(temp);
        }

        return ans;
    }
};