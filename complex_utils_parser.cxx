#include <istream>
#include <iterator>
#include <fstream>
#include <string>
#include <boost/spirit/include/support_istream_iterator.hpp>

#include "complex_utils.hxx"
#include "complex_parser.hxx"

//===========================================================================

namespace mrr {

//---------------------------------------------------------------------------

bool parse_from_stream(std::istream& is, std::vector<complex>& cv)
{
  // Save old flags...
  std::ios::fmtflags old = is.flags();
  is.unsetf(std::ios::skipws);

  // Parse...
  using boost::spirit::basic_istream_iterator;
  basic_istream_iterator<char> begin(is);
  basic_istream_iterator<char> end;
  bool const retval = parse_complex(begin, end, cv);

  // Reset the flags...
  is.flags(old);

  return retval;
}

//===========================================================================

} // namespace mrr

//---------------------------------------------------------------------------
