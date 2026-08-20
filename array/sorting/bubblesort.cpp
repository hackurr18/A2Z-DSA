#include<iostream>
using namespace std;
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){
            if(arr[i]> arr[j]){
                swap(arr[i],arr[j]);
                
                }
        }
    }
}
void bubble(int arr[],int n){
    for(int i=n-1;i>=0;i--){
        int didswap=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didswap=1;
            }
        }
        if(didswap==0){
            break;
        }
    }
    

    
}
int main(){
    int n=7;
    int arr[7]= {17,3,3,92,6,2,9};
    //bubblesort(arr,n);
    bubble(arr,n);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}