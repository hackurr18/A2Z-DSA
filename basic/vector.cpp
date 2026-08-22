#include<iostream>
using namespace std;
int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(7);
    vec.emplace_back(4);
    //sort
    //sort(vec.begin(),vec.end());
    vector<pair<int , int>>k={{2,3},{4,5}};
    k.push_back({9,4});
    for(pair<int,int > i: k){
        cout<<i.first<<' ';
    }
   
    /*cout<<vec[2]; */
    //kapil
    return 0;

}