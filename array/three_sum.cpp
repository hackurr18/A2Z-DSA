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
//optimal tc O(nlogn )+ O(n*n)
vector<vector<int>> threeSumm(vector<int>&nums){
    int n=nums.size();
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end()); //nlogn 

    for(int i=0;i<n;i++){ //O(n)
        // Skip duplicates for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int j=i+1 ,k=n-1;
        while(j<k){ //O(n)
            if(nums[i]+nums[j]+nums[k]<0){
                j++ ;
            }
            else if(nums[i]+nums[j]+nums[k]>0){
                k--;
            }
            else{
                vector<int>temp={nums[i],nums[j],nums[k]};
                j++, k-- ;
                ans.push_back(temp);
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }    
    return ans;
}
int main(){
    //vector<int>nums={-1,0,1,2,-1,-4};
    vector<int>nums={2,-1,2,0,-2,-1,0,-2,2,0,2,-1,-2};
    vector<vector<int>>ans=threeSumm(nums);
    for(const auto &i:ans){
        for(auto x:i){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

}