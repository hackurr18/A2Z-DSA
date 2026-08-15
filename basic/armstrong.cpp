#include<iostream>
using namespace std;
bool isArmstrong(int n) {
        int total=0;
        while(n>0){
            int pop=n%10;
            n/=10 ;
            total = total +(pop*pop*pop);
        
        }
    return true;
    }

int main(){
    int n;
    cin>>n;
    cout<<isArmstrong(n);

    return 0;
}