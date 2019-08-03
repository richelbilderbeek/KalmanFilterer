#pragma GCC diagnostic push



#include "gapsfilledwhitenoisesystem.h"

#include <boost/test/unit_test.hpp>

#include <boost/numeric/conversion/cast.hpp>

#include "ribi_random.h"
#include "matrix.h"
#include "gapsfilledwhitenoisesystem.h"
#include "gapsfilledwhitenoisesystemfactory.h"
#include "gapsfilledwhitenoisesystemparameters.h"

#pragma GCC diagnostic pop

using namespace ribi;
using namespace ribi::kalman;

BOOST_AUTO_TEST_CASE(ribi_kalman_GapsFilledWhiteNoiseSystem)
{
  //Check if measurements are indeed lagged:
  //The system's real value should update immediatly, but this fresh measurement
  //must only be accessible after lag timesteps
  //Context: measuring the position of an object with constant velocity
  {
    const int f = 5;
    const boost::shared_ptr<GapsFilledWhiteNoiseSystem> my_system
      = GapsFilledWhiteNoiseSystemFactory().Create(
        Matrix::CreateMatrix(1,1, { 1.0 } ), //control
        Matrix::CreateVector(     { 0.0 } ), //initial_state,
        Matrix::CreateVector(     {   f } ), //measurement frequencies
        Matrix::CreateVector(     { 0.0000001 } ), //real_measurement_noise
        Matrix::CreateVector(     { 0.0000001 } ), //real_process_noise
        Matrix::CreateMatrix(1,1, { 1.0 } )  //state_transition
    );
    BOOST_CHECK(my_system);
    //Context: airhockey puck
    const boost::numeric::ublas::vector<double> input = Matrix::CreateVector( { 1.0 } );

    for (int i=0; i!= 3*f; ++i)
    {
      const boost::numeric::ublas::vector<double> measurements = my_system->Measure();
      BOOST_CHECK(!measurements.empty());
      BOOST_CHECK(measurements.size() == 1);
      BOOST_CHECK(measurements.size() == my_system->PeekAtRealState().size());
      const double expected = static_cast<double>(i);
      const double measured = measurements(0);
      const double real = my_system->PeekAtRealState()(0);
      #ifdef FIX_ISSUE_2
      BOOST_CHECK(Matrix::IsAboutEqual(real,expected));
      if (i % f == 0)
      {
        BOOST_CHECK(Matrix::IsAboutEqual(measured,expected));
      }
      else
      {
        BOOST_CHECK(!Matrix::IsAboutEqual(measured,expected));
      }
      #endif // FIX_ISSUE_2
      my_system->GoToNextState(input);
    }
  }
}
