#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "fixedlagsmootherkalmanfilter.h"
#include <boost/test/unit_test.hpp>

#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/conversion/cast.hpp>

#include "matrix.h"
#include "standardkalmanfilterfactory.h"
#pragma GCC diagnostic pop

using namespace ribi;
using namespace ribi::kalman;

BOOST_AUTO_TEST_CASE(ribi_kalman_FixedLagSmootherKalmanFilter)
{
  BOOST_CHECK_THROW(boost::numeric_cast<std::size_t>(-1), std::exception);

  //CreateTermA
  {
    const int lag = 13;
    const int state_size = 17;
    const boost::numeric::ublas::matrix<double> v = CreateTermA(lag,state_size);
    const int n_rows = lag * state_size;
    const int n_cols =   1 * state_size;
    BOOST_CHECK(boost::numeric_cast<int>(v.size1()) == n_rows);
    BOOST_CHECK(boost::numeric_cast<int>(v.size2()) == n_cols);
    for (int row = 0; row!=n_rows; ++row)
    {
      BOOST_CHECK(row < boost::numeric_cast<int>(v.size1()));
      for (int col = 0; col!=n_cols; ++col)
      {
        BOOST_CHECK(col < boost::numeric_cast<int>(v.size2()));
        const double expected = row == col ? 1.0 : 0.0;
        BOOST_CHECK(Matrix::IsAboutEqual(v(row,col),expected));
      }
    }
  }
  //CreateTermB
  {
    const int lag = 3;
    const int state_size = 5;
    const boost::numeric::ublas::matrix<double> v = CreateTermB(lag,state_size);
    const int n_rows = lag * state_size;
    const int n_cols = (lag - 1) * state_size;
    BOOST_CHECK(boost::numeric_cast<int>(v.size1()) == n_rows);
    BOOST_CHECK(boost::numeric_cast<int>(v.size2()) == n_cols);
    for (int row = 0; row!=n_rows; ++row)
    {
      BOOST_CHECK(row < boost::numeric_cast<int>(v.size1()));
      for (int col = 0; col!=n_cols; ++col)
      {
        BOOST_CHECK(col < boost::numeric_cast<int>(v.size2()));
        const double expected = row - state_size == col ? 1.0 : 0.0;
        BOOST_CHECK(Matrix::IsAboutEqual(v(row,col),expected));
      }
    }
  }
}
