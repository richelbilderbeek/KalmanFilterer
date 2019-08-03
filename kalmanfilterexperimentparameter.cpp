#include "kalmanfilterexperimentparameter.h"

#include <cassert>
#include <stdexcept>

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include <boost/numeric/conversion/cast.hpp>
#pragma GCC diagnostic pop

#include "kalmanfilterparameter.h"
#include "whitenoisesystemparameter.h"

ribi::kalman::KalmanFilterExperimentParameter::KalmanFilterExperimentParameter()
  : m_map_kalman_filter{CreateMapKalmanFilter()},
    m_map_white_noise_system{CreateMapWhiteNoiseSystem()}
{

}

bool ribi::kalman::KalmanFilterExperimentParameter::CanConvertToKalmanFilterParameter(
  const KalmanFilterExperimentParameterType parameter) const noexcept
{
  const auto j = m_map_kalman_filter.end();
  for (auto i = m_map_kalman_filter.begin(); i!=j ;++i)
  {
    if ((*i).second == parameter) return true;
  }
  return false;
}


bool ribi::kalman::KalmanFilterExperimentParameter::CanConvertToWhiteNoiseSystemParameter(
  const KalmanFilterExperimentParameterType parameter) const noexcept
{
  const auto j = m_map_white_noise_system.end();
  for (auto i = m_map_white_noise_system.begin(); i!=j ;++i)
  {
    if ((*i).second == parameter) return true;
  }
  return false;
}

ribi::kalman::KalmanFilterExperimentParameterType
ribi::kalman::KalmanFilterExperimentParameter::ConvertToKalmanFilterExperimentParameter(
  const KalmanFilterParameterType parameter) const noexcept
{
  const auto j = m_map_kalman_filter.end();
  for (auto i = m_map_kalman_filter.begin(); i!=j ;++i)
  {
    if ((*i).first == parameter) return (*i).second;
  }
  assert(!"Should never get here");
  return ribi::kalman::KalmanFilterExperimentParameterType::n_parameters;
}

ribi::kalman::KalmanFilterExperimentParameterType
ribi::kalman::KalmanFilterExperimentParameter::ConvertToKalmanFilterExperimentParameter(
  const WhiteNoiseSystemParameterType parameter) const noexcept
{
  const auto j = m_map_white_noise_system.end();
  for (auto i = m_map_white_noise_system.begin(); i!=j ;++i)
  {
    if ((*i).first == parameter) return (*i).second;
  }
  assert(!"Should never get here");
  return ribi::kalman::KalmanFilterExperimentParameterType::n_parameters;
}

ribi::kalman::KalmanFilterParameterType
ribi::kalman::KalmanFilterExperimentParameter::ConvertToKalmanFilterParameter(
  const KalmanFilterExperimentParameterType parameter) const noexcept
{
  assert(CanConvertToKalmanFilterParameter(parameter));
  const auto j = m_map_kalman_filter.end();
  for (auto i = m_map_kalman_filter.begin(); i!=j ;++i)
  {
    if ((*i).second == parameter) return (*i).first;
  }
  assert(!"Should never get here");
  return ribi::kalman::KalmanFilterParameterType::n_parameters;
}

ribi::kalman::WhiteNoiseSystemParameterType
ribi::kalman::KalmanFilterExperimentParameter::ConvertToWhiteNoiseSystemParameter(
  const KalmanFilterExperimentParameterType parameter) const noexcept
{
  assert(CanConvertToWhiteNoiseSystemParameter(parameter));
  const auto j = m_map_white_noise_system.end();
  for (auto i = m_map_white_noise_system.begin(); i!=j ;++i)
  {
    if ((*i).second == parameter) return (*i).first;
  }
  assert(!"Should never get here");
  return ribi::kalman::WhiteNoiseSystemParameterType::n_parameters;
}

std::vector<
  std::pair<
    ribi::kalman::KalmanFilterParameterType,
    ribi::kalman::KalmanFilterExperimentParameterType
  >
