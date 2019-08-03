



#include "standardkalmanfilterfactory.h"

#include <cassert>



ribi::kalman::StandardKalmanFilterFactory::StandardKalmanFilterFactory()
{

}

boost::shared_ptr<ribi::kalman::StandardKalmanFilter>
ribi::kalman::StandardKalmanFilterFactory::Create(
  const boost::shared_ptr<const KalmanFilterParameters>& parameters) const noexcept
{
  assert(parameters);
  assert(parameters->GetType() == KalmanFilterType::standard);

  const boost::shared_ptr<StandardKalmanFilterCalculationElements> calculation{
    new StandardKalmanFilterCalculationElements
  };

  assert(calculation);

  const boost::shared_ptr<StandardKalmanFilter> kalman_filter{
    new StandardKalmanFilter(calculation,parameters)
  };
  assert(kalman_filter);
  assert(kalman_filter->GetType() == KalmanFilterType::standard);
  return kalman_filter;
}
