#include<iostream>
using namespace std;
//brute tc O(N)
int singleNonDup(vector<int>&nums){
    int n=nums.size();
    if(n==1) return nums[0];
    for(int i=0;i<n;i++){
        //1 ele
        if(i==0){
            if(nums[0]!=nums[1]) return nums[0];
        }
        //last ele
        if(i==n-1){
            if(nums[n-1]!=nums[n-2]) return nums[n-1];
        }
        else{
            if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]) return nums[i];
        }
    }
    return 1;
}
//optimal tc O(LOgn)
int singleNonDuplicate(vector<int>&nums){
    int n=nums.size();
    if(n==1) return nums[0];
    //1 ele
    if(nums[0]!=nums[1]) return nums[0];
    //last ele
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    int low=1 ,high=n-2;
    while(low<=high){
        int mid=low +(high-low)/2;
        
        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
        //we are in left
        if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            low=mid+1;
        }
        //we are on left
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int>nums={1,1,2,2,3,4,4,5,5,6,6};
    //vector<int>nums={1,1,2,3,3,4,4};
     //vector<int>nums={3};
    cout<<singleNonDuplicate(nums);
    return 0;
}