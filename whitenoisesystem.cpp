#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "whitenoisesystem.h"

#include <cassert>

#include "ribi_random.h"

#pragma GCC diagnostic pop

ribi::kalman::WhiteNoiseSystem::WhiteNoiseSystem(
  const boost::shared_ptr<const WhiteNoiseSystemParameters>& parameters
)
  : m_current_state{parameters->GetInitialState()},
    m_parameters{parameters}
{
  assert(m_parameters);
}

const boost::numeric::ublas::vector<double>&
ribi::kalman::WhiteNoiseSystem::GetCurrentState() const noexcept
{
  return m_current_state;
}

const boost::shared_ptr<const ribi::kalman::WhiteNoiseSystemParameters>&
ribi::kalman::WhiteNoiseSystem::GetParameters() const noexcept
{
  return m_parameters;
}

double ribi::kalman::WhiteNoiseSystem::GetRandomNormal(
  const double mean, const double sigma
) noexcept
{
  return Random().GetNormal(mean,sigma);
}

void ribi::kalman::WhiteNoiseSystem::SetNewCurrentState(
  const boost::numeric::ublas::vector<double>& new_current_state
)
{
  assert(m_current_state.size() == new_current_state.size());
  m_current_state = new_current_state;
}

const boost::numeric::ublas::vector<double>&
ribi::kalman::WhiteNoiseSystem::PeekAtRealState() const noexcept
{
  return m_current_state;
}
