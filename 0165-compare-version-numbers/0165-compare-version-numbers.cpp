class Solution {
public:
    int compareVersion(string version1, string version2) {
        // from left to right, compare the integer values till the next seperation point('.')
        // if v1 < v2 return -1 or 1, if both are equal then return 0
        
        int n = version1.size();
        int m = version2.size();

        while(version1.size() || version2.size()) {
            // if string is at end, there is no '.' next, then find function retuns large value, so while taking 
            // substring till seperation till gives entire remaining string, so no problem comes
            int seperation1 = version1.find('.');
            int seperation2 = version2.find('.');
            int val1, val2;

            // cout << "seperations: " << seperation1 << "-" << seperation2 << endl;

            if(version1.size())       val1 = stoi(version1.substr(0, seperation1));
            else                      val1 = 0;

            if(version2.size())       val2 = stoi(version2.substr(0, seperation2));
            else                      val2 = 0;

            // cout << val1 << " v2: " << val2 << endl;

            if(val1 < val2) return -1;
            if(val1 > val2) return 1;

            // remove the checked part from versions
            version1 = seperation1 == -1 ? "" : version1.substr(seperation1+1);
            version2 = seperation2 == -1 ? "" : version2.substr(seperation2+1);

            // cout << "versions: " << version1 << "-" << version2 << endl;
        }

        return 0;
    }
};