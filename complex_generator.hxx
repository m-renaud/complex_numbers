#ifndef MRR_COMPLEX_GENERATOR_HXX__
#define MRR_COMPLEX_GENERATOR_HXX__

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/karma.hpp>

#include "complex_adapt.hxx"

//===========================================================================

namespace mrr {

//---------------------------------------------------------------------------

  namespace ka = boost::spirit::karma;

  //===========================================================================
  template <typename Iter>
  struct complex_generator : ka::grammar<Iter, std::vector<complex>() >
  {
    complex_generator() : complex_generator::base_type(start_state)
    {
      using ka::double_;
      using ka::lit;
      using ka::string;

      complex_number =
      lit("<complex>")
      << lit("<real>") << double_ << lit("</real>")
      << lit("<imaginary>") << double_ << lit("</imaginary>")
      ;


      start_state =
        lit("<complex_numbers>")
        << *complex_number
        << lit("</complex_numbers>")
      ;
    }

    ka::rule<Iter, complex()> complex_number;
    ka::rule<Iter, std::vector<complex>()> start_state;
  };


  //===========================================================================
  template <typename Iter>
  inline bool generate_complex_xml(Iter& sink, std::vector<complex>& v)
  {
    complex_generator<Iter> g;
    return ka::generate(sink, g, v);
  }


//===========================================================================

} // namespace mrr

//---------------------------------------------------------------------------


#endif // #ifndef MRR_COMPLEX_GENERATOR_HXX__
