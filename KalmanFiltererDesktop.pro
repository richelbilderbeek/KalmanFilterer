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

# Qwt
# Normal compiling
LIBS += -lqwt-qt5
INCLUDEPATH += /usr/include/qwt
