//  File: main.cpp
//  Berisi kode untuk menjalankan program utama untuk menyelesaikan Permainan Kartu 24

#include "solver.cpp"
#include <iostream>
using namespace std;

int main() {
    int numArr[4] = {0,0,0,0};
    string pilihan;
    string solutions;

    pilihan = solve24mode();
    if (pilihan == "1") {
        inputNum(numArr);
    }
    else {
        generateNum(numArr);
    }
    
    solutions = solve24(numArr);
    saveOpt(solutions);
    return 0;
}