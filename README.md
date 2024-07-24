# UAS Struktur Data dan Algoritma PJJ Informatika Unsia

Nama : Rijal Asepnugroho

NIM : 210401010129

## 1. Mengurutkan Data dalam C++

Data awal sebelum diurutkan :

| Nama     | Alamat     |
| -------- | ---------- |
| Fahmi    | Jakarta    |
| Romi     | Solo       |
| Andri    | Jakarta    |
| Fadillah | Banyuwangi |
| Ruli     | Bandung    |
| Rudi     | Bali       |
| Dendi    | Purwokerto |
| Zaki     | Madiun     |

Hasil akhir setelah data diurutkan

| Nama     | Alamat     |
| -------- | ---------- |
| Andri    | Jakarta    |
| Dendi    | Purwokerto |
| Fadillah | Banyuwangi |
| Fahmi    | Jakarta    |
| Romi     | Solo       |
| Rudi     | Bali       |
| Ruli     | Bandung    |
| Zaki     | Madiun     |

### 1.1 Bubble Sort

Kita akan mengimplementasikan algoritma Bubble Sort untuk mengurutkan data dalam C++. Contoh ini menggunakan struktur Data yang berisi nama dan kota, dan mengurutkan berdasarkan nama.

#### 1.1.1 Struktur Data

Kita mulai dengan mendefinisikan struktur `Data` yang berisi dua atribut: `name` dan `city`.

```cpp
struct Data {
    string name;
    string city;
};
```

#### 1.1.2. Fungsi Bubble Sort

Berikut adalah fungsi `bubbleSort` yang mengurutkan vektor `Data` berdasarkan `name` menggunakan algoritma Bubble Sort.

```cpp
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
```

**Penjelasan**
- **Looping Luar**: Loop `for` pertama berjalan dari indeks `0` hingga `n-2`. Ini karena pada setiap iterasi, elemen terbesar "mengambang" ke posisi akhirnya.
- **Looping Dalam**: Loop `for` kedua berjalan dari indeks `0` hingga `n-i-2`. Ini karena elemen terbesar sudah berada di posisi akhir pada setiap iterasi luar.
- **Kondisi Swap**: Jika elemen saat ini (`arr[j].name`) lebih besar dari elemen berikutnya (`arr[j + 1].name`), maka kita tukar kedua elemen tersebut.

#### 1.1.3. Fungsi Print Array

Fungsi `printArray` digunakan untuk mencetak elemen-elemen dalam vektor `Data`.

```cpp
void printArray(const vector<Data>& arr) {
    for (const auto& item : arr) {
        cout << item.name << " " << item.city << endl;
    }
}
```

**Penjelasan**
- Loop `for` digunakan untuk iterasi setiap elemen dalam vektor `Data`.
- Setiap elemen dicetak dalam format `name city`.

#### 1.1.4. Fungsi `main`

Berikut adalah fungsi `main` yang menginisialisasi vektor `Data`, mencetak array asli, mengurutkannya menggunakan `bubbleSort`, dan mencetak array yang sudah diurutkan.

```cpp
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
```

**Penjelasan**
- **Inisialisasi Vektor**: Vektor `arr` diinisialisasi dengan beberapa elemen `Data`.
- **Cetak Array Asli**: Fungsi `printArray` digunakan untuk mencetak array asli.
- **Urutkan dengan Bubble Sort**: Fungsi `bubbleSort` dipanggil untuk mengurutkan array.
- **Cetak Array yang Diurutkan**: Fungsi `printArray` digunakan kembali untuk mencetak array yang sudah diurutkan.

Gabungkan seluruh potongan kode di atas dalam 1 file bernama `01-bubble-sort.cpp`. Keseluruhan kode adalah sebagai berikut:

```cpp
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
```

#### 1.1.5. Build

Untuk mem-build kode di atas menjadi file binary yang bisa diexecute, buka terminal dan lakukan perintah berikut :

```console
g++ 01-bubble-sort.cpp -o bubble-sort -std=c++11
```

Perintah di atas akan menghasilkan file binary bernama bubble-sort.

#### 1.1.6. Output Program

Masih di terminal, jalankan program dengan cara berikut :

```console
./bubble-sort
```

Ketika program dijalankan, outputnya adalah sebagai berikut:

```console
Original Array:
Fahmi Jakarta
Romi Solo
Andri Jakarta
Fadillah Banyuwangi
Ruli Bandung
Rudi Bali
Dendi Purwokerto
Zaki Madiun

Sorted Array using Bubble Sort:
Andri Jakarta
Dendi Purwokerto
Fadillah Banyuwangi
Fahmi Jakarta
Romi Solo
Rudi Bali
Ruli Bandung
Zaki Madiun
```

![Output Bubble Sort](./output-bubble-sort.png?raw=true)

### 1.2 Selection Sort

