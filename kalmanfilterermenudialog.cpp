

#include "kalmanfilterermenudialog.h"

#include "container.h"
#include "fixedlagsmootherkalmanfilter.h"
#include "fixedlagsmootherkalmanfilterfactory.h"
#include "gapsfilledwhitenoisesystem.h"
#include "gapsfilledwhitenoisesystemfactory.h"
#include "kalmanfilterfactory.h"
#include "laggedwhitenoisesystem.h"
#include "matrix.h"
#include "standardkalmanfilter.h"
#include "standardkalmanfilterparameters.h"
#include "standardwhitenoisesystem.h"
#include "standardwhitenoisesystemparameters.h"
#include "steadystatekalmanfilter.h"
#include "steadystatekalmanfilterparameters.h"


int ribi::kalman::KalmanFiltererMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc > 1)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }
  std::cout << "KalmanFilterer does not have a command-line version\n";
  return 0;
}

ribi::About ribi::kalman::KalmanFiltererMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "KalmanFilterer",
    "tool to work with Kalman filters",
    "[date unknown]",
    "2013-2019",
    "https://github.com/richelbilderbeek/KalmanFilterer",
    GetVersion(),
    GetVersionHistory()
  );
  return a;
}

ribi::Help ribi::kalman::KalmanFiltererMenuDialog::GetHelp() const noexcept
{
  return ribi::Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {
      //Options
    },
    {
      //Example options
    }
  );
}

std::string ribi::kalman::KalmanFiltererMenuDialog::GetVersion() const noexcept
{
  return "2.1";
}

std::vector<std::string> ribi::kalman::KalmanFiltererMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2013-04-28: version 1.0: initial Qt4 and Boost 1.49.0 version that started from CppKalmanFilterExample13",
    "2013-05-01: version 1.1: added plotting, added steady-state Kalman filter",
    "2013-05-02: version 1.2: fixed messed-up graphs and calculation displayal",
    "2013-05-03: version 1.3: improved parameters GUI and use",
    "2013-05-06: version 1.4: prepared architecture for expansion",
    "2013-05-16: version 1.5: use of model/view architecture, preparations for adding fixed-lag-smoother Kalman filter",
    "2013-05-28: version 1.6: added loading (from DokuWiki) and saving (to DokuWiki and HTML) of parameters",
    "2013-05-28: version 1.7: added possibility to save graphs to file",
    "2013-06-13: version 1.8: fixed bug in parameter tables, allow to view data as a table",
    "2013-06-14: version 1.9: allow to copy data from table",
    "2013-06-17: version 1.10: removed useless examples",
    "2013-06-27: version 1.11: added gaps-filled white noise system, added versioning to parameter files for backwards compatibility",
    "2013-07-01: version 1.12: added the constants pi and tau to function parser, context can be saved to file, tables are displayed correctly",
    "2013-07-05: version 1.13: added simple statistics",
    "2013-07-08: version 1.14: display statistics and value tables correctly, allow editing of context, tables resize to the number of rows",
    "2013-07-17: version 1.15: allow copying from and pasting to parameter tables, transitioned to Qt5, GCC 4.8.0 and Boost 1.54.0, able to crosscompile again",
    "2014-08-10: version 1.16: increased use of TDD",
    "2015-01-03: version 1.17: set locale to English in Desktop version", //SET_LOCALE_TO_ENGLISH_MODELFUNCTIONPARSER
    "2015-01-04: version 1.18: made locale local",
    "2015-11-21: version 2.0: moved to own GitHub",
    "201x-xx-xx: version 2.1: use of Boost.Test, clean OCLint"
  };
}
