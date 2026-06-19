// Approach: Sliding Window to Find Maximum Average Subarray

class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    int windowSum = 0;

    // Calculate sum of the first window of size k
    for (int i = 0; i < k; i++) {
      windowSum += nums[i];
    }

    int maxSum = windowSum;

    // Slide the window across the array
    for (int i = k; i < nums.size(); i++) {
      windowSum += nums[i] - nums[i - k];
      maxSum = max(maxSum, windowSum);
    }

    return (double)maxSum / k;
  }
};

/*
Time Complexity: O(n)
- Compute the first window sum in O(k).
- Slide the window through the remaining elements in O(n - k).
- Overall complexity is O(n).

Space Complexity: O(1)
- Only a few variables (windowSum and maxSum) are used.
- No extra data structures are required.
*/