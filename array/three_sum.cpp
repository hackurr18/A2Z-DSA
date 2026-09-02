#include<iostream>
#include<set>
using namespace std;
//brute O(n3)*log(no. of triplet)
vector<vector<int>> triplet(vector<int>& nums) {
    set<vector<int>>st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i] +nums[j]+nums[k]==0){
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
//better TC O(N2)*log m
vector<vector<int>> threeSum(vector<int>&nums){
    set<vector<int>>st;
    int n=nums.size();
    for(int i=0;i<n;i++){
        set<int>hashset;
        for(int j=i+1 ;j<n;j++){
            int second= -(nums[i]+nums[j]);
            if(hashset.find(second) != hashset.end()){
                vector<int>temp={nums[i],nums[j],second};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);

        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=threeSum(nums);
    for(const auto &i:ans){
        for(auto x:i){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

}