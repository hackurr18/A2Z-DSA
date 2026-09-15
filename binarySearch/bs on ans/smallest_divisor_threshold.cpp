#include<iostream>
using namespace std;
//brute tc O(max*n)
int smallestDivisor(vector<int>& nums, int threshold) {
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
int main(){
    //vector<int>nums={1,2,5,9};
    vector<int>nums={44,22,33,11,1};
    //int threshold=6;
    int threshold=5;
    cout<<smallestDivisor(nums,threshold);
    return 0;
}