class Solution {
public:
	bool isNumber(string s) {
		map<char, int> chCount;
		chCount['+'] = 0;
		chCount['-'] = 0;
		chCount['.'] = 0;
		chCount['e'] = 0;
		for (char c = '0'; c <= '9'; ++c)
			chCount[c] = 0;

		s = Trim(s);
		int n = s.length();
		if (!n)
			return false;
		int e_pos = -1, point_pos = -1;
		bool num_exist = false;
		for (int i = 0; i < n; ++i)
		{
			if (chCount.count(s[i]) == 0)
			{
				return false;
			}
			else if (s[i] == 'e')
			{
				if (chCount[s[i]] == 0)
				{
					++chCount[s[i]];
					e_pos = i;
				}
				else
				{
					return false;
				}
			}
			else if (s[i] == '.')
			{
				if (chCount[s[i]] == 0)
				{
					++chCount[s[i]];
					point_pos = i;
				}
				else
				{
					return false;
				}
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				num_exist = true;
				++chCount[s[i]];
			}
			else
			{
				++chCount[s[i]];
			}
		}
		if (chCount['e'] == 0)
		{
			if (!num_exist)
				return false;
			if (chCount['+'] + chCount['-'] > 1)
				return false;
			if ((chCount['+'] > 0 && s[0] != '+') || (chCount['-'] > 0 && s[0] != '-'))
				return false;
			return true;
		}
		else
		{
			if (point_pos > e_pos)
				return false;
			if (isNumber(s.substr(0, e_pos)) && isNumber(s.substr(e_pos + 1)))
				return true;
			else
				return false;
		}
	}

private:
	string Trim(string s)
	{
		if (s.empty())
			return s;
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
		return s;
	}
};