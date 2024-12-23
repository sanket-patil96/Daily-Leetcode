class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        // T/C: O(N+P)   S/C: O(N+P)    (where N = no.of courses, & P = prerequisites)
        // we can solve this problem by using the Topological Sort Algorithm, where the 
        // independant task should executed first.

        // 2nd approach:
        // make it as graph representation to directly use Topological SORT
        vector<vector<int>> adj(N);


        // mark dependancies
        int P = prerequisites.size();
        for(int i = 0; i < P; i++) {
            int task = prerequisites[i][0];
	        int dependantOn = prerequisites[i][1];

            adj[task].push_back(dependantOn);
        }


        // get indegree 
        vector<int> indegree(N);
        for(auto u: adj)
            for(auto v: u)
                indegree[v]++;
        

        // get 0 indegree tasks in queue
        queue<int> q;
        for(int i = 0; i < N; i++)
            if(indegree[i] == 0)
                q.push(i);


        int completedTasks = 0;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            completedTasks++;

            // remove dependancy
            for(auto v: adj[node]) {
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        return completedTasks == N;
    }
};