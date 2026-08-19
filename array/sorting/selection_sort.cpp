#include<iostream>
using namespace std;
// n^2
void selection_sort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}
int main(){
    int n=7;
    int arr[7]={1,6,9,3,7,5,1};
    selection_sort(arr,n);
    for(auto i:arr){
        cout<<i <<" ";
    }
    return 0;
}