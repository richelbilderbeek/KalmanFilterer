#ifndef QTKALMANFILTERERMAINDIALOG_TEST_H
#define QTKALMANFILTERERMAINDIALOG_TEST_H

#include <QtTest/QtTest>

namespace ribi {
namespace kalman {

class QtKalmanFiltererMainDialogTest : public QObject
{
    Q_OBJECT //!OCLINT

private slots:
  void all_tests();
};

} //~namespace kalman
} //~namespace ribi


#endif // QTKALMANFILTERERMAINDIALOG_TEST_H
