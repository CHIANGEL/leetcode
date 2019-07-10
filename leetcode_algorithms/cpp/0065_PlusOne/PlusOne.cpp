class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();
		++digits[n - 1];
		for (int i = n - 1; i >= 0; --i)
		{
			if (digits[i] < 10)
				return digits;
			else if (i > 0)
			{
				digits[i] %= 10;
				++digits[i - 1];
			}
			else
			{
				digits[i] %= 10;
				digits.insert(digits.begin(), 1);
				return digits;
			}
		}
		return digits;
	}
};