// https://leetcode-cn.com/problems/compare-version-numbers/
class Solution {
public:
    vector<int> split_and_atoi(string s) {
        vector<int> ret;
        auto pos = s.find(".", 0);
        int i = 0;
        while (pos != string::npos) {
            string tmp = s.substr(i, pos -i);
            ret.push_back(atoi(tmp.c_str()));
            i = pos  + 1;
            pos = s.find(".", i);
        }
        ret.push_back(atoi(s.substr(i, string::npos -i).c_str()));
        return ret;        
    }

    int compareVersion(string version1, string version2) {
        vector<int> v1 = split_and_atoi(version1);
        vector<int> v2 = split_and_atoi(version2);
        int n = v1.size() > v2.size() ? v2.size() : v1.size();
        for (int i = 0; i < n; i++) {
            if (v1[i] > v2[i])
                return 1;
            else if (v1[i] < v2[i])
                return -1;
        }

        if (v1.size() > n) {
            for (int i = n; i < v1.size(); i++) {
                if (v1[i] != 0)
                    return 1;
            }
        }
        
        if (v2.size() > n) {
            for (int i = n; i < v2.size(); i++) {
                if (v2[i] != 0)
                    return -1;
            }
        }

        return 0;
    }
};
		
