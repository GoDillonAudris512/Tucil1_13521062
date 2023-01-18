//  File: functions.cpp
//  Berisi kumpulan fungsi-fungsi untuk menyelesaikan Permainan Kartu 24 
//  dan yang akan digunakan pada file main.cpp

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int charToNum (string CC) {
//  Mengembalikan angka yang bersesuaian dengan A, 2-10, J, Q, K sesuai dengan input user
//  Mengembalikan -1 jika karakter tidak valid

//  KAMUS LOKAL

//  ALGORITMA
    if (CC == "A") {
        return 1;
    }
    else if (CC == "J") {
        return 11;
    }
    else if (CC == "Q") {
        return 12;
    }
    else if (CC == "K") {
        return 13;
    }
    else if (CC == "2") {
        return 2;
    }
    else if (CC == "3") {
        return 3;
    }
    else if (CC == "4") {
        return 4;
    }
    else if (CC == "5") {
        return 5;
    }
    else if (CC == "6") {
        return 6;
    }
    else if (CC == "7") {
        return 7;
    }
    else if (CC == "8") {
        return 8;
    }
    else if (CC == "9") {
        return 9;
    }
    else if (CC == "10") {
        return 10;
    }
    else {
        return -1;
    }
}

string numToChar (int num) {
//  Mengembalikan karakter yang bersesuaian dengan angka num

//  KAMUS LOKAL

//  ALGORITMA
    if (num == 13) {
        return "K";
    }
    else if (num == 12) {
        return "Q";
    }
    else if (num == 11) {
        return "J";
    }
    else if (num == 10){
        return "10";
    }
    else if (num == 9) {
        return "9";
    }
    else if (num == 8) {
        return "8";
    }
    else if (num == 7) {
        return "7";
    }
    else if (num == 6) {
        return "6";
    }
    else if (num == 5) {
        return "5";
    }
    else if (num == 4) {
        return "4";
    }
    else if (num == 3) {
        return "3";
    }
    else if (num == 2) {
        return "2";
    }
    else {
        return "A";
    }
}

string numToOperand (int num) {
//  Mengembalikan karakter operan yang bersesuaian dengan num
//  1 = +
//  2 = -
//  3 = *
//  4 = /

//  KAMUS LOKAL

//  ALGORITMA
    if (num == 1) {
        return " + ";
    }
    else if (num == 2) {
        return " - ";
    }
    else if (num == 3) {
        return " * ";
    }
    else {
        return " / ";
    }
}

void inputNum (int arr[]) {
//  I.S Array arr berukuran 4 dan semua elemen bernilai 0
//  F.S Array arr akan terisi dengan angka-angka yang bersesuaian dengan karakter yang dimasukkan oleh user

//  KAMUS LOKAL
    string val;
    int temp;

//  ALGORITMA
    cout << "Mohon masukkan 4 angka atau huruf yang sesuai (A, 2-10, J, Q, K)\n";

    cout << "\nMohon masukkan angka atau huruf ke-1: ";
    while (arr[0] == 0) {
        cin >> val;
        temp = charToNum(val);
        if (temp == -1) {
            cout << "Input tidak valid\nMohon masukkan angka atau huruf ke-1: ";
        }
        else {
            arr[0] = temp;
        }
    }

    cout << "\nMohon masukkan angka atau huruf ke-2: ";
    while (arr[1] == 0) {
        cin >> val;
        temp = charToNum(val);
        if (temp == -1) {
            cout << "Input tidak valid\nMohon masukkan angka atau huruf ke-2: ";
        }
        else {
            arr[1] = temp;
        }
    }

    cout << "\nMohon masukkan angka atau huruf ke-3: ";
    while (arr[2] == 0) {
        cin >> val;
        temp = charToNum(val);
        if (temp == -1) {
            cout << "Input tidak valid\nMohon masukkan angka atau huruf ke-3: ";
        }
        else {
            arr[2] = temp;
        }
    }

    cout << "\nMohon masukkan angka atau huruf ke-4: ";
    while (arr[3] == 0) {
        cin >> val;
        temp = charToNum(val);
        if (temp == -1) {
            cout << "Input tidak valid\nMohon masukkan angka atau huruf ke-4: ";
        }
        else {
            arr[3] = temp;
        }
    }
}

float operation (float num1, int operand, float num2) {
//  Mengembalikan hasil operasi antara num1 dan num2 dengan operand yang sesuai

//  KAMUS LOKAL

//  ALGORITMA
    if (operand == 1) {
        return num1 + num2;
    }
    else if (operand == 2) {
        return num1 - num2;
    }
    else if (operand == 3) {
        return num1 * num2;
    }
    else {
        return num1 / num2;
    }
}

