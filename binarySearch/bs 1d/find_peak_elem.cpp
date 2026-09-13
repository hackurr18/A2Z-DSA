#include<iostream>
using namespace std;
//brute
int peaky(vector<int>&nums){
    int n=nums.size();
    
    for(int i=0;i<n;i++){
        if((i==0 || nums[i]>nums[i-1]) &&
            (i==n-1 || nums[i]>nums[i+1])){
            return nums[i];
            break;
        }
    }
    return -1;
}
//optimal
int peak(vector<int>&nums){
    int n=nums.size();
    if(n==1) return nums[0];//boundry cond
    if(nums[0]>nums[1]) return nums[0];
    if(nums[n-1]>nums[n-2]) return nums[n-1];
    int low=1 , high=n-1;
    while(low<=high){
        int mid=low +(high-low)/2 ;
        if(nums[mid]> nums[mid-1] && nums[mid]>nums[mid+1]) return nums[mid];
        //ele is in right
        else if(nums[mid]>nums[mid-1]){
            low=mid+1;
        }
        //no need ,coverd in else
        //ele is in left
        //else if(nums[mid]>nums[mid+1]){
         //   high=mid-1;
        //}
        else{
            //low=mid+1;
            high=mid-1; //we can use any
        }
        
    }
    return -1;
}
int main(){
    //vector<int>nums={1,2,3,4,5,6,7,8,5,1};
    //vector<int>nums={1,2,4,5};
    vector<int>nums={1,10,13,7,6,5,4,2,1,0};
    //vector<int>nums={4,5,1,2,1};
    cout<<peak(nums);
    return 0;
}