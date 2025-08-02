#include <stdio.h>

int lengthOfLongestSubstring(char* s);
// This took 0 ms, beats 100% of C submissions

int lengthOfLongestSubstring(char* s) {
    if (!*s || !s) {
        return 0;
    }

    int seen[256] = {0};
    int max = 1, current = 0, left = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (seen[s[i]] > left) {
            left = seen[s[i]];
        }

        seen[s[i]] = i + 1;
        current = i - left + 1;
        if (current > max) {
            max = current;
        }
    }
    return max;
}

int main() {
    char* s = "this is a test";
    int maximumSize = lengthOfLongestSubstring(s); // "this " new length 5
    printf("Max length is: %d\n", maximumSize);
    return 0;
}