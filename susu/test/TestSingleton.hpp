
#include "cxxtest_ext.hpp"

#include <singleton/SingletonCallOnce.hpp>

class DummySingleton
    : public singleton::SingletonCallOnce<DummySingleton>
{
  public:
    int m_dummyVar;
};


class TestSingleton : public CxxTest::TestSuite
{
  public:
    void testSingleton()
    {
      TCH;
      DummySingleton::getInstance()->m_dummyVar = 10;

      TS_ASSERT_EQUALS( 10, DummySingleton::getInstance()->m_dummyVar );
    }
};


