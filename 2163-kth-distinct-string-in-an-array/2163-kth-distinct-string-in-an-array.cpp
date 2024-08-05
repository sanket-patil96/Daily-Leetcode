class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int cnt = 0;

        for(int i = 0; i < arr.size(); i++) {
            bool flag = false;      // true if same string found
            for(int j = 0; j < arr.size(); j++) {
                if(i != j && arr[i] == arr[j]) {
                    flag = true;
                    break;
                }
            }

            if(!flag) {
                cnt++;
                if(cnt == k) {
                    return arr[i];
                }
            }
        }

        return "";
    }
};