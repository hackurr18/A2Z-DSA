#include<iostream>
#include<map>
using namespace std;
//better O(N^2)
int county_subarray(vector<int>nums,int target){
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int xoor=0;
        for(int j=i;j<n;j++){
            xoor= xoor ^ nums[j];
            if(xoor == target) cnt++ ;
        }      
    }
    return cnt;
}
//optimal O(n) ||o(n log n) sc O(n)
int count_subarray(vector<int>nums,int target){
    int xr=0 , cnt=0;
    map<int,int>mpp;
    mpp[xr]++; //{0,1}
    int n=nums.size();
    
    for(int i=0;i<n;i++){
        xr=xr ^ nums[i];
        int x=xr ^ target; // k
        cnt= cnt + mpp[x];
        mpp[xr]++;
        
    }
    return cnt;
}
int main(){
    vector<int>nums={4,2,2,6,4};
    int target = 6;
    cout<<count_subarray(nums,target);
    return 0;
}