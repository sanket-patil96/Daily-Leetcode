class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // insertion can happen if one of either 3 conditions matches
        // stack is empty(),  || current astroid is moving left, || there is astroid moving right on top of stack

        int n = asteroids.size();
        stack<int> s;

        for(int i = n-1; i >= 0; i--) {
            if(s.empty() || asteroids[i] < 0 || s.top() > 0) {
                s.push(asteroids[i]);
            }
            // it will go in else case only if there is left moving asteroid on top of stack & current asteroid is moving Right
            // means at collide time \U0001f4a5
            else {
                while(s.size() && s.top() < 0 && asteroids[i] > abs(s.top())) {
                    s.pop();  // smaller top asteroid that moving left will explode
                }

                // now check if current asteroid is exploded or not, 
                // if yes then there will be -ve value on top which is Strictly lesser than current asteroid
                // also handle if top is -ve and they are equal then both exploid
                if(s.size() && s.top() < 0 && abs(s.top()) == asteroids[i])
                    s.pop();
                else if(s.size() && s.top() < 0) 
                    continue;           // top -ve asteroid remain as it is but current one exploded
                else 
                    s.push(asteroids[i]);    // means this is servived in collision
            }
        }

        // now all elements remain in stack will not collide
        vector<int> ans;

        while(s.size()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};