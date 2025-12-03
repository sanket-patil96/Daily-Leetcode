class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        // another simple method:
        // if +ve value comes push directly into back of answer array
        // if -ve comes, check if last value is +ve if yes then explosion possibility, else push into answer array

        vector<int> ans;
        int n = arr.size();
        
        for(int i = 0; i < n; i++) {
            // if +ve or (negative and empty array || if -ve but last asteroid also same -ve direction)
            if(arr[i] > 0 || (ans.empty() || ans.back() < 0))
                ans.push_back(arr[i]);
            else {
                bool flag = true;        // if its false then current asteroid get destroyed!
                
                // check collision when -ve comes & previous asteroids are opposite direction
                while(flag && ans.size() && ans.back() > 0) {
                    if(abs(ans.back() < abs(arr[i])))
                         ans.pop_back();
                    else if(abs(ans.back() == abs(arr[i]))) {
                        // both destroyed!
                        ans.pop_back();
                        flag = false;
                    }
                    else 
                        flag = false;    // means current asteroid is destroyed
                }

                if(flag)
                    ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};