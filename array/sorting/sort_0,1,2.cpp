#include<iostream>
using namespace std;
//better O(2N) sc O(1)
void sort_nums(vector<int> &nums){
    int cnt0=0, cnt1=0 , cnt2=0 ;
    for(int i=0;i<nums.size();i++){
        if(nums[i]== 0) cnt0 ++;
        else if(nums[i]== 1) cnt1 ++ ;
        else cnt2 ++ ;
    }
    for(int i=0 ;i<nums.size();i++){
        if(i<cnt0) nums[i]=0 ;
        else if(i< (cnt0+cnt1)) nums[i]=1 ;
        else nums[i]= 2;
    }

}
//optimal O(N)  sc O(1)
void sort_colors(vector<int> &nums){
    int low=0 , high=nums.size()-1, mid=0;
    //for(int i=0;i<nums.size();i++){
    while(mid <=high){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++ ;
            mid ++ ;
        }
        else if(nums[mid]==1) mid++ ;
        else{
            swap(nums[mid],nums[high]);
            high-- ;
        }
    }
}
int main(){
    vector<int>nums={0,1,0,2,2,0,2,1,2,2};
    sort_colors(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
    return 0;
}