#include<iostream>
using namespace std;
//brute tc O(n^2)
vector<int>leaders(vector<int>&nums){
    vector<int>ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int leader=true;
        for(int j=i+1 ;j<n ; j++){
            if(nums[j]>nums[i]){
                leader=false;
                break;
            }
        }
        if(leader == true) ans.push_back(nums[i]);
    }
    return ans;
}
//optimal O(N) and if asked for sorted leader tc O(n) +O(nlogn)
vector<int>leaders_array(vector<int>&nums){
    vector<int>ans;
    int n=nums.size();
    int maxi= INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(nums[i]>maxi){
            ans.push_back(nums[i]);
        }
        //keep track of right max
        maxi=max( maxi , nums[i]);
    }
    return ans;
}
int main(){
    vector<int>nums={10,22,12,3,0,6};
    vector<int>ans=leaders_array(nums);
    for(int i: ans){
        cout<<i<<" ";
    }
}