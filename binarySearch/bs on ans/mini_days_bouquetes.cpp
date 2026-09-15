#include<iostream>
using namespace std;
//brute O((maxDay − minDay) * n)
int minimum(vector<int>&bloomDay ,int n){
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<mini) mini=bloomDay[i];
    }
    return mini;
}
int maximum(vector<int>&bloomDay,int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(bloomDay[i]>maxi) maxi=bloomDay[i];
    }
    return maxi;
}

int miniDays(vector<int>& bloomDay, int m, int k) {
    int  n =bloomDay.size();
    if(n < 1LL * m * k) return -1;
    int mini=minimum(bloomDay,n);
    int maxi=maximum(bloomDay,n);
    int days=mini ;
    while(days<=maxi){
        int buq=0;
        vector<int>hash;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=days){
                hash.push_back(1);
            }
            else{
                hash.push_back(0);
            }
        }
        long long sum=0 ,cnt=0;
        for(auto i:hash){
            if(i==1){
                sum++;
                if(sum==k){
                    cnt++;
                    sum=0;
                }
            }
            else sum=0;
            if(cnt>=m){
                return days;
            }
        }
        days++;
    }
    return -1;
}
//optimal tc O(n* log(maxi - mini+1))
bool canMake(vector<int>& bloomDay, int m, int k, int day,int n) {
    int noofboq=0 ,cnt=0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
            noofboq+= (cnt/k);
            cnt=0;
        }
    }
    noofboq+= (cnt/k);
    return noofboq >= m ;
}
int minDays(vector<int>& bloomDay, int m, int k){
    int  n =bloomDay.size();
    if(n < 1LL * m * k) return -1;
    int low= *min_element(bloomDay.begin(),bloomDay.end());
    int high= *max_element(bloomDay.begin(),bloomDay.end());
    int ans=high;
    while(low<=high){
        int mid=low +(high-low)/2;
        if(canMake(bloomDay,m,k,mid,n)==1){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}
int main(){
        vector<int>bloomDay={7,7,7,7,13,11,12,7};
       // vector<int>bloomDay={1,10,3,10,2};
        int m=2 , k=3;
       //int m=3, k=1;
        cout<<minDays(bloomDay,m,k);
        return 0;

    }