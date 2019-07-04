class Solution {
public:
	int strStr(string haystack, string needle) {
		int m = haystack.length();
		int n = needle.length();
		if (!n)
			return 0;
		if (m == n)
			return haystack == needle ? 0 : -1;
		if (m < n)
			return -1;
		for (int i = 0; i <= m - n; ++i)
		{
			int flag = 1;
			for (int j = i; j < i + n; ++j)
				if (haystack[j] != needle[j - i])
				{
					flag = 0;
					break;
				}
			if (flag)
				return i;
		}
		return -1;
	}
};