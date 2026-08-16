#include<iostream>
using namespace std;
int slargest(int arr[],int n){
    int largest=arr[0];
    int slargest= -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            slargest=largest;
            largest=arr[i];
            } 

        if(arr[i]>slargest && arr[i]!=largest) slargest=arr[i];
    }
    return slargest;
}
int main(){
    int arr[6]={1,2,4,7,7,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n<<endl;
    cout<<slargest(arr,n);
    return 0;
}