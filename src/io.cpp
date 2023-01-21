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

bool getNum(int arr[], string input) {
//  Mengembalikan true jika fungsi berhasil mengisi arr dengan angka yang ada pada input
//  Mengembalikan false jika tidak 

//  KAMUS LOKAL
    int count = 0;
    string temp = "";
    bool done = true, inWord = false;

//  ALGORITMA
    for (char CC : input) {
        if (not(CC == ' ' || CC == '\n' || CC == '\0')) {
            temp += CC;
            inWord = true;
        }
        else if ((CC == ' ' || CC == '\n' || CC == '\0') && inWord) {
            if (charToNum(temp) != -1) {
                arr[count] = charToNum(temp);
                count++;
                temp = "";
                inWord = false;
            }
            else {
                done = false;
                inWord = false;
                break;
            }
        }
    }

    if (inWord) {
        if (charToNum(temp) != -1) {
                arr[count] = charToNum(temp);
                count++;
                temp = "";
                inWord = false;
            }
            else {
                done = false;
                inWord = false;
            }
    }

    return done;
}

string solve24mode () {
//  Menampilkan pilihan mode untuk memasukkan angka kepada pengguna (random atau input sendiri).
//  Mengembalikan pilihan mode yang dipilih (1-2)

//  KAMUS LOKAL
    int len;
    string temp;
    bool valid = false;

//  ALGORITMA
    cout << "==================================================\n";
    cout << "Selamat datang di 24 Solver. Silakan pilih mode yang anda inginkan: ";
    cout << "\n1. Input angka kartu oleh pengguna";
    cout << "\n2. Generate angka kartu secara random";

    while (!valid) {
        cout << "\nMasukkan pilihan mode (1-2): ";
        getline(cin, temp);
        len = countWords(temp);
        if (len == 1) {
            if (temp == "1" || temp == "2") {
                valid = true;
            }
            else {
                cout << "Input tidak valid";
            }
        }
        else {
            cout << "Input tidak valid";
        }
    }

    return temp;
}

void inputNum (int arr[]) {
//  I.S Array arr berukuran 4 dan semua elemen bernilai 0
//  F.S Array arr akan terisi dengan angka-angka yang bersesuaian dengan karakter yang dimasukkan oleh user

//  KAMUS LOKAL
    string val;
    int len;
    bool done = false;

//  ALGORITMA
    cout << "\n==================================================\n\n";
    cout << "Mohon masukkan 4 angka atau huruf yang sesuai (A, 2-10, J, Q, K)\n\n";

    while (!done) {
        cout << "Input: ";
        getline(cin, val);
        len = countWords(val);

        if (len != 4) {
            cout << "Input tidak valid\n";
        }
        else {
            done = getNum(arr, val);
            if (!done) {
                cout << "Input tidak valid\n";
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
    int len;
    string fileName, opt;
    bool valid = false;
    ofstream file;

//  ALGORITMA
    while (!valid) {
        cout << "\nApakah solusi ingin disimpan ke file (Y/n) ? ";
        getline(cin, opt);
        len = countWords(opt);
        if (len == 1) {
            valid = (opt == "y" or opt == "Y" or opt == "n" or opt == "N");
            if (!valid) {
                cout << "Input tidak valid";
            }
        }
        else {
            cout << "Input tidak valid";
        }
    }

    if (opt == "Y" or opt == "y") {
        valid = false;
        while (!valid) {
            cout << "\nMasukkan nama file: ";
            getline(cin, fileName);
            valid = (countWords(fileName) != 0);
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
    
    cout << "\nTerima kasih sudah menggunakan 24 Solver";
}