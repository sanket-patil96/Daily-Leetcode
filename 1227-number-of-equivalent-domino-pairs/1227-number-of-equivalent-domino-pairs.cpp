class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // method 2:                                       
        // we store all the pairs in map, & check if same pair exist more than 1 (coz 1st is itself) OR its reverse pair found then we increment count

        // Instead of tracking [a,b] and [b,a] separately, normalize the pair such that the smaller value is always first, i.e., [min(a,b), max(a,b)].
        // This makes sure that [1,2] and [2,1] are treated the same.
        // Use a hash map to count how many times each normalized domino occurs, and then for each count c, the number of pairs is c * (c - 1) / 2.


        int n = dominoes.size();                            
        int cnt = 0;

        unordered_map<int, int> mp;

        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            int key = min(a, b) * 10 + max(a, b);  // Normalize to unique key
            cnt += mp[key];  // All previously seen identical dominoes can pair with this one
            mp[key]++;
        }

        // By using min(a, b) * 10 + max(a, b) as a key, [1,2] and [2,1] both become 12.
        // Each time a normalized domino is seen again, it can form a new pair with each previous occurrence (count += mp[key]).
        // This approach avoids double counting and is very efficient (O(n) time, O(1) space since max 9×9 = 81 possible domino values).


        return cnt;
    }
};