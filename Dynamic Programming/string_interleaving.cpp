#include <iostream>
using namespace std;
 
// Function to check if strings 'X' and 'Y' are interleaving of string 'S' or not
bool isInterleaving(string X, string Y, string S)
{
    // return true if the end of all strings is reached
    if (!X.length() && !Y.length() && !S.length()) {
        return true;
    }
 
    // return false if the end of string 'S' is reached,
    // but string 'X' or 'Y' is not empty
 
    if (!S.length()) {
        return false;
    }
 
    // if string 'X' is not empty and its first character matches with the
    // first character of 'S', recur for the remaining substring
 
    if (X.length() && S[0] == X[0]) {
        return isInterleaving(X.substr(1), Y, S.substr(1));
    }
 
    // if string 'Y' is not empty and its first character matches with the
    // first character of 'S', recur for the remaining substring
 
    if (Y.length() && S[0] == Y[0]) {
        return isInterleaving(X, Y.substr(1), S.substr(1));
    }
 
    return false;
}
 
int main()
{
    string X = "ABC";
    string Y = "DEF";
    string S = "ADEBCF";
 
    if (isInterleaving(X, Y, S)) {
        cout << "Interleaving";
    }
    else {
        cout << "Not an Interleaving";
    }
 
    return 0;
}
