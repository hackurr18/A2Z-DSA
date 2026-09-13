#include<iostream>
using namespace std;
//iterative O(nlogn)
int bsearch(vector<int>&nums, int target){
    int n=nums.size();
    int low=0 , high=n-1;
    while(low<=high){
        //long long mid or int mid=(low +(high-low))/2 to avoid overflow
        int mid=(low+high)/2;
        if(nums[mid]== target) return mid;
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
//recursive O(nlog n)
int binary(vector<int>nums,int low,int high,int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(nums[mid]== target) return mid;
    else if (nums[mid]>target) return binary(nums,low,mid-1,target);
    return binary(nums,mid+1,high,target);

}
int main(){
    vector<int>nums={3,4,6,7,9,12,24,45};
    int target=24;
    int n=nums.size();
    //cout<<bsearch(nums,target);
    cout<<binary(nums,0,n-1,target);
    return 0;
}