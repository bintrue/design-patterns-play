//
// demo of expression templates
//

#include <algorithm>
#include <iostream>

typedef double MatrixDataType;

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
    template <class Lhs, class Op, class Rhs>
    Matrix& operator=(const Expression<Lhs, Op, Rhs>& expr)
    {
      for (int i(0); i < m_rows * m_cols; ++i)
      {
        data[i] = expr(i / m_cols, i % m_cols);
      }
      return *this;
    }

    const int m_rows;
    const int m_cols;

    MatrixDataType* data;
};

template <class Lhs>
Expression<Lhs, Addition, Matrix> operator+(const Lhs& lhs, const Matrix& rhs)
{
  return Expression<Lhs, Addition, Matrix>(lhs, rhs);
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
    arr[i].data[i] = 1;
  Matrix res;
  for (int i(0); i<10000; ++i)
  {
    res = arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] + arr[7] + arr[8] + arr[9] + arr[10] + arr[11] + arr[12] + arr[13] + arr[14] + arr[15];
  }
  PrintMatrix(res, "grand result");
}

