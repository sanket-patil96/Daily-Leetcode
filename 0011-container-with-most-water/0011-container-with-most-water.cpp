class Solution {
public:
    int maxArea(vector<int>& height) {
        // Time: O(N^2)  Space: O(1)     GIVING TLE!!!
        // we start from 1st line and for each line from starting we calculate max water it 
        // can store from last line, and multiply the space between both by the minimum of both lines (starting line, last line)

        int n = height.size();
        int maxWater = 0;

        // for(int i = 0; i < n; i++) {
        //     for(int j = n-1; j >= 0; j--) {
        //         int space = j - i;
        //         int weightOfStoredWater = min(height[i], height[j]);
        //         maxWater = max(maxWater, weightOfStoredWater*space);
        //     }
        // }

        // method 2: time: O(n)  space: O(1)
        // using 2 pointers appraoch
        // 1st pointer on first line & 2nd on last line
        // calculate maxWater same as previous and then move the smaller pointer further
        // wheather do increment of first pointer OR decrement of last pointer
        // using this we always be moving toward getting maximum water between 2 points
        int s = 0, e = n-1;         // defining starting & ending pointer

        while(s < e) {
            int space = e - s;
            int weightOfStoredWater = min(height[s], height[e]);
            maxWater = max(maxWater, weightOfStoredWater*space);

            if(height[s] < height[e])
                s++;
            else 
                e--;
        }

        return maxWater;
    }
};