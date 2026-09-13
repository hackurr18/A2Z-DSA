#include<iostream>
using namespace std;
int count(vector<int>&nums){
    int n=nums.size();
    int low=0, high=n-1;
    int mini= INT_MAX , idx=-1;
    while(low<=high){
        int mid= low +(high-low)/2;
        //if both are sorted
        if(nums[low]<=nums[high]) {
            if(nums[low]< mini){
                idx=low;
                mini=nums[low];
            }
            break;
        }
        //is right sorted
        if(nums[mid]<=nums[high]){
            if(nums[mid]<mini){
                idx=mid;
                mini=nums[mid];   
            }
            high=mid-1;
        }
        //is left sorted
        else{
            if(nums[low]<mini){
                idx=low;
                mini=nums[low];
                
            }
            low=mid+1;
        }
    }
    return idx ;
}
int main(){
    vector<int>nums={7,8,9,10,2,3,4};
    cout<<count(nums);
    return 0;
}