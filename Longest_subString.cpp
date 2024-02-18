#include <iostream>
#include <unordered_map>
#include <algorithm>

int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> charIndexMap;  // Map to store the last index of each character
    int start = 0;  // Starting index of the current substring
    int maxLength = 0;  // Length of the longest substring without repeating characters

    for (int end = 0; end < s.length(); ++end) {
        if (charIndexMap.find(s[end]) != charIndexMap.end() && charIndexMap[s[end]] >= start) {
            // If the character is repeated and its last occurrence is within the current substring
            start = charIndexMap[s[end]] + 1;
        }

        charIndexMap[s[end]] = end;  // Update the last index of the character
        maxLength = std::max(maxLength, end - start + 1);  // Update the maximum length
    }

    return maxLength;
}

int main() {
    std::string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    std::cout << result << std::endl;  // Output: 3 (substring "abc" has length 3)

    return 0;
}