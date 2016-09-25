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

double ribi::kalman::WhiteNoiseSystem::GetRandomNormal(
  const double mean, const double sigma
) noexcept
{
  return Random().GetNormal(mean,sigma);
}

std::string ribi::kalman::WhiteNoiseSystem::GetVersion() noexcept
{
  return "1.0";
}

std::vector<std::string> ribi::kalman::WhiteNoiseSystem::GetVersionHistory() noexcept
{
  return {
    "2013-05-03: version 1.0: initial version"
  };
}

void ribi::kalman::WhiteNoiseSystem::SetNewCurrentState(
  const boost::numeric::ublas::vector<double>& new_current_state
)
{
  assert(m_current_state.size() == new_current_state.size());
  m_current_state = new_current_state;
}
