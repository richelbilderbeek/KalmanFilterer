CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14

# Cannot use -Weffc++ due to function parser
# Cannot use -Werror due to function parser
QMAKE_CXXFLAGS += -Wall -Wextra

QT += core gui widgets

TEMPLATE = app

CONFIG += debug_and_release
CONFIG(release, debug|release) {
  message(Release mode)
  DEFINES += NDEBUG
}

include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/Fparser.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)

include(../RibiClasses/CppContainer/CppContainer.pri)
include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../RibiClasses/CppMatrix/CppMatrix.pri)
include(../RibiClasses/CppQtMatrix/CppQtMatrix.pri)
include(../RibiClasses/CppQtModel/CppQtModel.pri)
include(../RibiClasses/CppRibiRandom/CppRibiRandom.pri)
include(../RibiClasses/CppRibiRegex/CppRibiRegex.pri)
include(../RibiClasses/CppTempLocale/CppTempLocale.pri)
include(KalmanFilter.pri)
include(KalmanFiltererDesktop.pri)

SOURCES += qtmain.cpp

# Thanks to Qt
QMAKE_CXXFLAGS += -Wno-unused-variable

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

# Fixes
#/usr/include/boost/math/constants/constants.hpp:277: error: unable to find numeric literal operator 'operator""Q'
#   BOOST_DEFINE_MATH_CONSTANT(half, 5.000000000000000000000000000000000000e-01, "5.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e-01")
#   ^
QMAKE_CXXFLAGS += -fext-numeric-literals

# Qwt
# Normal compiling
LIBS += -lqwt-qt5
INCLUDEPATH += /usr/include/qwt

# For crosscompiling
#INCLUDEPATH += /home/richel/GitHubs/RibiLibraries/mxe/usr/i686-w64-mingw32.static/qt5/include
#LIBS += -lqwt
#QT += svg

