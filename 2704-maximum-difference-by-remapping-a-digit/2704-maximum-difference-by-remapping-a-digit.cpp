class Solution {
public:
    int minMaxDifference(int num) {
        // -- to Maximize num:
        // we can get max numbere by only replacing the first digit then whatever it is without 9 (coz itself its max)
        // if first digit is 9 then find the next smaller than 9 & replace the first one with its all occurances
        // -- to minimize num:
        // just make the first digit 0 (and its all occurances)

        // first convert num to string
        string maxi = to_string(num);
        string mini = maxi;             // use this for getting minimum
        char numToReplace = ' ';       // its the number that we will change to max('9')
        char makeZero = mini[0];        // always make first digit 0 to minimize the overall value of num

        // get maxVal
        for(int i = 0; i < maxi.size(); i++) {
            if((numToReplace == ' ' && maxi[i] != '9') || numToReplace == maxi[i]) {     // only do when we don't select any num to replace
                numToReplace = maxi[i];
                maxi[i] = '9';             
            }

            if(mini[i] == makeZero) {
                mini[i] = '0';
            }
        }

        // now get difference
        int diff = stoi(maxi)-stoi(mini);
        return diff;
    }
};