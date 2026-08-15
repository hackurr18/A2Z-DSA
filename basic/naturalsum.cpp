#include<iostream>
using namespace std;
 int sum =0;
int sumof(int n);
int main(){
   
    int a=8;
    cout<< sumof(a);
    return 0;
}
/*int sumof(int n){
   
    sum+=n ;
    if(n==0) return 1;
    
    else{
         sumof(n-1);
    }
    return sum;
    
}*/
int sumof( int n){
    if(n<1) return 0;
    else return n+sumof(n-1);
}