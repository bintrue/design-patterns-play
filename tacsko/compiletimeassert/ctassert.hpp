#ifndef CTASSERT_HPP
#define CTASSERT_HPP

/*
 * Compile time assert implementation.
 * source: http://ksvanhorn.com/Articles/ctassert.html
 */

template <bool t>
struct ctassert {
  enum { N = 1 - 2 * int(!t) };
  static char CompileTimeAssertion[N];
};

template <bool t>
char ctassert<t>::CompileTimeAssertion[N];

#endif

