#include<iostream>
#include<stack>
using namespace std;
//better O(N^2)
int county_subarray(vector<int>nums,int target){
    int n=nums.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int xoor=0;
        for(int j=i;j<n;j++){
            xoor= xoor ^ nums[j];
            if(xoor == target) cnt++ ;
        }      
    }
    return cnt;
}

int main(){
    vector<int>nums={4,2,2,6,4};
    int target = 6;
    cout<<count_subarray(nums,target);
    return 0;
}