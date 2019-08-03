#ifndef LAGGEDWHITENOISESYSTEMFACTORY_H
#define LAGGEDWHITENOISESYSTEMFACTORY_H




#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/shared_ptr.hpp>


#include "laggedwhitenoisesystem.h"

namespace ribi {
namespace kalman {

///Factory for LaggedWhiteNoiseSystem
struct LaggedWhiteNoiseSystemFactory
{
  LaggedWhiteNoiseSystemFactory();

  ///Create a LaggedWhiteNoiseSystem from the loose parameters
  boost::shared_ptr<LaggedWhiteNoiseSystem> Create(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::vector<double>& initial_state,
    const int lag,
    const boost::numeric::ublas::vector<double>& real_measure_noise, //real_measurement_noise
    const boost::numeric::ublas::vector<double>& real_process_noise,
    const boost::numeric::ublas::matrix<double>& state_transition
  ) const noexcept;

  ///Create a LaggedWhiteNoiseSystem from the parameters
  boost::shared_ptr<LaggedWhiteNoiseSystem> Create(
    const boost::shared_ptr<WhiteNoiseSystemParameters>& parameters
  ) const noexcept;
};

} //~namespace kalman
} //~namespace ribi

#endif // LAGGEDWHITENOISESYSTEMFACTORY_H
