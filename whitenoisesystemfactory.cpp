



#include "whitenoisesystemfactory.h"


#include <cassert>
#include "gapsfilledwhitenoisesystemfactory.h"
#include "laggedwhitenoisesystemfactory.h"
#include "standardwhitenoisesystemfactory.h"

ribi::kalman::WhiteNoiseSystemFactory::WhiteNoiseSystemFactory()
{

}

boost::shared_ptr<ribi::kalman::WhiteNoiseSystem>
ribi::kalman::WhiteNoiseSystemFactory::Create(
  const boost::shared_ptr<WhiteNoiseSystemParameters>& parameters) const noexcept
{
  boost::shared_ptr<WhiteNoiseSystem> p;
  switch (parameters->GetType())
  {
    case WhiteNoiseSystemType::gaps_filled:
      p = GapsFilledWhiteNoiseSystemFactory().Create(parameters);
      break;
    case WhiteNoiseSystemType::lagged:
      p = LaggedWhiteNoiseSystemFactory().Create(parameters);
      break;
    case WhiteNoiseSystemType::standard:
      p = StandardWhiteNoiseSystemFactory().Create(parameters);
      break;
    case WhiteNoiseSystemType::n_types:
      assert(!"Unimplemented white noise system");
      throw std::logic_error(__func__);
  }
  assert(p);
  return p;
}


