#ifndef TELEMETRY_H
#define TELEMETRY_H

#include "modelpanel.h"
#include <QGroupBox>
#include <QComboBox>
#include <QDoubleSpinBox>

namespace Ui {
  class TelemetryAnalog;
  class TelemetryCustomScreen;
  class Telemetry;
}

class TelemetryAnalog: public ModelPanel
{
    Q_OBJECT

    friend class TelemetryPanel;

  public:
    TelemetryAnalog(QWidget *parent, FrSkyChannelData & analog, ModelData & model, GeneralSettings & generalSettings, FirmwareInterface * firmware);
    virtual ~TelemetryAnalog();

  signals:
    void modified();

  private slots:
    void on_UnitCB_currentIndexChanged(int index);
    void on_RatioSB_editingFinished();
    void on_RatioSB_valueChanged();
    void on_CalibSB_editingFinished();
    void on_alarm1LevelCB_currentIndexChanged(int index);
    void on_alarm1GreaterCB_currentIndexChanged(int index);
    void on_alarm1ValueSB_editingFinished();
    void on_alarm2LevelCB_currentIndexChanged(int index);
    void on_alarm2GreaterCB_currentIndexChanged(int index);
    void on_alarm2ValueSB_editingFinished();

  private:
    Ui::TelemetryAnalog *ui;
    FrSkyChannelData & analog;
    bool lock;

    void update();
};

class TelemetryCustomScreen: public ModelPanel
{
    Q_OBJECT

  public:
    TelemetryCustomScreen(QWidget *parent, ModelData & model, FrSkyScreenData & screen, GeneralSettings & generalSettings, FirmwareInterface * firmware);
    ~TelemetryCustomScreen();
    void update();

  private slots:
    void on_screenType_currentIndexChanged(int index);
    void customFieldChanged(int index);
    void barSourceChanged(int index);
    void barMinChanged(double value);
    void barMaxChanged(double value);

  protected:
    void populateTelemetrySourceCB(QComboBox *b, unsigned int value, bool last, int hubproto);

  private:
    void updateBar(int line);
    Ui::TelemetryCustomScreen * ui;
    FrSkyScreenData & screen;
    QComboBox * fieldsCB[4][3];
    QComboBox * barsCB[4];
    QDoubleSpinBox * minSB[4];
    QDoubleSpinBox * maxSB[4];
};

class TelemetryPanel : public ModelPanel
{
    Q_OBJECT

  public:
    TelemetryPanel(QWidget *parent, ModelData & model, GeneralSettings & generalSettings, FirmwareInterface * firmware);
    virtual ~TelemetryPanel();
    virtual void update();

  private slots:
    void on_telemetryProtocol_currentIndexChanged(int index);
    void on_telemetryCom_currentIndexChanged(int index);
    void on_telemetryBaud_currentIndexChanged(int index);
    void on_telemetryMirrorCom_currentIndexChanged(int index);
    
    
    void onAnalogModified();
    void on_frskyProtoCB_currentIndexChanged(int index);
    void on_bladesCount_editingFinished();
    void on_AltitudeToolbar_ChkB_toggled(bool checked);
    void on_rssiAlarm1CB_currentIndexChanged(int index);
    void on_rssiAlarm2CB_currentIndexChanged(int index);
    void on_rssiAlarm1SB_editingFinished();
    void on_rssiAlarm2SB_editingFinished();
    void on_AltitudeGPS_ChkB_toggled(bool checked);
    void on_varioLimitMin_DSB_editingFinished();
    void on_varioLimitMax_DSB_editingFinished();
    void on_varioLimitCenterMin_DSB_editingFinished();
    void on_varioLimitCenterMax_DSB_editingFinished();
    void on_fasOffset_DSB_editingFinished();
    void on_mahCount_SB_editingFinished();
    void on_mahCount_ChkB_toggled(bool checked);

  private:
    Ui::Telemetry *ui;
    TelemetryAnalog * analogs[4];
    TelemetryCustomScreen * telemetryCustomScreens[4];

    void setup();
    void telBarUpdate();
    void populateVoltsSource();
    void populateCurrentSource();
    void populateVarioSource();
};

#endif // TELEMETRY_H
