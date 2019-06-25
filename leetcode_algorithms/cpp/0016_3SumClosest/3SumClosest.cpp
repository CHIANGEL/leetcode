class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int res = 0, min_gap = INT_MAX;

		for (int i = 0; i < n - 2; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int start = i + 1;
			int end = n - 1;
			while (start < end)
			{
				int tmp = nums[i] + nums[start] + nums[end];
				int gap = tmp - target;
				if (abs(gap) < min_gap)
				{
					res = tmp;
					min_gap = abs(gap);
				}
				if (gap == 0)
				{
					return target;
				}
				else if (gap > 0)
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