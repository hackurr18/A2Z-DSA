#include<iostream>
#include<map>
using namespace std;
//brute O(2n) sc O(N)
vector<int>missing(vector<int>&nums){
    int n=nums.size();
    
    vector<int>ans;
    vector<int>vec(n+1,0);
    for(int i=0;i<=n;i++){
        vec[nums[i]]++;
    }
    int repeating = -1, missing = -1;
    for(int i=1;i<=n;i++){
        if(vec[i] == 0)  missing =i;
        else if(vec[i]==2) repeating = i;
        if (repeating != -1 && missing != -1) {
                break;
        }
    }
    return {repeating, missing};
}
//optimal1 math tc O(N)
vector<int>missing_num(vector<int>&nums){
    int n=nums.size();
    long long sn= (n*(n+1))/2;
    long long sn2=(n*(n+1)*(2*n+1))/6;
    long long s=0 , s2=0;
    for(int i=0;i<n;i++){
        s+=nums[i];
        s2 += (long long )nums[i] *(long long)nums[i];

    }
    long long val1= s-sn; //x-y
    long long val2=s2- sn2 ; //x^2 -y^2
    val2= val2 / val1 ; //x+y
    long long x =(val1 + val2)/2;
    long long y= x - val1;
    //return the result as  {repeating, missing  }
    return {(int)x , (int)y};
}
//optimal2 xor(only for knowledge) tc O(N)
vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        int n = nums.size(); 
        int xr = 0;
        for (int i = 0; i < n; i++) {
            // XOR of all elements in nums
            xr = xr ^ nums[i]; 
            // XOR of numbers from 1 to n
            xr = xr ^ (i + 1);  
        }
        // Get the rightmost set bit in xr
        int number = (xr & ~(xr - 1));
        //Group the numbers based on the differentiating bit
        // Number that falls into the 0 group
        int zero = 0; 
        // Number that falls into the 1 group
        int one = 0;  

        for (int i = 0; i < n; i++) {
            
            /* Check if nums[i] belongs to the 1 group
            based on the differentiating bit*/
            if ((nums[i] & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ nums[i];
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ nums[i]; 
            }
        }

        // Group numbers from 1 to n based on differentiating bit
        for (int i = 1; i <= n; i++) {
            
            /* Check if i belongs to the 1 group 
            based on the differentiating bit*/
            if ((i & number) != 0) {
                
                // XOR operation to find numbers in the 1 group
                one = one ^ i; 
                
            } else {
                // XOR operation to find numbers in the 0 group
                zero = zero ^ i; 
            }
        }

        // Count occurrences of zero in nums
        int cnt = 0; 

        for (int i = 0; i < n; i++) {
            if (nums[i] == zero) {
                cnt++;
            }
        }

        if (cnt == 2) {
            /*zero is the repeating number,
            one is the missing number*/
            return {zero, one}; 
        }
        
        /* one is the repeating number, 
        zero is the missing number*/
        return {one, zero}; 
    }

int main(){
    vector<int>nums={1,4,6,2,7,5,7};
    //vector<int>ans=missing_num(nums);
    vector<int>ans=findMissingRepeatingNumbers(nums);
    for(auto i :ans){
        cout<<i<<" ";
    }
    return 0;
}
