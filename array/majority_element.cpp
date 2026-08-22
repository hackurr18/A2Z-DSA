#include<iostream>
#include<map>
using namespace std;
//better O(n)for map, O(logn)for unordredmap ,sc O(N)
int majority(vector<int>&nums,int n){
    map<int,int>hash;
    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }
    for(auto i:hash){
        if(i.second >(n/2)) return i.first; 
    }
    return -1;

}
//moore's voting
//optimal O(N) sc O(1)
int majority_ele(vector<int>&nums,int n){
    int ele,cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt++;
            ele=nums[i];
        }
        else if(ele == nums[i]) cnt++;
        else cnt-- ;
    }
    int ans=0;
    //this is not included in tc bcz it only checks...
    for(int i=0;i<n ;i++){
        if(nums[i]==ele) ans++ ;
    }
    if(ans > (n/2)) return ele;
    return -1 ;
}
int main(){
    vector<int> nums={2,2,3,4,3,2,2};
    int n=nums.size();
    
    cout<<majority_ele(nums,n);
}