>
ribi::kalman::CreateMapKalmanFilter() noexcept
{
  std::vector<
    std::pair<KalmanFilterParameterType,KalmanFilterExperimentParameterType>
  > v;
  v.push_back(std::make_pair(
    KalmanFilterParameterType::control,
    KalmanFilterExperimentParameterType::control
  ));
  v.push_back(std::make_pair(
    KalmanFilterParameterType::estimated_measurement_noise,
    KalmanFilterExperimentParameterType::estimated_measurement_noise
  ));
  v.push_back(std::make_pair(
    KalmanFilterParameterType::estimated_optimal_kalman_gain,
    KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain
  ));
  v.push_back(std::make_pair(
    KalmanFilterParameterType::estimated_process_noise_covariance,
    KalmanFilterExperimentParameterType::estimated_process_noise_covariance
  ));
  v.push_back(std::make_pair(
    KalmanFilterParameterType::initial_covariance_estimate,
    KalmanFilterExperimentParameterType::initial_covariance_estimate
  ));
  v.push_back(std::make_pair(
    KalmanFilterParameterType::initial_state_estimate,
    KalmanFilterExperimentParameterType::initial_state_estimate
  ));
  v.push_back(std::make_pair(
    KalmanFilterParameterType::observation,
    KalmanFilterExperimentParameterType::observation
  ));
  v.push_back(std::make_pair(
    KalmanFilterParameterType::state_transition,
    KalmanFilterExperimentParameterType::state_transition
  ));
  assert(boost::numeric_cast<int>(v.size())
    == static_cast<int>(KalmanFilterParameterType::n_parameters)
  );
  return v;
}

std::vector<
  std::pair<
    ribi::kalman::WhiteNoiseSystemParameterType,
    ribi::kalman::KalmanFilterExperimentParameterType
  >
>
ribi::kalman::CreateMapWhiteNoiseSystem() noexcept
{
  std::vector<
    std::pair<WhiteNoiseSystemParameterType,KalmanFilterExperimentParameterType>
  > v;
  v.push_back(std::make_pair(
    WhiteNoiseSystemParameterType::control,
    KalmanFilterExperimentParameterType::control
  ));
  v.push_back(std::make_pair(
    WhiteNoiseSystemParameterType::initial_state_real,
    KalmanFilterExperimentParameterType::initial_state_real
  ));
  v.push_back(std::make_pair(
    WhiteNoiseSystemParameterType::measurement_frequency,
    KalmanFilterExperimentParameterType::measurement_frequency
  ));
  v.push_back(std::make_pair(
    WhiteNoiseSystemParameterType::real_measurement_noise,
    KalmanFilterExperimentParameterType::real_measurement_noise
  ));
  v.push_back(std::make_pair(
    WhiteNoiseSystemParameterType::real_process_noise,
    KalmanFilterExperimentParameterType::real_process_noise
  ));
  v.push_back(std::make_pair(
    WhiteNoiseSystemParameterType::state_transition,
    KalmanFilterExperimentParameterType::state_transition
  ));
  assert(boost::numeric_cast<int>(v.size())
    == static_cast<int>(WhiteNoiseSystemParameterType::n_parameters)
  );
  return v;
}

std::vector<ribi::kalman::KalmanFilterExperimentParameterType>
  ribi::kalman::KalmanFilterExperimentParameter::GetAll() const noexcept
{
  const std::vector<KalmanFilterExperimentParameterType> v
    =
    {
      KalmanFilterExperimentParameterType::control,                            //E K W
      KalmanFilterExperimentParameterType::estimated_measurement_noise,        //E K
      KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain,      //E K
      KalmanFilterExperimentParameterType::estimated_process_noise_covariance, //E K
      KalmanFilterExperimentParameterType::initial_covariance_estimate,        //E K
      KalmanFilterExperimentParameterType::initial_state_estimate,             //E K
      KalmanFilterExperimentParameterType::measurement_frequency,              //E   W
      KalmanFilterExperimentParameterType::initial_state_real,                 //E   W
      KalmanFilterExperimentParameterType::real_measurement_noise,             //E   W
      KalmanFilterExperimentParameterType::real_process_noise,                 //E   W
      KalmanFilterExperimentParameterType::input,                              //E
      KalmanFilterExperimentParameterType::observation,                        //E K
      KalmanFilterExperimentParameterType::state_names,                        //E
      KalmanFilterExperimentParameterType::state_transition                    //E K W
    };

  assert(boost::numeric_cast<int>(v.size())
    == static_cast<int>(KalmanFilterExperimentParameterType::n_parameters)
    && "All parameters must be in"
  );
  return v;
}
bool ribi::kalman::KalmanFilterExperimentParameter::IsDouble(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  switch (type)
  {
    case KalmanFilterExperimentParameterType::control:                            return true;
    case KalmanFilterExperimentParameterType::estimated_measurement_noise:        return true;
    case KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain:      return true;
    case KalmanFilterExperimentParameterType::estimated_process_noise_covariance: return true;
    case KalmanFilterExperimentParameterType::initial_covariance_estimate:        return true;
    case KalmanFilterExperimentParameterType::initial_state_estimate:             return true;
    case KalmanFilterExperimentParameterType::initial_state_real:                 return true;
    case KalmanFilterExperimentParameterType::measurement_frequency:              return false;
    case KalmanFilterExperimentParameterType::real_measurement_noise:             return true;
    case KalmanFilterExperimentParameterType::real_process_noise:                 return true;
    case KalmanFilterExperimentParameterType::input:                              return false;
    case KalmanFilterExperimentParameterType::observation:                        return true;
    case KalmanFilterExperimentParameterType::state_names:                        return false;
    case KalmanFilterExperimentParameterType::state_transition:                   return true;
    case KalmanFilterExperimentParameterType::n_parameters:
      assert(!"n_parameters is not implemented to be used");
      return false;
  }
  assert(!"Unimplemented type");
  return false;
}

