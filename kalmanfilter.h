#ifndef KALMANFILTER_H
#define KALMANFILTER_H





#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>
#include "kalmanfiltertype.h"
#include "kalmanfilterparameters.h"
#include "kalmanfiltercalculationelements.h"


namespace ribi {
namespace kalman {

///Kalman filter base class
struct KalmanFilter
{
  KalmanFilter(const KalmanFilter&) = delete;
  KalmanFilter& operator=(const KalmanFilter&) = delete;
  virtual ~KalmanFilter() noexcept {}

  ///Obtain the Kalman filter type as an enum
  virtual KalmanFilterType GetType() const = 0;

  ///Get the Kalman filter last calculation elements
  virtual boost::shared_ptr<KalmanFilterCalculationElements> GetLastCalculation() const = 0;

  ///Obtain the Kalman filter parameters
  virtual boost::shared_ptr<const KalmanFilterParameters> GetParameters() const = 0;

  virtual void SupplyMeasurementAndInput(
    const boost::numeric::ublas::vector<double>& measurements,
    const boost::numeric::ublas::vector<double>& input
  ) = 0;

  protected:
  explicit KalmanFilter() {}
};

} //~namespace kalman
} //~namespace ribi

#endif // KALMANFILTER_H
