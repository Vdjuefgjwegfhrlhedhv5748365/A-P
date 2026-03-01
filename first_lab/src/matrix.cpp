#include "matrix.hpp"
#include <iostream>
Matrix :: Matrix(int n)
{
    Matrix(n, n, 0);
}
Matrix::Matrix(int n, int m, double fillValue = 0)
{
    m_rows = n;
    m_colums = m;
    m_matrix = new double*[n];
    for (int i=0; i<n; i++){
        m_matrix[i] = new double[m];
    }

    for (int i=0; i<n;i++){
        for (int j=0; j<m; j++){
            m_matrix[i][j] = fillValue;
        }
    }
}

Matrix::Matrix(const Matrix &other)
{
    m_rows =other.m_rows;
    m_colums = other.m_colums;
    m_matrix = new double*[m_rows];
    for (int i=0; i<m_rows;i++){
        m_matrix[i] = new double[m_colums];
        for (int j=0; j<m_colums; j++){
            m_matrix[i][j] = other.m_matrix[i][j];
        }
    }
}

Matrix :: ~Matrix(){
    if (m_matrix){
        for (int i = 0; i < m_rows; i++){
            delete[] m_matrix[i];
        }
        delete[] m_matrix;
    }
}

double Matrix::get (int i, int j) const{
    if (i < 0 || i >= m_rows || j < 0 || j>= m_colums){
        throw std::out_of_range("Индексы матрицы за ее пределами");
    }
    return m_matrix[i][j];
}

void Matrix :: set(int i, int j, double value){
    if (i < 0 || i >= m_rows || j < 0 || j>= m_colums){
        throw std::out_of_range("Индексы матрицы не соответствуют ее пределам");
    }
    m_matrix[i][j] = value;
}

void Matrix :: negate(){
    for (int i=0; i<m_rows; i++){
        for (int j=0; j<m_colums; j++){
            m_matrix[i][j] *= -1;
        }
    }
}

void Matrix :: addInPlace(Matrix &other){
    if (m_rows != other.m_rows || m_colums != other.m_colums){
        throw std::invalid_argument("Матрицы не совпадают");
    }
    for (int i=0; i< m_rows; i++){
        for (int j=0; j<m_colums;j++){
            m_matrix[i][j] += other.m_matrix[i][j];
        }
    }
}

Matrix Matrix :: multiply(Matrix &other){
    if (m_colums != other.m_rows){
        throw std::invalid_argument("Колличество столбцов первой матрицы должно совпадать с колличеством столбцов второй матрицы");
    }
    Matrix result(m_rows, other.m_colums, 0.0);
    for (int i=0; i<m_rows; i++){
        for (int j=0; j<other.m_colums; j++){
            double sum = 0.0;
            for (int k=0; k<m_colums;k++){
                sum += m_matrix[i][k] * other.m_matrix[k][j];
            }
            result.m_matrix[i][j] = sum;
        }
    }
    return result;
}