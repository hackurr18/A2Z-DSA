#include<iostream>
using namespace std;
/*int main(){
    vector<int> vec={1,37,4,9,33};
    sort(vec.begin(),vec.end());
    //sort(a,a+n); sort any sub part [a to n)
    auto k=vec.begin();
    auto p=vec.end();
    //for(int i=0;i<5;i++){
      //  cout<<&k+i<<endl;
        
    //}
   
    
   // for(int i: vec)
     //   cout<<i <<' ';

    return 0;
}*/
bool comp(pair<int , int>p1 ,pair<int,int>p2);
int main(){
    pair<int , int>arr[]={{1,2},{2,1},{4,1}};
    //sort 4 1, 2 1, 1 2
  // cout<<arr[2].first;
   int n=sizeof(arr)/sizeof(arr[0]);
    
    sort(arr,arr+n,comp);
    for(auto i :arr)
        cout<<i.first <<' '<<i.second<<endl;

    return 0;
}
bool comp(pair<int , int>p1 ,pair<int,int>p2){
    if(p1.second <p2.second) return true;
    else if(p1.second>p2.second) return false;
    // if they are same
    else if(p1.first>p2.first) return true;
    return false;

 }

