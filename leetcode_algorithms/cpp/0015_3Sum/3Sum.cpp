class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int n = nums.size();
		vector< vector<int> > res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < n - 2; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int start = i + 1;
			int end = n - 1;
			while (start < end)
			{
				int tmp = nums[i] + nums[start] + nums[end];
				if (tmp == 0)
				{
					res.push_back({ nums[i],nums[start],nums[end] });
					while (nums[end] == nums[end - 1] && end > start)
						--end;
					--end;
					while (nums[start] == nums[start + 1] && start < end)
						++start;
					++start;
				}
				else if (tmp > 0)
				{
					while (start < end && nums[end] == nums[end - 1])
						--end;
					--end;
				}
				else
				{
					while (start < end && nums[start] == nums[start + 1])
						++start;
					++start;
				}
			}
		}
		return res;
	}
};