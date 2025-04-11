#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>
#include <iostream>
template <typename T>
class Matrix {
public:
    std::vector<std::vector<T>> matrix_vector;
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<T>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, T n);
    T get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
};
template class Matrix<int>;
template class Matrix<double>;
using namespace std;
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:
template <typename T>
Matrix<T>::Matrix(size_t N) {
    vector<T> row (N);
    matrix_vector = vector<vector<T>>(N, row);
}
template <typename T>
Matrix<T>::Matrix(vector<vector<T>> nums){
    matrix_vector = nums;
}

// e.g. for a member function:
template <typename T>
void Matrix<T>::print_matrix() const {
    int size = matrix_vector.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << (matrix_vector)[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &rhs) const {
    int size = matrix_vector.size();
    vector<vector<T>> matrix_return(size, vector<T>(size));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            T dot_prod = 0;
            for(int k = 0; k < size; k++){
                dot_prod += matrix_vector[i][k]*rhs.get_value(k, j);
            }
            matrix_return[i][j] = dot_prod;
        }
    }
    matrix_return.print_matrix();
    return matrix_return;
}
template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &rhs) const {
    int N = matrix_vector.size();
    vector<vector<T>> matrix_return(N, vector<T>(N));
    int size = matrix_vector.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            matrix_return[i][j] = (matrix_vector[i][j] + (rhs.get_value(i, j)));
        }
    }
    matrix_return.print_matrix();
    return matrix_return;
}
template <typename T>
void Matrix<T>::set_value(std::size_t i, std::size_t j, T n){
    std::size_t size = matrix_vector.size();
    if (i < size && j < size) {matrix_vector[i][j] = n;}
    print_matrix();
}
template <typename T>
T Matrix<T>::get_value(std::size_t i, std::size_t j) const {
    std::size_t size = matrix_vector.size();
    if (i < size && j < size) {return (matrix_vector)[i][j];}
    else{throw out_of_range("out_of_bounds");}
}
template <typename T>
int Matrix<T>::get_size() const{
    return matrix_vector.size();
}
template <typename T>
T Matrix<T>::sum_diagonal_major() const{
    T adder = 0; int size = matrix_vector.size();
    for(int i = 0; i < size; i++){
        adder += (matrix_vector)[i][i];
    }
    cout << adder << endl;
    return adder;
}
template <typename T>
T Matrix<T>::sum_diagonal_minor() const{
    T adder = 0; int size = matrix_vector.size();
    for(int i = 0; i < size; i++){
        adder += (matrix_vector)[i][size-i-1];
    }
    cout << adder << endl;
    return adder;
}
template <typename T>
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2){
    std::size_t size = matrix_vector.size();
    if (r1 < size && r2 < size) {
        vector<T> temp = matrix_vector[r1];
        matrix_vector[r1] = matrix_vector[r2];
        matrix_vector[r2] = temp;
    }
    print_matrix();
}
template <typename T>
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2){
    int size = matrix_vector.size();
    std::size_t sizet = matrix_vector.size();
    if (c1 < sizet && c2 < sizet) {
        vector<T> temp1 = {}; vector<T> temp2 = {};
        for(int i = 0; i < size; i++){
            temp1.push_back((matrix_vector)[i][c1]);
            temp2.push_back((matrix_vector)[i][c2]);
        }
        for(int j = 0; j < size; j++){
            (matrix_vector)[j][c1] = temp2[j];
            (matrix_vector)[j][c2] = temp1[j];
        }
    }
    print_matrix();
}
#endif // __MATRIX_HPP__
