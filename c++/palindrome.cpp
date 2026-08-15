#include<iostream>
using namespace std;
bool isPalindrome(int x) {
        int rev = 0;
        int n=x;
        while (n>0) {
        int pop = n % 10; 
        n /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        rev = rev * 10 + pop;
    }
    if(x== rev || x==0) return true;
    else return false;
}
int main(){
    int x;
    cin>>x;
    cout<<isPalindrome(x);
    return 0;
}