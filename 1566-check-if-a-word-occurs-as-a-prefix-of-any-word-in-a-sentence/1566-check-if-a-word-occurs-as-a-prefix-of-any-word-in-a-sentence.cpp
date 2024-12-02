class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        // if(sentence.find(searchWord) != string::npos) {
        //     return 
        // }
        int i = 0;
        int cnt = 1;
        bool flag = false;
        while(i < sentence.size()) {
            string word = "";

            while(i < sentence.size() && sentence[i] != ' ')
                word += sentence[i++];

            cout << word << " ";
            if(word.find(searchWord) != string::npos) {
                cout << " find: " << word << endl;

                // check if searchWord is at prefix of word
                bool found = true;
                for(int j = 0; j < searchWord.size(); j++) {
                    if(searchWord[j] != word[j]) {
                        i++;
                        cnt++;
                        found = false;
                        break;
                    }
                }

                if(!found)
                    continue;
                
                flag = true;
                break;
            }

            i++;
            cnt++;
        }

        if(!flag)
            return -1;

        return cnt;
    }
};