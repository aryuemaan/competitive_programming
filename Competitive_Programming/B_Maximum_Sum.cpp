#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maxSum(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<long long> prefixSum(n + 1, 0);
    vector<long long> suffixSum(n + 1, 0);

    // Calculate prefix sum
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
    }

    // Calculate suffix sum
    for (int i = n - 1; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + nums[i];
    }

    long long maxSum = prefixSum[n]; // Initialize maxSum with sum of all elements

    // Remove two minimum elements k/2 times
    for (int i = 1; i <= k / 2; i++) {
        long long currentSum = prefixSum[i - 1] + suffixSum[n - k + 2 * i];
        maxSum = max(maxSum, currentSum);
    }

    // Remove the maximum element
    maxSum = max(maxSum, suffixSum[k]);

    return maxSum;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        long long answer = maxSum(nums, k);
        cout << answer << endl;
    }

    return 0;
}
