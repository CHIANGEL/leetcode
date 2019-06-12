class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int start = 0, end = -1, result = 0;
		map<char, int> charmap;
		for (int i = 0; i < s.length(); ++i)
		{
			if (charmap.count(s[i]) == 0)
			{
				charmap[s[i]] = i;
				++end;
			}
			else
			{
				result = max(result, end - start + 1);
				for (int j = start; j < charmap[s[i]]; ++j)
					charmap.erase(s[j]);
				start = charmap[s[i]] + 1;
				charmap[s[i]] = i;
				++end;
			}
		}
		result = max(result, end - start + 1);
		return result;
	}
};