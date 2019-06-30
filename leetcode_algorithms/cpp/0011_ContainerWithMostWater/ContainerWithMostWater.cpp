class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int res = INT_MIN;
		for (int i = 0; i < n - 1; ++i)
			for (int j = i + 1; j < n; ++j)
				if ((j - i) * min(height[i], height[j]) > res)
					res = (j - i) * min(height[i], height[j]);
		return res;
	}
};