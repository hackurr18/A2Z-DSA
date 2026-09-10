#include<iostream>
using namespace std;
//lowerbound ..found first occurence
//lb=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
//tc O(logn)
int lower(vector<int>&nums, int target){
    int n=nums.size();
    int ans=n;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1; 

    }
    return ans;
}
//upperbound ..find last occurence +1
int upper(vector<int>&nums,int target){
    int n=nums.size();
    int ans=n;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1; 

    }
    return ans;
}
//search insert position 
int searchInsert(vector<int>&nums,int target){
    int n=nums.size();
    int ans=n;
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1; 

    }
    return ans;
}
//floor
int findFloor(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] <= x) {
                ans = arr[mid];     // Potential floor
                low = mid + 1;      // Search right side
            } else {
                high = mid - 1;     // Search left side
            }
        }
        return ans;
}
//ceil
int findCeil(int arr[], int n, int x) {
        int low = 0, high = n - 1;
        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = arr[mid];     // Potential ceil
                high = mid - 1;     // Search left side
            } else {
                low = mid + 1;      // Search right side
            }
        }
        return ans;
    }
int main(){
    vector<int>nums={1,2,3,3,4,8,8,9,9};
    int target=8;
    //cout<<lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    //cout<<upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    cout<<upper(nums,target);
    cout<<lower(nums,target);
    //cout<<searchInsert(nums,target);
    return 0;
}