//
// for comparison with expr templates
//

#include <iostream>
#include <algorithm>

typedef double MatrixDataType;

class Matrix
{
  public:
    Matrix(int row = 100, int col = 10): m_rows(row), m_cols(col), data(new MatrixDataType[row * col])
    {
      std::fill(&data[0], &data[row * col], MatrixDataType());
    }
    Matrix(const Matrix& oth): m_rows(oth.m_rows), m_cols(oth.m_cols), data(new MatrixDataType[m_rows * m_cols])
    {
      std::copy(&oth.data[0], &oth.data[m_rows * m_cols], &data[0]);
    }
    ~Matrix()
    {
      delete[] data;
    }
    MatrixDataType& operator()(int row, int col)
    {
      return data[row * m_cols + col];
    }
    MatrixDataType operator()(int row, int col) const
    {
      return data[row * m_cols + col];
    }
    Matrix& operator=(const Matrix& oth)
    {
      std::copy(&oth.data[0], &oth.data[m_rows * m_cols], &data[0]);
      return *this;
    }

    const int m_rows;
    const int m_cols;

    MatrixDataType* data;
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
  Matrix res(lhs.m_rows, lhs.m_cols);
  for (int i(0); i < res.m_rows * res.m_cols; ++i)
  {
    res.data[i] = lhs.data[i] + rhs.data[i];
  }
  return res;
}

void PrintMatrix(const Matrix& m, const char name[] = "nincs")
{
  std::cout << name << '\n';
  for (int row(0); row < m.m_rows; ++row)
  {
    for (int col(0); col < m.m_cols; ++col)
    {
      std::cout << m(row, col) << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

int main()
{
  Matrix arr[16];
  for (int i(0); i<16; ++i)
  {
    arr[i].data[i] = 1;
  }
  Matrix res;
  for (int i(0); i<10000; ++i)
  {
    res = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] + arr[7] + arr[8] + arr[9] + arr[10] + arr[11] + arr[12] + arr[13] + arr[14] + arr[15];
  }
  PrintMatrix(res, "grand result");
}

