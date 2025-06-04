#include <iostream>
#include <string>
using namespace std;

// Function to find the first occurrence
int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();

    if (m == 0) return 0; // Edge case: empty needle

    for (int i = 0; i <= n - m; i++) {
        if (haystack.substr(i, m) == needle) {
            return i;
        }
    }

    return -1;
}

int main() {
    string haystack, needle;

    cout << "Enter the haystack string: ";
    getline(cin, haystack);  // Allows input with spaces

    cout << "Enter the needle string: ";
    getline(cin, needle);

    int index = strStr(haystack, needle);

    if (index != -1) {
        cout << "The needle is found at index: " << index << endl;
    } else {
        cout << "The needle was not found in the haystack." << endl;
    }

    return 0;
}
