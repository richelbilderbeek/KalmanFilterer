#ifndef WHITENOISESYSTEMTYPES_H
#define WHITENOISESYSTEMTYPES_H

#include <string>
#include <vector>

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/bimap.hpp>
#pragma GCC diagnostic pop

#include "whitenoisesystemtype.h"

namespace ribi {
namespace kalman {

struct WhiteNoiseSystemTypes
{
  WhiteNoiseSystemTypes();
  std::vector<WhiteNoiseSystemType> GetAllTypes() const noexcept;
  std::string ToStr(const WhiteNoiseSystemType type) const noexcept;
  WhiteNoiseSystemType ToType(const std::string& s) const;

  private:
  const boost::bimap<WhiteNoiseSystemType,std::string> m_map;
};

boost::bimap<WhiteNoiseSystemType,std::string> CreateWhiteNoiseSystemTypeMap() noexcept;

} //~namespace kalman
} //~namespace ribi

#endif // WHITENOISESYSTEMTYPES_H
