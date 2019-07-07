class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		int I = nums.size() - 3, J = nums.size() - 2, S = nums.size() - 1;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < I; ++i)
		{
			if (i != 0 && nums[i - 1] == nums[i])
				continue;
			if (4 * nums[i] > target)
				break;
			if (nums[i] + nums[S - 2] + nums[S - 1] + nums[S] < target)
				continue;
			for (int j = i + 1; j < J; ++j)
			{
				if (j != i + 1 && nums[j - 1] == nums[j])
					continue;
				if (nums[i] + nums[j] + nums[S - 1] + nums[S] < target)
					continue;
				int left = j + 1, right = S, tmp_sum;
				while (left < right)
				{
					tmp_sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (tmp_sum == target)
					{
						res.push_back({ nums[i], nums[j], nums[left], nums[right] });
						while (++left, left <= S && nums[left - 1] == nums[left]);
						while (--right, right >= j + 1 && nums[right + 1] == nums[right]);
					}
					else if (tmp_sum < target)
					{
						while (++left, left <= S && nums[left] == nums[left - 1]);
					}
					else
					{
						while (--right, right >= j + 1 && nums[right] == nums[right + 1]);
					}
				}
			}
		}
		return res;
	}
};