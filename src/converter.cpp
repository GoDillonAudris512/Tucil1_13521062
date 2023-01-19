//  File: converter.cpp
//  Berisi kumpulan fungsi-fungsi antara untuk memudahkan konversi antara string, integer, dan operand

#include <iostream>
using namespace std;

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