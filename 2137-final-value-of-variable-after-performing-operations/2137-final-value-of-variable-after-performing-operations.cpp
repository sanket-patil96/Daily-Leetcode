class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for(auto str: operations) {
            // this ensures both --x && x--
            if(str[0] == '-' || str[1] == '-')
                x--;
            else
                x++;
        }

        return x;
    }
};