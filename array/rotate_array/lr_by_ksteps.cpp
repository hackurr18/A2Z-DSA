#include <iostream>
#include <vector>
using namespace std;

void leftrotate(vector<int>& nums, int k, int d) {
    d = d % k;

    vector<int> temp(d);

    // Store first d elements
    for(int i = 0; i < d; i++) {
        temp[i] = nums[i];
    }

    // Shift remaining elements to the left
    for(int i = d; i < k; i++) {
        nums[i-d] = nums[i];
    }

    // Put temp elements at the end
    for(int i = 0; i < d; i++) {
        nums[k-d+i] = temp[i];
    }
}

int main() {
    vector<int> nums = {1, 2, 34, 5, 6, 7};

    int k = nums.size();
    int d = 11;

    leftrotate(nums, k, d);

    for(auto i : nums) {
        cout << i << " ";
    }

    return 0;
}