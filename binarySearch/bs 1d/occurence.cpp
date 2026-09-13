#include<iostream>

using namespace std;
//lower.. find first occurence
int lower(vector<int>&nums, int target){
    int n=nums.size();
    int ans=n;
    int low=0, high=n-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1; 

    }
    return ans;
}
//upperbound ,..find last occurrence +1
int upper(vector<int>&nums,int target){
    int n=nums.size();
    int ans=n;
    int low=0, high=n-1;
    while(low<=high){
        int mid = low + (high - low) / 2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1; 

    }
    return ans;
}
//tc O(2*logn)
pair<int,int>firstAndLast(vector<int>&nums,int target){
    int lb=lower(nums,target);
    if(lb== nums.size() || nums[lb]!= target ) return {-1 ,-1};
    return {lb, upper(nums,target)-1};
}
//count occurence
int count(vector<int>&nums, int target){
    int lb=lower(nums,target);
    int ub=upper(nums,target);
    return ub-lb ;

}
int main(){
    vector<int> nums = {5,7,7,8,8,8,10};
    int target=8;
    
    pair<int,int>ans=firstAndLast(nums,target); 
    //cout<<ans.first <<" "<<ans.second;
    //for count occurence
    cout<<count(nums,target);
    return 0;
}