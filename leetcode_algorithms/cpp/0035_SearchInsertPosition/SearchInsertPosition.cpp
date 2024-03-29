class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		int res_index;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (nums[left] == target)
			return left;
		return nums[left] < target ? left + 1 : left;
	}
};