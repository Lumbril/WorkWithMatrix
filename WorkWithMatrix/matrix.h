#ifndef MATRIX_H
#define MATRIX_H
#include <utility>

class Matrix{
private:
    int height;
    int width;
    double ** matrix;

    void createZeroMatrix(int height, int width);
public:
    enum Type{
        IDENTITY
    };

    explicit Matrix(int height, int width);

    explicit Matrix(int sz, Type type);

    std::pair<int, int> getSize();

    double ** getMatrix();

    void setItem(int i, int j, double x) {
        Matrix::matrix[i][j] = x;
    }

    double getItem(int i, int j) {
        return Matrix::matrix[i][j];
    }

    int getHeigth() {
        return height;
    }

    int getWidth() {
        return width;
    }

    void init(double ** matrix);

    Matrix * mult(double alpha);

    Matrix * mult(Matrix * b);

    Matrix * T();

    void show();

    ~Matrix() {
        delete [] matrix[0];
        delete [] matrix;
    };
};

#endif // MATRIX_H
