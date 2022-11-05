//Checking if two strings are anagram or not
//An anagram of a string is another string that contains the same characters,
//only the order of characters can be different.
//For example, “abcd” and “dabc” are an anagram of each other.

#include <stdio.h>

// Using "Hashing", aka an array
// This function only works with lower case letters
int isAnagram(char *a, char *b) {
    int H[26] = {0};

    for (int i = 0; a[i] != '\0'; i++)
        H[a[i]-97]++;

    for (int i = 0; b[i] != '\0'; i++) {
        H[b[i]-97]--;
        if (H[b[i]-97] < 0) return 0;
    }

    // Check if there are any non zero vals in H, if so it is not an Anagram
    for (int i = 0; i < 26; i++) {
        if (H[i] > 0) return 0;
    }
    return 1;
}

int main() {
    char s1[] = "listen";
    char s2[] = "silent";
    if (isAnagram(s1, s2)) printf("is Anagram\n");
    else printf("is NOT Anagram\n");

    char s3[] = "peach";
    char s4[] = "cheap";
    if (isAnagram(s3, s4)) printf("is Anagram\n");
    else printf("is NOT Anagram\n");

    return 0;
}
