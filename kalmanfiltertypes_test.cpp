#include "kalmanfiltertypes.h"
#include <boost/test/unit_test.hpp>

using namespace ribi;
using namespace ribi::kalman;

BOOST_AUTO_TEST_CASE(ribi_kalman_KalmanFilterTypes)
{
  const std::vector<KalmanFilterType> v = KalmanFilterTypes().GetAllTypes();
  const std::size_t sz = v.size();
  for (std::size_t i=0; i!=sz; ++i)
  {
    BOOST_CHECK(i < v.size());
    const KalmanFilterType t = v[i];
    const std::string s = KalmanFilterTypes().ToStr(t);
    BOOST_CHECK(!s.empty());
    const KalmanFilterType u = KalmanFilterTypes().ToType(s);
    BOOST_CHECK(u == t);
  }
}
