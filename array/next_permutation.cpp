#include<iostream>
using namespace std;
// next permutation of an array of integers is the next lexicographically greater permutation of its integer.
//tc O(3n)
vector<int> find_next(vector<int>&nums){
    int idx=-1;
    int n=nums.size();
    //to find break point
    for(int i=n-2 ;i>=0 ; i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
    }
    //if no break point
    if(idx== -1){
        reverse(nums.begin(),nums.end());
        return nums;
    }
    
    for(int i=n-1 ;i>idx ;i--){
        if(nums[i]> nums[idx]){
            swap(nums[i],nums[idx]);
            break;
        }
    } 
    // though they are in desc order , revrse them after the break point
    reverse(nums.begin()+ idx +1 ,nums.end());
    return nums;
}
int main(){
    //vector<int>nums={2,1,5,4,3,0,0};
    vector<int>nums={3,2,1};
    find_next(nums);
    for(int i:nums){
        cout<<i<<' ';
    }

    return 0;
}