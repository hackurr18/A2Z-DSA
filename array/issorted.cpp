#include<iostream>
using namespace std;
bool check(vector<int>& nums) {
        for(int i=0; i< nums.size();i++){
            if(nums[i]>= nums[i-1]){

            }
            else{
                 return false;
        }
        }
        return true;
    }
int main(){
    vector<int>nums={1,2,9,6,6,7};
    cout<<check(nums);
    return 0;
}