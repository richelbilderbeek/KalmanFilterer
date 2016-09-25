#include "kalmanfiltertypes.h"

boost::bimap<
  ribi::kalman::KalmanFilterType,std::string
> ribi::kalman::KalmanFilterTypes::m_map;

boost::bimap<
  ribi::kalman::KalmanFilterType,std::string
> ribi::kalman::KalmanFilterTypes::CreateMap() noexcept
{
  boost::bimap<KalmanFilterType,std::string> m;
  m.insert(boost::bimap<KalmanFilterType,std::string>::value_type(
    KalmanFilterType::fixed_lag_smoother,"fixed lag smoother"));
  m.insert(boost::bimap<KalmanFilterType,std::string>::value_type(
    KalmanFilterType::standard,"discrete"));
  m.insert(boost::bimap<KalmanFilterType,std::string>::value_type(
    KalmanFilterType::steady_state,"steady state"));
  return m;
}

std::vector<ribi::kalman::KalmanFilterType>
  ribi::kalman::KalmanFilterTypes::GetAllTypes() const noexcept
{
  const std::vector<KalmanFilterType> v
  =
  {
    KalmanFilterType::fixed_lag_smoother,
    KalmanFilterType::standard,
    KalmanFilterType::steady_state
  };
  assert(static_cast<int>(v.size()) == static_cast<int>(KalmanFilterType::n_types));
  return v;
}

std::string ribi::kalman::KalmanFilterTypes::ToStr(
  const KalmanFilterType type
) const noexcept
{
  if (m_map.left.empty()) m_map = CreateMap();
  assert(!m_map.left.empty());
  assert(m_map.left.count(type));
  const std::string s = m_map.left.find(type)->second;
  return s;
}

ribi::kalman::KalmanFilterType ribi::kalman::KalmanFilterTypes::ToType(
  const std::string& s
) const
{
  if (m_map.right.empty()) m_map = CreateMap();
  assert(!m_map.right.empty());
  assert(m_map.right.count(s) == 1);
  const KalmanFilterType t = m_map.right.find(s)->second;
  return t;
}
