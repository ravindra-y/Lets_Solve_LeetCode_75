// Approach: Use Hash Sets to Store Unique Elements and Find Differences

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        // Store unique elements from both arrays
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> diff1, diff2;

        // Elements present in nums1 but not in nums2
        for (int x : set1) {
            if (set2.find(x) == set2.end()) {
                diff1.push_back(x);
            }
        }

        // Elements present in nums2 but not in nums1
        for (int x : set2) {
            if (set1.find(x) == set1.end()) {
                diff2.push_back(x);
            }
        }

        return {diff1, diff2};
    }
};

/*
Time Complexity: O(n + m) (Average Case)
- Creating two unordered_sets takes O(n + m).
- Traversing both sets takes O(n + m).
- Each lookup in unordered_set is O(1) on average.

Space Complexity: O(n + m)
- Two unordered_sets store the unique elements of both arrays.
- The result vectors store the unique differences.
*/