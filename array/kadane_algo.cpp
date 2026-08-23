#include<iostream>
using namespace std;
int kadane(vector<int>nums){
    long long sum=0 ,  maxi=LONG_MIN ;
    int start, anstart=-1, ansend=-1;
    for(int i=0;i<nums.size();i++){
       if(sum==0) start=i;
        sum+=nums[i];
        if(maxi< sum){
            maxi=sum;
            anstart= start ,ansend=i;
        }
        if(sum<0) sum=0;
    }
    //to dispalay substring 
    for(int i=anstart ;i<=ansend;i++){
        cout<<nums[i]<<" ";
    }
    return maxi;
}
int main(){
    vector<int>nums={-2,-3,4,-1,-2,1,5,-3};
    cout<<kadane(nums);

}