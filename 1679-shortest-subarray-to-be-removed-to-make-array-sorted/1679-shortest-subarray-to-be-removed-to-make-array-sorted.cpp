class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // You need to find some sequence from 0th index which is in increasing order, let this sequence a_1 <= a_2 <= ... <= a_i
        // Then you need to find some sequence from the back which is in decreasing order such that b_j <= b_(j+1) <= ... <= b_n (j <= i)
        // Then it is guranteed you need to remove subarray from (i + 1, j - 1). 
        // But it is possible if we could merge some part from b_j <= b_(j+1) <= ... <= b_n, with a_1 <= a_2 <= ... <= a_i, to create a bigger increasing subarray.

        int n = arr.size();
        int left = 0;
        while(left+1 < n && arr[left] <= arr[left+1])
            left++;
        //arr[0...l] is non-decreasing

        // if whole array is in increasing order
        if(left == n-1)
            return 0;

        int right = arr.size()-1;
        while(right > left && arr[right-1] <= arr[right])
            right--;
         //arr[r...n-1] is non-decreasing
        
        //remove [l+1...n-1] or [0...r-1]
        int min_len = min(n-left-1, right);
        int i = 0; 
        int j = right;


        // move the two pointer i and j in their valid range,
        // i.e. keep the two subarrays in both sides,
        // and remove the subarray in the middle        
        while(i <= left && j < n) {
            if(arr[j] >= arr[i]) {
                min_len = min(min_len, j-i-1);
                i++;
            }
            else 
                j++;
        }

        return min_len;
    }
};