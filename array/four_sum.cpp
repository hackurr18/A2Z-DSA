#include<iostream>
#include<set>
using namespace std;
//brute O(N4)
vector<vector<int>> fourSummm(vector<int>&nums, int target){
    int n=nums.size();
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    long long sum=nums[i]+nums[j];
                    sum +=nums[k];
                    sum+= nums[l];
                    if(sum==target){
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }

        }
    }
    vector<vector<int>>ans={st.begin(),st.end()};
    return ans;
}
//better O(N3)
vector<vector<int>> fourSumm(vector<int>&nums, int target){
    int n=nums.size();
    set<vector<int>>st;
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int>hashset;
            for(int k=j+1;k<n;k++){
                int rem=target-(nums[i]+nums[j]+nums[k]);
                if(hashset.find(rem) != hashset.end()){
                    vector<int>temp={nums[i],nums[j],rem,nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                    
                }
                hashset.insert(nums[k]);
            }
        }
    }
        
    vector<vector<int>>ans={st.begin(),st.end()};    
        
    return ans;
}
//optimal O(N2 *n)
vector<vector<int>> fourSum(vector<int>&nums, int target){
    int n=nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!= i+1 && nums[j]==nums[j-1]) continue;
            int k=j+1 ,l=n-1;
            while(k<l){
                long long sum=nums[i]+nums[j];
                sum += nums[k];
                sum+= nums[l];

                if(sum< target){
                    k++;
                }
                else if(sum> target){
                    l-- ;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++ ,l-- ;
                    while(k<l && nums[k]==nums[k-1]) k++ ;
                    while(k<l && nums[l]==nums[l+1]) l-- ;
                }
            }
        }

    }
    
    return ans;
}
int main(){
    //vector<int>nums={1,0,-1,0,-2,2};
   // vector<int>nums={1,2,-1,-2,2,0,-1};
   vector<int>nums={1,1,1,2,2,2,3,3,3,4,4,4,5,5};

    int target=8;
    vector<vector<int>>ans=fourSumm(nums,target);
    for(const auto &i:ans){
        for(auto x:i){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}