#ifndef KALMANFILTERTYPES_H
#define KALMANFILTERTYPES_H

#include <string>
#include <vector>




#include <boost/bimap.hpp>


#include "kalmanfiltertype.h"


namespace ribi {
namespace kalman {

///Class to work on one or more KalmanFilterType instances
struct KalmanFilterTypes
{
  KalmanFilterTypes();
  std::vector<KalmanFilterType> GetAllTypes() const noexcept;
  std::string ToStr(const KalmanFilterType type) const noexcept;
  KalmanFilterType ToType(const std::string& s) const;

  private:
  const boost::bimap<KalmanFilterType,std::string> m_map;
};

boost::bimap<KalmanFilterType,std::string> CreateKalmanFilterTypesMap() noexcept;

} //~namespace kalman
} //~namespace ribi

#endif // KALMANFILTERTYPES_H
