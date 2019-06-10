class Solution {
public:
	string longestPalindrome(string s) {
		string str = "$";
		for (int i = 0; i < s.length(); ++i)
		{
			str += "#";
			str += s[i];
		}
		str += "#";
		return Manacher(str);
	}

private:
	string Manacher(string str)
	{
		int max_len = 0, max_id = 0, id = 0, mx = 0;
		int* len = new int[str.length()];
		string res = "";
		len[0] = 0; // 0的位置是$符号，因此不算是回文串
		for (int i = 1; i < str.length(); ++i)
		{
			if (i < mx)
				len[i] = min(len[2 * id - i], mx - i);
			else
				len[i] = 1;
			while (str[i - len[i]] == str[i + len[i]])
				++len[i];
			if (i + len[i] > mx)
			{
				mx = i + len[i];
				id = i;
				if (len[i] > max_len)
				{
					max_len = len[i];
					max_id = i;
				}
			}
		}
		for (int i = max_id - max_len + 1; i < max_id + max_len; ++i)
			if (str[i] != '#')
				res += str[i];
		return res;
	}
};