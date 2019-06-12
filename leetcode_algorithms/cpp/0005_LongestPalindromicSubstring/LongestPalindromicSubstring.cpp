/*
 * 这种方法会TLE
 */

class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		string s_reverse = "";
		s_reverse.assign(s.rbegin(), s.rend());
		for (int len = n; len >= 1; --len)
		{
			for (int i = 0; i + len <= n; ++i)
			{
				if (s.substr(i, len) == s_reverse.substr(n - i - len, len))
				{
					return s.substr(i, len);
				}

			}
		}
		return s;
	}
};