win32 {
  # Windows only
  message("Console application, built for Windows")
  QMAKE_CXXFLAGS += -std=c++1y -Wall -Wextra -Weffc++
}

macx {
  # Mac only
  message("Console application, built for Mac")
  QMAKE_CXXFLAGS = -mmacosx-version-min=10.7 -std=gnu0x -stdlib=libc+
  CONFIG +=c++1y
}

unix:!macx{
  # Linux only
  message("Console application, built for Linux")

  CONFIG += c++14
  QMAKE_CXX = g++-5
  QMAKE_LINK = g++-5
  QMAKE_CC = gcc-5

  # Cannot use -Weffc++ due to function parser
  QMAKE_CXXFLAGS += -Wall -Wextra -Werror -std=c++14
}

# Go ahead and use Qt.Core: it is about as platform-independent as
# the STL and Boost
QT += core

# Go ahead and use Qt.Gui: it is about as platform-independent as
# the STL and Boost. It is needed for QImage
QT += gui widgets

# Don't define widgets: it would defy the purpose of this console
# application to work non-GUI
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

#
#
# Type of compile
#
#

CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}



include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppContainer/CppContainer.pri)
include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMatrix/CppMatrix.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)
include(../RibiClasses/CppQtAboutDialog/CppQtAboutDialog.pri)
include(../RibiClasses/CppQtHideAndShowDialog/CppQtHideAndShowDialog.pri)
include(../RibiClasses/CppQtMatrix/CppQtMatrix.pri)
include(../RibiClasses/CppQtModel/CppQtModel.pri)
include(../RibiClasses/CppRibiRandom/CppRibiRandom.pri)
include(../RibiClasses/CppRibiRegex/CppRibiRegex.pri)
include(../RibiClasses/CppTestTimer/CppTestTimer.pri)
include(../RibiClasses/CppTempLocale/CppTempLocale.pri)
include(../RibiClasses/CppTrace/CppTrace.pri)
include(../RibiLibraries/Fparser.pri)
include(../RibiLibraries/Qwt.pri)

include(KalmanFilter.pri)
include(KalmanFiltererDesktop.pri)
include(KalmanFilterTestDesktop.pri)

SOURCES += qtmain_test.cpp

# QTest
QT += testlib

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

# Boost.Graph
LIBS += \
  -lboost_date_time \
  -lboost_graph \
  -lboost_regex

# QResources give this error
QMAKE_CXXFLAGS += -Wno-unused-variable

# QtConcurrent::ThreadEngineStarter gives this error
QMAKE_CXXFLAGS += -Wno-unused-local-typedefs
