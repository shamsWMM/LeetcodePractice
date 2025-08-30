#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(const char* s, const char* p) {
    int lenS = strlen(s);
    int lenP = strlen(p);
    bool matches[lenS+1][lenP + 1];
    memset(matches, 0, sizeof(matches));

    matches[lenS][lenP] = true; // empty matches empty

    for (int i = lenS; i >= 0; i--) {
        for (int j = lenP-1; j >= 0; j--) {
            bool match = (i < lenS &&
                              (s[i] == p[j] || p[j] == '.'));

            if (j+1 < lenP && p[j+1] == '*') {
                matches[i][j] = matches[i][j+2] || (match && matches[i+1][j]);
            } else {
                matches[i][j] = match && matches[i+1][j+1];
            }
        }
    }

    return matches[0][0];
}

int main()
{
    int result = isMatch("aab", "c*a*b");
    printf("Result: %d\n", result);
    return 0;
}