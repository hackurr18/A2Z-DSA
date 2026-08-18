#include<iostream>
#include<vector>
using namespace std;
int main(){
   /* cout<<"hello world"<<endl;
    int x, y;
    cin>>x;
    cout<<"the value of x is"<<x<<endl;
    cin>>y;
    cout<<"the value of y is"<<y<<endl;
    */
   vector<int> vec={2,4,0,6,0,3,7,0,0};
   int n=vec.size();
   vector<int>temp;
    //to store non 0 in temp
   for(int i=0;i<n;i++){
      if(vec[i]!=0) temp.push_back(vec[i]);
   }
   for(auto i:temp){
      cout<<i<<" ";
   }
   return 0;
}