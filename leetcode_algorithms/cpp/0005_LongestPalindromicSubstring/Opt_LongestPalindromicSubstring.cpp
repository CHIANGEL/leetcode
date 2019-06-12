class Solution {
public:
	string longestPalindrome(string s) {
		int res_start = 0, res_len = 1;
		for (int i = 0; i < s.length(); ++i)
		{
			int len1 = expandFromCenter(i, i, s);
			int len2 = expandFromCenter(i, i + 1, s);
			int len = max(len1, len2);
			if (len > res_len)
			{
				res_start = i - (len - 1) / 2;
				res_len = len;
			}
		}
		return s.substr(res_start, res_len);
	}

private:
	int expandFromCenter(int left, int right, string s)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{
			--L;
			++R;
		}
		return R - L - 1;
	}
};