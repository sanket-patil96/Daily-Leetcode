class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // here n/3 times means at max there will be only 2 elements that are occured n/3 times
        // ex: [4,4,4,3,3,3,2,2] n = 8    
        // n/3 = 2(floor value) so here 3&4 are two majority elements

        // ex: [4,4,4,3,3,3,2,2,2] n = 9 
        // n/3 = 3(floor value) so here not single element occur more than n/3 times

        // ex: [4,4,4,4,3,3,3,3,2] n = 9    
        // n/3 = 3(floor value) so here 3&4 are two majority elements

        // so we can say there can at max 2 majority in any size array
        // it based on simple logic that if we make 3 parts of an array on n
        // n = 8   n/3 = 2, so for the majority elem must occur minimum 3 times:
        // 3 occurence elems are :      ---|---|--    here '-' that are occured 3 times
        // so majority elem is 2, to 3rd number for majority needs 1 more occurence but array 
        // only has size 8 so we can't fit in array
        // so at max there are only 2 majority elements at min they can be zero


        // brute force: O(n^2)
        // traverse array using two arrays and check occurence each element

        // better:
        // here we can use hashing to take count the occurences and return which elem has 
        // occurence more thank n/3 time: O(n) for normal traversaing + O(1) for unordered map
        // worst case unordered map time is: O(n)   space will be (N) in worst case


        // we can use the Majority Element I question example as the reference for this example

        // here we create 2 count & 2 elements for the answer & all same as its previous question

        // for first majority element
        int cnt1 = 0;
        int elem1 = INT_MIN;          
        
        // for second majority element
        int cnt2 = 0;
        int elem2 = INT_MIN;


        for(int i: nums) {
            // here the only improvement is check if both elements don't point to same element
            if(cnt1 == 0 && elem2 != i) {
                cnt1 = 1;
                elem1 = i;
            }

            else if(cnt2 == 0 && elem1 != i) {
                cnt2 = 1;
                elem2 = i;
            }

            else if(i == elem1)
                cnt1++;

            else if(i == elem2)
                cnt2++;

            // if both elem1 & elem2 are not same then reduce both cnt
            else {
                cnt1--;
                cnt2--;
            }
        }

        // after this loop we can't say thay there are two majority elements in loop, so
        vector<int> ans;
        cnt1 = 0;       // we traverse array again and validate for majority
        cnt2 = 0;

        for(int i: nums) {
            if(i == elem1)
                cnt1++;
            else if(i == elem2)
                cnt2++;
        }

        if(cnt1 > nums.size()/3)
            ans.push_back(elem1);

        if(cnt2 > nums.size()/3)
            ans.push_back(elem2);


        return ans;
    }
};