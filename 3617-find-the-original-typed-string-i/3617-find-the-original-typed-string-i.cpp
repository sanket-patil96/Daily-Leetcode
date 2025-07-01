class Solution {
public:
    int possibleStringCount(string word) {
        // only need to count the (extra frequency of every character) (coz 1st occurnace is mandatory in original string so count only extra)
        // and at last add +1 to it (means all original letters, ex: 'abbccc' extra = 1b+2c = 3 & 'abc' oroginal total = 4)

        char prev = '#';    // to find if current char is extra or not
        int extra = 0;

        for(int i = 0; i < word.size(); i++) {
            if(word[i] == prev)
                extra++;
            prev = word[i];
        }

        return extra+1;
    }
};