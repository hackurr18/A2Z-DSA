/*
//brute no. of subarrays of sum k
//O(n3)
cnt =0;
for(i=0;i<n;i++){
    for(j=i ;j<n;j++){
        sum=0;
        for(k=i ; k<=j ;k++){
            sum= sum + arr[k];
        }
        if(sum==k){
            cnt++;
        }
    }
}
//better O(N2)
cnt =0;
for(i=0;i<n;i++){
    sum=0;
    for(j=i ;j<n;j++){
        sum= sum + arr[j]
        if(sum==k){
            cnt++;
        }
    }
}
*/
//optimal O(N * logn)
#include<iostream>
using namespace std;
int findAllSubarrayWithGivenSumK(vector<int>&nums,int k){
    unordered_map<int,int>mpp;
    mpp[0]=1;
    int presum=0 ,cnt=0;
    for(int i=0;i<nums.size();i++){
        presum += nums[i] ;
        int remove = presum - k ;
        cnt +=mpp[remove];
        mpp[presum]+=1 ;
    }
    return cnt;
}
int main(){
    vector<int>nums={1,2,3,-3,1,1,1,4,2,-3};
    int k=3;
    cout<<findAllSubarrayWithGivenSumK(nums,k);
    return 0;
}   