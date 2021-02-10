#include "matrix.h"
#include <iostream>

void Matrix::createZeroMatrix(int height, int width) {
    Matrix::height = height;
    Matrix::width = width;

    matrix = new double * [height];
    matrix[0] = new double[height * width];

    for (int i = 1; i < height; i++) {
        matrix[i] = matrix[i - 1] + width;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int height, int width) {
    createZeroMatrix(height, width);
}

Matrix::Matrix(int sz, Type type) {
    Matrix::height = sz;
    Matrix::width = sz;

    createZeroMatrix(Matrix::height, Matrix::width);

    switch (type) {
        case IDENTITY:
            for (int i = 0; i < height; i++) {
                Matrix::matrix[i][i] = 1;
            }

            break;
        default:
            std::cout << "wrong type\n"
                    << "available types: 'IDENTITY'";
            break;
    }
}

void Matrix::init(double ** matrix) {
    for (int i = 0; i < Matrix::height; i++) {
        for (int j = 0; j < Matrix::width; j++) {
            Matrix::matrix[i][j] = matrix[i][j];
        }
    }
}

std::pair<int, int> Matrix::getSize() {
    std::pair<int, int> p = std::make_pair(Matrix::height, Matrix::width);

    return p;
}

double ** Matrix::getMatrix() {
    double ** copyMatrix = new double * [Matrix::height];
    copyMatrix[0] = new double[Matrix::height * Matrix::width];

    for (int i = 1; i < Matrix::height; i++) {
        copyMatrix[i] = copyMatrix[i - 1] + Matrix::width;
    }

    for (int i = 0; i < Matrix::height; i++) {
        for (int j = 0; j < Matrix::width; j++) {
            copyMatrix[i][j] = Matrix::matrix[i][j];
        }
    }

    return copyMatrix;
}

Matrix * Matrix::add(Matrix * b) {
    try {
        if (Matrix::height == b->getHeigth() && Matrix::width == b->getWidth()) {
            Matrix * c = new Matrix(Matrix::height, Matrix::width);

            for (int i = 0; i < Matrix::height; i++) {
                for (int j = 0; j < Matrix::width; j++) {
                    c->setItem(i, j, Matrix::matrix[i][j] + b->getItem(i, j));
                }
            }

            return c;
        } else {
            throw -1;
        }
    } catch (int a) {
        std::cout << "Not correct size matrices\n";
    }
}

Matrix * Matrix::mult(double alpha) {
    Matrix * b = new Matrix(Matrix::getHeigth(), Matrix::getWidth());
    b->init(Matrix::matrix);

    for (int i = 0; i < Matrix::height; i++) {
        for (int j = 0; j < Matrix::width; j++) {
            b->setItem(i, j, matrix[i][j] * alpha);
        }
    }

    return b;
}

Matrix * Matrix::mult(Matrix * b) {
    try {
        if (Matrix::width == b->getHeigth()) {
            Matrix * c = new Matrix(Matrix::height, b->getWidth());

            for (int i = 0; i < c->getHeigth(); i++) {
                for (int j = 0; j < c->getWidth(); j++) {
                    double sum = 0;

                    for (int k = 0; k < Matrix::width; k++) {
                        sum += Matrix::matrix[i][k] * b->getItem(k, j);
                    }

                    sum = sum > Matrix::EPS ? sum : 0;
                    c->setItem(i, j, sum);
                }
            }

            return c;
        } else {
            throw -1;
        }
    } catch(int a) {
        std::cout << "Not correct size matrices";
    }
}

Matrix * Matrix::T() {
    Matrix * b = new Matrix(Matrix::getWidth(), Matrix::getHeigth());

    for (int i = 0; i < Matrix::height; i++) {
        for (int j = 0; j < Matrix::width; j++) {
            b->setItem(j, i, Matrix::matrix[i][j]);
        }
    }

    return b;
}

void Matrix::show() {
    std::cout << '\n';

    for (int i = 0; i < Matrix::height; i++) {
        for (int j = 0; j < Matrix::width; j++) {
            std::cout << getItem(i, j) << " ";
        }

        std::cout << '\n';
    }
}
