#include<iostream>
using namespace std;
//brute tc O(n)
int findKthPositivee(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=k;
        for(int i=0;i<n;i++){
            if(arr[i]<=ans){
                ans++;
            }
            else return ans;
        }
        return ans;
}
//optimal tc O(log n)
int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0 ,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing =arr[mid] -(mid+1);
            if(missing <k) low=mid+1;
            else high=mid-1;
        }
        return high+1+k  ; //low+k;
}
int main() {
    vector<int> vec = {4, 7, 9, 10};  // Sorted array
    int k = 4;                       // k-th missing number to find
    int ans =  findKthPositive(vec, k); 

    cout << "The missing number is: " << ans << "\n";  // Print result
    return 0;
}