#include<iostream>
using namespace std;
// This function returns the floor value of the square root of a number
int sqareroot(int num){
    int low=1 ,high=num/2; //reduce the search space
    int ans=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(mid*mid <= num){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    int nums=37;
    cout<<sqareroot(nums);
    return 0;
}