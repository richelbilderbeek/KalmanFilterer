#ifndef STEADYSTATEKALMANFILTERPARAMETERS_H
#define STEADYSTATEKALMANFILTERPARAMETERS_H



#include <boost/checked_delete.hpp>


#include "kalmanfilterparameters.h"

namespace ribi {
namespace kalman {

///Parameters for the standard Kalman filter
struct SteadyStateKalmanFilterParameters : public KalmanFilterParameters
{
  explicit SteadyStateKalmanFilterParameters(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::matrix<double>&
      est_opt_kalman_gain, //estimated_optimal_kalman_gain
    const boost::numeric::ublas::vector<double>&
      initial_state_est, //initial_state_estimate
    const boost::numeric::ublas::matrix<double>& observation,
    const boost::numeric::ublas::matrix<double>& state_transition
  );

  ///Calculate the optimal Kalman gain
  static boost::numeric::ublas::matrix<double> CalculateOptimalKalmanGain(
    const boost::numeric::ublas::matrix<double>& initial_covariance,
    const boost::numeric::ublas::matrix<double>& measurement_noise,
    const boost::numeric::ublas::matrix<double>& observation,
    const boost::numeric::ublas::matrix<double>& state_transition);

  ///Obtain the (estimated) optimal Kalman gain ('K')
  const boost::numeric::ublas::matrix<double>& GetEstimatedOptimalKalmanGain() const
    { return m_estimated_optimal_kalman_gain; }


  ///Obtain the Kalman filter type as an enum
  KalmanFilterType GetType() const { return KalmanFilterType::steady_state; }

  ///Check if this parameter set has a certain type of KalmanFilterParameter
  static bool HasParameterType(const KalmanFilterParameterType type);

  private:
  ///Can only be deleted by boost::checked_delete
  ~SteadyStateKalmanFilterParameters() noexcept {}
  friend void boost::checked_delete<>(SteadyStateKalmanFilterParameters*);

  ///K: Estimated optimal Kalman gain
  const boost::numeric::ublas::matrix<double> m_estimated_optimal_kalman_gain;
};

///Check if two parameter sets are equal with a fuzzy compare
bool IsAboutEqual(
  const SteadyStateKalmanFilterParameters& lhs,
  const SteadyStateKalmanFilterParameters& rhs
);

} //~namespace kalman
} //~namespace ribi

#endif // STEADYSTATEKALMANFILTERPARAMETERS_H
