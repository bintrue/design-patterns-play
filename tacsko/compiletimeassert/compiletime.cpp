#include <assert.h>
#include "ctassert.hpp"
#include "ctassert2.hpp"

int main()
{
  assert( sizeof( int ) > 10 ); // runtime assert...
  ctassert< 10 < sizeof( int ) > assert; // catch the problem at compile time
  CompileTimeAssert< 10 < sizeof( int ) > assert2; // catch the problem at compile time
}

