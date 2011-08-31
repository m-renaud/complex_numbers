#ifndef MRR_COMPLEX_ADAPT_HXX
#define MRR_COMPLEX_ADAPT_HXX

#include <boost/fusion/include/adapt_struct.hpp>

#include "complex_types.hxx"

BOOST_FUSION_ADAPT_STRUCT(
  mrr::complex,
  (double, real)
  (double, imaginary)
)

#endif // #ifndef MRR_PAIR_ADAPT_HXX
