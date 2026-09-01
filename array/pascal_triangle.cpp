#include<iostream>
using namespace std;
//optimal TC=O(N^2)

vector<int>generateRow(int row){
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int col=1 ;col<row ;col++){
        ans=ans*(row -col);
        ans=ans/col ;
        ansRow.push_back(ans);
    }
    return ansRow ;
}
//find ele at given row and col
//TC O(r)
int nCr(int n, int r){
    int row=n-1;
    int col=r-1;
    long long res=1;
    for(int i=0 ; i<col;i++){
        res=res * (row-i) ;
        res= res / (i+1) ;
    }
    return res;
}
int main(){
        int numRows=6; 
        vector<vector<int>>ans;
        for(int i=1;i<=numRows ;i++){
            ans.push_back(generateRow(i));
        }
        for(const auto &row :ans){
            for(auto x:row){
                cout<<x <<" ";
            }
            cout<<'\n';
        }
        //
        cout<<nCr(5,3);
        return 0;
}
