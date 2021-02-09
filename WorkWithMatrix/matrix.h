#ifndef MATRIX_H
#define MATRIX_H
#include <utility>

class Matrix{
private:
    int height;
    int width;
    double ** matrix;
public:
    explicit Matrix(int height, int width);

    std::pair<int, int> getSize();

    double ** getMatrix();

    void init(double ** matrix);

    ~Matrix();
};

#endif // MATRIX_H
