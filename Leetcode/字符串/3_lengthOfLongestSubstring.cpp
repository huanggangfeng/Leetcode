#include <iostream>
#include <string>
#include <unordered_map>

//�������ڣ�
// ʹ��һ��hash table�������ϴ�ĳ���ַ����ֵ�λ�ã�
// ������ַ��Ѿ����֣���λ����ǰһ��λ�ý�β���Ӵ�֮�У����last_pos������
// ������ֵĸ��磬��ֻ�迼��

using namespace std;
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
			// 左指针向右移动，直到子串中s[i]的出现次数恢复成成1.
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

int main()
{
	string s(" ");
	std::cout << lengthOfLongestSubstring(s) << "\n";
	return 0;
}
