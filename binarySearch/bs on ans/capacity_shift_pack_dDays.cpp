#include<iostream>
#include<algorithm>
#include <numeric>
using namespace std;
//brute tc O(sum-max * n)
int sumOf(vector<int>&weights){
    int sum=0;
    for(int i:weights){
        sum+=i;
    }
    return sum;
}
int func(vector<int>&weight,int cap){
    int n=weight.size();
    int days=1 ,load=0;
    for(int i=0;i<n;i++){
        if(load +weight[i]>cap){
            days++;
            load=weight[i];
        }
        else load+=weight[i];
    }
    return days;
    
}

int shipWithinDayss(vector<int>& weights, int days) {
        int n=weights.size();
        int capi= *max_element(weights.begin(),weights.end());
        int idx=0 ,total=0;
        int ans=sumOf(weights);
        for(int cap=capi;cap<ans;cap++){
            int dayreq=func(weights,cap);
            if(dayreq<=days) return cap;
        }
        return ans;
}
//optimal tc O(logsum-max *n)
int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low= *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(weights,mid)<=days){
                high=mid-1;
            }
            else low=mid+1;
        }
        return low;
    }
int main() {
    // Input weights
    vector<int> weights = {5,4,5,2,3,4,5,6};
    // Days to ship
    int d = 5;

    // Call the function and print result
    cout <<shipWithinDays(weights, d) << "\n";
    return 0;
}