#include<iostream>
using namespace std;
//maximum (possible minimum dist btween two cows stalls for k cows
//brute
bool canweplace(vector<int>&stall,int dist,int cows){
    int n=stall.size();
    int cntcows=1 ,last=stall[0];
    for(int i=1;i<n;i++){
        if(stall[i]-last >=dist){
            cntcows++;
            last=stall[i];
        }
        if(cntcows >=cows) return true;
        
    }
    return false;
}
int agressiveCowss(vector<int>&stall ,int cows){
    int n=stall.size();
    if(n<cows) return -1;
    sort(stall.begin(),stall.end());
    int maxi=stall[n-1]-stall[0];
    for(int i=1;i<=maxi;i++){
        if(canweplace(stall,i,cows)==true) continue;
        else return i-1;
    }
    return -1;
}
//optimal tc O(nlogn) + O(log maxi)*O(n)
int agressiveCows(vector<int>&stall ,int cows){
    int n=stall.size();
    if(n<cows) return -1;
    sort(stall.begin(),stall.end());
    int maxi=stall[n-1]-stall[0];
    int low=1 ,high=maxi;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(canweplace(stall,mid,cows)==true){
            low=mid+1;
        }
        else high=mid-1;
    }
    return high;

}
int main(){
    vector<int>stall={0,3,4,7,10,9};
    int cows=4;
    cout<<agressiveCows(stall,cows);
    return 0;

}