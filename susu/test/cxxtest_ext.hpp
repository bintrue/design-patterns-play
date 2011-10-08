#ifndef CXXTEST_EXT_HPP_INC
#define CXXTEST_EXT_HPP_INC


#include <cxxtest/TestSuite.h>
#include <iostream>

#define TCH tc_header(__PRETTY_FUNCTION__, __LINE__)

std::string strip( const std::string & );


void tc_header( const std::string & funcName,
                int line )
{
  std::cout << "\n=== " << strip( funcName ) << " ===" << std::endl;
}


std::string
strip( const std::string & func ) 
{
  size_t pos = func.find( "test" );
  return func.substr( pos, func.length() - pos - 2 );
}
#endif
