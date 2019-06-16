class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		else if (x < 10)
			return true;
		int rev_x = 0;
		int len = 0;
		for (int tmp = x; tmp; tmp /= 10)
			++len;
		for (int i = 0; i < len / 2; ++i)
		{
			(rev_x *= 10) += (x % 10);
			x /= 10;
		}
		if (len & 1)
			x /= 10;
		return x == rev_x;
	}
};