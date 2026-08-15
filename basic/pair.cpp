#include<iostream>
using namespace std;
int main(){
    pair<int ,int> p={1,3};
    pair<int , pair<float,float>>k={6,{7.0,9.5}};
    cout<<p.first ;
    cout<<p.second <<endl ;
    cout<<k.first<<' '<<k.second.first<<' '<<k.second.second <<endl;
    pair<int,float> arr[]={{1,2.9},{3,5},{4,5.56}};
    cout<<arr[2].second;
    return 0;
}