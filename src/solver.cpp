//  File: solver.cpp
//  Berisi kumpulan fungsi-fungsi untuk menyelesaikan Permainan Kartu 24 
//  dan yang akan digunakan pada file main.cpp

#include "io.cpp"

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool isAlreadyPermute (int mat[][4], int arr[], int neff) {
//  Mengembalikan true jika arr merupakan salah satu elemen array pada mat
//  Mengembalikan false jika tidak

//  KAMUS LOKAL
    bool thereIs = false;
    int i = 0;

//  ALGORITMA
    while (i < neff && !thereIs) {
        if (mat[i][0] == arr[0] && mat[i][1] == arr[1] && mat[i][2] == arr[2] && mat[i][3] == arr[3]) {
            thereIs = true;
        }
        else {
            i++;
        }
    }

    return thereIs;
}

void addElement (int mat[][4], int arr[], int neff) {
//  I.S mat, arr, dan neff terdefinisi
//  F.S Menambahkan arr sebagai salah satu elemen mat

//  KAMUS LOKAL

//  ALGORITMA
    for (int i = 0; i < 4; i++) {
        mat[neff][i] = arr[i];
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
    int count = 0, neff = 0;
    string solutions;
    int tempArr[4], operandArr[3];
    int matArr[24][4];

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
                                
                                if (!isAlreadyPermute(matArr, tempArr, neff)) {
                                    addElement(matArr, tempArr, neff);
                                    neff++;
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