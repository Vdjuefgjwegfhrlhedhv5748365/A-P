#pragma once
class Matrix
{
private:
    double** m_matrix;
    int m_rows;
    int m_colums;
public:
    //конструктор с одним параметром
    Matrix(int n);
    //конструктор, создающий матрицу размерами (m*n) и заполняющий ее нулями
    Matrix(int n, int m, double fillValue = 0);
    //конструктор копирования
    Matrix(const Matrix &other);
    //деструктор
    ~Matrix();

    double get(int i, int j) const;
    void set(int i, int j, double value);
    int getHeight() const{return m_rows;}
    int getWidth() const {return m_colums;}
    void negate();
    void addInPlace(Matrix &other);
    Matrix multiply(Matrix &other);
};



