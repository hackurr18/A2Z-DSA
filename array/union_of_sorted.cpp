#include<iostream>
#include<set>
#include<vector>
using namespace std;
vector<int> union_sorted_arr(vector <int>vec1,vector<int>vec2,int n1,int n2){
    set<int>st;
    for(int i=0;i<n1;i++){
        st.insert(vec1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(vec2[i]);   
    }
    vector<int>temp;
    for(auto i:st){
        temp.push_back(i);

    }
    return temp;
}
int main(){
    vector<int>vec1={1,2,4,6,7,7,8};
    vector<int>vec2={1,4,5,8,9};
    int n1=vec1.size();
    int n2=vec2.size();
    vector<int>temp= union_sorted_arr(vec1,vec2,n1,n2);
    for(auto i:temp){
        cout<<i<<" ";
    }
    return 0;
}