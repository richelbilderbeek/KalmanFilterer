#pragma GCC diagnostic push



#include "standardwhitenoisesystemparameters.h"
#pragma GCC diagnostic pop

#include <cassert>
#include "matrix.h"

ribi::kalman::StandardWhiteNoiseSystemParameters::StandardWhiteNoiseSystemParameters(
  const boost::numeric::ublas::matrix<double>& control,
  const boost::numeric::ublas::vector<double>& initial_state,
  const boost::numeric::ublas::vector<double>& real_measurement_noise,
  const boost::numeric::ublas::vector<double>& real_process_noise,
  const boost::numeric::ublas::matrix<double>& state_transition)
  : WhiteNoiseSystemParameters(
      control,
      initial_state,
      real_measurement_noise,
      real_process_noise,
      state_transition)
{

}

bool ribi::kalman::IsAboutEqual(
  const StandardWhiteNoiseSystemParameters& lhs,
  const StandardWhiteNoiseSystemParameters& rhs
) noexcept
{
  return
       Matrix::MatricesAreAboutEqual(lhs.GetControl(),rhs.GetControl())
    && Matrix::VectorsAreAboutEqual(lhs.GetInitialState(),rhs.GetInitialState())
    && Matrix::VectorsAreAboutEqual(lhs.GetMeasurementNoise(),rhs.GetMeasurementNoise())
    && Matrix::VectorsAreAboutEqual(lhs.GetProcessNoise(),rhs.GetProcessNoise())
    && Matrix::MatricesAreAboutEqual(lhs.GetStateTransition(),rhs.GetStateTransition());
}
