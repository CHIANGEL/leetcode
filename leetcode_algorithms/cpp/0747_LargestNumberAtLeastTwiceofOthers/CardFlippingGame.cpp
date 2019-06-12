class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;
		int first_max = INT_MIN, second_max = INT_MIN, index = -1;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > first_max)
			{
				second_max = first_max;
				first_max = nums[i];
				index = i;
			}
			else if (nums[i] > second_max)
			{
				second_max = nums[i];
			}
		}
		if (second_max > INT_MAX / 2 || first_max >= 2 * second_max)
			return index;
		else
			return -1;
	}
};