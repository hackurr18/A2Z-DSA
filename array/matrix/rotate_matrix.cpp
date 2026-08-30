#include<iostream>
using namespace std;
//brute tc O(n2) sc O(n2)
/*
ans[n][n];
for(int i=0 ->n){
   for(j=0 ->n)
        ans[j][(n-1)-i]=ans[i][j]
*/

//optimal
void rotateMatrix(vector<vector<int>>&matrix){
    int n=matrix.size();
    //transpose O(n/2 * n/2)
    for(int i=0; i<=n-2 ;i++){
        for(int j=i+1 ; j<=n-1 ;j++){
            swap(matrix[i][j] , matrix[j][i]);
        }
    }
    //reverse O(n * n/2)
    for(int i=0;i<n;i++){
        //row is mat[i]
        reverse(matrix[i].begin() , matrix[i].end());
    }

}
int main(){
    vector<vector<int>>matrix={
        { 1,  2,  3,  4},
        { 5,  6,  7,  8},
        { 9,  10,  11,  12},
        { 1,  1,  1,  1}
    };
    rotateMatrix(matrix);
    for(const auto &i :matrix){
        for(auto x:i){
            cout<<x<<" ";
        }
    cout<<"\n";
    }
    return 0;
}