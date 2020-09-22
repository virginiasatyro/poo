#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "matrix.h"

// ------------------------------------------------------------------- //

double Matrix::get(int row, int col) const {
    if (rows <= row || cols <= col) throw std::invalid_argument("Index out of bounds.");
    return matrix[row][col];
}