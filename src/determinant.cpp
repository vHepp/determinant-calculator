#include "determinant.hpp"

Determinant::Determinant() {

    string fileName = "test.txt";
    ifstream myFile(fileName);

    if (myFile.is_open()){
        cout << fileName << " is open.\n";
    }
    else {
        cout << "File is not open.\n";
        return;
    }

    myFile >> n;

    matrix = new Fraction*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new Fraction[n];

        for (int j = 0; j < n; j++) {
            int temp;
            myFile >> temp;
            matrix[i][j] = Fraction(temp);
        }
    }

    myFile.close();

    cout << "\nMatrix filled.\n";
    printMatrix();
}

Determinant::Determinant(int n) {
    this->n = n;
    matrix = new Fraction*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new Fraction[n];
    }
    
    cout << "Enter " << n*n << " fractions to fill the " 
         << n << "x" << n << " matrix:\n";

    Fraction temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            matrix[i][j] = temp;
        }
    }    

    cout << "\nMatrix filled.\n";
    printMatrix();
}

Determinant::~Determinant() { 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j].~Fraction();
        }
    }
}

void Determinant::Es(int r1, int r2) {
    if (r1 >= n || r1 < 0 || r2 >= n || r2 < 0 || r1 == r2) {
        throw domain_error("Invalid row choices.\n");
    }

    Fraction temp;
    for (int j = 0; j < n; j++) {
        temp = matrix[r1][j];
        matrix[r1][j] = matrix[r2][j];
        matrix[r2][j] = temp;
    }
    printMatrix();
}

void Determinant::Em(int r1, Fraction c) {
    if (r1 < 0 || r1 >= n) {
        throw domain_error("Invalid row choice.\n");
    }
    if (c == 0) {
        throw domain_error("Fraction c cannot equal 0.\n");
    }

    for (int j = 0; j < n; j++) {
        matrix[r1][j] =  matrix[r1][j] * c;
    }

    printMatrix();
}

void Determinant::Ema(int r1, int r2, Fraction c) {
    if (r1 >= n || r1 < 0 || r2 >= n || r2 < 0 || r1 == r2) {
        throw domain_error("Invalid row choices.\n");
    }
    if (c == 0) {
        throw domain_error("Fraction c cannot equal 0.\n");
    }

    for (int i = 0; i < n; i++) {
        matrix[r2][i] = matrix[r1][i] * c + matrix[r2][i];

    }

    printMatrix();
}

bool Determinant::upperTriangular() {

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != Fraction()){
                return false;
            }
        }
    }
    return true;
}

Fraction Determinant::findDeterminant() {
    Fraction det = 1;

    int currentGoodRow = -1;
    while(!upperTriangular()) { 
        int r1 = currentGoodRow + 1;

        //if [r][r] = 1
        if (matrix[r1][r1] == Fraction(1,1)) {
            for (int r2 = r1 + 1; r2 < n; r2++) {
                if (matrix[r2][r1] != Fraction(0,1)) {
                    Ema(r1,r2,matrix[r2][r1] * -1);
                }
            }
            currentGoodRow++;
        }

        //if [r][r] != 1 and != 0
        if (matrix[r1][r1] != Fraction(1,1) && matrix[r1][r1] != Fraction(0,1)) {
            det = det * matrix[r1][r1]; //note: reciprocal of the reciprocal
            Em(r1,matrix[r1][r1].reciprocal());
            
            for (int r2 = r1 + 1; r2 < n; r2++) {
                if (matrix[r2][r1] != Fraction(0,1)) {
                    Ema(r1,r2,matrix[r2][r1] * -1);
                }
            }
            currentGoodRow++;
        }

        //if [r][r] == 0
        else if (matrix[r1][r1] == Fraction(0,1)) {
            int r2 = findGoodRow(r1);

            Es(r1,r2);
            det = det * -1;
        }
    }

    for (int i = 0; i < n; i++) {
        det = det * matrix[i][i];
    }

    return det;
}

int Determinant::findGoodRow(int r1) {
    for (int r2 = r1 + 1; r2 < n; r2++) {
        if (matrix[r2][r1] != Fraction(0,1)) {
            return r2;
        }
    }
    throw domain_error("No good row for Es");
}

void Determinant::printMatrix() {
    for (int i = 0; i < n*7; i++) {
        cout << '-';
    }

    cout << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << '\n';
    }

}
