class Solution {
public:
	int flipgame(vector<int>& fronts, vector<int>& backs) {
		set<int> same;
		int res = INT_MAX;
		for (int i = 0; i < fronts.size(); ++i)
			if (fronts[i] == backs[i])
				same.insert(fronts[i]);
		for (int i = 0; i < fronts.size(); ++i)
		{
			if (same.find(fronts[i]) == same.end())
				res = min(res, fronts[i]);
			if (same.find(backs[i]) == same.end())
				res = min(res, backs[i]);
		}
		return res % INT_MAX;
	}
};