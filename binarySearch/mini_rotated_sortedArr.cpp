#include<iostream>
using namespace std;
//brute tc o(logn)
int mini(vector<int>&nums){
    int n=nums.size();
    int low=0, high=n-1;
    int mini= INT_MAX;
    while(low<=high){
        int mid= low +(high-low)/2;
        //if both are sorted
        if(nums[low]<=nums[high]) {
            mini=min(mini,nums[low]);
            break;
        }
        //is right sorted
        if(nums[mid]<=nums[high]){
            mini=min(mini,nums[mid]);
            high=mid-1;
        }
        //is left sorted
        else{
            mini=min(mini,nums[low]);
            low=mid+1;
        }
    }
    return mini;
}
int main(){
    //vector<int>nums={5,7,8,9,0,1,3,4};
    vector<int>nums={3,1,2};
    cout<<mini(nums);
    return 0;
}