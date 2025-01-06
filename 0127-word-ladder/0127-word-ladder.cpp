class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // this approach can give TLE!!!
        // problem is we have to return no.of words in transformation from begin to last
        // here we want 'shortest' path means we can think in direction of using BFS
        // from given string we have to make single change & try to reach endWord So,
        // push beginWord in queue with its distance & try changing each value in q.front() to match any string from wordlist
        // if we reach endWord then store the min transformation words needed(distance) & return at last

        unordered_set<string> vis;
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<string> q;

        if(!set.count(endWord))
            return 0;

        q.push(beginWord);
        vis.insert(beginWord);

        int totalWords = 1;         // initially there is beginWord in transformation path

        while(!q.empty()) {

            int size = q.size();

            // for each level increment totalWords 1 time only
            for(int k = 0; k < size; k++) {
                
                string str = q.front();
                q.pop();

                if(str == endWord) 
                    return totalWords;

                // try changing every word in str & check if exist in wordList
                for(int i = 0; i < str.size(); i++) {
                    char original = str[i];
                    for(int j = 0; j < 26; j++) {
                        str[i] = 'a'+j;
                        if(!vis.count(str) && set.count(str)) {
                            vis.insert(str);
                            q.push(str);
                        }
                    }

                    // reseat original string for checking next options
                    str[i] = original;
                }
            }

            totalWords++;
        }
        
        return 0;
    }
};
