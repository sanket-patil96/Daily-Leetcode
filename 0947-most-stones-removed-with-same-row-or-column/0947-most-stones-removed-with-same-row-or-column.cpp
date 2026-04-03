class Solution {
public:
    void dfs(vector<vector<int>>&stones,int index,vector<bool>&visited,int&n){
        visited[index]=true;

        for(int i=0;i<n;i++)
            // we can go from stone A to stone B if and only if A and B have common row or column
            if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                dfs(stones,i,visited,n);
    }

    int removeStones(vector<vector<int>>& stones) {
        
        // The best way to maximize the number of removable stones is to treat the problem as a connected components problem:
        // Treat each stone as a node in a graph.
        // Connect stones if they share the same row or column.
        // The goal is to determine the size of each connected component and remove all but one stone from each component.
        // Key Insight
        // The number of stones that can be removed is: 
        // Total Stones − Number of Connected Components

        // Steps:
        // Consider indexes of each stone as an ID number.
        // Visit each ID if it hasn't been visited.(Note that we can go from stone A to stone B if and only if A and B have common row or column)
        // just calculate the no of unconnected groups, and subtrack it from total stones

        int n = stones.size();
        vector<bool>visited(n,0);
        int count=0;
        
        for(int i=0;i<n;i++){
            if(visited[i]){continue;}
            dfs(stones,i,visited,n);
            count++;
        }

        return n-count;
    }
};