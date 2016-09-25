#include "whitenoisesystemtypes.h"

#include <boost/test/unit_test.hpp>

using namespace ribi;
using namespace ribi::kalman;

BOOST_AUTO_TEST_CASE(ribi_kalman_WhiteNoiseSystemTypes)
{
  for (const auto& t: WhiteNoiseSystemTypes().GetAllTypes())
  {
    const std::string s = WhiteNoiseSystemTypes().ToStr(t);
    BOOST_CHECK(!s.empty());
    const auto u = WhiteNoiseSystemTypes().ToType(s);
    BOOST_CHECK(u == t);
  }
}
