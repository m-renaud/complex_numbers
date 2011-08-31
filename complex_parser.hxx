#ifndef MRR_COMPLEX_PARSER_HXX__
#define MRR_COMPLEX_PARSER_HXX__

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/repository/include/qi_flush_multi_pass.hpp>

#include "complex_types.hxx"
#include "complex_adapt.hxx"

//===========================================================================

namespace mrr {

//---------------------------------------------------------------------------

  namespace qi = boost::spirit::qi;

  //===========================================================================
  template <typename Iter>
  struct complex_parser : qi::grammar<Iter, std::vector<complex>() >
  {
    complex_parser() : complex_parser::base_type(start_state)
    {
      using qi::double_;
      using qi::space;
      using qi::lexeme;
      using qi::omit;
      using qi::lit;
      using qi::eol;
      using qi::eoi;
      using boost::spirit::repository::flush_multi_pass;


      end_of_complex %=
        (
	  eol
	  | lit(',')
	  | space
	  | eoi
        )
        >> flush_multi_pass
      ;

      complex_number %= lexeme['(' >> double_ >> ',' > double_ >> ')'];
//        | lexeme[double_ << ]
//      ;

      start_state %= complex_number % end_of_complex;
    }

    qi::rule<Iter, complex()> complex_number;
    qi::rule<Iter, std::string()> end_of_complex;
    qi::rule<Iter, std::vector<complex>()> start_state;

  };

  //===========================================================================
  template <typename Iter>
  bool parse_complex(Iter& first, Iter& last, std::vector<complex>& v)
  {
    complex_parser<Iter> p;
    return qi::parse(first, last, p, v);
  }

//===========================================================================

} // namespace mrr

//---------------------------------------------------------------------------

#endif // #ifndef MRR_COMPLEX_PARSER_HXX__
