class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		for (int i = 0; i <= nums.size(); ++i)
			findSubset(nums, i, 0);
		return res;
	}

private:
	vector<vector<int>> res;
	vector<int> tmp;
	void findSubset(vector<int>& nums, int len, int step) {
		if (len == step)
		{
			res.push_back(tmp);
			return;
		}
		for (int i = step; i < nums.size(); ++i)
		{
			tmp.push_back(nums[i]);
			findSubset(nums, len, i + 1);
			tmp.pop_back();
		}
	}
};