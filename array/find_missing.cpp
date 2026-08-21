#include <iostream>
#include <vector>
using namespace std;
//brute
int missingNum(vector<int>& arr) {
    int n = arr.size() + 1;

    // Iterate from 1 to n and check
    // if the current number is present
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }

        // If the current number is not present
        if (!found)
            return i;
    }
    return -1;
}
//better

int missingNumber(vector<int> &arr) {

    int n = arr.size() + 1;

    // Create hash array of size n+1
    vector<int> hash(n + 1, 0);

    // Store frequencies of elements
    for (int i = 0; i < n - 1; i++) {
        hash[arr[i]]++;
    }

    // Find the missing number
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
    return -1;
}
//optim sum=n)n+1)/2.  - s2 ;
//optimal using xor.
int missingNumb(vector<int> &arr) {
    int N = arr.size() + 1;
    int xor1=0 , xor2=0;
    int n=N-1;
    for(int i=0;i<n;i++){
        xor2=xor2 ^ arr[i];
        xor1= xor1 ^ (i+1);
    }
    xor1=xor1 ^ N;
    return xor1 ^ xor2;
}
int main() {
    vector<int> arr = { 2, 6, 5, 3, 7, 1}; 
    cout << missingNum(arr) << endl; 
    int res = missingNumb(arr);
    cout << res << endl;
    return 0;
}