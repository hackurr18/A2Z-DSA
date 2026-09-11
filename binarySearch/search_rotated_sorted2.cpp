//Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. 
//Now the array is rotated at some pivot point unknown to you.
// Return True if k is present and otherwise, return False.
#include<iostream>
using namespace std;

//tc average O(LOGN) ,, worst O(n/2)
bool search(vector<int>&nums, int target){
    int n=nums.size();
    int low=0 , high=n-1;
    while(low<=high){
        int mid= low + (high -low)/2 ;
        if(nums[mid]== target) return true;
        //all are same
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low=low+1;
            high=high-1;
            continue;
        }
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
    return false;
}
int main(){
    //vector<int>nums={3,3,1,2,3,3,3,3,3,3};
    vector<int>nums={2,3,4,5,6,7,8,9,1};
    int target=1;
    cout<<search(nums,target);
    return 0;
}