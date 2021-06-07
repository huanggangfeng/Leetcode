// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

int lengthOfLongestSubstring(string s) {
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        map<char, int> character_pos;
        int ret = 1;
        int last_pos = -1;
        for (int i = 0; i < s.size(); i++) {
            auto it = character_pos.find(s[i]);
            if (it != character_pos.end()) {
                if (it->second > last_pos)
                    last_pos = it->second ;
            }
            character_pos[s[i]] = i;
            ret = ret > i - last_pos ? ret : i - last_pos;
        }
        return ret;
    }
}


int lengthOfLongestSubstring(string s)
{
	if (s.empty())
		return 0;
	int ret = 0;
	int last_pos = 0;
	std::unordered_map<char, int> pre_position;
	for (size_t i = 0; i < s.size(); i++) {
		int len = 0;
		auto it = pre_position.find(s[i]);
		if (it != pre_position.end()) {
			if (it->second > last_pos)
				last_pos = it->second;
		}
		len = i - last_pos;
		ret = ret > len ? ret : len;
		pre_position[s[i]] = i;
	}
	return ret;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> c_cnt;
        int ret = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            c_cnt[s[i]] += 1;
            while (c_cnt[s[i]] > 1) {
                c_cnt[s[left]] -= 1;
                left++;
            }
            int len = i - left + 1;
            if (len > ret)
                ret = len;
        }

        return ret;
    }
};