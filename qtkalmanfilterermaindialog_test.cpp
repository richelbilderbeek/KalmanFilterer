#pragma GCC diagnostic push



#include "qtkalmanfilterermaindialog_test.h"
#include "qtkalmanfilterermaindialog.h"

#include <cassert>
#include <cstdlib>

#include <boost/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/numeric/ublas/functional.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/signals2.hpp>

#include <QDesktopWidget>
#include <QKeyEvent>
#include <QLabel>
#include <QMessageBox>
#include <QFileDialog>
#include <QPainter>
#include <QVBoxLayout>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_grid.h>
//#include <qwt_plot_seriesitem.h>
#include <qwt_legend.h>

#if QWT_VERSION >= 0x060100
#include <qwt_point_data.h>
#endif

#include "kalmanfilter.h"
#include "kalmanfilterexample.h"
#include "kalmanfilterexperiment.h"
#include "kalmanfilterexperimentparametertype.h"
#include "kalmanfilterparameters.h"
#include "matrix.h"
#include "qtcopyalltablewidget.h"
#include "qtfixedlagsmootherkalmanfiltercalculationdialog.h"
#include "qtkalmanfilterdialog.h"
#include "qtkalmanfilterexamplesdialog.h"
#include "qtkalmanfilterexperimentmodel.h"
#include "qtkalmanfilterexperimentdialog.h"
#include "qtmatrix.h"
#include "qtstandardkalmanfiltercalculationdialog.h"
#include "qtsteadystatekalmanfiltercalculationdialog.h"
#include "qtwhitenoisesystemparametersdialog.h"
#include "standardwhitenoisesystemparameters.h"
#include "ui_qtkalmanfilterermaindialog.h"

//#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
//Due to Qmake error
//http://richelbilderbeek.nl/CppQmakeErrorUnknownModulesInQtLocationSensors.htm
#define DISABLE_QWEBVIEW
//#endif

#pragma GCC diagnostic pop


void ribi::kalman::QtKalmanFiltererMainDialogTest::all_tests()
{
  return; // TODO

  //if (verbose) { TRACE("ribi::kalman::QtKalmanFiltererMainDialog: Create self"); }
  {
    const boost::shared_ptr<QtKalmanFiltererMainDialog> d
      = ribi::kalman::QtKalmanFiltererMainDialog::Create();
    assert(d);
    assert(d->GetModel());
    d->GetModel()->SetNumberOfTimesteps(1); //Otherwise these tests take too long
    d->SetShowCalculation(true);
    d->SetShowGraph(true);
    d->SetShowStatistics(true);
    d->SetShowTable(true);
    d->show();
    d->on_button_start_clicked();
    d->show();
  }
  //if (verbose) { TRACE("ribi::kalman::QtKalmanFiltererMainDialog: (1/2) Click on example x and write these to a DokuWiki file"); }
  //if (verbose) { TRACE("ribi::kalman::QtKalmanFiltererMainDialog: (2/2) Click on example y and read the file from x"); }
  {
    const boost::shared_ptr<QtKalmanFiltererMainDialog> d
      = ribi::kalman::QtKalmanFiltererMainDialog::Create();
    assert(d);
    assert(d->GetModel());
    assert(d->GetExperimentDialog());
    d->GetModel()->SetNumberOfTimesteps(2); //Otherwise these tests take too long
    const std::string filename = "TempQtKalmanFiltererMainDialogTest.txt";
    const int n_examples = 1; //Can be changed to 6
    for (int x = 0; x!= n_examples; ++x)
    {
      //1) Click on example x and write these to a DokuWiki file
      {
        d->GetExperimentDialog()->GetExamplesDialog()->EmitExample(x);
        d->GetModel()->SetNumberOfTimesteps(2); //Otherwise these tests take too long
        d->GetExperimentDialog()->SaveToDokuWiki(filename);
      }
      for (int y = 0; y!= n_examples; ++y)
      {
        //2) Click on example y and read the file from x
        d->GetExperimentDialog()->GetExamplesDialog()->EmitExample(y);
        d->GetModel()->SetNumberOfTimesteps(2); //Otherwise these tests take too long
        d->GetExperimentDialog()->LoadFromDokuWiki(filename);
      }
    }
    //Delete file
    std::remove(filename.c_str());
  }
}
