class Solution {
public:
	int countPrimeSetBits(int L, int R) {
		int res = 0;
		for (int i = L; i <= R; ++i)
		{
			res += isPrime[setBits(i)];
		}
		return res;
	}
private:
	int isPrime[33] = { 0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0 };

	int setBits(int n)
	{
		int res = 0;
		while (n)
		{
			res += (n & 1);
			n >>= 1;
		}
		return res;
	}
};