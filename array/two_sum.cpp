#include<iostream>
#include<map>
using namespace std;
//better
//O(n*logn) #logn for insertion/ find operations in map , sc o(n)
vector<int> two_sum(vector<int>nums,int target){
    //map<int,int>mpp;
    unordered_map<int,int>mpp; //tc O(n) ,sc O(n) #lookup/insert takes O(1)
    for(int i=0;i<nums.size();i++){
        int a=nums[i];
        int rem=target- a;
        //if not found then points at the end(milega toh bhichme hi)
        if(mpp.find(rem) !=mpp.end()){
            return {mpp[rem], i};
        }
        mpp[a]=i;
    }
    return {-1,-1};

}
//optimal two pointer O(N) + O(NLOGN)for sorting
vector<int> two_summ(vector<int>nums,int target){
    int left=0, right=nums.size()-1 ;
    sort(nums.begin(),nums.end());
    while(left<right){
        if((nums[left]+nums[right]) < target) left++;
        else if((nums[left] + nums[right])> target) right-- ;
        else return{left,right};
    }
    return {-1,-1};
}
int main(){
    vector<int>nums={2,6,5,8,11,4};
    int target=14;
    vector<int>ans=two_summ(nums,target);
    for(auto i:ans){
        cout<<i<<' ';
    }
    return 0;
}