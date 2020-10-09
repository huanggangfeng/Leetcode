// https://leetcode-cn.com/problems/jewels-and-stones/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<int> count;
        count.resize(52);
        for (char &ch : S) {
            if (ch >= 'a' && ch <= 'z')
                count[ch - 'a']++;
            else if (ch >= 'A' && ch <= 'Z')
                count[ch - 'A' + 26]++;
        }
        int ret = 0;
        for (char &ch : J) {
            if (ch >= 'a' && ch <= 'z')
                ret += count[ch - 'a'];
            else if (ch >= 'A' && ch <= 'Z')
                ret += count[ch - 'A' + 26];
        }

        return ret;
    }
};