bool ribi::kalman::KalmanFilterExperimentParameter::IsFunction(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  switch (type)
  {
    case KalmanFilterExperimentParameterType::control:                            return false;
    case KalmanFilterExperimentParameterType::estimated_measurement_noise:        return false;
    case KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain:      return false;
    case KalmanFilterExperimentParameterType::estimated_process_noise_covariance: return false;
    case KalmanFilterExperimentParameterType::initial_covariance_estimate:        return false;
    case KalmanFilterExperimentParameterType::initial_state_estimate:             return false;
    case KalmanFilterExperimentParameterType::initial_state_real:                 return false;
    case KalmanFilterExperimentParameterType::measurement_frequency:              return false;
    case KalmanFilterExperimentParameterType::real_measurement_noise:             return false;
    case KalmanFilterExperimentParameterType::real_process_noise:                 return false;
    case KalmanFilterExperimentParameterType::input:                              return true;
    case KalmanFilterExperimentParameterType::observation:                        return false;
    case KalmanFilterExperimentParameterType::state_names:                        return false;
    case KalmanFilterExperimentParameterType::state_transition:                   return false;
    case KalmanFilterExperimentParameterType::n_parameters:
      assert(!"n_parameters is not implemented to be used");
      return false;
  }
  assert(!"Unimplemented type");
  return false;
}

bool ribi::kalman::KalmanFilterExperimentParameter::IsInt(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  switch (type)
  {
    case KalmanFilterExperimentParameterType::control:                            return false;
    case KalmanFilterExperimentParameterType::estimated_measurement_noise:        return false;
    case KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain:      return false;
    case KalmanFilterExperimentParameterType::estimated_process_noise_covariance: return false;
    case KalmanFilterExperimentParameterType::initial_covariance_estimate:        return false;
    case KalmanFilterExperimentParameterType::initial_state_estimate:             return false;
    case KalmanFilterExperimentParameterType::initial_state_real:                 return false;
    case KalmanFilterExperimentParameterType::measurement_frequency:              return true;
    case KalmanFilterExperimentParameterType::real_measurement_noise:             return false;
    case KalmanFilterExperimentParameterType::real_process_noise:                 return false;
    case KalmanFilterExperimentParameterType::input:                              return false;
    case KalmanFilterExperimentParameterType::observation:                        return false;
    case KalmanFilterExperimentParameterType::state_names:                        return false;
    case KalmanFilterExperimentParameterType::state_transition:                   return false;
    case KalmanFilterExperimentParameterType::n_parameters:
      assert(!"n_parameters is not implemented to be used");
      return false;
  }
  assert(!"Unimplemented type");
  return false;
}

bool ribi::kalman::KalmanFilterExperimentParameter::IsString(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  switch (type)
  {
    case KalmanFilterExperimentParameterType::control:                            return false;
    case KalmanFilterExperimentParameterType::estimated_measurement_noise:        return false;
    case KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain:      return false;
    case KalmanFilterExperimentParameterType::estimated_process_noise_covariance: return false;
    case KalmanFilterExperimentParameterType::initial_covariance_estimate:        return false;
    case KalmanFilterExperimentParameterType::initial_state_estimate:             return false;
    case KalmanFilterExperimentParameterType::initial_state_real:                 return false;
    case KalmanFilterExperimentParameterType::measurement_frequency:              return false;
    case KalmanFilterExperimentParameterType::real_measurement_noise:             return false;
    case KalmanFilterExperimentParameterType::real_process_noise:                 return false;
    case KalmanFilterExperimentParameterType::input:                              return true;
    case KalmanFilterExperimentParameterType::observation:                        return false;
    case KalmanFilterExperimentParameterType::state_names:                        return true;
    case KalmanFilterExperimentParameterType::state_transition:                   return false;
    case KalmanFilterExperimentParameterType::n_parameters:
      assert(!"n_parameters is not implemented to be used");
      return false;
  }
  assert(!"Unimplemented type");
  return false;
}

