#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (const auto& row : matrix.data) {
            for (int val : row) {
                os << val << " ";
            }
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (auto& row : matrix.data) {
            for (int& val : row) {
                is >> val;
            }
        }
        return is;
    }
};

int main() {
    Matrix A(2, 2);
    Matrix B(2, 2);

    std::cout << "Enter values for Matrix A (2x2):" << std::endl;
    std::cin >> A;

    std::cout << "Enter values for Matrix B (2x2):" << std::endl;
    std::cin >> B;

    std::cout << "Matrix A + B:" << std::endl;
    std::cout << A + B << std::endl;

    std::cout << "Matrix A - B:" << std::endl;
    std::cout << A - B << std::endl;

    std::cout << "Matrix A * B:" << std::endl;
    std::cout << A * B << std::endl;

    return 0;
}
