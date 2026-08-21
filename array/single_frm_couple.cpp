#include<iostream>
#include<map>
using namespace std;
//brute O(3n) space O(maxi+1);
int single_num(vector<int>&nums,int n){
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,nums[i]);
    }
    vector<int> hash((maxi+1),0);
    for(int i=0;i<n;i++ ){
        hash[nums[i]]++ ;
    }
    for(int i=0;i<n;i++){
        if(hash[i]==1) return i ;
    }
    return 1;
}
int single_numb(vector<int>&nums,int n){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }
    for(auto i:mpp){
        if(i.second==1) return i.first;
    }
    return 1;
}
int single_number(vector<int>&nums,int n){
    int xor1= 0;
    for(int i=0;i<n;i++){
        xor1=xor1 ^nums[i];
    }
    return xor1;
}
int main(){
    vector<int>nums={1,2,3,1,3,2,4,4,6};
    int n=nums.size();
    cout<<single_number(nums,n);
}