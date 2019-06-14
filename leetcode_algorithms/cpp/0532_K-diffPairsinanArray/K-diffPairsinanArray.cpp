class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int res = 0, n = nums.size();
		auto i = nums.begin();
		while (i != nums.end())
		{
			if (binary_search(i + 1, nums.end(), *i + k))
				++res;
			do {
				++i;
			} while (i != nums.end() && *(i - 1) == *i);
		}
		return res;
	}
};