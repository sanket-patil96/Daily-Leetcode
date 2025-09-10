class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        // logic in Note!
        unordered_set<int> usersToTeach;

        // step1: identify friends who can't communicate
        for(auto &friendship: friendships) {
            int user1 = friendship[0] - 1;      // to convert 0-based indexing
            int user2 = friendship[1] - 1;
            bool canCommunicate = false;

            for(int lang1: languages[user1]) {
                for(int lang2: languages[user2]) {
                    if(lang1 == lang2) {
                        canCommunicate = true;
                        break;
                    }
                }
                if(canCommunicate)
                    break;
            }

            if(!canCommunicate) {
                usersToTeach.insert(user1);
                usersToTeach.insert(user2);
            }
        }

        // step 2: Try teaching each language
        int minUsersToTeach = languages.size() + 1;

        for (int language = 1; language <= n; language++) {
            int count = 0;

            for(int user: usersToTeach) {
                bool knowsLanguage = false;
                for(int lang: languages[user]) {
                    if(lang == language) {
                        knowsLanguage = true;
                        break;
                    }
                }
                if(!knowsLanguage)  count++;
            }

            minUsersToTeach = min(minUsersToTeach, count);
        }

        return minUsersToTeach;
    }
};