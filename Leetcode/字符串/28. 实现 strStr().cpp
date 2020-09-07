class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;

        int k;
        int m = needle.size(); //第一次匹配时 源串中参与匹配的元素的下一位
        unordered_map<char, int> hash_map;
        for(int i = 0; i < m; i++) {
            hash_map[needle[i]] = m - i;
        }

        int i = 0; 
        int j = 0;    
        int start_pos = i;
        while(i < haystack.size())
        {
            if(haystack[i] != needle[j])
            {
                int k = 1; // 默认i+1
                if (hash_map.find(haystack[m]) != hash_map.end())
                    k = hash_map[haystack[m]];

                // i 向右滑动的个数，如果haystack[m]在子串中没出现过，i直接可以跳到 m的位置
                start_pos += k; 
                i = start_pos;
                j = 0; 
                m = start_pos + needle.size(); //m为下一次参与匹配的源串最后一位元素的下一位

                if(m > haystack.size()) {
                    return -1;
                }
            }
            else
            {
                if(j == needle.size() - 1) //若j为子串末位 匹配成功 返回源串此时匹配首位
                    return i - j;
                i++;
                j++;
            }
        }
        return -1;
    }
};