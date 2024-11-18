class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        // if k > 0 then we do preprocessing for getting the suffixSum of next k elems
        // if k < 0 then we have to do prefixSum of previous k elements (we use queue for simply removing the last out of window element)
        int n = code.size();
        vector<int> defuse(n);

        if(k > 0) {
            
            // first get the first window for i == 0
            int sum = 0;
            for(int i = 1; i <= k; i++)
                sum += code[i];
            // cout << sum;

            defuse[0] = sum;
            for(int i = 1; i < n; i++) {
                sum -= code[i];
                sum += code[(i+k)%n];       // next element of new window
                defuse[i] = sum;
            }
        }
        else if(k < 0) {
            // first get the sum for last k elements
            k = abs(k);
            int sum = 0;
            queue<int> q;
            for(int i = n-k; i < n; i++) {      // start from last k elems (ie. from n-k)
                sum += code[i];
                q.push(code[i]);
            }
            
            defuse[0] = sum;
            
            sum -= q.front();       // remove the last element that will go out of window for next element
            q.pop();
            sum += code[0];         // add the current number as it will be in next window
            q.push(code[0]);
            
            for(int i = 1; i < n; i++) {
                defuse[i] = sum;

                sum -= q.front();
                q.pop();
                sum += code[i];
                q.push(code[i]);
            }
        }


        return defuse;
    }
};