class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		if (!n)
			return "";
		int min_length = strs[0].length();
		for (int i = 1; i < n; ++i)
			min_length = min_length > strs[i].length() ? min_length : strs[i].length();
		for (int i = 0; i < min_length; ++i)
			for (int j = 1; j < n; ++j)
				if (strs[j][i] != strs[0][i])
					return strs[0].substr(0, i);
		return strs[0].substr(0, min_length);
	}
};