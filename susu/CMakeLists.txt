cmake_minimum_required( VERSION 2.8 )

project( DesignPatterns )

set( BOOST_LIBS thread )

## set up CFLAGS, warning := error and use 0x features
if (CMAKE_COMPILER_IS_GNUCXX)
  list( APPEND CMAKE_CXX_FLAGS "-Wall -Werror -std=c++0x -pthread" )
  #list( APPEND CMAKE_CXX_FLAGS "-Wall -Werror " )
endif()

find_package( Boost COMPONENTS ${BOOST_LIBS} REQUIRED )

find_package( CxxTest )

include_directories( ${CXXTEST_INCLUDE_DIR} )
enable_testing( )
CXXTEST_ADD_TEST( testSubject cxxtest_subject.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/TestSubject.hpp )
CXXTEST_ADD_TEST( testObserverPattern cxxtest_.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/TestObserverPattern.hpp )
CXXTEST_ADD_TEST( singletonCallOnce cxxtest_singleton_call_once.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/TestSingleton.hpp )
CXXTEST_ADD_TEST( singletonCallOnceBoost cxxtest_singleton_call_once_boost.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/TestSingletonBoost.hpp )
CXXTEST_ADD_TEST( decorator cxxtest_decorator.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/TestDecorator.hpp )

#CXXTEST_ADD_TEST( observerPattern cxxtest_osberverPattern.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test/TestObserverPattern.hpp )

include_directories( "include" )

add_library( observer src/Subject.cpp src/Observer.cpp )
add_library( printerDecorator src/SimplePrinter.cpp src/PrinterDecorator.cpp src/UnderlineDecorator.cpp )

target_link_libraries( testSubject ${Boost_LIBRARIES} observer )
target_link_libraries( testObserverPattern ${Boost_LIBRARIES} observer )
# singletonCallOnce: template stuff, linking not needed
target_link_libraries( singletonCallOnceBoost ${Boost_LIBRARIES})
target_link_libraries( decorator printerDecorator ) 
