#include<iostream>
using namespace std;
//brute sc O(N)
int mediannn (vector<int>&nums1,vector<int>&nums2){
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    vector<int>ans;
    int i=0 , j=0;
    while(i<n1 && j<n2){
        if(nums1[i]<=nums2[j]){
            ans.push_back(nums1[i]);
            i++;
        }
        else{
            ans.push_back(nums2[j]);
            j++;
        }
    }
    while(i<n1){
        ans.push_back(nums1[i]);
        i++;
    }
    while(j<n2){
        ans.push_back(nums2[j]);
        j++;
    }
    if(n%2==1){
        return ans[n/2];
    }
    else{
        return ((ans[n/2]+ans[n/2-1])/2);
    }
    return -1;
}
//brute sc O(1) tc O(n1+n2)
double mediann(vector<int>&nums1, vector<int>&nums2){
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    int ind2=n/2;
    int ind1= (n/2 -1);
    int i=0 , j=0;
    int cnt=0;
    int ele1=-1 , ele2=-1;
    while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            if(cnt==ind1) ele1=nums1[i];
            if(cnt==ind2) ele2=nums1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt==ind1) ele1=nums2[j];
            if(cnt==ind2) ele2=nums2[j];
            cnt++ ,j++;
        }
    }
    while(i<n1){
        if(cnt==ind1) ele1=nums1[i];
        if(cnt==ind2) ele2=nums1[i];
            cnt++;
            i++;
    }
    while(j<n2){
        if(cnt==ind1) ele1=nums2[j];
        if(cnt==ind2) ele2=nums2[j];
            cnt++ ,j++;
    }
    if(n%2==1){
        return ele2;
    }
    return (double)((double)(ele1 + ele2))/2.0;
    
    
}
//optimal tc O(min(log n1,log n2))
double  median(vector<int>&nums1, vector<int>&nums2){
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
    if(n1>n2) return median(nums2,nums1);
    
    int low=0 , high=n1;
    int left=(n1+n2+1)/2;//left side of median line
    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=(left-mid1);

        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];
        if(mid1 -1 >=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];
        if( l1<=r2 && l2<=r1){
            if(n%2==1) return max(l1,l2);
            return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
        }
        else if(l1>r2) high=mid1-1;
        else low =mid1+1;
    
    }
    return 0;
}
int main(){
    vector<int>nums1={1,3,4,7,10,12};
    //vector<int>nums1={};
    vector<int>nums2={2,3,6,15};
    cout<<median(nums1,nums2);
    return 0;
}