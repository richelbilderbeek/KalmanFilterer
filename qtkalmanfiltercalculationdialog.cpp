



#include "qtkalmanfiltercalculationdialog.h"

#include <boost/lexical_cast.hpp>

#include "ui_qtkalmanfiltercalculationdialog.h"



ribi::kalman::QtKalmanFilterCalculationDialog
  ::QtKalmanFilterCalculationDialog(QWidget *parent) :
  QtHideAndShowDialog(parent),
  ui(new Ui::QtKalmanFilterCalculationDialog)
{
  ui->setupUi(this);
}

ribi::kalman::QtKalmanFilterCalculationDialog
  ::~QtKalmanFilterCalculationDialog() noexcept
{
  delete ui;
}

