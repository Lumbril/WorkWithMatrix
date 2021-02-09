#include "matrix.h"

Matrix::Matrix(int height, int width) {
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
