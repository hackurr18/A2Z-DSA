//Given an integer array nums, sorted in ascending order (with distinct values) and a target value k.
// The array is rotated at some pivot point that is unknown.
// Find the index at which k is present and if k is not present return -1.
#include<iostream>
using namespace std;
//time taken 2 hrs
//tc O(LOGN)
int search(vector<int>&nums, int target){
    int n=nums.size();
    int low=0 , high=n-1;
    while(low<=high){
        int mid= low + (high -low)/2 ;
        if(nums[mid]== target) return mid;
        
        //is right sorted
        if(nums[mid]<=nums[high]){
            if(nums[mid]<= target && target<= nums[high]){
                low=mid+1;
            }
            else high=mid-1;
        }
        //is left half sorted
        else{
            if(nums[low] <= target && target <=nums[mid]){
                high=mid-1;
            }
            else low=mid+1; 
        }
    }
    return -1;
}
int main(){
    vector<int>nums={7,8,9,1,2,3,4,5,6};
    //vector<int>nums={2,3,4,5,6,7,8,9,1};
    int target=1;
    cout<<search(nums,target);
    return 0;
}