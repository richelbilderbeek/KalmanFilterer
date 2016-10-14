#include "whitenoisesystemtypes.h"

ribi::kalman::WhiteNoiseSystemTypes::WhiteNoiseSystemTypes()
  : m_map{CreateWhiteNoiseSystemTypeMap()}
{
}

boost::bimap<ribi::kalman::WhiteNoiseSystemType,std::string>
ribi::kalman::CreateWhiteNoiseSystemTypeMap() noexcept
{

  boost::bimap<WhiteNoiseSystemType,std::string> m;
  m.insert(boost::bimap<WhiteNoiseSystemType,std::string>::value_type(
    WhiteNoiseSystemType::gaps_filled,"gaps_filled"));
  m.insert(boost::bimap<WhiteNoiseSystemType,std::string>::value_type(
    WhiteNoiseSystemType::lagged,"lagged"));
  m.insert(boost::bimap<WhiteNoiseSystemType,std::string>::value_type(
    WhiteNoiseSystemType::standard,"standard"));
  return m;
}

std::vector<ribi::kalman::WhiteNoiseSystemType>
  ribi::kalman::WhiteNoiseSystemTypes::GetAllTypes() const noexcept
{
  const std::vector<WhiteNoiseSystemType> v {
    WhiteNoiseSystemType::gaps_filled,
    WhiteNoiseSystemType::lagged,
    WhiteNoiseSystemType::standard
  };
  assert(static_cast<int>(v.size())
    == static_cast<int>(WhiteNoiseSystemType::n_types)
  );
  return v;
}

std::string ribi::kalman::WhiteNoiseSystemTypes::ToStr(
  const WhiteNoiseSystemType type
) const noexcept
{
  assert(!m_map.left.empty());
  assert(m_map.left.count(type) == 1);
  const std::string s = m_map.left.find(type)->second;
  return s;
}

ribi::kalman::WhiteNoiseSystemType ribi::kalman::WhiteNoiseSystemTypes::ToType(
  const std::string& s
) const
{
  assert(!m_map.right.empty());
  assert(m_map.right.count(s) == 1);
  return m_map.right.find(s)->second;
}
