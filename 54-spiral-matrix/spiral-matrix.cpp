class Solution {
public:
    vector <int> spiralOrder(vector <vector <int>> &matrix) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    int sRow = 0; 
    int sCol = 0;
    int eRow = m - 1;
    int eCol = n - 1;
    vector<int> result;

    while (sRow <= eRow && sCol <= eCol)
    {
        // top 
        for (int i = sCol; i <= eCol; i++) {
            result.push_back(matrix[sRow][i]);
        }
        // right
        for(int j = sRow + 1; j <= eRow; j++) {
            result.push_back(matrix[j][eCol]);
        }
        // bottom
        if (sRow < eRow) {
            for(int i = eCol - 1; i >= sCol; i--) {
                result.push_back(matrix[eRow][i]);
            }
        }
        // left
        if (sCol < eCol) {
            for(int j = eRow - 1; j > sRow; j--) {
                result.push_back(matrix[j][sCol]);
            }
        }
        sRow++;
        sCol++;
        eRow--;
        eCol--;
    }
    return result;

}

};