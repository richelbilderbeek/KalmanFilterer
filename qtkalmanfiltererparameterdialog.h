#ifndef QTKALMANFILTERERPARAMETERDIALOG
#define QTKALMANFILTERERPARAMETERDIALOG

#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qthideandshowdialog.h"
#include <QTableWidgetItem>
#pragma GCC diagnostic pop

namespace Ui {
  class QtKalmanFiltererParameterDialog;
}

namespace ribi {
namespace kalman {

///Dialog for a parameter, stores a QtKalmanFiltererParameterDialog::ValueType
class QtParameterDialog : public QtHideAndShowDialog
{
    Q_OBJECT //!OCLINT

public:
  QtParameterDialog(const QtParameterDialog&) = delete;
  QtParameterDialog& operator=(const QtParameterDialog&) = delete;

  explicit QtParameterDialog(
    const std::string& parameter_name,
    const std::string& description, //parameter_description
    QAbstractTableModel * const model,
    QWidget *parent = 0);

  ~QtParameterDialog() noexcept;

  ///Convert the table and its content to HTML
  std::string ToHtml() const;

signals:
  ///Emitted when table changes from/to a valid to/from an invalid state
  void signal_state_changed();

protected:
  void keyPressEvent(QKeyEvent * event);

private:
  Ui::QtKalmanFiltererParameterDialog *ui;

private slots:
  void OnModelSizeChanged();
};

} //~namespace kalman
} //~namespace ribi

#endif // QTKALMANFILTERERPARAMETERDIALOG
