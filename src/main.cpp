//  File: main.cpp
//  Berisi kode untuk menjalankan program utama untuk menyelesaikan Permainan Kartu 24

#include "functions.cpp"
#include <iostream>
using namespace std;

int main() {
    int numArr[4] = {0,0,0,0};
    string solutions;

    inputNum(numArr);
    solutions = solve24(numArr);
    saveOpt(solutions);
    return 0;
}