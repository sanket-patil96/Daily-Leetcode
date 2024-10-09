class Solution {
public:

    int minAddToMakeValid(string parenthesis) {
        // store all opening chars in stack, if current bracket is closing then 
        // pop the top opening char if there is any, else increment the cnt of invalid brackets
        // at last add stack size to count and return total count 

        // Method 2: reduce space: Time: O(N)  Space: O(1)
        // we can reduce the space of stack by maintaining count for opening brackets
        // if current bracket is closing then we check if count of opening brackets are > 0 then we minus 1 from it as we closed that open bracket
        // else we simply add 1 to count for invalid closing brackets 
        // at last add opening + invalid count & return as answer
        int opening = 0;
        int closing = 0;
        
        for(int i = 0; i < parenthesis.size(); i++)
        {
            // if current parenthesis is opening add opening
            if(parenthesis[i] == '(')
                opening++;
            
            // if its an closing one then 
            else
            {
                if(opening > 0)
                    opening--;            
                else 
                    closing++;
            }
        }
    
        // after all these operations if all opened brackets are closed 
        // then only, we can say valid parenthesis 
        // all remaining unclosed brackets should be added to closing bracket count
    
        return opening+closing;
    }
};