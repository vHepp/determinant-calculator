#include "determinant.hpp"
#include <fstream>

int main(){

    Determinant A;

    int det = A.findDeterminant().getNum();

    cout << "\ndet(A) = " << det << "\n\n";
    return 0;
}