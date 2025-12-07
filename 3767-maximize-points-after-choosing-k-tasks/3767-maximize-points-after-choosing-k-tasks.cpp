class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        // used example: technique1 = [5,2,10], technique2 = [10,3,8], k = 2
        // to get the maximum points, we initially complete all tasks using tech2
        // so initially points = sum of all points from tech2; ex: 10+3+8 =21
        // after that we keep an array of differences of points between tech1 - tech2
        // it will be: [-5, -1, +2] we sort this in descending order- [+2, -1, -5]

        // for run i from 0 to k, that the min tasks we have to perform using tech 1
        // now add the difference[i] to the answer, 
        // ex: k = 2, diff = [2,-1,-5], points = 21
        // for i = 0, add 2 to the points, points = 23, (its like, we can choose task 3 using tech1, but in ans we did it using tech2 so we add extra 2 points (10-8) to the answer)
        // for i = 1, add -1 to points, points = 22, (like, we have to complete 1 more task using tech1, but we counted using tech2, so we have to add such task that gives less points reduction, so we choose task 2 using tech1, so we have to reduce that 1 extra point from tech2 from ans)
        // now k requirement is over,
        // i = 2, we can choose any technique for this task,
        // if diff[2] > 0 then add that extra points to ans
        // if diff[2] < 0 then no need for reducing from ans, coz we alredy perform that taks using tech2


        int n = technique1.size();
        long long points = 0;
        vector<int> diff(n);

        for(int i = 0; i < n; i++) 
            points += technique2[i];

        for(int i = 0; i < n; i++) 
            diff[i] = technique1[i] - technique2[i];


        // sort decreasingly
        sort(diff.rbegin(), diff.rend());
        
        // complete at least k tasks using tech1
        int i = 0;
        while(i < k) {
            points += diff[i];
            i++;
        }

        // check if there is any other tasks that are more profitable than technique2 so we can add diff into answer
        while(i < n) {
            if(diff[i] < 0)     break;
            points += diff[i];
            i++;
        }

        return points;
    }
};