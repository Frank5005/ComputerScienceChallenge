class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            //Getting the rows and columns number
            int n = matrix.size();
            //int rows = (sizeof(matrix)/sizeof(matrix[0]));
            //int columns = (sizeof(matrix[0])/sizeof(matrix[0][0]));
            //Traversing the matrix
            for(int i = 0; i < n / 2; ++i){
                for(int j = 0; j < n; ++j){
                    //Transpose the matrix
                    swap(matrix[i][j], matrix[n - 1 - i][j]);
                }
            }
            for(int i = 0; i < n; ++i){
                for(int j = i + 1; j < n; ++j){
                    //Reverse the rows
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    };