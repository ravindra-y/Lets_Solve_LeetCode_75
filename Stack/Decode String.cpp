// Approach: Use Two Stacks to Decode the Encoded String

class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> stringStack;
        int k = 0;

        // Traverse each character
        for (char c : s) {

            if (isdigit(c)) {
                k = k * 10 + (c - '0');
                continue;
            }

            // Store the repeat count and start of a new substring
            if (c == '[') {
                numStack.push(k);
                k = 0;
                stringStack.push("[");
                continue;
            }

            // Store normal characters
            if (c != ']') {
                stringStack.push(string(1, c));
                continue;
            }

            // Build the substring inside the brackets
            string temp = "";
            while (stringStack.top() != "[") {
                temp = stringStack.top() + temp;
                stringStack.pop();
            }

            stringStack.pop();

            // Repeat the substring
            string decoded = "";
            int count = numStack.top();
            numStack.pop();

            while (count--) {
                decoded += temp;
            }

            // Push the decoded substring back onto the stack
            stringStack.push(decoded);
        }

        // Build the final decoded string
        string result = "";
        while (!stringStack.empty()) {
            result = stringStack.top() + result;
            stringStack.pop();
        }

        return result;
    }
};

/*
Time Complexity: O(n × k)
- Traverse the input string once.
- Repeating substrings takes time proportional to the decoded output.
- Overall complexity is O(decoded string length.

Space Complexity: O(n)
- Two stacks store the repeat counts and substrings.
- Excluding the space required for the output string.
*/