Selanjutnya kita akan mengimplementasikan algoritma Selection Sort untuk mengurutkan data dalam C++. Contoh ini menggunakan struktur Data dan kode yang sama dengan Sub bab 1.1 Bubble Sort. Hanya saja kita akan membuat fungsi `selectionSort` untuk menggantikan fungsi `bubbleSort`. Perubahan juga dilkaukan di fungsi `main` untuk memanggil fungsi `selectionSort` saat mengurutkan data.

#### 1.2.1. Fungsi Selection Sort

Berikut adalah fungsi `selectionSort` yang mengurutkan vektor `Data` berdasarkan `name` menggunakan algoritma Selection Sort.

```cpp
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
```

**Penjelasan**
- **Looping Luar**: Loop `for` pertama berjalan dari indeks `0` hingga `n-2`. Setiap iterasi memilih elemen terkecil dari elemen yang tersisa dan menukarnya dengan elemen pada indeks `i`.
- **Looping Dalam**: Loop `for` kedua berjalan dari indeks `i+1` hingga `n-1` untuk mencari elemen terkecil dalam subarray yang tersisa.
- **Kondisi Swap**: Jika elemen saat ini (`arr[j].name`) lebih kecil dari elemen minimum (`arr[min_idx].name`), maka indeks minimum diperbarui. Setelah menemukan elemen terkecil, elemen tersebut ditukar dengan elemen pada indeks `i`.

#### 1.2.2. Fungsi `main`

Berikut adalah fungsi `main` yang menginisialisasi vektor `Data`, mencetak array asli, mengurutkannya menggunakan `selectionSort`, dan mencetak array yang sudah diurutkan.

```cpp
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
```

**Penjelasan**
- **Inisialisasi Vektor**: Vektor `arr` diinisialisasi dengan beberapa elemen Data.
- **Cetak Array Asli**: Fungsi `printArray` digunakan untuk mencetak array asli.
- **Urutkan dengan Selection Sort**: Fungsi `selectionSort` dipanggil untuk mengurutkan array.
- **Cetak Array yang Diurutkan**: Fungsi `printArray` digunakan kembali untuk mencetak array yang sudah diurutkan.

Kita akan menggabungkan seluruh kode menjadi 1 file bernama `01-selection-sort.cpp`.

```cpp
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
```

#### 1.2.3. Build

Untuk mem-build kode di atas menjadi file binary yang bisa diexecute, buka terminal dan lakukan perintah berikut :

```console
g++ 01-selection-sort.cpp -o selection-sort -std=c++11
```

Perintah di atas akan menghasilkan file binary bernama selection-sort.

#### 1.2.4. Output Program

Masih di terminal, jalankan program dengan cara berikut :

```console
./selection-sort
```

Ketika program dijalankan, outputnya adalah sebagai berikut:

```console
Original Array:
Fahmi Jakarta
Romi Solo
Andri Jakarta
Fadillah Banyuwangi
Ruli Bandung
Rudi Bali
Dendi Purwokerto
Zaki Madiun

Sorted Array using Selection Sort:
Andri Jakarta
Dendi Purwokerto
Fadillah Banyuwangi
Fahmi Jakarta
Romi Solo
Rudi Bali
Ruli Bandung
Zaki Madiun
```

![Output Selection Sort](./output-selection-sort.png?raw=true)

### 1.3. Kesimpulan

Kita telah menggunakan algoritma Bubble Sort dan Selection Sort untuk mengurutkan data dalam C++. Kedua algoritma ini efektif untuk memahami konsep dasar pengurutan meskipun dalam praktik sering digunakan algoritma yang lebih efisien seperti Quick Sort atau Merge Sort.

## 2. Mencari Data dalam Array Menggunakan Binary Search dalam C++

Array : 19, 40, 10, 90, 2, 50, 60, 50, 1

Test Case Skenario : 
- Input : 1
Output : Angka 1 ada di indeks ke 9
- Input : 50
Output : Angka 50 ada di indeks ke 6 dan 8
- Input : 100
Output : Angka 100 tidak ada dalam array

Kita akan mengimplementasikan pencarian data dalam sebuah kumpulan array menggunakan algoritma Binary Search. Kita juga akan mencari semua indeks kemunculan elemen dalam array asli yang belum diurutkan.

### 2.1. Fungsi Print Array

Fungsi `printArray` digunakan untuk mencetak elemen-elemen dalam vektor `int`.

```cpp
void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
```

**Penjelasan**
- Loop `for` digunakan untuk iterasi setiap elemen dalam vektor `int`.
- Setiap elemen dicetak diikuti oleh spasi.
- Setelah mencetak semua elemen, `endl` digunakan untuk pindah ke baris baru.

### 2.2. Fungsi Binary Search All

Berikut adalah fungsi `binarySearchAll` yang mencari semua kemunculan elemen target dalam array yang sudah diurutkan dan mengembalikan indeks asli dari elemen-elemen tersebut.

