class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        // brute force: use 2 loops 
        // since all values in baskets are positive we use negative values to trace used baskets
        int unplaced = 0;

        for(int i = 0; i < fruits.size(); i++) {
            int j;
            for(j = 0; j < baskets.size(); j++) {
                if(baskets[j] != -1 && baskets[j] >= fruits[i]) {
                    baskets[j] = -1;
                    break;
                }
            }

            if(j == baskets.size())
                unplaced++;
        }

        return unplaced;
    }
};