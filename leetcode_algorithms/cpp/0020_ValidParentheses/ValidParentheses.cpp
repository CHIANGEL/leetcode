class Solution {
public:
	bool isValid(string s) {
		for (int i = 0; i < s.length(); ++i)
		{
			switch (s[i])
			{
			case '(':
			case '[':
			case '{':
				parStack.push(s[i]);
				break;
			case ')':
				if (parStack.empty() || parStack.top() != '(')
					return false;
				else
					parStack.pop();
				break;
			case ']':
				if (parStack.empty() || parStack.top() != '[')
					return false;
				else
					parStack.pop();
				break;
			case '}':
				if (parStack.empty() || parStack.top() != '{')
					return false;
				else
					parStack.pop();
				break;
			};
		}
		if (parStack.empty())
			return true;
		return false;
	}

private:
	stack<char> parStack;
};