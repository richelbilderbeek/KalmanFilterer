#ifndef KALMANFILTEREXAMPLE_H
#define KALMANFILTEREXAMPLE_H

#include <memory>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/checked_delete.hpp>
#include <boost/shared_ptr.hpp>
#pragma GCC diagnostic pop

#include "standardkalmanfilterparameters.h"
#include "standardwhitenoisesystemparameters.h"


namespace ribi {
namespace kalman {

///KalmanFilterExample contains an example set of variables
struct KalmanFilterExample
{
  explicit KalmanFilterExample(
    const std::string& title,
    const std::string& context,
    const std::vector<std::string>& inputs,
    const boost::shared_ptr<const StandardKalmanFilterParameters>&
      kf_parameters, //kalman_filter_parameters
    const int number_of_timesteps,
    const std::vector<std::string>& state_names,
    const boost::shared_ptr<const StandardWhiteNoiseSystemParameters>&
      wns_parameters //white_noise_system_parameters
    );

  const std::string& GetContext() const { return m_context; }
  const std::vector<std::string>& GetInputs() const { return m_inputs; }
  const auto& GetKalmanFilterParameters() const
    { return m_kalman_filter_parameters; }
  int GetNumberOfTimesteps() const { return m_number_of_timesteps; }
  const std::vector<std::string>& GetStateNames() const { return m_state_names; }
  const std::string& GetTitle() const { return m_title; }
  const auto& GetWhiteNoiseSystemParameters() const
    { return  m_white_noise_system_parameters; }

  private:
  ///Can only be deleted by boost::checked_delete
  ~KalmanFilterExample() noexcept {}
  ///Can only be deleted by smart pointers: boost::checked_delete and std::unique_ptr
  friend void boost::checked_delete<>(KalmanFilterExample*);
  friend void boost::checked_delete<>(const KalmanFilterExample*);
  friend struct std::default_delete<KalmanFilterExample>;

  const std::string m_context;
  const std::vector<std::string> m_inputs;
  const boost::shared_ptr<const StandardKalmanFilterParameters> m_kalman_filter_parameters;
  const int m_number_of_timesteps;
  const std::vector<std::string> m_state_names;
  const std::string m_title;
  const boost::shared_ptr<
    const StandardWhiteNoiseSystemParameters
  > m_white_noise_system_parameters;

};

std::vector<boost::shared_ptr<KalmanFilterExample> > CreateExamples() noexcept;

///Throws if i is out of range
std::unique_ptr<KalmanFilterExample> CreateExample(const int i);

std::unique_ptr<KalmanFilterExample> CreateExample0() noexcept;
std::unique_ptr<KalmanFilterExample> CreateExample1() noexcept;
std::unique_ptr<KalmanFilterExample> CreateExample2() noexcept;
std::unique_ptr<KalmanFilterExample> CreateExample3() noexcept;
std::unique_ptr<KalmanFilterExample> CreateExample4() noexcept;
std::unique_ptr<KalmanFilterExample> CreateExample5() noexcept;
std::unique_ptr<KalmanFilterExample> CreateExample6() noexcept;
std::unique_ptr<KalmanFilterExample> CreateExample7() noexcept;
std::unique_ptr<KalmanFilterExample> CreateExample8() noexcept;

std::string DisplayAsUblasVector(const std::vector<std::string>& v);

} //~namespace kalman
} //~namespace ribi

#endif // KALMANFILTEREXAMPLE_H
