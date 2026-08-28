#include<iostream>
using namespace std;
//brute tc O(n^2)
bool ls(vector<int>&nums,int next){
    for(int i=0;i<nums.size();i++){
        if(nums[i]==next) return true;
    }
    return false;
}
int conse(vector<int>&nums){
    if(nums.size()==0) return 0;
    int largest=1;

    for(int i=0;i<nums.size();i++){
        int x=nums[i];
        int cnt=1;
        while(ls(nums,x+1)){
            x=x+1;
            cnt+=1;
        }
        largest=max(largest,cnt);
    }
    return largest;
}
//better tc O(nlogn +n)
int longestSuccessiveElements(vector<int>&nums){
    if(nums.size()==0) return 0;
    sort(nums.begin(),nums.end());
    int lastSmaller= INT_MIN;
    int cnt=0;
    int longest=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]-1 == lastSmaller){
            cnt+=1;
            lastSmaller=nums[i];
        }
        else if(nums[i] != lastSmaller){
            cnt=1;
            lastSmaller=nums[i];
        }
        longest=max(longest,cnt);
    }
    return longest;

}
int main(){
    vector<int>nums={102,4,100,1,101,3,2,1,1};
    //cout<<conse(nums);
    cout<<longestSuccessiveElements(nums);
}