bool isIt24 (int tempArr[], int groupType, int operandArr[]) {
//  Mengembalikan true jika hasil operasi dengan susunan angka, operand, dan jenis grouping menghasilkan 24
//  Mengembalikan false jika hasil operasi tidak sama dengan 24

//  KAMUS LOKAL
    float result;

//  ALGORITMA
    if (groupType == 1) {
        result = operation(operation(tempArr[0], operandArr[0], tempArr[1]), operandArr[1], operation(tempArr[2], operandArr[2], tempArr[3]));
    }
    else if (groupType == 2) {
        result = operation(operation(operation(tempArr[0], operandArr[0], tempArr[1]), operandArr[1], tempArr[2]), operandArr[2], tempArr[3]);
    }
    else if (groupType == 3) {
        result = operation(operation(tempArr[0], operandArr[0], operation(tempArr[1], operandArr[1], tempArr[2])), operandArr[2], tempArr[3]);
    }
    else if (groupType == 4) {
        result = operation(tempArr[0], operandArr[0], operation(operation(tempArr[1], operandArr[1], tempArr[2]), operandArr[2], tempArr[3]));
    }
    else {
        result = operation(tempArr[0], operandArr[0], operation(tempArr[1], operandArr[1], operation(tempArr[2], operandArr[2], tempArr[3])));
    }

    return result == 24.0;
}

string solutionStringGenerator (int arr[], int groupType, int operandArr[]) {
//  Mengembalikan string berupa teks yang menjadi salah satu solusi untuk Permainan Kartu 24

//  KAMUS LOKAL
    string tempArr[4] = {numToChar(arr[0]), numToChar(arr[1]), numToChar(arr[2]), numToChar(arr[3])};
//  ALGORITMA
    if (groupType == 1) {
        return "(" + (tempArr[0]) + numToOperand(operandArr[0]) + (tempArr[1]) + ")" +
                numToOperand(operandArr[1]) +
                "(" + (tempArr[2]) + numToOperand(operandArr[2]) + (tempArr[3]) + ")";
    }
    else if (groupType == 2) {
        return "((" + (tempArr[0]) + numToOperand(operandArr[0]) + (tempArr[1]) + ")" +
                numToOperand(operandArr[1]) + (tempArr[2]) + ")" +
                numToOperand(operandArr[2]) + (tempArr[3]);
    }
    else if (groupType == 3) {
        return "(" + (tempArr[0]) + numToOperand(operandArr[0]) + "(" + 
                (tempArr[1]) + numToOperand(operandArr[1]) + (tempArr[2]) + "))" + 
                numToOperand(operandArr[2]) + (tempArr[3]);
    }
    else if (groupType == 4) {
        return (tempArr[0]) + numToOperand(operandArr[0]) + "((" + 
               (tempArr[1]) + numToOperand(operandArr[1]) + (tempArr[2]) + ")" + 
               numToOperand(operandArr[2]) + (tempArr[3]) + ")";
    }
    else {
        return (tempArr[0]) + numToOperand(operandArr[0]) + "(" + 
               (tempArr[1]) + numToOperand(operandArr[1]) + "(" +
               (tempArr[2]) + numToOperand(operandArr[2]) + (tempArr[3]) + "))";
    }
}

string solve24 (int arr[]) {
//  Mengembalikan string berisi semua solusi Permainan Kartu 24 dan banyaknya

//  KAMUS LOKAL
    int count = 0;
    string solutions;
    int tempArr[4], operandArr[3];

//  ALGORITMA
    cout << "\n==================================================\n\n";
    solutions = "Untuk susunan kartu: ";
    for (int i = 0; i <= 2; i++) {
        solutions += numToChar(arr[i]) + ", ";
    }
    solutions += numToChar(arr[3]);
    solutions += "\n\nSolusi Permainan Kartu 24: \n";

    auto start = high_resolution_clock::now();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                for (int k = 0; k < 4; k++) {
                    if (k != j && k != i) {
                        for (int l = 0; l < 4; l++) {
                            if (l != k && l != j && l != i) {
                                tempArr[0] = arr[i]; 
                                tempArr[1] = arr[j];
                                tempArr[2] = arr[k];
                                tempArr[3] = arr[l];

                                for (int groupType = 1; groupType < 6; groupType++) {
                                    for (int p = 1; p < 5; p++) {
                                        for (int q = 1; q < 5; q++) {
                                            for (int r = 1; r < 5; r++) {
                                                operandArr[0] = p;
                                                operandArr[1] = q;
                                                operandArr[2] = r;

                                                if (isIt24(tempArr, groupType, operandArr)) {
                                                    count++;
                                                    solutions += to_string(count) + ". " + solutionStringGenerator(tempArr, groupType, operandArr) + "\n";
                                                }
                                            }
                                        }    
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop-start);
    
    if (count == 0) {
        solutions += "Tidak ada solusi yang mungkin\n";
    }
    else {
        solutions += "\nBanyak solusi: " + to_string(count);
    }
    solutions += "\nWaktu eksekusi: " + to_string(duration.count()) + " mikrodetik";

    cout << solutions;
    cout << "\n\n==================================================\n";
    return solutions;
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
}