class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();

        int total = n * m;
        int count = 0;

        int startRow = 0 , startCol = 0, endRow = n-1, endCol = m-1;

        while(count <  total)
        {
            //1st row
            for(int i=startCol; count<total && i<=endCol; i++)
            {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++;

            //last col
            for(int i=startRow; count<total && i<=endRow; i++)
            {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            //last row
            for(int i=endCol; count<total && i>=startCol; i--)
            {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            //1st col
            for(int i=endRow; count<total && i>=startRow; i--)
            {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++;

        }   

        return ans;
    }
};
