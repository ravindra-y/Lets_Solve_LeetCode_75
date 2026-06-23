// Approach: Track Current Altitude and Maximum Altitude Reached

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0, curr = 0;

        for (int g : gain) {
            curr += g;                  // Update current altitude
            maxAlt = max(maxAlt, curr); // Update highest altitude reached
        }

        return maxAlt;
    }
};

/*
Time Complexity: O(n)
- Traverse the gain array once.
- Each element is processed exactly one time.

Space Complexity: O(1)
- Only two integer variables (curr and maxAlt) are used.
- No extra data structures are required.
*/