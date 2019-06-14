class Solution {
public:
	string reverseOnlyLetters(string S) {
		string rev_S;
		// reverse(rev_S.begin(), rev_S.end());
		int n = S.size();
		for (int i = 0, k = n - 1; i < n; ++i)
		{
			if (!isalpha(S[i]))
			{
				rev_S += S[i];
			}
			else
			{
				while (!isalpha(S[k]) && k >= 0)
					--k;
				rev_S += S[k--];
			}
		}
		return rev_S;
	}
};