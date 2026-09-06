#include<iostream>
using namespace std;
//brute O(nlog n + 2n)
vector<vector<int>> mergey(vector<vector<int>>& intervals) {
    int n=intervals.size();
    sort(intervals.begin(),intervals.end()); //nlog n
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){ //O(2n ) bcz of break and conti
        int start=intervals[i][0];
        int end= intervals[i][1];
        if(!ans.empty() && end <= ans.back()[1]) continue;
        for(int j=i+1 ;j<n;j++){
            if(intervals[j][0]<= end){
                end=max(end, intervals[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

//me sc optimal se thodi jyada
vector<vector<int>> merges(vector<vector<int>>& intervals) {
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<int>temp;
    vector<vector<int>>ans;
    temp.push_back(intervals[0][0]);
    temp.push_back(intervals[0][1]);
    for(int i=1 ;i<n ;i++){
        
        if(intervals[i][0] <= temp[1]){
            temp[1]=max(temp[1],intervals[i][1]);

        }
        else{
            ans.push_back(temp);
            temp.clear();
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
        }
        
    }
    ans.push_back(temp);
    return ans;
        
}
//optimal O(nlog n +n) sc O(N)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n=intervals.size();
    sort(intervals.begin(),intervals.end()); //nlog n
    vector<vector<int>>ans;
    for(int i=0 ;i<n ;i++){
        if(ans.empty() || intervals[i][0] > ans.back()[1]){
            ans.push_back(intervals[i]);
        }
        else{
            ans.back()[1]= max(ans.back()[1] , intervals[i][1]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>intervals={{1, 3},{2, 6},{2, 4}, {8, 9}, {9, 11}, {8, 10}, {15, 18}, {16, 17}};
    vector<vector<int>>ans=merge(intervals);
    for(const auto &i:ans){
        for(auto x:i){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
    return 0;
}