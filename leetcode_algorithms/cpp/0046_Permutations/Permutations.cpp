class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		n = nums.size();
		if (n == 0)
			return { {} };
		else if (n == 1)
			return { nums };
		vector<bool> isPerm(n, false);
		dfs(nums, isPerm);
		return res;
	}

private:
	vector<vector<int>> res;
	vector<int> tmp;
	int n;

	void dfs(vector<int>& nums, vector<bool>& isPerm)
	{
		if (tmp.size() > n)
			return;
		else if (tmp.size() == n)
		{
			res.push_back(tmp);
			return;
		}
		for (int i = 0; i < n; ++i)
			if (!isPerm[i])
			{
				isPerm[i] = true;
				tmp.push_back(nums[i]);
				dfs(nums, isPerm);
				tmp.pop_back();
				isPerm[i] = false;
			}
	}
};