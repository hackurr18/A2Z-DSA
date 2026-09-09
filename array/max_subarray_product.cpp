#include<iostream>
using namespace std;
//brute tc O(N^2)
long long maxproduct(vector<int>nums){
    int n=nums.size();
    long long mixi= INT_MIN;
    for(int i=0;i<n;i++){
        long long product=1;
        for(int j=0;j<n;j++){
            product *= nums[j];
            mixi=max(product,mixi);
        }
        
    }
    return mixi;
}
//optimal tc O(N)
long long maxprod(vector<int>&nums){
    int n=nums.size();
    long long maxi=INT_MIN;
    long long prefix=1 , suffix=1;

    for(int i=0;i<n;i++){
        if(prefix== 0) prefix=1;
        if(suffix==0) suffix=1;
        
        prefix *= nums[i];
        suffix *= nums[n-i-1];
        maxi=max(maxi,max(prefix,suffix));
    }
    return maxi;
    
}
int main(){
    vector<int>nums={2,3,-2,0,4,6,0,3,4};
    cout<<maxprod(nums);
    return 0;
}