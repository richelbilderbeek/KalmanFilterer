



#include "whitenoisesystemparameters.h"


#include <cassert>
#include "matrix.h"

ribi::kalman::WhiteNoiseSystemParameters::WhiteNoiseSystemParameters(
  const boost::numeric::ublas::matrix<double>& control,
  const boost::numeric::ublas::vector<double>& initial_state,
  const boost::numeric::ublas::vector<double>& measurement_noise,
  const boost::numeric::ublas::vector<double>& real_process_noise,
  const boost::numeric::ublas::matrix<double>& state_transition)
  : m_control{control},
    m_initial_state{initial_state},
    m_real_measurement_noise{measurement_noise},
    m_real_process_noise{real_process_noise},
    m_state_transition{state_transition}
{
  #ifndef NDEBUG
  //Check for correct dimensionality
  const size_t sz = initial_state.size();
  //assert(sz >= 0); //Inevitable for std::size_t
  assert(m_control.size1() == sz);
  assert(m_control.size2() == sz);
  assert(m_initial_state.size() == sz);
  assert(m_real_measurement_noise.size() == sz);
  assert(m_real_process_noise.size() == sz);
  assert(m_state_transition.size1() == sz);
  assert(m_state_transition.size2() == sz);
  #endif
}

bool ribi::kalman::IsAboutEqual(
  const WhiteNoiseSystemParameters& lhs, const WhiteNoiseSystemParameters& rhs) noexcept
{
  return
       Matrix::MatricesAreAboutEqual(lhs.GetControl(),rhs.GetControl())
    && Matrix::VectorsAreAboutEqual(lhs.GetInitialState(),rhs.GetInitialState())
    && Matrix::VectorsAreAboutEqual(lhs.GetMeasurementNoise(),rhs.GetMeasurementNoise())
    && Matrix::VectorsAreAboutEqual(lhs.GetProcessNoise(),rhs.GetProcessNoise())
    && Matrix::MatricesAreAboutEqual(lhs.GetStateTransition(),rhs.GetStateTransition());
}
