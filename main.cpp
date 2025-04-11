#include "matrix.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
template <typename T>
pair<vector<vector<T>>, vector<vector<T>>> readMatrixFromFile(int N, ifstream &file) {
    vector<vector<T>> firstMatrix(N, vector<T>(N));
    vector<vector<T>> secondMatrix(N, vector<T>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> firstMatrix[i][j];
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            file >> secondMatrix[i][j];
        }
    }
    file.close();
    return {firstMatrix, secondMatrix};
}

int main() {
    cout  << "File name por favor: ";
    string filename;
    cin >> filename;
    ifstream file(filename);
    string readLine;
    getline(file, readLine);
    int n = readLine[0] - '0';
    int type = readLine[2] - '0';
    if(type == 0){
        pair<vector<vector<int>>, vector<vector<int>>> matrix = readMatrixFromFile<int>(n, file);
        Matrix<int> bot(matrix.first);
        Matrix<int> tob(matrix.second);
        bot+tob;
        bot*tob;
        cout << "major Diagonal: ";
        bot.sum_diagonal_major();
        cout << "minor diagonal: ";
        bot.sum_diagonal_minor();
        bot.swap_cols(1, 2);
        bot.swap_rows(1, 2);
        bot.set_value(1, 1, 0);
        bot.print_matrix();
        return 0;
    }
    else if(type == 1){
        pair<vector<vector<double>>, vector<vector<double>>> matrix= readMatrixFromFile<double>(n, file);
        Matrix<double> bot(matrix.first);
        Matrix<double> tob(matrix.second);
        bot+tob;
        bot*tob;
        cout << "major Diagonal: ";
        bot.sum_diagonal_major();
        cout << "minor diagonal: ";
        bot.sum_diagonal_minor();
        bot.swap_cols(1, 2);
        bot.swap_rows(1, 2);
        bot.set_value(1, 1, 0);
        return 0;
    }
}

