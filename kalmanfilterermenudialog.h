#ifndef KALMANFILTERERMENUDIALOG_H
#define KALMANFILTERERMENUDIALOG_H

#include <string>
#include <vector>

#include "about.h"
#include "menudialog.h"
#include "help.h"

namespace ribi {
namespace kalman {

///GUI independent KalmanFilterer menu dialog
struct KalmanFiltererMenuDialog final : public ribi::MenuDialog
{
  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;
};

} //~namespace kalman
} //~namespace ribi

#endif // KALMANFILTERERMENUDIALOG_H
