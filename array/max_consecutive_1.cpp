#include<iostream>
using namespace std;
int max_one(int arr[],int n){
    int maxi=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt++;
            maxi=max(maxi,cnt);
        }
        else cnt=0;
    }
    return maxi;
}
int main(){
    int n=14;
    int arr[14]={0,1,0,1,0,0,1,1,1,0,1,1,0,0};
    cout<<max_one(arr,n);
}