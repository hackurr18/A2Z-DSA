//greater then floor of n/3
//only two ele are possible
#include<iostream>
#include<map>
using namespace std;
//brute O(N^2)
//better tc O(n) sc O(N) for ls
vector<int> majorityEle(vector<int>& nums) {
    vector<int>ls;
    map<int,int>mpp;
    int n=nums.size();
    int min= (int)(n/3) +1;
    for(int i=0;i<n ;i++){
        mpp[nums[i]]++ ;
        if(mpp[nums[i]]==min)
            ls.push_back(nums[i]);
        if(ls.size() == 2) break;
    }
    return ls;
}

//optimal tc O(2n) sc O(1)
vector<int> majorityElement(vector<int>& nums) {
    int cnt1=0 , cnt2=0 ;
    int ele1= INT_MIN;
    int ele2= INT_MIN ;
    for(int i=0;i<nums.size();i++){ //O(N)
        if(cnt1==0 && nums[i]!=ele2){
            ele1=nums[i];
            cnt1 ++;
        }
        else if(cnt2==0 && nums[i]!= ele1){
            ele2=nums[i];
            cnt2 ++ ;
        }
        else if(ele1 == nums[i]) cnt1++;
        else if(ele2 == nums[i]) cnt2 ++;
        else {
            cnt1-- , cnt2-- ;
        }
    }
    vector<int>ls;
    cnt1=0 , cnt2=0 ;
    for(int i=0;i<nums.size();i++){ //O(N)
        if(ele1==nums[i]) cnt1++ ;
        if(ele2==nums[i]) cnt2++ ;
    }
    int min=(int)(nums.size()/3) +1;
    if(cnt1 >= min) ls.push_back(ele1);
    if(cnt2 >= min) ls.push_back(ele2);
    return ls;    
}
int main(){
    vector<int>nums={2,1,1,3,1,4,2,2};
    vector<int>ans=majorityElement(nums);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}
