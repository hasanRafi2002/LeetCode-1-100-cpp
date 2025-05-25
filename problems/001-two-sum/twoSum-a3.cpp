#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    // Brute-force nested loop
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (nums[i] + nums[j] == target) {
                cout << "Indices: [" << i << ", " << j << "]\n";
                return 0;
            }
        }
    }

    cout << "No valid pair found.\n";
    return 0;
}
