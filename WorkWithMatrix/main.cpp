#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
    Matrix * a = new Matrix(3, Matrix::IDENTITY);
    Matrix * b = a->mult(-1);

    a->show();
    b->show();

    Matrix * c = a->add(b);

    c->show();

    return 0;
}
