#include <iostream>

#include "qtkalmanfilterermaindialog_test.h"
#include "qtwhitenoisesystemparametersdialog_test.h"

#include <QtTest/QtTest>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  int error = 0;

  { ribi::kalman::QtKalmanFiltererMainDialogTest t; error |= QTest::qExec(&t, argc, argv); }

  if (error == 0) { std::cout << "Pass\n"; }
  if (error != 0) { std::cout << "Fail\n"; }
  return error;
}
