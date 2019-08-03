#ifndef STANDARDWHITENOISESYSTEMPARAMETERS_H
#define STANDARDWHITENOISESYSTEMPARAMETERS_H

#pragma GCC diagnostic push

#include <boost/checked_delete.hpp>
#include "whitenoisesystemparameters.h"
#pragma GCC diagnostic pop

namespace ribi {
namespace kalman {

struct StandardWhiteNoiseSystemParameters : public WhiteNoiseSystemParameters
{
  explicit StandardWhiteNoiseSystemParameters(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::vector<double>& initial_state,
    const boost::numeric::ublas::vector<double>&
      real_msm_noise, //real_measurement_noise
    const boost::numeric::ublas::vector<double>& real_process_noise,
    const boost::numeric::ublas::matrix<double>& state_transition
  );

  ///Obtain the type as an enum
  WhiteNoiseSystemType GetType() const noexcept { return WhiteNoiseSystemType::standard; }

  private:
  ///Can only be deleted by boost::checked_delete
  ~StandardWhiteNoiseSystemParameters() noexcept {}
  friend void boost::checked_delete<>(StandardWhiteNoiseSystemParameters*);
};

///Check two parameter sets for equality using a fuzzy comparison
bool IsAboutEqual(
  const StandardWhiteNoiseSystemParameters& lhs,
  const StandardWhiteNoiseSystemParameters& rhs
) noexcept;

} //~namespace kalman
} //~namespace ribi

#endif // STANDARDWHITENOISESYSTEMPARAMETERS_H
