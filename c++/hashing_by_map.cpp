#include<iostream>
#include<map>
using namespace std;
int main(){
    int n=7;
    int arr[7]={1,2,4,6,2,3,6};
    //unordered_map can also be used(best ,less time)
    map<int ,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<mp[num]<<endl;
    }
    for(auto i:mp){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    return 0;
}