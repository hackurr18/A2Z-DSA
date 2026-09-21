#include<iostream>
using namespace std;
//brute sc O(N)
int median (vector<int>&nums1,vector<int>&nums2){
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    vector<int>ans;
    int i=0 , j=0;
    while(i<n1 && j<n2){
        if(nums1[i]<=nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }
        else{
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i<n1){
        ans.push_back(nums1[i]);
        i++;
    }
    while(j<n2){
        ans.push_back(nums2[j]);
        j++;
    }
    if(n%2==1){
        return ans[n/2];
    }
    else{
        return ((ans[n/2]+ans[n/2-1])/2);
    }
    return -1;
}

int main(){
    //vector<int>nums1={1,3,4,7,10,12};
    vector<int>nums1={};
    vector<int>nums2={2,3,6,15};
    cout<<median(nums1,nums2);
    return 0;
}