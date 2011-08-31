#include <istream>
#include <iterator>
#include <fstream>
#include <string>

#include "complex_utils.hxx"
#include "complex_generator.hxx"

//===========================================================================

namespace mrr {

//---------------------------------------------------------------------------

  bool generate_xml(std::vector<complex>& v,
		    std::ostream& out,
		    std::ostream& err)
  {
    std::ostream_iterator<char> begin(out);
    return generate_complex_xml(begin, v);
  }


//===========================================================================

} // namespace mrr

//---------------------------------------------------------------------------
