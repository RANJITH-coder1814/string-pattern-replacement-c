#include <stdio.h>
#include <string.h>

#define MAX 200

char str[MAX], pat[MAX], rep[MAX], ans[MAX];

void readInput() {
    printf("Enter the main string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';   // remove newline

    printf("Enter the pattern string: ");
    fgets(pat, MAX, stdin);
    pat[strcspn(pat, "\n")] = '\0';

    printf("Enter the replacement string: ");
    fgets(rep, MAX, stdin);
    rep[strcspn(rep, "\n")] = '\0';
}

void patternMatchReplace() {
    int i = 0, j = 0, k, m;
    int found = 0;

    while (str[i] != '\0') {
        m = 0;

        while (str[i + m] == pat[m] && pat[m] != '\0') {
            m++;
        }

        if (pat[m] == '\0') {   // Pattern found
            printf("\nPattern \"%s\" found at position %d", pat, i);

            for (k = 0; rep[k] != '\0'; k++) {
                ans[j++] = rep[k];
            }

            i += m;
            found = 1;
        } else {
            ans[j++] = str[i++];
        }
    }

    ans[j] = '\0';

    if (!found)
        printf("\nPattern not found!");
    else
        printf("\nResulting string: %s\n", ans);
}

int main() {
    printf("=== STRING PATTERN MATCH & REPLACE ===\n\n");

    readInput();
    patternMatchReplace();

    return 0;
}
