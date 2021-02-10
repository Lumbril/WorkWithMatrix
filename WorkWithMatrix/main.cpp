#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
    Matrix * a = new Matrix(4, 2);
    Matrix * b = a->T();

    b->show();

    Matrix * c = new Matrix(3, Matrix::IDENTITY);

    c->show();

    Matrix * d = c->mult(2);
    d->show();

    return 0;
}
