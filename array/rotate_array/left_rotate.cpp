#include<iostream>
using namespace std;
int leftrotate(vector<int>&vec,int n){
    int temp=vec[0];
    for(int i=0;i<n-1;i++){
        vec[i]=vec[i+1];
    }
    vec[n-1]=temp;
    return 1;
}
int main(){
    vector<int>vec={1,2,34,5,6,7};
    int n=vec.size();
    leftrotate(vec,n);
    for(auto i:vec){
        cout<<i<<" ";
    }
    return 0;
}