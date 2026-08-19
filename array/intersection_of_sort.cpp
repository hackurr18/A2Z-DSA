#include<iostream>
#include<vector>
using namespace std;
//brute O(n1*n2)
vector<int>intersection_of_sort(vector<int>vec1,vector<int>vec2,int n1,int n2){
    vector<int>vis(n2,0);
    vector<int>temp;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(vec1[i]==vec2[j] && vis[j]==0){
                temp.push_back(vec1[i]);
                vis[j]=1;
                break;
            }
            if(vec2[j]>vec1[i]) break;
        }
    }
    return temp;

}
//optimal O(n1+n2)
vector<int>intersection_of(vector<int>vec1,vector<int>vec2,int n1,int n2){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n1 && j<n2){
        if(vec1[i]<vec2[j]) i++ ;
        else if(vec2[j]<vec1[i]) j++;
        else{
            ans.push_back(vec1[i]);
            i++;
            j++;   
        }
    }
    return ans;

}
int main(){
    vector<int>vec1={1,2,2,3,3,4,5,6};
    vector<int>vec2={2,2,3,5,6,6,7,8,8};
    int n1=vec1.size();
    int n2= vec2.size();
   // vector<int>temp= intersection_of_sort(vec1,vec2,n1,n2);
    vector<int>temp= intersection_of(vec1,vec2,n1,n2);
    for(auto i:temp){
        cout<<i<<" ";
    }
    return 0;
}