#include "kalmanfilterexperimentparameter.h"

#include <stdexcept>
#include <boost/test/unit_test.hpp>

#pragma GCC diagnostic push



#include <boost/numeric/conversion/cast.hpp>
#pragma GCC diagnostic pop

#include "kalmanfilterparameter.h"
#include "whitenoisesystemparameter.h"

using namespace ribi;
using namespace ribi::kalman;

BOOST_AUTO_TEST_CASE(ribi_kalman_KalmanFilterExperimentParameter)
{
  KalmanFilterExperimentParameter p;
  BOOST_CHECK( p.IsMatrix(KalmanFilterExperimentParameterType::control));
  BOOST_CHECK( p.IsMatrix(KalmanFilterExperimentParameterType::estimated_measurement_noise));
  BOOST_CHECK( p.IsMatrix(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain));
  BOOST_CHECK( p.IsMatrix(KalmanFilterExperimentParameterType::estimated_process_noise_covariance));
  BOOST_CHECK( p.IsMatrix(KalmanFilterExperimentParameterType::initial_covariance_estimate));
  BOOST_CHECK(!p.IsMatrix(KalmanFilterExperimentParameterType::initial_state_estimate));
  BOOST_CHECK(!p.IsMatrix(KalmanFilterExperimentParameterType::initial_state_real));
  BOOST_CHECK(!p.IsMatrix(KalmanFilterExperimentParameterType::measurement_frequency));
  BOOST_CHECK(!p.IsMatrix(KalmanFilterExperimentParameterType::real_measurement_noise));
  BOOST_CHECK(!p.IsMatrix(KalmanFilterExperimentParameterType::real_process_noise));
  BOOST_CHECK(!p.IsMatrix(KalmanFilterExperimentParameterType::input));
  BOOST_CHECK( p.IsMatrix(KalmanFilterExperimentParameterType::observation));
  BOOST_CHECK(!p.IsMatrix(KalmanFilterExperimentParameterType::state_names));
  BOOST_CHECK( p.IsMatrix(KalmanFilterExperimentParameterType::state_transition));

  BOOST_CHECK(!p.IsVector(KalmanFilterExperimentParameterType::control));
  BOOST_CHECK(!p.IsVector(KalmanFilterExperimentParameterType::estimated_measurement_noise));
  BOOST_CHECK(!p.IsVector(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain));
  BOOST_CHECK(!p.IsVector(KalmanFilterExperimentParameterType::estimated_process_noise_covariance));
  BOOST_CHECK(!p.IsVector(KalmanFilterExperimentParameterType::initial_covariance_estimate));
  BOOST_CHECK( p.IsVector(KalmanFilterExperimentParameterType::initial_state_estimate));
  BOOST_CHECK( p.IsVector(KalmanFilterExperimentParameterType::initial_state_real));
  BOOST_CHECK( p.IsVector(KalmanFilterExperimentParameterType::measurement_frequency));
  BOOST_CHECK( p.IsVector(KalmanFilterExperimentParameterType::real_measurement_noise));
  BOOST_CHECK( p.IsVector(KalmanFilterExperimentParameterType::real_process_noise));
  BOOST_CHECK( p.IsVector(KalmanFilterExperimentParameterType::input));
  BOOST_CHECK(!p.IsVector(KalmanFilterExperimentParameterType::observation));
  BOOST_CHECK( p.IsVector(KalmanFilterExperimentParameterType::state_names));
  BOOST_CHECK(!p.IsVector(KalmanFilterExperimentParameterType::state_transition));

  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::control));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::estimated_measurement_noise));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::estimated_process_noise_covariance));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::initial_covariance_estimate));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::initial_state_estimate));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::initial_state_real));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::measurement_frequency));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::real_measurement_noise));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::real_process_noise));
  BOOST_CHECK( p.IsString(KalmanFilterExperimentParameterType::input));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::observation));
  BOOST_CHECK( p.IsString(KalmanFilterExperimentParameterType::state_names));
  BOOST_CHECK(!p.IsString(KalmanFilterExperimentParameterType::state_transition));

  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::control));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::estimated_measurement_noise));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::estimated_process_noise_covariance));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::initial_covariance_estimate));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::initial_state_estimate));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::initial_state_real));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::measurement_frequency));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::real_measurement_noise));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::real_process_noise));
  BOOST_CHECK( p.IsFunction(KalmanFilterExperimentParameterType::input));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::observation));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::state_names));
  BOOST_CHECK(!p.IsFunction(KalmanFilterExperimentParameterType::state_transition));

  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::control));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::estimated_measurement_noise));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::estimated_process_noise_covariance));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::initial_covariance_estimate));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::initial_state_estimate));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::initial_state_real));
  BOOST_CHECK(!p.IsDouble(KalmanFilterExperimentParameterType::measurement_frequency));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::real_measurement_noise));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::real_process_noise));
  BOOST_CHECK(!p.IsDouble(KalmanFilterExperimentParameterType::input));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::observation));
  BOOST_CHECK(!p.IsDouble(KalmanFilterExperimentParameterType::state_names));
  BOOST_CHECK( p.IsDouble(KalmanFilterExperimentParameterType::state_transition));

  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::control));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::estimated_measurement_noise));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::estimated_process_noise_covariance));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::initial_covariance_estimate));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::initial_state_estimate));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::initial_state_real));
  BOOST_CHECK( p.IsInt(KalmanFilterExperimentParameterType::measurement_frequency));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::real_measurement_noise));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::real_process_noise));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::input));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::observation));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::state_names));
  BOOST_CHECK(!p.IsInt(KalmanFilterExperimentParameterType::state_transition));

}
