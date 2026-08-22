#include<iostream>
using namespace std;
int main(){
    int arr[6]={10,6,6,5,9,9};
    int largest=arr[0];
    for(int i=1;i<6;i++){
        if(largest<arr[i]) largest = arr[i];
    }
    int slargest=-1;
    for(int i=0;i<6;i++){
        if(arr[i]>slargest && arr[i]!=largest) slargest=arr[i];
    }
    cout<<slargest;
    return 0;
}