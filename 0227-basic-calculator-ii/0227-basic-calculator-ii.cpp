class Solution {
public:
    // get the top operator from fst and evaluate between first 2 values from 2nd stack
    void calculate(stack<char> &fst, stack<long long> &snd) {   
        int res = 0;
        // while(!fst.empty() && !snd.empty() && mp[fst.top()] >= mp[ch]) {
            int second = snd.top();
            snd.pop();
            int first = snd.top();
            snd.pop();

            char oprator = fst.top();
            fst.pop();

            switch(oprator) {
                case '*':
                    res = first * second;
                    break;
                
                case '/':
                    if(second == 0)
                        res = 0;
                    else 
                        res = first / second;
                    break;

                case '+':
                    res = first + second;
                    break;
                
                case '-':
                    res = first - second;
                    break;

                default: break;
            }
        // }

        snd.push(res);      // push the result in 2nd stack 
    }

    int calculate(string s) {
        // we can do this using 2 stacks, 
        // 1st stack will store operator's & 2nd will store operands

        stack<char> fst;
        stack<long long> snd;
        unordered_map<char, int> mp;        // store precedance
        mp['*'] = 2;
        mp['/'] = 2;
        mp['-'] = 1;
        mp['+'] = 1;

        string word = "";
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // skip spaces
            if(ch == ' ') 
                continue;

            if(ch == '*' || ch == '/' || ch == '+' || ch == '-') {
                // first push the current formed word inside stack
                long long num = stoll(word);        // for handling long long exp: 0-2147483647
                snd.push(num);
                word = "";      // make it empty for next operations

                // if operator at top of stack has greater precedance than current operator, do calculation first
                while(!fst.empty() && mp[fst.top()] >= mp[ch])
                    calculate(fst, snd);

                // now after checking precedance push the current operator
                fst.push(ch);
            } 
            else 
                word += ch;
        }

        // push the last word to 2nd stack
        if(word != "") {
            long long num = stoll(word);
            snd.push(num);
            // cout << word << "  " << num << endl;
        }

        // now calculate all remaining values from stack, single value will remain on snd & fst will be empty
        while(!fst.empty())
            calculate(fst, snd);
        

        return snd.top();
    }

// 2nd solution: 
    int calculateNew(string s) {
        int length = s.length();
        if (length == 0) return 0;
        int currentNumber = 0, lastNumber = 0, result = 0;
        char sign = '+';
        
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            
            if (isdigit(currentChar)) 
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            
            if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
                if (sign == '+' || sign == '-') {
                    result += lastNumber;
                    lastNumber = (sign == '+') ? currentNumber : -currentNumber;
                } 
                else if (sign == '*') 
                    lastNumber = lastNumber * currentNumber;
                
                else if (sign == '/')
                    lastNumber = lastNumber / currentNumber;
                
                sign = currentChar;
                currentNumber = 0;
            }
        }
        result += lastNumber;
        return result;  
    }
};