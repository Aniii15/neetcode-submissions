class Solution {
public:
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    int left = 0;
    int right = matrix.size()*matrix[0].size() - 1;

    for(int i = 0; i<matrix.size()*matrix[0].size(); i++){
        int mid = (left+right)/2;

        int row = mid/(matrix[0].size());
        int col = mid%(matrix[0].size());

        if (target == matrix[row][col]){
            return 1;
        }

        else if (target > matrix[row][col]){
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }
    }

    return 0; 
}
};
