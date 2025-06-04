#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;

    int j = 0; // position of last unique element

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }

    return j + 1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k = removeDuplicates(nums);

    cout << "\nNumber of unique elements: " << k << endl;
    cout << "Modified array: ";
    for (int i = 0; i < k; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
