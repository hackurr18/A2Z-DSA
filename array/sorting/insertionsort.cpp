#include<iostream>
using namespace std;
//O(n^2)
void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
            cout<<"runs"<<endl;
        }
    }
}
int main(){
    int n=7;
    int arr[7]={1,6,2,89,4,2,9};
    insertionsort(arr,n);
    for(auto i: arr){
        cout<<i<< " ";
    }
    return 0;
}