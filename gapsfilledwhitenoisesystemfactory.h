#ifndef GAPSFILLEDWHITENOISESYSTEMFACTORY_H
#define GAPSFILLEDWHITENOISESYSTEMFACTORY_H




#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/shared_ptr.hpp>


#include "gapsfilledwhitenoisesystem.h"

namespace ribi {
namespace kalman {

///Factory for GapsFilledWhiteNoiseSystem
struct GapsFilledWhiteNoiseSystemFactory
{
  GapsFilledWhiteNoiseSystemFactory();

  ///Create a GapsFilledWhiteNoiseSystem from its parameters
  /// @param measurement_freq the measurement frequency
  /// @param measurement_noise the real measurement noise
  boost::shared_ptr<GapsFilledWhiteNoiseSystem> Create(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::vector<double>& initial_state,
    const boost::numeric::ublas::vector<int>& measurement_freq,
    const boost::numeric::ublas::vector<double>& measurement_noise,
    const boost::numeric::ublas::vector<double>& real_process_noise,
    const boost::numeric::ublas::matrix<double>& state_transition
  ) const noexcept;

  ///Create a GapsFilledWhiteNoiseSystem from the parameters
  boost::shared_ptr<GapsFilledWhiteNoiseSystem> Create(
    const boost::shared_ptr<WhiteNoiseSystemParameters>& parameters
  ) const noexcept;

};

} //~namespace kalman
} //~namespace ribi

#endif // GAPSFILLEDWHITENOISESYSTEMFACTORY_H
