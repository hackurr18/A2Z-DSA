//You are given an integer n. You need to return the number of digits in the number.
//The number will have no leading zeroes, except when the number is 0 itself.
#include<iostream>
using namespace std;
int countDigit(int n) {
    //140 104 000 0 1300 
    int count=0;
    if(n==0) return ++count;
    while(n>0){
        if(n<9){
            count++ ;
            return count;
        }
        else{
            n=n/10 ;
            count++ ;

        }
    
    }
    return count;
}
int main(){
    int n;
    cin>>n;
    cout<<countDigit(n);
    return 0;
}
