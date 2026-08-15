#include<iostream>
using namespace std;

/*int reverse(int x) {
        int rev = 0;
        int flag=0;
        if(x<0){
            flag=1;
            x=-x;
        } 
        int n=x;
        cout<<n;
        while(n>0){
            int now=n%10;
            n=n/10;
            rev=rev*10 + now ;
        }
        if(flag==1){
             return -(rev);
        }
        else{
             return rev;
        }
    }*/
#include <climits>

int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10; // Extract last digit (works for negative numbers too)
        x /= 10;

        // Check for positive overflow
        // If rev > 214748364, then rev * 10 will definitely overflow.
        // If rev == 214748364, then rev * 10 + pop overflows if pop > 7.
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;

        // Check for negative overflow
        // If rev < -214748364, then rev * 10 will definitely overflow.
        // If rev == -214748364, then rev * 10 + pop overflows if pop < -8.
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

        rev = rev * 10 + pop;
    }
    return rev;
}
int main(){
    int x;
    cin>>x;
    cout<<reverse(x);
    return 0;
}