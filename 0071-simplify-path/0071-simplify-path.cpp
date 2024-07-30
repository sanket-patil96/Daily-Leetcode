class Solution {
public:
    // 1. we add characters till '/' as it should be the seperator for file paths, we don't push '/' to word, we stop adding words when we see '/'
    // 2. if word == '..' and stack is not empty then we pop the above directory 
    // 3. if word != '..' and not equals '.' then we push the current word
    // 4. after traversing path, we start from stack top and add answer after it coz stack is LIFO
    // 5. before we add top word we need to push '/' 
    // 6. if final answer is == '', then make ans = '/' as root directory

    // word == '..' - then pop the top of stack
    //      == ''   - skip
    //      == '.'  - skip  (denotes current directory so ignore it)
    //      == '/'  - stop while loop

    string simplifyPath(string path) {
        string ans = "";
        string word = "";
        stack<string> st;
        int n = path.size();
 
        for(int i = 0; i < n; i++) {
            word = "";
            while(i != n && path[i] != '/') {
                word += path[i];
                i++;
            }

            // go one directory above!
            if(word == "..") {
                // this condition should be here only otherwise it will go to else when stack is empty and current word == '..', exp: path = "/../"
                if(!st.empty())             
                   st.pop();
            }

            // add only if there is word
            else if(word != "" && word != ".")
                st.push(word);
        }


        while(!st.empty()) {
            // all left side path will gone & only upper level path will remain
            ans = "/" + st.top() + ans;
            st.pop();
        }

        // if no path then single slash should be there
        if(ans == "")
            ans = "/";

        return ans;
    }
};