#include<iostream>
using namespace std ;
int main(){
    int arr[6]={2,53,3,7,7,44};
    int largest =arr[0];
    for(int i=1;i<6;i++){
        if(largest < arr[i]) largest =arr[i];
    }
    cout<<largest;
   return 0;
}