



#include "laggedwhitenoisesystemfactory.h"

#include <boost/test/unit_test.hpp>

#include "matrix.h"



using namespace ribi;
using namespace ribi::kalman;

BOOST_AUTO_TEST_CASE(ribi_kalman_LaggedWhiteNoiseSystemFactory)
{
  const boost::shared_ptr<LaggedWhiteNoiseSystem> my_system
    = LaggedWhiteNoiseSystemFactory().Create(
      Matrix::CreateMatrix(1,1, { 1.0 } ), //control
      Matrix::CreateVector(     { 0.0 } ), //initial_state,
      0,
      Matrix::CreateVector(     { 0.0 } ), //real_measurement_noise
      Matrix::CreateVector(     { 0.0 } ), //real_process_noise
      Matrix::CreateMatrix(1,1, { 1.0 } )  //state_transition
  );
  BOOST_CHECK(my_system);
}
