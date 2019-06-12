class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        int block = 2 * numRows - 2;
        int n = s.length();
        string res = "";
        for (int k = 0; k < n; k += block)
            res += s[k];
        for (int row = 1; row < numRows - 1; ++row)
        {
            int j, k;
            for (k = block - row, j = row; k < n && j < n; k += block, j += block)
            {
                res += s[j];
                res += s[k];
            }
            if (j < n)
                res += s[j];
            if(k < n)
                res += s[k];
        }
        for (int k = numRows - 1; k < n; k += block)
            res += s[k];
        return res;
    }
};