```cpp
vector<int> binarySearchAll(const vector<int>& sortedArr, const vector<int>& originalArr, int target) {
    vector<int> indices;
    int left = 0;
    int right = sortedArr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedArr[mid] == target) {
            indices.push_back(mid);

            int leftSide = mid - 1;
            while (leftSide >= 0 && sortedArr[leftSide] == target) {
                indices.push_back(leftSide);
                leftSide--;
            }

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

    vector<int> originalIndices;
    unordered_map<int, int> seen;
    for (int idx : indices) {
        for (size_t i = 0; i < originalArr.size(); ++i) {
            if (originalArr[i] == sortedArr[idx]) {
                if (seen[i] == 0) {
                    originalIndices.push_back(i + 1);
                    seen[i] = 1;
                }
            }
        }
    }

    sort(originalIndices.begin(), originalIndices.end());
    return originalIndices;
}
```

**Penjelasan**
- Inisialisasi Variabel: `indices` untuk menyimpan indeks kemunculan elemen `target` dalam array yang sudah diurutkan. `left` dan `right` digunakan untuk menentukan batas pencarian.
- Binary Search: Loop `while` digunakan untuk mencari `target` dengan membagi array menjadi dua bagian. Jika elemen tengah (`mid`) adalah `target`, kita mencari semua kemunculan `target` di kiri dan kanan `mid`.
- Konversi Indeks: Menggunakan `unordered_map<int, int> seen` untuk melacak kemunculan elemen dalam array asli dan mengonversi indeks yang ditemukan dari array yang diurutkan ke indeks asli.
- Mengurutkan Indeks: Indeks asli diurutkan dan dikembalikan.

### 2.3. Fungsi `main`

Berikut adalah fungsi `main` yang menginisialisasi array, mencetak array asli dan array yang sudah diurutkan, serta meminta input dari pengguna untuk mencari elemen dalam array.

```cpp
int main() {
    vector<int> originalArr = {19, 40, 10, 90, 2, 50, 60, 50, 1};
    vector<int> sortedArr = originalArr;

    cout << "Original Array:" << endl;
    printArray(originalArr);

    sort(sortedArr.begin(), sortedArr.end());

    cout << "\nSorted Array:" << endl;
    printArray(sortedArr);

    string choice;
    do {
        cout << "\nEnter the number to search (or 'q' to quit): ";
        cin >> choice;

        if (choice == "q") {
            break;
        }

        stringstream ss(choice);
        int target;
        if (ss >> target) {
            vector<int> result = binarySearchAll(sortedArr, originalArr, target);

            if (!result.empty()) {
                cout << "Angka " << target << " ada di indeks ke ";
                for (size_t i = 0; i < result.size(); i++) {
                    cout << result[i];
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
```

**Penjelasan**
- Inisialisasi Array: `originalArr` diinisialisasi dengan beberapa elemen `int`, dan `sortedArr` adalah salinan dari `originalArr`.
- Cetak Array Asli: Fungsi `printArray` digunakan untuk mencetak array asli.
- Urutkan Array: `sort` digunakan untuk mengurutkan `sortedArr`.
- Cetak Array yang Diurutkan: Fungsi `printArray` digunakan kembali untuk mencetak array yang sudah diurutkan.
- Input dari Pengguna: Loop `do-while` digunakan untuk meminta input dari pengguna untuk mencari elemen dalam array. Jika input adalah 'q', program berhenti. Jika input valid, `binarySearchAll` dipanggil untuk mencari semua kemunculan elemen `target` dan mencetak hasilnya.

Gabungkan semua kode di atas, simpan dengan nama `02-binary-search.cpp`.

```cpp
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

```

### 2.4. Build dan Output Program

Untuk mem-build kode di atas menjadi file binary yang bisa diexecute, buka terminal dan lakukan perintah berikut :

```console
g++ 02-binary-search.cpp -o binary-search -std=c++11
```

Perintah di atas akan menghasilkan file binary bernama binary-search. Masih di terminal, jalankan program dengan cara berikut :

```console
./binary-search
```

Ketika program dijalankan, outputnya adalah sebagai berikut:

```console
Original Array:
19 40 10 90 2 50 60 50 1 

Sorted Array:
1 2 10 19 40 50 50 60 90 

Enter the number to search (or 'q' to quit): 1
Angka 1 ada di indeks ke 9

Enter the number to search (or 'q' to quit): 50
Angka 50 ada di indeks ke 6 dan 8

Enter the number to search (or 'q' to quit): 100
Angka 100 tidak ada dalam array

Enter the number to search (or 'q' to quit): q
```

![Output Binary Search](./output-binary-search.png?raw=true)

### 2.5. Kesimpulan

Kita telah mempelajari cara mengimplementasikan algoritma Binary Search untuk mencari semua kemunculan elemen dalam array yang sudah diurutkan, serta mengonversi indeks yang ditemukan ke indeks asli dalam array yang belum diurutkan. Algoritma ini efektif untuk pencarian elemen dalam array dengan waktu pencarian yang lebih cepat dibandingkan pencarian linier pada umumnya.