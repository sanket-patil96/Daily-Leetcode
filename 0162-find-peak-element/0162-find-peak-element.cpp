class Solution {
public:
    int findPeakElement(vector<int>& a) {
        // its like find peak in mountain array
        // for mid to be peak to should be greater than next element
            
        int n = a.size();
        int low = 0;
        int high = n-1;             // already check for n-1
        
        while(low < high) {
            int mid = (low + high) / 2;

            // can't do this coz will go out of boundry
            // if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            //     return mid;
            
            // mid + 1 won't go out of bounds coz loop till low < high not <= using here
            // if its greater means it can be possible ans go left side to check more
            if(a[mid] > a[mid+1])
                high = mid;
                
            // means we are in incresing side so go forword
            else
                low = mid + 1;
        }
        
        // high always remain on mid which is peak till end
        return high;
    }
};