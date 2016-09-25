include(../RibiLibraries/DesktopApplicationNoWeffcpp.pri) #Qwt does not go well with -Weffc++

include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/Fparser.pri)
include(../RibiLibraries/GeneralConsole.pri)
include(../RibiLibraries/GeneralDesktop.pri)
include(../RibiLibraries/Qwt.pri)

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
