#include <stdio.h>

int lengthOfLongestSubstring(char* s);

int lengthOfLongestSubstring(char* s) {
    if (!*s || !s) {
        return 0;
    }

    int seen[256] = {0};
    int max = 1, current = 0, left = 0, right = 0;

    while (s[right] != '\0') {
        while (seen[s[right]]) {
            seen[s[left]] = 0;
            left++;
        }

        seen[s[right]] = 1;
        right++;
        current = right - left;
        if (current > max) {
            max = current;
        }
    }
    return max;
}

int main() {
    char* s = "this is a test";
    int maximumSize = lengthOfLongestSubstring(s); // "this " has length 5
    printf("Max length is: %d\n", maximumSize);
    return 0;
}