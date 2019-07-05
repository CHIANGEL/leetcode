class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (!digits.length())
			return res;
		maps.push_back({ 'a', 'b', 'c' });
		maps.push_back({ 'd', 'e', 'f' });
		maps.push_back({ 'g', 'h', 'i' });
		maps.push_back({ 'j', 'k', 'l' });
		maps.push_back({ 'm', 'n', 'o' });
		maps.push_back({ 'p', 'q', 'r', 's' });
		maps.push_back({ 't', 'u', 'v' });
		maps.push_back({ 'w', 'x', 'y' ,'z' });
		dfs(digits, "");
		return res;
	}

private:
	vector<string> res;
	vector< vector<char> > maps;

	void dfs(string digits, string str) {
		int index = int(digits[0] - '2');
		string str_tmp;
		for (int i = 0; i < maps[index].size(); ++i)
		{
			str_tmp = str + maps[index][i];
			if (digits.length() == 1)
			{
				res.push_back(str_tmp);
				continue;
			}
			string digit_rest = digits.substr(1, digits.length() - 1);
			dfs(digit_rest, str_tmp);
		}
	}
};