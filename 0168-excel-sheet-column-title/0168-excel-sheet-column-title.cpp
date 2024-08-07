class Solution {
public:
    string convertToTitle(int n) {
        // https://www.youtube.com/watch?v=UcTKk2y_3s4
        string result = "";

        while(n) {
            char c = 'A' + (n-1)%26;
            result = c + result;
            n = (n-1)/26;
        }

        return result;
    }
};