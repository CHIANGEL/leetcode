class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size();
		int size2 = nums2.size();
		vector<int> tmp;
		int i = 0, j = 0, k = 0;
		while (i < size1 && j < size2)
		{
			if (nums1[i] < nums2[j])
				tmp.push_back(nums1[i++]);
			else
				tmp.push_back(nums2[j++]);
		}
		while (i < size1)
			tmp.push_back(nums1[i++]);
		while (j < size2)
			tmp.push_back(nums2[j++]);
		if ((size1 + size2) % 2)
			return tmp[(size1 + size2) / 2];
		else
			return double(tmp[(size1 + size2) / 2] + tmp[(size1 + size2) / 2 - 1]) / 2;
	}
};
