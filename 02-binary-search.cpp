#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> binarySearchAll(const vector<int>& sortedArr, const vector<int>& originalArr, int target) {
    vector<int> indices;
    int left = 0;
    int right = sortedArr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedArr[mid] == target) {
            // Find all occurrences of target in the sorted array
            indices.push_back(mid);

            // Check left side of mid
            int leftSide = mid - 1;
            while (leftSide >= 0 && sortedArr[leftSide] == target) {
                indices.push_back(leftSide);
                leftSide--;
            }

            // Check right side of mid
            int rightSide = mid + 1;
            while (rightSide < sortedArr.size() && sortedArr[rightSide] == target) {
                indices.push_back(rightSide);
                rightSide++;
            }

            break;
        }

        if (sortedArr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Convert sorted indices to original indices
    vector<int> originalIndices;
    unordered_map<int, int> seen; // to track occurrences in the original array
    for (int idx : indices) {
        for (size_t i = 0; i < originalArr.size(); ++i) {
            if (originalArr[i] == sortedArr[idx]) {
                if (seen[i] == 0) { // if not seen before
                    originalIndices.push_back(i + 1); // 1-based index
                    seen[i] = 1; // mark as seen
                }
            }
        }
    }

    sort(originalIndices.begin(), originalIndices.end());
    return originalIndices;
}

int main() {
    vector<int> originalArr = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    vector<int> sortedArr = originalArr;

    cout << "Original Array:" << endl;
    printArray(originalArr);

    // Sort the array for binary search
    sort(sortedArr.begin(), sortedArr.end());

    cout << "\nSorted Array:" << endl;
    printArray(sortedArr);

    string choice;
    do {
        // Prompt the user to enter the number to search
        cout << "\nEnter the number to search (or 'q' to quit): ";
        cin >> choice;

        if (choice == "q") {
            break;
        }

        stringstream ss(choice);
        int target;
        if (ss >> target) {
            // Perform binary search for all occurrences
            vector<int> result = binarySearchAll(sortedArr, originalArr, target);

            // Print the result
            if (!result.empty()) {
                cout << "Angka " << target << " ada di indeks ke ";
                for (size_t i = 0; i < result.size(); i++) {
                    cout << result[i]; // Output original indices
                    if (i < result.size() - 1) {
                        cout << " dan ";
                    }
                }
                cout << endl;
            } else {
                cout << "Angka " << target << " tidak ada dalam array" << endl;
            }
        } else {
            cout << "Input tidak valid, silakan coba lagi." << endl;
        }

    } while (true);

    return 0;
}
