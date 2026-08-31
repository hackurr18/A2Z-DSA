/* for leetcode
#pragma GCC optimize("O3") // Optional: enables high compiler optimization

// 1. Fast I/O Snippet (Paste this at the top)
static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
*/
#include<iostream>
using namespace std;
//tc O(n*m). , sc O(N*M)for ans vec.
vector<int>spiralMatrix(vector<vector<int>>&matrix){
    int n=matrix.size(); //row
    int m=matrix[0].size();
    int left=0 ,right=m-1;
    int top=0 , bottom=n-1;
    vector<int>ans;

    while(top<=bottom && left <= right){
        //rigth
        for(int i=left; i<=right ;i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top ;i<=bottom ;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right ;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<= right){
            for(int i=bottom ;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++ ;
        }
    }

    return ans;
}
int main(){
  //  ios_base::sync_with_stdio(false);
   // cin.tie(NULL);

    vector<vector<int>>matrix={
        { 1,  2,  3,  4},
        {12,  13,  14,  5},
        { 11,  16, 15, 6},
        { 10,  9,  8,  7}
    };
    vector<int>ans=spiralMatrix(matrix);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}