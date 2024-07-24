#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Data {
    string name;
    string city;
};

void selectionSort(vector<Data>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].name < arr[min_idx].name) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void printArray(const vector<Data>& arr) {
    for (const auto& item : arr) {
        cout << item.name << " " << item.city << endl;
    }
}

int main() {
    vector<Data> arr = {
        {"Fahmi", "Jakarta"},
        {"Romi", "Solo"},
        {"Andri", "Jakarta"},
        {"Fadillah", "Banyuwangi"},
        {"Ruli", "Bandung"},
        {"Rudi", "Bali"},
        {"Dendi", "Purwokerto"},
        {"Zaki", "Madiun"}
    };

    cout << "Original Array:" << endl;
    printArray(arr);

    selectionSort(arr);

    cout << "\nSorted Array using Selection Sort:" << endl;
    printArray(arr);

    return 0;
}
