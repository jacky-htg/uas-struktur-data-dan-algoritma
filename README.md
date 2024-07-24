# UAS Struktur Data dan -Algoritma

## 1. Mengurutkan Data dengan Bubble Sort dalam C++

Kita akan mengimplementasikan algoritma Bubble Sort untuk mengurutkan data dalam C++. Contoh ini menggunakan struktur Data yang berisi nama dan kota, dan mengurutkan berdasarkan nama.

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

### 1.1 Struktur Data

Kita mulai dengan mendefinisikan struktur `Data` yang berisi dua atribut: `name` dan `city`.

```cpp
struct Data {
    string name;
    string city;
};
```

### 1.2. Fungsi Bubble Sort

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

### 1.3. Fungsi Print Array

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

### 1.4. Fungsi `main`

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

### 1.5. Build

Untuk mem-build kode di atas menjadi file binary yang bisa diexecute, buka terminal dan lakukan perintah berikut :

```console
g++ 01-bubble-sort.cpp -o bubble-sort -std=c++11
```

Perintah di atas akan menghasilkan file binary bernama bubble-sort.

### 1.6. Output Program

Masih di terminal, jalankan program dengan cara berikut :

```console
./bubble-sort
```

Ketika program dijalankan, outputnya adalah sebagai berikut:

```console
mathematica
Copy code
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

### 1.7. Kesimpulan

Kita telah mengimplementasikan algoritma Bubble Sort untuk mengurutkan data dalam C++. Algoritma ini berguna untuk memahami konsep dasar pengurutan meskipun dalam praktik sering digunakan algoritma yang lebih efisien seperti Quick Sort atau Merge Sort.