class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prerequisites) {
        // T/C: O(N+P)   S/C: O(N+P)    (where N = no.of courses, & P = prerequisites)
        // we can solve this problem by using the Topological Sort Algorithm, where the 
        // independant task should executed first.

        // first we get the dependancies of each task 
        vector<int> dependancy(N, 0);                    // it show current taks dependant on any task or not
        unordered_map<int, vector<int>> preTask;   // it shows current task is prerequisit of which tasks
	    
        int P = prerequisites.size();
	    for(int i = 0; i < P; i++) {
	        int task = prerequisites[i][0];
	        int dependantOn = prerequisites[i][1];
	        
	        dependancy[task] = dependancy[task]+1;
	        preTask[dependantOn].push_back(task);
	    }
	    
	    
	    // now we have to execute tasks that have 0 dependancy, push then in a queue
	    queue<int> q;
	    for(int i = 0; i < N; i++)
	        if(dependancy[i] == 0)
	            q.push(i);
	            
	   
	   // now execute 0 dependancy tasks
	   int completedTasks = 0;
	   
	   while(!q.empty()) {
	        int task = q.front();
	        q.pop();
	        completedTasks++;
	        
	        // now check if any task was dependant on current task & remove dependancy
	        if(preTask.count(task)) {
	            for(auto i: preTask[task]) {
	                dependancy[i]--;
	                
	               // if the dependant task has 0 dependancies remain then push in queue for execution
	                if(dependancy[i] == 0)
	                    q.push(i);
	            }
	        }
	   }
	    
	   return completedTasks == N;
    }
};