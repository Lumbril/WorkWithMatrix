#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
    Matrix * a = new Matrix(4, 2);

    pair<int, int> sz = a->getSize();

    cout << sz.first << " " << sz.second << '\n';

    double ** copyMat = a->getMatrix();

    for (int i = 0; i < sz.first; i++) {
        for (int j = 0; j < sz.second; j++) {
            cout << copyMat[i][j] << ' ';
        }

        cout << '\n';
    }

    double ** initMat = new double * [sz.first];
    initMat[0] = new double[sz.first * sz.second];
    for (int i = 1; i < sz.first; i++) {
        initMat[i] = initMat[i - 1] + sz.second;
    }
    for (int i = 0; i < sz.first; i++) {
        for (int j = 0; j < sz.second; j++) {
            initMat[i][j] = i * 10 + j + 1;
        }
    }

    a->init(initMat);

    delete [] copyMat[0];
    delete [] copyMat;

    copyMat = a->getMatrix();

    for (int i = 0; i < sz.first; i++) {
        for (int j = 0; j < sz.second; j++) {
            cout << copyMat[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
