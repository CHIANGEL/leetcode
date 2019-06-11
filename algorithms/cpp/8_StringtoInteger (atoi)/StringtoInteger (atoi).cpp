class Solution {
public:
	int myAtoi(string str) {
		int n = str.length();
		int start = 0;
		int res = 0;
		bool isNegative = false;
		while (str[start] == ' ')
			++start;
		if (str[start] == '-')
		{
			isNegative = true;
			++start;
		}
		else if (str[start] == '+')
		{
			isNegative = false;
			++start;
		}
		if (start >= n || str[start] < '0' || str[start] > '9')
			return 0;
		for (int i = start; i < n && str[i] >= '0' && str[i] <= '9'; ++i)
		{
			int tmp = int(str[i] - '0');
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && tmp > 7))
				return INT_MAX;
			if (res < INT_MIN / 10 || (res == INT_MIN / 10 && tmp > 8))
				return INT_MIN;
			if (isNegative)
				(res *= 10) -= tmp;
			else
				(res *= 10) += tmp;
		}
		return res;
	}
};