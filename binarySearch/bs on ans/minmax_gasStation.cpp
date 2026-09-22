#include<iostream>
using namespace std;
//brute tc O(k*n)
long double minimiseMaxDistancee(vector<int>&arr,int k){
    int n=arr.size();
    vector<int>howMany(n-1,0);
    for(int gasstation=1;gasstation<=k;gasstation++){
        long double maxsection =-1;
        int maxind=-1;
        for(int i=0;i<n-1;i++){
            long double diff = (arr[i+1]-arr[i]);
            long double sectionlenght= diff/(long double)(howMany[i]+1);
            if(sectionlenght>maxsection){
                maxsection=sectionlenght;
                maxind=i;
            }
        }
        howMany[maxind]++ ;
    }
    long double maxans=-1;
    for(int i=0;i<n-1;i++){
        long double diff=(arr[i+1]-arr[i]);
        long double sectionlenght= diff/(long double)(howMany[i]+1);
        maxans=max(maxans,sectionlenght);
    }
    return maxans;
}
//better
/*
       Utilizes a max heap to continuously retrieve and divide
       the largest available distance segment efficiently
    */
long double minimiseMaxDistanceee(vector<int> &arr, int k) {
    int n = arr.size();
    // Array to track how many new stations are added in each original gap
    vector<int> howMany(n - 1, 0);
    
    // Max heap to store pairs of current gap distance and its original index
    priority_queue<pair<long double, int>> pq;
    
    // fill the heap with the initial gaps between stations
    for (int i = 0; i < n - 1; i++) {
        pq.push({arr[i + 1] - arr[i], i});
    }
    
    // Place k stations one by one by always splitting the largest gap
    for (int stations = 1; stations <= k; stations++) {
        // Retrieve the maximum gap from the top of the heap
        auto top = pq.top();
        pq.pop();
        int secIndex = top.second;
        
        // Add a station to this specific gap segment
        howMany[secIndex]++;
        
        // Calculate the newly divided segment length
        long double originalDiff = arr[secIndex + 1] - arr[secIndex];
        long double newSectionLen = originalDiff / (long double)(howMany[secIndex] + 1);
        
        // Reinsert the reduced gap back into the heap for future operations
        pq.push({newSectionLen, secIndex});
    }
    
    // The maximum distance is guaranteed to be at the top of the heap
    return pq.top().first;
}
//optimal tc O((N x log2(Max / 1e-6))
int numberOfGasStationsRequired(vector<int>& arr, long double dist) {
        int required = 0;
        
        
        for (int i = 1; i < arr.size() ; i++) {
            int numberinbetween=((arr[i]-arr[i-1])/dist);
            if(((arr[i]-arr[i-1])/dist) == numberinbetween*dist){
                numberinbetween--;
            }
            required += numberinbetween;
        }
        
        return required;
    }
long double minimiseMaxDistance(vector<int> &arr, int k){
	long double low = 0;
        long double high = 0;
        
        for (int i = 0; i < arr.size() - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }
        
        while (high - low > 1e-6) {
            long double mid = low + (high - low) / 2.0;
            
            if (numberOfGasStationsRequired(arr, mid) > k) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return high;
    
}

int main(){
    vector<int>arr={1,13,17,23};
    int k=5;
    cout<<minimiseMaxDistance(arr,k);
    return 0;
}