#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Copy remaining elements from nums2
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

int main() {
    int m, n;

    cout << "Enter the number of initialized elements in nums1 (m): ";
    cin >> m;

    cout << "Enter the number of elements in nums2 (n): ";
    cin >> n;

    vector<int> nums1(m + n); // total size to hold merged result
    vector<int> nums2(n);

    cout << "Enter " << m << " sorted elements for nums1: ";
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }

    // Fill the rest with zeros (not necessary but helps visualize)
    for (int i = m; i < m + n; ++i) {
        nums1[i] = 0;
    }

    cout << "Enter " << n << " sorted elements for nums2: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int i = 0; i < m + n; ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
