#include "cxxtest_ext.hpp"

#include <decorator/SimplePrinter.hpp>
#include <decorator/UnderlineDecorator.hpp>

class TestDecorator : public CxxTest::TestSuite
{
  public:
    void test_SimplePrinterWithUnderlineDecorator()
    {
      TCH;
      decorator::SimplePrinter * simple =
          new decorator::SimplePrinter();

      decorator::UnderlineDecorator * decorated =
          new decorator::UnderlineDecorator( simple );
      
      decorated->print( "Message from the Mars." );
      // will produce:
      // Message from the Mars.
      // ======================
      delete decorated;
      delete simple;
    }
};