bool ribi::kalman::KalmanFilterExperimentParameter::IsMatrix(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  return !ribi::kalman::KalmanFilterExperimentParameter::IsVector(type);
}

bool ribi::kalman::KalmanFilterExperimentParameter::IsVector(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  switch (type)
  {
    case KalmanFilterExperimentParameterType::control:                            return false;
    case KalmanFilterExperimentParameterType::estimated_measurement_noise:        return false;
    case KalmanFilterExperimentParameterType::estimated_optimal_kalman_gain:      return false;
    case KalmanFilterExperimentParameterType::estimated_process_noise_covariance: return false;
    case KalmanFilterExperimentParameterType::initial_covariance_estimate:        return false;
    case KalmanFilterExperimentParameterType::initial_state_estimate:             return true;
    case KalmanFilterExperimentParameterType::initial_state_real:                 return true;
    case KalmanFilterExperimentParameterType::measurement_frequency:              return true;
    case KalmanFilterExperimentParameterType::real_measurement_noise:             return true;
    case KalmanFilterExperimentParameterType::real_process_noise:                 return true;
    case KalmanFilterExperimentParameterType::input:                              return true;
    case KalmanFilterExperimentParameterType::observation:                        return false;
    case KalmanFilterExperimentParameterType::state_names:                        return true;
    case KalmanFilterExperimentParameterType::state_transition:                   return false;
    case KalmanFilterExperimentParameterType::n_parameters:
      assert(!"n_parameters is not implemented to be used");
      return false;
  }
  assert(!"Unimplemented type");
  return false;
}

std::string ribi::kalman::KalmanFilterExperimentParameter::ToDescription(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  //Check for the subset
  if (CanConvertToKalmanFilterParameter(type))
  {
    const KalmanFilterParameterType sub_type = ConvertToKalmanFilterParameter(type);
    return KalmanFilterParameter().ToDescription(sub_type);
  }
  if (CanConvertToWhiteNoiseSystemParameter(type))
  {
    const WhiteNoiseSystemParameterType sub_type = ConvertToWhiteNoiseSystemParameter(type);
    return WhiteNoiseSystemParameter().ToDescription(sub_type);
  }
  //Check the unique types
  switch (type)
  {
    case KalmanFilterExperimentParameterType::input:
      return "Vector of inputs";
    default: assert(type == KalmanFilterExperimentParameterType::state_names);
      return "Vector of the state element names";
  }
}

std::string ribi::kalman::KalmanFilterExperimentParameter::ToName(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  //Check for the subset
  if (CanConvertToKalmanFilterParameter(type))
  {
    const KalmanFilterParameterType sub_type = ConvertToKalmanFilterParameter(type);
    return KalmanFilterParameter().ToName(sub_type);
  }
  if (CanConvertToWhiteNoiseSystemParameter(type))
  {
    const WhiteNoiseSystemParameterType sub_type = ConvertToWhiteNoiseSystemParameter(type);
    return WhiteNoiseSystemParameter().ToName(sub_type);
  }
  //Check the unique types
  switch (type)
  {
    case KalmanFilterExperimentParameterType::input:
      return "Input";
    default: assert(type == KalmanFilterExperimentParameterType::state_names);
      return "State names";
  }
}

std::string ribi::kalman::KalmanFilterExperimentParameter::ToSymbol(
  const KalmanFilterExperimentParameterType type
) const noexcept
{
  //Check for the subset
  if (CanConvertToKalmanFilterParameter(type))
  {
    const KalmanFilterParameterType sub_type = ConvertToKalmanFilterParameter(type);
    return KalmanFilterParameter().ToSymbol(sub_type);
  }
  if (CanConvertToWhiteNoiseSystemParameter(type))
  {
    const WhiteNoiseSystemParameterType sub_type = ConvertToWhiteNoiseSystemParameter(type);
    return WhiteNoiseSystemParameter().ToSymbol(sub_type);
  }
  //Check the unique types
  switch (type)
  {
    case KalmanFilterExperimentParameterType::input:
      return "y";
    default: assert(type == KalmanFilterExperimentParameterType::state_names);
      return ""; //State names has no symbol
  }
}
