#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool Booster = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return true;}();inline bool is_digit(char c) { return c >= '0' && c <= '9';}std::array<int, 100000> nums;void parse_input_and_solve(std::ofstream& out, const std::string& s) { const int N = s.size(); int left = 0; int idx = 0; while (left < N) { if (!is_digit(s[left])) { ++left; continue; } int right = left; int value = 0; while (right < N && is_digit(s[right])) { value = value * 10 + (s[right] - '0'); ++right; } left = right; nums[idx] = value; ++idx; }  int area = 0, i = 0, j = idx-1; label:  area = max(area, (j-i)*min(nums[i], nums[j])); if(nums[i] < nums[j]) i++; else j--; if(i < j) goto label; out<<area<<"\n";}bool Solve = [](){ std::ofstream out("user.out"); for (std::string s; std::getline(std::cin, s);) { parse_input_and_solve(out, s); } out.flush(); exit(0); return true;}();
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