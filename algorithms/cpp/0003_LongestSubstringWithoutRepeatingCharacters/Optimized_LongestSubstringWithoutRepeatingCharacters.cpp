class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.length(), result = 0;
		int start = 0, end = 0;
		map<char, int> charmap;
		while (end < n) // [start, end)
		{
			if (charmap.count(s[end]) == 1)
			{
				result = max(result, end - start);
				start = max(start, charmap[s[end]] + 1);
			}
			charmap[s[end]] = end;
			++end;
		}
		result = max(result, end - start);
		return result;
	}
};