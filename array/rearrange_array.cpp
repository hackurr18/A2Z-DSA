#include<iostream>
using namespace std;
// O(2n)
vector<int> rearrangeArray(vector<int>nums){
    int n=nums.size();
    vector<int>ans(n,0);
    int posindex=0 , negindex=1;
    for(int i=0;i<n;i++){
        if (nums[i]>0){
            ans[posindex]=nums[i];
            posindex +=2;
        }
        else{
            ans[negindex]=nums[i];
            negindex +=2 ;
        }
    }
    return ans;

}
// pos , neg are !=
vector<int >alternate_num(vector<int>&nums){
    vector<int>pos , neg ;
    int n =nums.size();
    for(int i:nums){
        if(i>0){
            pos.push_back(i);
        }
        else{
            neg.push_back(i);
        }
    }
    if(pos.size() > neg.size()){
        for(int i=0;i< neg.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=neg.size() *2;
        for(int i = neg.size() ;i< pos.size() ;i++){
            nums[index++]=pos[i];
        }
    }
    else{
        for(int i=0;i< pos.size();i++){
            nums[2*i]=pos[i];
            nums[2*i+1]=neg[i];
        }
        int index=pos.size() *2;
        for(int i = pos.size() ;i< neg.size() ;i++){
            nums[index++]=neg[i];
        }

    }
    return nums;
}
int main(){
    vector<int>nums={3,1,-2,-5,2,-4,7,9};
    
   //vector<int>ans=rearrangeArray( nums);
   vector<int>ans=alternate_num(nums);
    for(auto i:nums){
        cout<<i <<" " ;
    }

}