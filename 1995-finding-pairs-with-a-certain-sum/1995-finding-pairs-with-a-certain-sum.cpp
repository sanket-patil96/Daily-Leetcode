class FindSumPairs {
// Algo:
// count: for counting the pairs, we can use the standard hashmap approach, we store freq of all values in nums2(as for lookup nums1 can be used as its size is very small than nums2)
//        then traverse all nums1 if freq.count(tot-nums1[i]) will present in map then get the count of frequency, that no.of pairs can pair with nums1[i]
// add:   for adding we have to remove the previous value frequency by 1 from map as this value is now changing, and add the given value to oroginal Value
//        update it in nums2 as well as add in frequency map

private:
    vector<int> n1, n2;
    unordered_map<int, int> freq;       // it will store the frequency of n1 values, which used to find the count of matching pairs

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;

        for(auto i: n2)
            freq[i]++;
    }
    
    void add(int index, int val) {
        // remove the previous value frequency and add new value to frequency and update in nums2
        freq[n2[index]]--;
        n2[index] += val;
        freq[n2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto i: n1) {
            if(freq.count(tot-i))
                ans += freq[tot-i];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */