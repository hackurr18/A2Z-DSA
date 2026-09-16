#include<iostream>
using namespace std;
//Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given threshold value.
//brute tc O(max*n)
int smallestDivi(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi= *max_element(nums.begin(),nums.end());
        int div=1;
        while(div<=maxi){
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)nums[i]/div);
            }
            if(sum<=threshold){
                return div;
            }
            div++ ;

        }
        return -1;
}
//optimal tc O(n*log max)
bool divisor(vector<int>&nums,int threshold,int div , int n){
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)nums[i]/(double)div);
        if(sum>threshold) return false;
    }
    return true;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int n=nums.size();
    if(n>threshold) return -1;
    int maxi= *max_element(nums.begin(),nums.end());
    int div=1;
    int low=1 , high=maxi;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(divisor(nums,threshold,mid,n)==1){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
int main(){
    //vector<int>nums={1,2,5,9};
    vector<int>nums={44,22,33,11,1};
    //int threshold=6;
    int threshold=5;
    cout<<smallestDivisor(nums,threshold);
    return 0;
}