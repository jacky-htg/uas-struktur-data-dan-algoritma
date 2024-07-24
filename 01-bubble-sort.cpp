// Nama : Rijal Asepnugroho
// NIM : 210401010129

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Data {
    string name;
    string city;
};

void bubbleSort(vector<Data>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].name > arr[j + 1].name) {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    bubbleSort(arr);

    cout << "\nSorted Array using Bubble Sort:" << endl;
    printArray(arr);

    return 0;
}
