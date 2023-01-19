//  File: io.cpp
//  Berisi kumpulan fungsi-fungsi untuk menyelesaikan permasalahan terkait input/output
//  dan yang akan digunakan pada file main.cpp

#include "converter.cpp"

#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int countWords (string input) {
//  Mengembalikan jumlah kata dalam suatu strings

//  KAMUS LOKAL
    int count = 0;
    bool inWord = false;

//  ALGORITMA
    for (char CC : input) {
        if (not(CC == ' ' || CC == '\n' || CC == '\0')) {
            inWord = true;
        }
        else if ((CC == ' ' || CC == '\n' || CC == '\0') && inWord) {
            count++;
            inWord = false;
        }
    }

    if (inWord) {
        count++;
        inWord = false;
    }

    return count;
}

string solve24mode () {
//  Menampilkan pilihan mode untuk memasukkan angka kepada pengguna (random atau input sendiri).
//  Mengembalikan pilihan mode yang dipilih (1-2)

//  KAMUS LOKAL
    string temp;
    bool valid = false;

//  ALGORITMA
    cout << "Selamat datang di 24 Solver. Silakan pilih mode yang anda inginkan: ";
    cout << "\n1. Input angka kartu oleh pengguna";
    cout << "\n2. Generate angka kartu secara random";

    while (!valid) {
        cout << "\nMasukkan pilihan mode (1-2): ";
        cin >> temp;
        if (temp == "1" || temp == "2") {
            valid = true;
        }
        else {
            cout << "Input tidak valid";
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return temp;
}

void inputNum (int arr[]) {
//  I.S Array arr berukuran 4 dan semua elemen bernilai 0
//  F.S Array arr akan terisi dengan angka-angka yang bersesuaian dengan karakter yang dimasukkan oleh user

//  KAMUS LOKAL
    string val;
    int temp, len;

//  ALGORITMA
    cout << "\n==================================================\n\n";
    cout << "Mohon masukkan 4 angka atau huruf yang sesuai (A, 2-10, J, Q, K)\n";

    while (arr[0] == 0) {
        cout << "\nMohon masukkan angka atau huruf ke-1: ";
        getline(cin, val);
        len = countWords(val);

        if (len == 0 || len > 1) {
            cout << "Input tidak valid";
        }
        else {
            temp = charToNum(val);
            if (temp == -1) {
                cout << "Input tidak valid";
            }
            else {
                arr[0] = temp;
            }
        }
    }

    while (arr[1] == 0) {
        cout << "\nMohon masukkan angka atau huruf ke-2: ";
        getline(cin, val);
        len = countWords(val);

        if (len == 0 || len > 1) {
            cout << "Input tidak valid";
        }
        else {
            temp = charToNum(val);
            if (temp == -1) {
                cout << "Input tidak valid";
            }
            else {
                arr[1] = temp;
            }
        }
    }

    while (arr[2] == 0) {
        cout << "\nMohon masukkan angka atau huruf ke-3: ";
        getline(cin, val);
        len = countWords(val);

        if (len == 0 || len > 1) {
            cout << "Input tidak valid";
        }
        else {
            temp = charToNum(val);
            if (temp == -1) {
                cout << "Input tidak valid";
            }
            else {
                arr[2] = temp;
            }
        }
    }

    while (arr[3] == 0) {
        cout << "\nMohon masukkan angka atau huruf ke-4: ";
        getline(cin, val);
        len = countWords(val);

        if (len == 0 || len > 1) {
            cout << "Input tidak valid";
        }
        else {
            temp = charToNum(val);
            if (temp == -1) {
                cout << "Input tidak valid";
            }
            else {
                arr[3] = temp;
            }
        }
    }
}

void generateNum (int arr[]) {
//  I.S Array arr berukuran empat dan semua nilainya 0
//  F.S Array arr terisi dengan angka 1 sampai 13 yang digenerate secara random

    srand((unsigned)time(0));
    for (int i = 0; i < 4; i++) {
        arr[i] = (rand() % 13) + 1;
    }
    
}

void saveOpt (string text) {
//  I.S solutions berisi solusi dari Permainan Kartu 24
//  F.S solutions akan disimpan pada suatu file atau tidak disimpan

//  KAMUS LOKAl
    string fileName, opt;
    bool valid = false;
    ofstream file;

//  ALGORITMA
    while (!valid) {
        cout << "\nApakah solusi ingin disimpan ke file (y/n) ? ";
        cin >> opt;
        valid = (opt == "y" or opt == "Y" or opt == "n" or opt == "N");
        if (!valid) {
            cout << "Input tidak valid";
        }
    }

    if (opt == "Y" or opt == "y") {
        valid = false;
        while (!valid) {
            cout << "\nMasukkan nama file: ";
            cin >> fileName;
            valid = (fileName != "");
            if (!valid) {
                cout << "Input tidak valid";
            }
        }

        fileName = "../test/" + fileName + ".txt";
        file.open(fileName);
        file << text;
        file.close();

        cout << "\nSolusi berhasil disimpan";
    }
    else {
        cout << "\nTerima kasih sudah menggunakan 24 Solver";
    }
}