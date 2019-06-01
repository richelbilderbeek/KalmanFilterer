include(../RibiLibraries/Fparser.pri)
include(../RibiClasses/CppAbout/CppAbout.pri)
include(../RibiClasses/CppFileIo/CppFileIo.pri)
include(../RibiClasses/CppHelp/CppHelp.pri)
include(../RibiClasses/CppMenuDialog/CppMenuDialog.pri)

include(../RibiClasses/CppContainer/CppContainer.pri)
include(../RibiClasses/CppFuzzy_equal_to/CppFuzzy_equal_to.pri)
include(../KalmanFilterer/KalmanFilter.pri)
include(../RibiClasses/CppMatrix/CppMatrix.pri)
include(../RibiClasses/CppQtMatrix/CppQtMatrix.pri)
include(../RibiClasses/CppQtModel/CppQtModel.pri)
include(../RibiClasses/CppRibiRandom/CppRibiRandom.pri)
include(../RibiClasses/CppTempLocale/CppTempLocale.pri)
include(KalmanFiltererConsole.pri)
include(KalmanFilterTestConsole.pri)

SOURCES += main_test.cpp

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++14

# High warning levels
# Qt does not go well with -Weffc++
QMAKE_CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic
# FunctionParser has many compile warning
# -Werror

# Debug and release mode
CONFIG += debug_and_release

# In release mode, define NDEBUG
CONFIG(release, debug|release) {

  DEFINES += NDEBUG

  # gprof
  QMAKE_CXXFLAGS += -pg
  QMAKE_LFLAGS += -pg

  # GSL
  DEFINES += GSL_UNENFORCED_ON_CONTRACT_VIOLATION
}

# In debug mode, turn on gcov and UBSAN
CONFIG(debug, debug|release) {

  # gcov
  QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
  LIBS += -lgcov

  # UBSAN
  QMAKE_CXXFLAGS += -fsanitize=undefined
  QMAKE_LFLAGS += -fsanitize=undefined
  LIBS += -lubsan

  # gprof
  QMAKE_CXXFLAGS += -pg
  QMAKE_LFLAGS += -pg
}

# Qt
QT += core gui widgets

# Prevent Qt for failing with this error:
# qrc_[*].cpp:400:44: error: ‘qInitResources_[*]__init_variable__’ defined but not used
# [*]: the resource filename
QMAKE_CXXFLAGS += -Wno-unused-variable

# Fixes
#/usr/include/boost/math/constants/constants.hpp:277: error: unable to find numeric literal operator 'operator""Q'
#   BOOST_DEFINE_MATH_CONSTANT(half, 5.000000000000000000000000000000000000e-01, "5.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000e-01")
#   ^
QMAKE_CXXFLAGS += -fext-numeric-literals

# Boost.Test
LIBS += -lboost_unit_test_framework

# Qwt
# Normal compiling
LIBS += -lqwt-qt5
INCLUDEPATH += /usr/include/qwt
