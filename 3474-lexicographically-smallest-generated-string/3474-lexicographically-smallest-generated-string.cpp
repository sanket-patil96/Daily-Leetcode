class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        string word(n + m - 1, '?');
        vector<bool> fixed(n + m - 1, false);

        // Step 1: enforce 'T'
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == s2[j]) {
                        word[i + j] = s2[j];
                        fixed[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        // Step 2: fill remaining with 'a'
        for (char &c : word) {
            if (c == '?') c = 'a';
        }

        // Step 3: fix 'F'
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'F') {
                if (word.substr(i, m) == s2) {
                    bool changed = false;

                    // try to break using non-fixed positions
                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;
                        if (!fixed[pos]) {
                            word[pos] = (word[pos] == 'a') ? 'b' : 'a';
                            changed = true;
                            break;
                        }
                    }

                    if (!changed) return "";
                }
            }
        }

        return word;
    }
};