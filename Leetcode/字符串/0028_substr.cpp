class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        
        unordered_map<char, int> hash_map;
        for (int i = 0; i < needle.size(); i++) {
            hash_map[needle[i]] = needle.size() - i;
        }

        int i = 0; // index of haystack
        int j = 0; // index of needle
        int k = needle.size(); // next 
        int start_pos = i;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                if (j == needle.size() - 1)
                    return i - j;
                else {
                    i++;
                    j++;
                    continue;
                }
            } else {
                    // i先回退到刚才起始位置， 然后觉得移动多少
                    i -= j;
                    if (hash_map.find(haystack[k]) != hash_map.end())
                        i += hash_map[haystack[k]];
                    else
                        i++;
                    j = 0;
                    k = i + needle.size();
                    if (k > haystack.size())
                        return -1;
            }
        }
        return -1;
    }
};