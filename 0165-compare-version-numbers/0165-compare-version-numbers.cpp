class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;

        while(true) {
            bool b1 = false, b2 = false;
            int v1 = 0;
            int v2 = 0;
            while(i < version1.size() && version1[i] != '.') {
                v1 *= 10;
                v1 += version1[i] - '0';
                i++;
                b1 = true;
            }
            i++;

            while(j < version2.size() && version2[j] != '.') {
                v2 *= 10;
                v2 += version2[j] - '0';
                j++;
                b2 = true;
            }
            j++;

            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
            if(!b1 && !b2) return 0;
        }

        return 0;
    }
};