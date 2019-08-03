#ifndef GAPSFILLEDWHITENOISESYSTEMPARAMETERS_H
#define GAPSFILLEDWHITENOISESYSTEMPARAMETERS_H

#pragma GCC diagnostic push

#include <boost/shared_ptr.hpp>
#pragma GCC diagnostic pop

#include "whitenoisesystemparameters.h"

namespace ribi {
namespace kalman {

struct GapsFilledWhiteNoiseSystemParameters : public WhiteNoiseSystemParameters
{
  /// @param measurement_freq the measurement frequency
  /// @param measurement_noise the real measurement noise
  explicit GapsFilledWhiteNoiseSystemParameters(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::vector<double>& initial_state,
    const boost::numeric::ublas::vector<int>& measurement_frequency,
    const boost::numeric::ublas::vector<double>& measurement_noise,
    const boost::numeric::ublas::vector<double>& real_process_noise,
    const boost::numeric::ublas::matrix<double>& state_transition);

  ///The number of timesteps after which a real measurement is acquired
  const auto& GetMeasurementFrequency() const noexcept
  {
    return m_measurement_frequency;
  }

  ///Obtain the type as an enum
  WhiteNoiseSystemType GetType() const noexcept
  {
    return WhiteNoiseSystemType::gaps_filled;
  }

  private:
  ///Can only be deleted by boost::checked_delete
  ~GapsFilledWhiteNoiseSystemParameters() noexcept {}
  friend void boost::checked_delete<>(GapsFilledWhiteNoiseSystemParameters*);

  ///The gaps (in timesteps) is the number of measurements
  /// of which only one real measurement is acquired
  const boost::numeric::ublas::vector<int> m_measurement_frequency;

};

} //~namespace kalman
} //~namespace ribi

#endif // GAPSFILLEDWHITENOISESYSTEMPARAMETERS_H
