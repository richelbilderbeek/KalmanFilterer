#pragma GCC diagnostic push



#include "laggedwhitenoisesystem.h"

#include <cassert>

#include <boost/numeric/conversion/cast.hpp>
#pragma GCC diagnostic pop

#include "matrix.h"
#include "laggedwhitenoisesystem.h"
#include "laggedwhitenoisesystemfactory.h"
#include "laggedwhitenoisesystemparameters.h"
#include "standardwhitenoisesystemparameters.h"
#include "standardwhitenoisesystemfactory.h"

ribi::kalman::LaggedWhiteNoiseSystem::LaggedWhiteNoiseSystem(
  const boost::shared_ptr<const WhiteNoiseSystemParameters>& parameters)
  : WhiteNoiseSystem{parameters},
    m_measuments{},
    m_parameters{boost::dynamic_pointer_cast<
      const LaggedWhiteNoiseSystemParameters
    >(parameters)},
    m_system{
      StandardWhiteNoiseSystemFactory().Create(
        parameters->GetControl(),
        parameters->GetInitialState(),
        parameters->GetMeasurementNoise(),
        parameters->GetProcessNoise(),
        parameters->GetStateTransition()
      )
    }
{
  assert(m_parameters);
  assert(m_parameters->GetLag() >= 0);
  assert(boost::numeric_cast<int>(m_measuments.size()) <= m_parameters->GetLag());
  assert(m_system);

  const int lag = m_parameters->GetLag();
  while (lag != boost::numeric_cast<int>(m_measuments.size()))
  {
    m_measuments.push(m_system->Measure());
  }
  assert(lag == boost::numeric_cast<int>(m_measuments.size()));
}

void ribi::kalman::LaggedWhiteNoiseSystem::GoToNextState(
  const boost::numeric::ublas::vector<double>& input
)
{
  m_system->GoToNextState(input);
}

boost::numeric::ublas::vector<double>
ribi::kalman::LaggedWhiteNoiseSystem::Measure() const noexcept
{
  assert(m_parameters->GetLag() == boost::numeric_cast<int>(m_measuments.size()));
  m_measuments.push(m_system->Measure());

  //Result is copied now, to also work for m_lag == 0
  const boost::numeric::ublas::vector<double> result = m_measuments.front();

  m_measuments.pop();
  assert(m_parameters->GetLag() == boost::numeric_cast<int>(m_measuments.size()));
  return result;
}

const boost::numeric::ublas::vector<double>&
ribi::kalman::LaggedWhiteNoiseSystem::PeekAtRealState() const noexcept
{
  return m_system->PeekAtRealState();
}

