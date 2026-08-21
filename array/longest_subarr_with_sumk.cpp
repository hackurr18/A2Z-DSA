#include<iostream>
#include<map>
using namespace std;
//better O(nlog n).  space O(n)
int getlongest_subarr(vector<int>nums,int n,int k){
   map<long long,int>preSumMap;
   long long sum=0;
   int maxlen=0; 
   for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum == k){
            maxlen=max(maxlen, i+1);
        }
        long long rem= sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len=i- preSumMap[rem];
            maxlen= max(maxlen,len);
        }
        if(preSumMap.find(sum)== preSumMap.end()){
            preSumMap[sum] =i;
        }
   }
   return maxlen;
}
//optimal two pointer 
//tc O(2n) sc O(1)
int getlongest_subarray(vector<int>nums,int n,long long k){
    int left=0 ,right=0;
    int maxlen=0; 
    long long sum=nums[0];
    while(right <n){
        while(sum >k && left<=right){
            sum -=nums[left];
            left++;
        }
        if(sum==k){
            maxlen=max(maxlen,right -left +1);
        }
        right ++ ;
        if(right <n){
            sum +=nums[right];
        }
        
    }
    return maxlen;

}
int main(){
    vector<int>nums={1,2,3,1,2,2,1,1,1,3};
    int n=nums.size();
    int k=9;
    cout<<getlongest_subarray(nums,n,k);
    return 0;
}