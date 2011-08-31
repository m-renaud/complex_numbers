#ifndef MRR_COMPLEX_UTILS_HXX__
#define MRR_COMPLEX_UTILS_HXX__

#include <istream>
#include <vector>
#include <ostream>

#include "complex_types.hxx"

//===========================================================================

namespace mrr {

//---------------------------------------------------------------------------

  bool parse_from_stream(std::istream& is, std::vector<complex>& cv);

  bool generate_xml(std::vector<complex>& v,
		    std::ostream& out,
		    std::ostream& err);

//===========================================================================

} // namespace mrr

//---------------------------------------------------------------------------
#endif // #ifndef MRR_COMPLEX_UTILS_HXX__
