#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "qtwhitenoisesystemparametersdialog_test.h"
#include "qtwhitenoisesystemparametersdialog.h"

#include <cassert>

#include <boost/lexical_cast.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include <QKeyEvent>
#include <QVBoxLayout>

#include "gapsfilledwhitenoisesystemfactory.h"
#include "laggedwhitenoisesystemfactory.h"
#include "kalmanfilterexperimentparameter.h"
#include "laggedwhitenoisesystem.h"
#include "laggedwhitenoisesystemfactory.h"
#include "laggedwhitenoisesystemparameters.h"
#include "matrix.h"
#include "testtimer.h"
#include "qtkalmanfiltererparameterdialog.h"
#include "qtmatrix.h"
#include "qtublasvectorintmodel.h"
#include "standardwhitenoisesystem.h"
#include "standardwhitenoisesystemfactory.h"
#include "standardwhitenoisesystemparameters.h"
#include "trace.h"
#include "ui_qtwhitenoisesystemparametersdialog.h"
#include "whitenoisesystemparameter.h"
#include "whitenoisesystemparametertype.h"

#pragma GCC diagnostic pop

void ribi::kalman::QtWhiteNoiseSystemParametersDialogTest::all_tests()
{
  {
    const boost::shared_ptr<QtKalmanFilterExperimentModel> model(new QtKalmanFilterExperimentModel);
    assert(model);

    QtWhiteNoiseSystemParametersDialog d(model);
    d.GetUi()->box_white_noise_system_type->setCurrentIndex(0);
    assert(d.GetWhiteNoiseSystemType() == WhiteNoiseSystemType::standard);
    assert(model->CreateWhiteNoiseSystemParameters()->GetType() == WhiteNoiseSystemType::standard);
    assert(!d.Find(WhiteNoiseSystemParameterType::measurement_frequency)->isVisible());
    assert(model->CreateWhiteNoiseSystemParameters());
    assert(model->CreateWhiteNoiseSystem());

    d.GetUi()->box_white_noise_system_type->setCurrentIndex(1);
    assert(d.GetWhiteNoiseSystemType() == WhiteNoiseSystemType::lagged);
    assert(model->CreateWhiteNoiseSystemParameters()->GetType() == WhiteNoiseSystemType::lagged);
    assert(!d.Find(WhiteNoiseSystemParameterType::measurement_frequency)->isVisible());
    assert(model->CreateWhiteNoiseSystemParameters());
    assert(model->CreateWhiteNoiseSystem());

    d.GetUi()->box_white_noise_system_type->setCurrentIndex(2);
    //assert(d.Find(WhiteNoiseSystemParameterType::measurement_frequency)->isVisible());
    assert(d.GetWhiteNoiseSystemType() == WhiteNoiseSystemType::gaps_filled);
    assert(model->Find(KalmanFilterExperimentParameterType::measurement_frequency));
    assert(model->CreateWhiteNoiseSystem());
    assert(model->CreateWhiteNoiseSystemParameters());
    assert(model->CreateWhiteNoiseSystemParameters()->GetType() == WhiteNoiseSystemType::gaps_filled);
  }
}
