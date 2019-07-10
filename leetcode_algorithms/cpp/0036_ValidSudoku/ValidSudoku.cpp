class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		set<char> chSet;
		for (int i = 0; i < 9; ++i)
		{
			chSet.clear();
			for (int j = 0; j < 9; ++j)
				if (board[i][j] != '.' && chSet.find(board[i][j]) != chSet.end())
					return false;
				else
					chSet.insert(board[i][j]);
		}

		for (int i = 0; i < 9; ++i)
		{
			chSet.clear();
			for (int j = 0; j < 9; ++j)
				if (board[j][i] != '.' && chSet.find(board[j][i]) != chSet.end())
					return false;
				else
					chSet.insert(board[j][i]);
		}

		for (int i = 0; i < 9; i += 3)
			for (int j = 0; j < 9; j += 3)
			{
				chSet.clear();
				for (int row = i; row < i + 3; ++row)
					for (int col = j; col < j + 3; ++col)
						if (board[row][col] != '.' && chSet.find(board[row][col]) != chSet.end())
							return false;
						else
							chSet.insert(board[row][col]);
			}
		return true;
	}
};