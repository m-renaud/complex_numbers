#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <unistd.h>

#include "complex_utils.hxx"

int main()
{
  std::ios::sync_with_stdio(false);

  std::vector<mrr::complex> cv;

  bool result = parse_from_stream(std::cin, cv);

  if(result)
  {
    std::cout << "Parse Successful" << std::endl;
    generate_xml(cv, std::cout, std::cerr);
  }
  else
  {
    std::cerr << "Pares Failed" << std::endl;
    return 1;
  }

  return 0;
}
