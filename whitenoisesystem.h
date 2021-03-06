#ifndef WHITENOISESYSTEM_H
#define WHITENOISESYSTEM_H




#include <boost/shared_ptr.hpp>

#include "whitenoisesystemtype.h"
#include "whitenoisesystemparameters.h"



namespace ribi {
namespace kalman {

struct WhiteNoiseSystem
{
  WhiteNoiseSystem(const WhiteNoiseSystem&) = delete;
  WhiteNoiseSystem& operator=(const WhiteNoiseSystem&) = delete;

  virtual ~WhiteNoiseSystem() noexcept {}

  ///The parameters
  const boost::shared_ptr<const WhiteNoiseSystemParameters>& GetParameters() const noexcept;

  ///Obtain the type as an enum
  virtual WhiteNoiseSystemType GetType() const noexcept = 0;

  ///Update reality, that is, let the real system (i.e. reality) go to its next state
  virtual void GoToNextState(const boost::numeric::ublas::vector<double>& input) = 0;

  ///Measure a value from this system with normally distributed noise
  virtual boost::numeric::ublas::vector<double> Measure() const = 0;

  ///Peek what the real value is
  virtual const boost::numeric::ublas::vector<double>& PeekAtRealState() const noexcept;

  protected:
  ///An ABC can only be constructed by derived classes
  explicit WhiteNoiseSystem(const boost::shared_ptr<const WhiteNoiseSystemParameters>& parameters);

  ///Obtain a random number from a normal distribution
  ///From http://www.richelbilderbeek.nl/CppGetRandomNormal.htm
  static double GetRandomNormal(const double mean = 0.0, const double sigma = 1.0) noexcept;

  ///The real state of the system
  const boost::numeric::ublas::vector<double>& GetCurrentState() const noexcept;

  ///Set the new current state
  void SetNewCurrentState(const boost::numeric::ublas::vector<double>& new_current_state);

  private:
  ///The real state of the system
  boost::numeric::ublas::vector<double> m_current_state;

  ///The parameters
  const boost::shared_ptr<const WhiteNoiseSystemParameters> m_parameters;

};

} //~namespace kalman
} //~namespace ribi

#endif // WHITENOISESYSTEM_H
