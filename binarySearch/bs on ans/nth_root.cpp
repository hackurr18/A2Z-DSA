#include<iostream>
using namespace std;
//brute yc O(mlogn)
//Given two numbers N and M, find the Nth root of M. The nth root of a number M is defined as a number X when raised to the power N equals M. If the 'nth root is not an integer, return -1.
//optimal tc O(LOGM)
int nroot(int n, int m){
    int low=1 ,high=m/n; //reduce the search space

    while(low<=high){
        int mid=(low +high)/2;
        long long ans=1;
        for(int i=0;i<n;i++){
            ans*=mid;
            if(ans >m) break;
        }
        
        if(ans== m) return mid;
        else if(ans>m) high=mid-1;
        else low=mid+1;
    }
      
    return -1;
}

int main(){
    int n=4 ,m=625;
    cout<<nroot(n,m);
    return 0;
}