#include<iostream>
using namespace std;

//brute
bool searchMatrixx(vector<vector<int>>& matrix, int target) {
        // Get number of rows in the matrix
        int n = matrix.size();

        // Get number of columns in the matrix
        int m = matrix[0].size();

        // Traverse each row
        for (int i = 0; i < n; i++) {
            // Traverse each column in the current row
            for (int j = 0; j < m; j++) {
                // Check if the current element matches the target
                if (matrix[i][j] == target)
                    return true;
            }
        }

        // Return false if the target is not found
        return false;
}
//better
bool binarySearch(vector<int>& nums, int target) {
        // Get the size of the array
        int n = nums.size();

        // Initialize low and high pointers for binary search
        int low = 0, high = n - 1;

        // Binary search loop
        while (low <= high) {
            // Calculate the middle index
            int mid = (low + high) / 2;

            // If the middle element is the target, return true
            if (nums[mid] == target)
                return true;

            // If the target is greater, move to the right half
            else if (target > nums[mid])
                low = mid + 1;

            // Otherwise, move to the left half
            else
                high = mid - 1;
        }

        // Return false if target not found
        return false;
    }



bool searchMatrixxx(vector<vector<int>>& matrix, int target) {
        // Get the number of rows
        int n = matrix.size();

        // Get the number of columns
        int m = matrix[0].size();

        // Traverse each row
        for (int i = 0; i < n; i++) {
            // Check if target could be within this row
            if (matrix[i][0] <= target && target <= matrix[i][m - 1]) {
                // Apply binary search on the current row
                return binarySearch(matrix[i], target);
            }
        }

        // Return false if target is not found in any row
        return false;
    }


//optimal
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0,high= n*m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
}

int main() {
    // Define a 2D matrix
    vector<vector<int>> matrix = {{1, 2, 3, 4}, 
                                  {5, 6, 7, 8}, 
                                  {9, 10, 11, 12}};

    

    // Call the searchMatrix function and print the result
    if (searchMatrixxx(matrix, 8)) 
        cout << "true\n";
    else 
        cout << "false\n";

    return 0;
}
