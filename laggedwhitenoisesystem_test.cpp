#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "laggedwhitenoisesystem.h"

#include <boost/test/unit_test.hpp>

#include <boost/numeric/conversion/cast.hpp>
#pragma GCC diagnostic pop

#include "matrix.h"
#include "laggedwhitenoisesystem.h"
#include "laggedwhitenoisesystemfactory.h"
#include "laggedwhitenoisesystemparameters.h"
#include "standardwhitenoisesystemparameters.h"
#include "standardwhitenoisesystemfactory.h"

using namespace ribi;
using namespace ribi::kalman;

BOOST_AUTO_TEST_CASE(ribi_kalman_LaggedWhiteNoiseSystem)
{
  //Check if measurements are indeed lagged:
  //The system's real value should update immediatly, but this fresh measurement
  //must only be accessible after lag timesteps
  //Context: measuring the position of an object with constant velocity
  {
    const int lag = 5;
    const boost::shared_ptr<LaggedWhiteNoiseSystem> my_system
      = LaggedWhiteNoiseSystemFactory().Create(
        Matrix::CreateMatrix(1,1, { 1.0 } ), //control
        Matrix::CreateVector(     { 0.0 } ), //initial_state,
        lag,
        Matrix::CreateVector(     { 0.0 } ), //real_measurement_noise
        Matrix::CreateVector(     { 0.0 } ), //real_process_noise
        Matrix::CreateMatrix(1,1, { 1.0 } )  //state_transition
    );
    const boost::numeric::ublas::vector<double> input = Matrix::CreateVector( { 1.0 } );

    for (int i=0; i!=lag; ++i)
    {
      BOOST_CHECK(Matrix::IsAboutEqual( my_system->Measure()(0), 0.0));
      BOOST_CHECK(Matrix::IsAboutEqual( my_system->PeekAtRealState()(0), boost::numeric_cast<double>(i) ) );
      my_system->GoToNextState(input);
    }
    for (int i=0; i!=10; ++i) //10 = just some value
    {
      const double expected = boost::numeric_cast<double>(i);
      BOOST_CHECK(Matrix::IsAboutEqual( my_system->Measure()(0), expected));
      BOOST_CHECK(Matrix::IsAboutEqual(
        my_system->PeekAtRealState()(0), boost::numeric_cast<double>(lag + i) )
      );
      my_system->GoToNextState(input);
    }
  }
}
