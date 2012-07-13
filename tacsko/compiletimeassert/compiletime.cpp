#include <assert.h>
#include "ctassert.hpp"

int main()
{
  assert( sizeof( int ) > 10 ); // runtime assert...
  ctassert< 10 < sizeof( int ) > assert; // catch the problem at compile time
}

