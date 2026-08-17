#include<iostream>
#include <set>
using namespace std;
/*
//brute force nlogn +n
int main(){
    vector<int>vec={1,1,2,2,3,4,5,5};
    set<int> st;
    for(int i=0;i<vec.size();i++){
         st.insert(vec[i]);
         }
    
    int index=0;
    for(auto i:st){
        vec[index]=i;
        index++;
    }
    vec.resize(index);
    for(auto i:vec){
        cout<<i<<" ";
    }
}
    */
//optimal Q(n)
int main(){
    vector<int>vec={1,1,2,2,3,4,5,5};
    int i=0,j=1;
    for(j=1;j<vec.size();j++){
        if(vec[i]!=vec[j]){
            vec[i+1]=vec[j];
            i++;
        }
    }
    vec.resize(i+1);
   for(auto i:vec) cout<<i<<" ";
}