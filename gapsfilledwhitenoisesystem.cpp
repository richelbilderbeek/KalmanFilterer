#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "gapsfilledwhitenoisesystem.h"

#include <cassert>

#include <boost/numeric/conversion/cast.hpp>

#include "ribi_random.h"
#include "matrix.h"
#include "gapsfilledwhitenoisesystem.h"
#include "gapsfilledwhitenoisesystemfactory.h"
#include "gapsfilledwhitenoisesystemparameters.h"

#pragma GCC diagnostic pop

ribi::kalman::GapsFilledWhiteNoiseSystem::GapsFilledWhiteNoiseSystem(
  const boost::shared_ptr<const WhiteNoiseSystemParameters>& parameters)
  : WhiteNoiseSystem{parameters},
    m_last_measument{parameters->GetInitialState().size(),0.0},
    m_parameters{boost::dynamic_pointer_cast<
      const GapsFilledWhiteNoiseSystemParameters
    >(parameters)},
    m_timestep{0}
{
  assert(m_parameters);
  //Check measuring frequecies
  {
    const auto v = m_parameters->GetMeasurementFrequency();
    const std::size_t sz = v.size();
    for (std::size_t i=0; i!=sz; ++i)
    {
      const int x = v[i];
      assert(x >= 1 && "At least one out of one measurements is a real measurement");
    }
  }
}

std::string ribi::kalman::GapsFilledWhiteNoiseSystem::GetVersion() noexcept
{
  return "1.0";
}

std::vector<std::string> ribi::kalman::GapsFilledWhiteNoiseSystem::GetVersionHistory() noexcept
{
  return {
    "2013-06-25: version 1.0: initial version"
  };
}

void ribi::kalman::GapsFilledWhiteNoiseSystem::GoToNextState(
  const boost::numeric::ublas::vector<double>& input
)
{
  //Standard transition
  assert(input.size() == GetCurrentState().size());
  assert(m_parameters->GetStateTransition().size1() == GetCurrentState().size());
  assert(m_parameters->GetStateTransition().size2() == GetCurrentState().size());
  assert(m_parameters->GetControl().size1() == input.size());
  assert(m_parameters->GetControl().size2() == input.size());

  boost::numeric::ublas::vector<double> new_state
    = Matrix::Prod(m_parameters->GetStateTransition(),GetCurrentState())
    + Matrix::Prod(m_parameters->GetControl(),input);
  //Add process noise
  const auto sz = new_state.size();
  assert(new_state.size() == m_parameters->GetProcessNoise().size());
  for (std::size_t i = 0; i!=sz; ++i)
  {
    new_state(i) = GetRandomNormal(new_state(i),m_parameters->GetProcessNoise()(i));
  }
  SetNewCurrentState(new_state);
}

boost::numeric::ublas::vector<double> ribi::kalman::GapsFilledWhiteNoiseSystem::Measure() const
{
  const boost::numeric::ublas::vector<int>& fs
    = this->GetGapsFilledWhiteNoiseSystemParameters()->GetMeasurementFrequency();

  assert(fs.size() == m_last_measument.size());
  assert(fs.size() == GetCurrentState().size());
  assert(fs.size() == m_parameters->GetMeasurementNoise().size());

  const std::size_t n_states = fs.size();
  for (std::size_t state=0; state!=n_states; ++state)
  {
    assert(state < fs.size());
    const int f = fs[state];
    assert(f >= 1);

    if (m_timestep % f == 0)
    {
      assert(state < m_last_measument.size());
      assert(state < GetCurrentState().size());
      assert(state < m_parameters->GetMeasurementNoise().size());
      m_last_measument(state) = GetRandomNormal(
        GetCurrentState()(state),
        m_parameters->GetMeasurementNoise()(state)
      );
    }
    else
    {
      //Should get here
    }
  }
  ++m_timestep;

  return m_last_measument;
}

const boost::numeric::ublas::vector<double>&
  ribi::kalman::GapsFilledWhiteNoiseSystem::PeekAtRealState() const noexcept
{
  return this->GetCurrentState();
}


