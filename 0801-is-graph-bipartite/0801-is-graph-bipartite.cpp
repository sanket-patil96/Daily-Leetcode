class Solution {
public:
    bool dfs(int i, int coloredWith, vector<int> &vis, vector<vector<int>>& graph) {
        // give another color to adjacents of i from its color
        int targetColor = coloredWith == 1 ? 2 : 1;

        for(auto j: graph[i]) {
            // if adjacent not visited then color it with targetColor
            if(!vis[j]) {
                vis[j] = targetColor;
                if(!dfs(j, targetColor, vis, graph))
                    return false;
            }

            // if adjacent already visited then check that it must not have same color as node i
            else if(vis[i] == vis[j]) {
                cout << i << " target: " << vis[i] << " " << j << " target: " << vis[j] << endl;
                return false;
            }
        }

        // means from this node we can give different colors to all its adjacents
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // i think its type of graph coloring problem
        // from given exp 1 & 2, it's description i think means by 
        // we have to save direct adjacents in different sets, so that
        // edge between 0-1 will be the edge that has both 1st set member & 2nd set member
        
        // for giving different colors from (1,2) to adjacents we have to use DFS/BFS so it will fix all the adjacents first
        // that why first code fails on test-case 78

        int n = graph.size();

        vector<int> vis(n);

        // instead of using sets we use s1 & s2 as colors on visited array
        // unordered_set<int> s1, s2;
        // traverse the graph & store adjacents in opposite sets

        for(int i = 0; i < n; i++) {
            // once it is visited its adjacents will also get traversed which will be in same component
            if(!vis[i]) {
                vis[i] = 1;     // we give color as '1' for  first node in new component;
                
                // passing color as 1, to indicate this node colored with 1
                if(!dfs(i, 1, vis, graph))      
                    return false;
            }
        }

        return true;
    }
};