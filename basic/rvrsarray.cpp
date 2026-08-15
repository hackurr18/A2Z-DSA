#include<iostream>
using namespace  std;
int reverse(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap(arr[i],arr[n-i-1]);
    }
    
    return 0;
}
int revector(vector<int>vec,int n){

    return 0;
}
int main()
{
    int arr[6]={1,2,3,5,6,9};
    vector<int>vec={1,2,3,4,5,6};
    int n=vec.size();
    int size= sizeof(arr)/ sizeof(arr[0]);
    for(int i:arr) cout<<i<<' ';
    cout<<endl;
    reverse(arr,size);
    revector(vec,n);
  
    for(int i:arr) cout<<i<<' ';
    return 0;   
}
