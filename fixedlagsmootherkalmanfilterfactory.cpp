



#include "fixedlagsmootherkalmanfilterfactory.h"

#include <cassert>



ribi::kalman::FixedLagSmootherKalmanFilterFactory::FixedLagSmootherKalmanFilterFactory()
{

}

boost::shared_ptr<ribi::kalman::FixedLagSmootherKalmanFilter>
ribi::kalman::FixedLagSmootherKalmanFilterFactory::Create(
  const boost::shared_ptr<const KalmanFilterParameters>& parameters) const noexcept
{
  assert(parameters);
  assert(parameters->GetType() == KalmanFilterType::fixed_lag_smoother);

  const boost::shared_ptr<FixedLagSmootherKalmanFilterCalculationElements> calculation {
    new FixedLagSmootherKalmanFilterCalculationElements
  };

  assert(calculation);

  const boost::shared_ptr<FixedLagSmootherKalmanFilter> kalman_filter {
    new FixedLagSmootherKalmanFilter(calculation,parameters)
  };
  assert(kalman_filter);
  assert(kalman_filter->GetType() == KalmanFilterType::fixed_lag_smoother);
  return kalman_filter;
}
