//
// demo of expression templates
//

#include <algorithm>
#include <iostream>

typedef double MatrixDataType;

#ifdef EXPRESSION
struct Addition
{
  inline static MatrixDataType execute(MatrixDataType l, MatrixDataType r)
  {
    return l + r;
  }
};

template <class Lhs, class Op, class Rhs>
struct Expression
{
  Expression(const Lhs& lhs, const Rhs& rhs): lhs(lhs), rhs(rhs)
  {}
  const Lhs& lhs;
  const Rhs& rhs;

  MatrixDataType operator()(int row, int col) const
  {
    return Op::execute(lhs(row, col), rhs(row, col));
  }
};
#endif

class Matrix
{
  public:
    Matrix(int row = 100, int col = 100): m_rows(row), m_cols(col), data(new MatrixDataType[row * col])
    {
      NewMatrix();
      std::fill(&data[0], &data[row * col], MatrixDataType());
    }
    Matrix(const Matrix& oth): m_rows(oth.m_rows), m_cols(oth.m_cols), data(new MatrixDataType[m_rows * m_cols])
    {
      NewMatrix();
      std::copy(&oth.data[0], &oth.data[m_rows * m_cols], &data[0]);
    }
    ~Matrix()
    {
      KillMatrix();
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
#ifdef EXPRESSION
    template <class Lhs, class Op, class Rhs>
    Matrix& operator=(const Expression<Lhs, Op, Rhs>& expr)
    {
      for (int i(0); i < m_rows * m_cols; ++i)
      {
        data[i] = expr(i / m_cols, i % m_cols);
      }
      return *this;
    }
#else
    Matrix& operator=(const Matrix& oth)
    {
      std::copy(&oth.data[0], &oth.data[m_rows * m_cols], &data[0]);
      return *this;
    }
#endif

    static void NewMatrix()
    {
      MaxMatrix = std::max(++NumOfMatrix, MaxMatrix);
    }
    static void KillMatrix()
    {
      --NumOfMatrix;
    }
    static int NumOfMatrix;
    static int MaxMatrix;

    const int m_rows;
    const int m_cols;

    MatrixDataType* data;
};

int Matrix::NumOfMatrix = 0;
int Matrix::MaxMatrix = 0;

#ifdef EXPRESSION
template <class Lhs>
Expression<Lhs, Addition, Matrix> operator+(const Lhs& lhs, const Matrix& rhs)
{
  return Expression<Lhs, Addition, Matrix>(lhs, rhs);
}
#else
Matrix operator+(const Matrix& lhs, const Matrix& rhs)
{
  Matrix res(lhs.m_rows, lhs.m_cols);
  for (int i(0); i < res.m_rows * res.m_cols; ++i)
  {
    res.data[i] = lhs.data[i] + rhs.data[i];
  }
  return res;
}
#endif

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
  const int MatrixNum = 32;
  Matrix arr[MatrixNum];
  for (int i(0); i < MatrixNum; ++i)
    arr[i].data[i] = 1;
  Matrix res;
  for (int i(0); i<10000; ++i)
  {
    res = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] + arr[7] + arr[8] + arr[9] + arr[10] + arr[11] + arr[12] + arr[13] + arr[14] + arr[15] + arr[16 + 0] + arr[16 + 1] + arr[16 + 2] + arr[16 + 3] + arr[16 + 4] + arr[16 + 5] + arr[16 + 6] + arr[16 + 7] + arr[16 + 8] + arr[16 + 9] + arr[16 + 10] + arr[16 + 11] + arr[16 + 12] + arr[16 + 13] + arr[16 + 14] + arr[16 + 15];
  }
  std::cerr << "max instances at the same time: " << Matrix::MaxMatrix << '\n';
  PrintMatrix(res, "grand result");
}

