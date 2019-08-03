#ifndef WHITENOISESYSTEMPARAMETERS_H
#define WHITENOISESYSTEMPARAMETERS_H




#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>


#include "whitenoisesystemtype.h"


namespace ribi {
namespace kalman {

///ABC of the parameters of a white noise system
struct WhiteNoiseSystemParameters
{
  WhiteNoiseSystemParameters(const WhiteNoiseSystemParameters&) = delete;
  WhiteNoiseSystemParameters& operator=(const WhiteNoiseSystemParameters&) = delete;

  virtual ~WhiteNoiseSystemParameters() noexcept {}

  ///The control matrix to determine the influence of the input (in GoToNextState)
  const boost::numeric::ublas::matrix<double>& GetControl() const noexcept
    { return m_control; }

  ///Obtain the real initial state
  const boost::numeric::ublas::vector<double>& GetInitialState() const noexcept
    { return m_initial_state; }

  ///The real standard deviation of the noise in the state transition
  ///(used in WhiteNoiseSystem::GoToNextState)
  const boost::numeric::ublas::vector<double>& GetProcessNoise() const noexcept
    { return m_real_process_noise; }

  ///The real amount of noise in the system
  ///A noise of zero indicates a system that can be measured accurately to infinite precision
  const boost::numeric::ublas::vector<double>& GetMeasurementNoise() const noexcept
    { return m_real_measurement_noise; }

  ///The state transitions in the system
  ///(used in WhiteNoiseSystem::GoToNextState)
  const boost::numeric::ublas::matrix<double>& GetStateTransition() const noexcept
    { return m_state_transition; }

  ///Obtain the type as an enum
  virtual WhiteNoiseSystemType GetType() const noexcept = 0;

  protected:
  ///An ABC can only be constructed by derived classes
  explicit WhiteNoiseSystemParameters(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::vector<double>& initial_state,
    const boost::numeric::ublas::vector<double>& real_measure_noise, //real_measurement_noise
    const boost::numeric::ublas::vector<double>& real_process_noise,
    const boost::numeric::ublas::matrix<double>& state_transition
  );

  private:
  ///The control matrix to determine the influence of the input (in GoToNextState)
  const boost::numeric::ublas::matrix<double> m_control;

  ///The real initial state
  const boost::numeric::ublas::vector<double> m_initial_state;

  ///The real amount of noise in the system
  ///A noise of zero indicates a system that can be measured accurately to infinite precision
  const boost::numeric::ublas::vector<double> m_real_measurement_noise;

  ///The standard deviation of the noise in the state transition (in GoToNextState)
  const boost::numeric::ublas::vector<double> m_real_process_noise;

  ///The state transitions in the system, used in GoToNextState
  const boost::numeric::ublas::matrix<double> m_state_transition;
};

///Check two parameter sets for equality using a fuzzy comparison
bool IsAboutEqual(
  const WhiteNoiseSystemParameters& lhs,
  const WhiteNoiseSystemParameters& rhs
) noexcept;

} //~namespace kalman
} //~namespace ribi

#endif // WHITENOISESYSTEMPARAMETERS_H
