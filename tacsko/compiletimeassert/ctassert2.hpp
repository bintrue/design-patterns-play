#ifndef CTASSERTSUSU_HPP
#define CTASSERTSUSU_HPP

/*
 * Compile time assertion with bodyless template class.
 * source: Susu
 */

/*
 * pure declaration
 */
template <bool> class CompileTimeAssert; // no body

/*
 * specialization for true
 */
template <> class CompileTimeAssert<true>  {}; // has body

#endif

