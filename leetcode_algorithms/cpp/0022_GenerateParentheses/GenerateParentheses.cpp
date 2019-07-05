class Solution {
public:
	vector<string> generateParenthesis(int n) {
		parMaker("", n, n);
		return res;
	}

private:
	vector<string> res;

	void parMaker(string str, int left, int right)
	{
		if (left == 0 && right == 0)
		{
			res.push_back(str);
			return;
		}
		if (left > 0)
			parMaker(str + '(', left - 1, right);
		if (right > 0 && left < right)
			parMaker(str + ')', left, right - 1);
	}
};