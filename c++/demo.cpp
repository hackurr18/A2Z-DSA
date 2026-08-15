#include<iostream>
using namespace std;
int main(){
   /* cout<<"hello world"<<endl;
    int x, y;
    cin>>x;
    cout<<"the value of x is"<<x<<endl;
    cin>>y;
    cout<<"the value of y is"<<y<<endl;
    */
   string s="kapil";
   int n=s.size();
   s[n-1] = 'k';
   cout<<s[n-1];
   return 0;
}