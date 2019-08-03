#ifndef QTCOPYALLTABLEVIEW_H
#define QTCOPYALLTABLEVIEW_H



#include <QTableView>


#include <string>
#include <vector>

namespace ribi {

class QtCopyAllTableView : public QTableView
{
  public:
  explicit QtCopyAllTableView(QWidget *parent = 0);

  protected:
  void keyPressEvent(QKeyEvent *event);
};

} //~namespace ribi

#endif // QTCOPYALLTABLEVIEW_H
