#include<iostream>
using namespace std;
//better tc O(2*n*m) sc O(n+m)
void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //column

        vector<int> row(n, 0), col(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
}
//optimal tc O(2n*m)
vector<vector<int>>zeromatrix(vector<vector<int>>&matrix){
    int n = matrix.size(); //rows
    int m = matrix[0].size(); //column
    // int col[m]={0};  -> matrix[0][...]
    // int row[n]={0}; -> matrix[..][0]
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]== 0){
               // mark the  i row 
               matrix[i][0]=0;
               // mark the j th col
               if(j!=0){
                matrix[0][j]=0;
               }
               else
                col0=0 ;
              
            }
        }
    }
    for(int i=1;i<n;i++){
        for (int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                //check for i row and j col
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j=1;j<m;j++){
            //set 0th row to 0
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
    return matrix;

}
int main(){
    vector<vector<int>>matrix={
        { 1,  1,  1,  1},
        { 1,  0,  0,  1},
        { 1,  1,  0,  1},
        { 1,  1,  1,  1}
    };
   //setZeroes(matrix);
   zeromatrix(matrix);
   for (const auto& row : matrix) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }
}