#include <iostream>
#include <fstream>
#include <exception>
#include "fraction.hpp"

using namespace std;

class Determinant {
    public:
        Determinant();
        Determinant(int);
        ~Determinant();

        void Es(int r1, int r2);
        void Em(int r1, Fraction c);
        void Ema(int r1, int r2, Fraction c);

        bool upperTriangular();

        Fraction findDeterminant();
        int findGoodRow(int r1);
        void printMatrix();
    private:
        Fraction **matrix;
        int n;
};