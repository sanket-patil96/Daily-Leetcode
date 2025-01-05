class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // topological sort (kahn's Algo) can be applied here
        // first create an adjancy list for graph

        vector<vector<int>> adj(numCourses);
        vector<int>  indegree(numCourses);

        // for each course store the courses dependant on this
        for(auto i: prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        // now extract 0 indegree courses, courses which have no prerequisites
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        

        // now run execution of courses from initial courses
        vector<int> ans;
        while(!q.empty()) {
            int course = q.front();
            q.pop();

            ans.push_back(course);

            // now this course is finished so, decrement the indegree from courses which dependant on this
            for(auto v: adj[course]) {
                indegree[v]--;
                cout << v << " " << indegree[v] << endl;
                if(indegree[v] == 0)
                    q.push(v);
            }
        }

        return ans.size() == numCourses ? ans : vector<int>{};
    }
};