class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        // T/C: O(N+P)   S/C: O(N+P)    (where N = no.of courses, & P = prerequisites)
        // create a adjacency list, ex: adj[0] = {list of dependant tasks on 0}
        // store indegree of each task 
        // complete tasks as their indegree completes

        vector<vector<int>> adj(N);

        // get indegree 
        vector<int> indegree(N);

        // mark dependancies
        int P = prerequisites.size();
        for(int i = 0; i < P; i++) {
            int task = prerequisites[i][0];
	        int dependantOn = prerequisites[i][1];

            indegree[task]++;

            // store dependancy list(tasks dependant on which task)
            adj[dependantOn].push_back(task);
        }        

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