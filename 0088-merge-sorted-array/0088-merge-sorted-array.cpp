class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;  // n1's actual elements last index
        int j = n-1;
        int k = m+n-1;  // end of n1 including last zeros
        
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) 
                nums1[k--] = nums1[i--];
            
            else 
                nums1[k--] = nums2[j--];
        }

        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};