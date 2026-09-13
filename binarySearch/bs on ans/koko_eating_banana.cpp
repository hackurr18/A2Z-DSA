#include<iostream>
#include<math.h>
using namespace std;
//Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
//brute tc O(max(arr)*size of arr)
int koko(vector<int>&nums,int h){
    int n=nums.size();
    /*
        int total , ans,l=1;
        for(int j=1;j<=l;j++){
            total=0;
            l++;
            for(int k=0;k<n;k++){
                total+=ceil((double)nums[k]/j);
                ans=j;
            }
            if(total==h) break;
            //cout<<total<<" ";
        }*/
    int total, ans, j=0;
    while(1){
        total=0;
        for(int k=0;k<n;k++){
            total+=ceil((double)nums[k]/j);
                ans=j;
        }
        if(total==h) break;
        j++ ;
    }

    
    return ans;
}
//optimal tc O(n*LOG(maxof arr ele))
int f(vector<int>&nums,int mid,int h){
    int n=nums.size();
    int total, ans, j=0;
    total=0;
    for(int k=0;k<n;k++){
        total+=ceil((double)nums[k]/mid);
    }
    return total;
}
int banana(vector<int>&nums,int h){
    int n=nums.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i]>maxi) maxi=nums[i];
    }
    int low=1, high=maxi;
    while(low<=high){
        int mid=low +(high-low)/2;
        int retime=f(nums,mid,h);
        if(retime<=h){
            high=mid-1;
            return mid;
        } 
        else low =mid+1; 

    }
    return -1;
}

int main(){
    vector<int>nums= {7, 15, 6, 3};
    int h = 8;
    //vector<int>nums={25, 12, 8, 14, 19};
    //int h=5;
    cout<<banana(nums,h);
    return 0;
//Output: 5

}
