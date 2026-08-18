#include<iostream>
using namespace std;
void movetoleft(vector<int> &vec, int n){
    vector<int>temp;
    //to store non 0 in temp
    for(int i=0;i<n;i++){
        if(vec[i]!=0) temp.push_back(vec[i]);
    }
    int nz=temp.size();
    for(int i=0;i< nz;i++){
        vec[i]=temp[i];
    }
    for(int i=nz;i<n;i++){
        vec[i]=0 ;
    }
}
void move0toleft(vector<int> &vec, int n){
    int j= -1;
    for(int i=0;i<n;i++){
        if(vec[i]==0){
            j=i;
            break;
        }
    }
    //if j=-1 return;
    int i=j+1;
    while(j<n-1 && i<n){
        if(vec[i]!=0){
            swap(vec[j++],vec[i++]);
        }
        else if(vec[i]==0) i++ ;
    }   
}                   // 2 4 6 3 0 0
int main(){         //2 4 6 3 7 0j 0 0 0i
    vector<int> vec={2,8,0,5,0,0,6};
    int n=vec.size();
    //brute
  //  movetoleft(vec,n);
    //optimal
    move0toleft(vec,n);
    for(auto i:vec){
        cout<<i<<" ";
    }
    return 0;
}