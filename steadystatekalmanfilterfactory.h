#ifndef STEADYSTATEKALMANFILTERFACTORY_H
#define STEADYSTATEKALMANFILTERFACTORY_H



#include <boost/shared_ptr.hpp>


#include "steadystatekalmanfilter.h"

namespace ribi {
namespace kalman {

///Factory for SteadyStateKalmanFilter
struct SteadyStateKalmanFilterFactory
{
  SteadyStateKalmanFilterFactory();

  boost::shared_ptr<SteadyStateKalmanFilter> Create(
    const boost::shared_ptr<const KalmanFilterParameters>& parameters
  ) const noexcept;

};

} //~namespace kalman
} //~namespace ribi

#endif // STEADYSTATEKALMANFILTERFACTORY_H
