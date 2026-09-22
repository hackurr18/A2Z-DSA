#include<iostream>
using namespace std;

//brute
 /*
    Returns the position of
    any valid peak element.
    */
vector<int> findPeakGridd(vector<vector<int>>& mat) {
        int rows = (int)mat.size();
        int cols = (int)mat[0].size();

        // Traverse each cell in the grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Initialize top neighbor; defaults to -1 if out of boundary
                int up = -1;
                if (i > 0) {
                    // Current cell is not in the top row, so fetch the upper neighbor
                    up = mat[i - 1][j];
                }

                // Initialize bottom neighbor; defaults to -1 if out of boundary
                int down = -1;
                if (i + 1 < rows) {
                    // Current cell is not in the bottom row, so fetch the lower neighbor
                    down = mat[i + 1][j];
                }

                // Initialize left neighbor; defaults to -1 if out of boundary
                int left = -1;
                if (j > 0) {
                    // Current cell is not in the leftmost column, so fetch the left neighbor
                    left = mat[i][j - 1];
                }

                // Initialize right neighbor; defaults to -1 if out of boundary
                int right = -1;
                if (j + 1 < cols) {
                    // Current cell is not in the rightmost column, so fetch the right neighbor
                    right = mat[i][j + 1];
                }

                // Check if current cell is strictly greater than all valid neighbors
                if (mat[i][j] > up && mat[i][j] > down &&
                    mat[i][j] > left && mat[i][j] > right) {
                    // Found a valid peak, return its coordinates immediately
                    return {i, j};
                }
            }
        }

        // Return {-1, -1} if no peak element is found
        return {-1, -1};
    }
//optimal tc O(nlogm)
int findMaxIndex(vector<vector<int>>&mat , int n ,int col){
    int maxValue=-1;
    int idx=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxValue){
            maxValue=mat[i][col];
            idx=i;
        }
    }
    return idx;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0 , high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int maxRowIndex=findMaxIndex(mat,n,mid);
            int left=mid-1 >=0 ? mat[maxRowIndex][mid-1] : -1;
            int right=mid+1 <m ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] >right){
                return {maxRowIndex , mid};
            }
            else if (mat[maxRowIndex][mid] < left){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return {-1,-1};
}

int main() {
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

   //vector<int> answer =findPeakGridd(mat);
    vector<int> answer =findPeakGrid(mat);
    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}
