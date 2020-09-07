// https://leetcode-cn.com/problems/longest-palindromic-substring/

#include <string>
#include <iostream>

using namespace std;

int is_Palindrome(const string &s, int &left, int right)
{
    while (left >=0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
    }
    // [left, right)
    left++;
    return right - left;
}

//������ɢ��������һ���ַ�����������������Ϊ������ɢ
string longestPalindrome(string s) {
    if (s.empty())
    	return "";

    int max_len = 1;
    int start_pos = 0;
    // ����Ϊn���ַ���
    for (int i = 0; i < s.size(); i++) {
        int left = i;
        // �ҵ���iλ��Ϊ���ĵ�������Ӵ�
        int len = is_Palindrome(s, left, i);
        if (len > max_len) {
            max_len = len;
            start_pos = left;
        }
        // �ҵ�i�Ҳ��϶Ϊ���ĵ�������Ӵ�
        left = i;
        len = is_Palindrome(s, left, i + 1);
        if (len > max_len) {
            max_len = len;
            start_pos = left;
        }

    }
    return s.substr(start_pos, max_len);
}

// dp[i][j]: [i, j] : [i, j)�ǲ��ǻ����Ӵ��� ����j >=i
string longestPalindrome2(string s)
{
    if (s.empty())
        return "";

    auto count = s.size();
    bool dp[count][count];
    int max = 1;
    int begin = 0;
    // [i,j] = [i+1, j-1] && s[i] == s[j]
    for (int i = count - 1; i >= 0; i--) {
        for (int j = i; j <= count -1; ++j) {
            dp[i][j] = false;
            if (j - i + 1 <= 2) {
                dp[i][j] = s[i] == s[j];
            } else if (dp[i+1][j-1] == true && s[i] == s[j])
            // [i,j] : [i+1, j-1] �����������һ���ַ� s[i] == s[j]
                dp[i][j] = true;

            if (dp[i][j] && (j- i + 1) > max) {
                    max = j - i + 1;
                    begin = i;
            }
        }
    }
    return s.substr(begin, max);
}

int main()
{
	std::string s("bb");
	std::cout << longestPalindrome2(s);
}

