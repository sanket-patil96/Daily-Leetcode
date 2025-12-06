class Solution {
public:

    int compareVersion(string version1, string version2) {

        while(!version1.empty() || !version2.empty()) {
            int pos1 = version1.find('.');
            int pos2 = version2.find('.');

            int revision1, revision2;

            // if no dot found, take whole string
            if (pos1 == string::npos) pos1 = version1.size();
            if (pos2 == string::npos) pos2 = version2.size();

             // extract number before dot (or end)
            revision1 = version1.empty() ? 0 : stoi(version1.substr(0, pos1));
            revision2 = version2.empty() ? 0 : stoi(version2.substr(0, pos2));

            if(revision1 < revision2)       return -1;
            else if(revision1 > revision2)  return 1;

            // cut off the processed part (skip the dot too if exists)
            version1 = (pos1 < version1.size()) ? version1.substr(pos1 + 1) : "";
            version2 = (pos2 < version2.size()) ? version2.substr(pos2 + 1) : "";
        }

        return 0;
    }
};