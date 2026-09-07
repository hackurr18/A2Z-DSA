#include<iostream>
using namespace std;
//brute 2 *O(n+m)
void mergey(vector<int>&nums1,vector<int>&nums2){
    int n=nums1.size();
    int m=nums2.size();
    int total=n+m;
    int left=0 , right=0;
    int index=0;
    vector<int>arr(n+m);
    while(left<n && right < m){
        if( nums1[left]<= nums2[right]){
            arr[index]=nums1[left];
            left++ , index++;
        }
        else {
            arr[index]=nums2[right];
            right ++ , index++;
        }
    }
    while(left<n){
        arr[index++]=nums1[left++];
    }
    while(right<m){
        arr[index++]=nums2[right++];
    }
    int i=0;
    while(i<total){
        if(i<n){
            nums1[i]=arr[i];
            i++;
        }
        else{
            nums2[i-n]=arr[i];
            i++;
        }
    } 
}
//optimal
void merge(vector<int>&nums1, vector<int>&nums2){
    int n=nums1.size();
    int m=nums2.size();
    int left=n-1;
    int right=0;
    while(left>=0 && right < m){
        if(nums1[left]>=nums2[right]){
            swap(nums1[left], nums2[right]);
            left-- , right++ ;
        }
        else{
            break;
        }

    }
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end()); 
}
//leetcode O(m + n) time, O(1) extra space)
//nums1 = [1,2,3,0,0,0,0], n = 3, nums2 = [2,5,6,7], m = 4
//nums1=[1,2,2,3,5,6,7]
void merges(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left  = m - 1;          // last valid element in nums1
    int right = n - 1;          // last element in nums2
    int k     = m + n - 1;      // write position (end of nums1)

    // Merge from the back
    while (left >= 0 && right >= 0) {
        if (nums1[left] > nums2[right]) {
            nums1[k--] = nums1[left--];
        } else {
            nums1[k--] = nums2[right--];
        }
    }

    // Copy any remaining elements from nums2
    while (right >= 0) {
        nums1[k--] = nums2[right--];
    }
}
//optimal2 using shell sort
//tc O(log (n+m))* O(n+m)
void swapIfGreater(vector<int>&nums1,vector<int>&nums2,int ind1,int ind2){
    if(nums1[ind1]>nums2[ind2]){
        swap(nums1[ind1],nums2[ind2]);
    }
}
void mergess(vector<int>&nums1,vector<int>&nums2,int n,int m){
    int len=(n+m);
    int gap=(len/2) +(len%2);
    while(gap>0){
        int left=0;
        int right=left+gap;
        while(right<len){
            //arr1 n arr2
            if(left<n && right>=n){
                swapIfGreater(nums1,nums2,left,right-n);
            }
            //arr2 n arr2
            else if(left>=n){
                swapIfGreater(nums2,nums2,left-n,right-n);
            }
            //arr1 n arr1
            else{
                swapIfGreater(nums1,nums1,left,right);
            }
            left++ , right++ ;
        }
        if(gap ==1) break;
        gap=(gap/2) + (gap%2);
    }
}
int main(){
    vector<int>nums1={1,3,5,7};
    //vector<int>nums2={0,2,6,8,9};
    //vector<int>nums1={1,2,3,0,0,0,0};
    vector<int>nums2={2,5,6,7};
    //int m=3;
    //int n=4;
    int m=3;
    int n=4;
    mergess(nums1,nums2 , n,m);
    for(auto i:nums1){
        cout<<i<<" ";
    }
    for(auto y:nums2){
        cout<<y<<" ";
    }
    return 0;
}