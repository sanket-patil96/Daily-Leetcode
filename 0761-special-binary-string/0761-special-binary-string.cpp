class Solution {
public:
    string makeLargestSpecial(string s) {
        if(s.size()==0) // for empty strings base case
        return "";

        int count=0;
        int start=0;
        vector<string> store_bal;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            count++;
            else
            count--;
            if(count==0)
            {
                // Aprimitive block is always 1+{inner}+0
                // We recurse on the {inner string} part

                string inner = s.substr(start+1,i-start-1); // i-start-1 because substr function needs second parameter as length and not the ending index
                inner = makeLargestSpecial(inner);
                store_bal.push_back("1"+inner+"0");
                start=i+1;

            }
        }

        // sort descending coz lexicographically
        sort(store_bal.begin(),store_bal.end(),greater<string>());

        // reconstruct the maximised string
        string ans="";
        for(string x: store_bal)
        ans+=x;
        return ans;
        
    }
};