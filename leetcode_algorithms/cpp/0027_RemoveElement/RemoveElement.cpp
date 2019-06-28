class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		int valCount = 0;
		auto it = nums.begin();
		while (it != nums.end())
		{
			if ((*it) == val)
			{
				it = nums.erase(it);
				++valCount;
			}
			else
				++it;
		}
		return n - valCount;
	}
};