#include "telemetry.h"
#include "ui_telemetry.h"
#include "ui_telemetry_analog.h"
#include "ui_telemetry_customscreen.h"
#include "helpers.h"
#include "appdata.h"

TelemetryAnalog::TelemetryAnalog(QWidget *parent, FrSkyChannelData & analog, ModelData & model, GeneralSettings & generalSettings, FirmwareInterface * firmware):
  ModelPanel(parent, model, generalSettings, firmware),
  ui(new Ui::TelemetryAnalog),
  analog(analog),
  lock(false)
{
  ui->setupUi(this);

  float ratio = analog.getRatio();

  if (analog.type==0 || analog.type==1 || analog.type==2) {
    ui->RatioSB->setDecimals(1);
    ui->RatioSB->setMaximum(25.5*firmware->getCapability(TelemetryMaxMultiplier));
  }
  else {
    ui->RatioSB->setDecimals(0);
    ui->RatioSB->setMaximum(255*firmware->getCapability(TelemetryMaxMultiplier));
  }
  ui->RatioSB->setValue(ratio);

  update();

  ui->UnitCB->setCurrentIndex(analog.type);
  if (!IS_TARANIS(firmware->getBoard())) {
    ui->alarm1LevelCB->setCurrentIndex(analog.alarms[0].level);
    ui->alarm1GreaterCB->setCurrentIndex(analog.alarms[0].greater);
    ui->alarm2LevelCB->setCurrentIndex(analog.alarms[1].level);
    ui->alarm2GreaterCB->setCurrentIndex(analog.alarms[1].greater);
  }
  else {
    ui->alarm1LevelCB->hide();
    ui->alarm2LevelCB->hide();
    ui->alarm1GreaterCB->hide();
    ui->alarm2GreaterCB->hide();
    ui->alarm1Label->setText(tr("Low Alarm"));
    ui->alarm2Label->setText(tr("Critical Alarm"));
  }

  if (!(firmware->getCapability(Telemetry) & TM_HASOFFSET)) {
    ui->CalibSB->hide();
    ui->CalibLabel->hide();
  }
  else {
    ui->label_Max->setText(tr("Range"));
  }

  disableMouseScrolling();
}

void TelemetryAnalog::update()
{
  float ratio = analog.getRatio();
  float step = ratio / 255;
  float mini = (ratio * analog.offset) / 255;
  float maxi = mini + ratio;

  ui->alarm1ValueSB->setDecimals(2);
  ui->alarm1ValueSB->setSingleStep(step);
  ui->alarm1ValueSB->setMinimum(mini);
  ui->alarm1ValueSB->setMaximum(maxi);
  ui->alarm1ValueSB->setValue(mini + step*analog.alarms[0].value);

  ui->alarm2ValueSB->setDecimals(2);
  ui->alarm2ValueSB->setSingleStep(step);
  ui->alarm2ValueSB->setMinimum(mini);
  ui->alarm2ValueSB->setMaximum(maxi);
  ui->alarm2ValueSB->setValue(mini + step*analog.alarms[1].value);

  ui->CalibSB->setDecimals(2);
  ui->CalibSB->setMaximum(step*127);
  ui->CalibSB->setMinimum(-step*128);
  ui->CalibSB->setSingleStep(step);
  ui->CalibSB->setValue(mini);
}

void TelemetryAnalog::on_UnitCB_currentIndexChanged(int index)
{
    float ratio = analog.getRatio();
    analog.type = index;
    switch (index) {
      case 0:
      case 1:
      case 2:
        ui->RatioSB->setDecimals(1);
        ui->RatioSB->setMaximum(25.5*firmware->getCapability(TelemetryMaxMultiplier));
        break;
      default:
        ui->RatioSB->setDecimals(0);
        ui->RatioSB->setMaximum(255*firmware->getCapability(TelemetryMaxMultiplier));
        break;
    }
    ui->RatioSB->setValue(ratio);
    update();
    emit modified();
}

void TelemetryAnalog::on_RatioSB_valueChanged()
{
  if (!lock) {
    if (analog.type==0 || analog.type==1 || analog.type==2) {
      analog.multiplier = findmult(ui->RatioSB->value(), 25.5);
      float singlestep =(1<<analog.multiplier)/10.0;
      lock=true;
      ui->RatioSB->setSingleStep(singlestep);
      ui->RatioSB->setValue(round(ui->RatioSB->value()/singlestep)*singlestep);
      lock=false;
    }
    else {
      analog.multiplier = findmult(ui->RatioSB->value(), 255);
      float singlestep = (1<<analog.multiplier);
      lock = true;
      ui->RatioSB->setSingleStep(singlestep);
      ui->RatioSB->setValue(round(ui->RatioSB->value()/singlestep)*singlestep);
      lock = false;
    }
    emit modified();
  }
}

void TelemetryAnalog::on_RatioSB_editingFinished()
{
  if (!lock) {
    float ratio, calib, alarm1value,alarm2value;

    if (analog.type==0 || analog.type==1 || analog.type==2) {
      analog.multiplier = findmult(ui->RatioSB->value(), 25.5);
      ui->CalibSB->setSingleStep((1<<analog.multiplier)/10.0);
      ui->alarm1ValueSB->setSingleStep((1<<analog.multiplier)/10.0);
      ui->alarm2ValueSB->setSingleStep((1<<analog.multiplier)/10.0);
      analog.ratio = ((int)(round(ui->RatioSB->value()*10))/(1 <<analog.multiplier));
    }
    else {
      analog.multiplier = findmult(ui->RatioSB->value(), 255);
      ui->CalibSB->setSingleStep(1<<analog.multiplier);
      ui->alarm1ValueSB->setSingleStep(1<<analog.multiplier);
      ui->alarm2ValueSB->setSingleStep(1<<analog.multiplier);
      analog.ratio = (ui->RatioSB->value()/(1 << analog.multiplier));
    }
    ui->CalibSB->setMaximum((ui->RatioSB->value()*127)/255);
    ui->CalibSB->setMinimum((ui->RatioSB->value()*-128)/255);
    ui->alarm1ValueSB->setMaximum(ui->RatioSB->value());
    ui->alarm2ValueSB->setMaximum(ui->RatioSB->value());
    repaint();
    ratio=analog.ratio * (1 << analog.multiplier);
    calib=ui->CalibSB->value();
    alarm1value=ui->alarm1ValueSB->value();
    alarm2value=ui->alarm2ValueSB->value();
    if (analog.type==0) {
      calib*=10;
      alarm1value*=10;
      alarm2value*=10;
    }
    if (calib>0) {
      if (calib>((ratio*127)/255)) {
        analog.offset=127;
      }
      else {
        analog.offset=round(calib*255/ratio);
      }
    }
    if (calib<0) {
      if (calib<((ratio*-128)/255)) {
        analog.offset=-128;
      }
      else {
        analog.offset=round(calib*255/ratio);
      }
    }
    analog.alarms[0].value=round((alarm1value*255-analog.offset*(analog.ratio<<analog.multiplier))/(analog.ratio<<analog.multiplier));
    analog.alarms[1].value=round((alarm2value*255-analog.offset*(analog.ratio<<analog.multiplier))/(analog.ratio<<analog.multiplier));
    update();
    emit modified();
  }
}

void TelemetryAnalog::on_CalibSB_editingFinished()
{
    float ratio = analog.getRatio();
    float calib,alarm1value,alarm2value;

    if (ratio!=0) {
      analog.offset = round((255*ui->CalibSB->value()/ratio));
      calib=ratio*analog.offset/255.0;
      alarm1value=ui->alarm1ValueSB->value();
      alarm2value=ui->alarm2ValueSB->value();
      if (alarm1value<calib) {
        alarm1value=calib;
      }
      else if (alarm1value>(ratio+calib)) {
        alarm1value=ratio+calib;
      }
      if (alarm2value<calib) {
        alarm2value=calib;
      }
      else if (alarm2value>(ratio+calib)) {
        alarm2value=ratio+calib;
      }
      analog.alarms[0].value=round(((alarm1value-calib)*255)/ratio);
      analog.alarms[1].value=round(((alarm2value-calib)*255)/ratio);
    }
    else {
      analog.offset=0;
      analog.alarms[0].value=0;
      analog.alarms[1].value=0;
    }
    update();
    emit modified();
}

void TelemetryAnalog::on_alarm1LevelCB_currentIndexChanged(int index)
{
  analog.alarms[0].level = index;
  emit modified();
}


void TelemetryAnalog::on_alarm1GreaterCB_currentIndexChanged(int index)
{
  analog.alarms[0].greater = index;
  emit modified();
}

void TelemetryAnalog::on_alarm1ValueSB_editingFinished()
{
    float ratio = analog.getRatio();
    float calib, alarm1value;

    calib=analog.offset;
    alarm1value=ui->alarm1ValueSB->value();

    if (alarm1value<((calib*ratio)/255)) {
      analog.alarms[0].value=0;
    }
    else if (alarm1value>(ratio+(calib*ratio)/255)) {
      analog.alarms[0].value=255;
    }
    else {
      analog.alarms[0].value = round((alarm1value-((calib*ratio)/255))/ratio*255);
    }
    update();
    emit modified();
}

void TelemetryAnalog::on_alarm2LevelCB_currentIndexChanged(int index)
{
  analog.alarms[1].level = index;
  emit modified();
}

void TelemetryAnalog::on_alarm2GreaterCB_currentIndexChanged(int index)
{
  analog.alarms[1].greater = index;
  emit modified();
}

void TelemetryAnalog::on_alarm2ValueSB_editingFinished()
{
    float calib, alarm2value;
    float ratio = analog.getRatio();
    calib = analog.offset;
    alarm2value = ui->alarm2ValueSB->value();
    if (alarm2value<((calib*ratio)/255)) {
      analog.alarms[1].value=0;
    }
    else if (alarm2value>(ratio+(calib*ratio)/255)) {
      analog.alarms[1].value=255;
    }
    else {
      analog.alarms[1].value = round((alarm2value-((calib*ratio)/255))/ratio*255);
    }
    update();
    emit modified();
}

TelemetryAnalog::~TelemetryAnalog()
{
  delete ui;
}

/******************************************************/

TelemetryCustomScreen::TelemetryCustomScreen(QWidget *parent, ModelData & model, FrSkyScreenData & screen, GeneralSettings & generalSettings, FirmwareInterface * firmware):
  ModelPanel(parent, model, generalSettings, firmware),
  ui(new Ui::TelemetryCustomScreen),
  screen(screen)
{
  ui->setupUi(this);

  for (int l=0; l<4; l++) {
    for (int c=0; c<firmware->getCapability(TelemetryCustomScreensFieldsPerLine); c++) {
      fieldsCB[l][c] = new QComboBox(this);
      fieldsCB[l][c]->setProperty("index", c + (l<<8));
      ui->screenNumsLayout->addWidget(fieldsCB[l][c], l, c, 1, 1);
      connect(fieldsCB[l][c], SIGNAL(currentIndexChanged(int)), this, SLOT(customFieldChanged(int)));
    }
  }

  for (int l=0; l<4; l++) {
    barsCB[l] = new QComboBox(this);
    barsCB[l]->setProperty("index", l);
    connect(barsCB[l], SIGNAL(currentIndexChanged(int)), this, SLOT(barSourceChanged(int)));
    ui->screenBarsLayout->addWidget(barsCB[l], l, 0, 1, 1);

    minSB[l] = new QDoubleSpinBox(this);
    minSB[l]->setProperty("index", l);
    connect(minSB[l], SIGNAL(valueChanged(double)), this, SLOT(barMinChanged(double)));
    ui->screenBarsLayout->addWidget(minSB[l], l, 1, 1, 1);

    QLabel * label = new QLabel(this);
    label->setAutoFillBackground(false);
    label->setStyleSheet(QString::fromUtf8("Background:qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 128, 255), stop:0.339795 rgba(0, 0, 128, 255), stop:0.339799 rgba(255, 255, 255, 255), stop:0.662444 rgba(255, 255, 255, 255),)\n"""));
    label->setFrameShape(QFrame::Panel);
    label->setFrameShadow(QFrame::Raised);
    label->setAlignment(Qt::AlignCenter);
    ui->screenBarsLayout->addWidget(label, l, 2, 1, 1);

    maxSB[l] = new QDoubleSpinBox(this);
    maxSB[l]->setProperty("index", l);
    connect(maxSB[l], SIGNAL(valueChanged(double)), this, SLOT(barMaxChanged(double)));
    ui->screenBarsLayout->addWidget(maxSB[l], l, 3, 1, 1);
  }

  disableMouseScrolling();

  update();
}

void TelemetryCustomScreen::populateTelemetrySourceCB(QComboBox *b, unsigned int value, bool last, int hubproto)
{
  b->clear();

  b->addItem(RawSource(SOURCE_TYPE_NONE, 0).toString(model));

  for (unsigned int i = 0; i < (last ? TELEMETRY_SOURCES_STATUS_COUNT : TELEMETRY_SOURCES_DISPLAY_COUNT); i++) {
    b->addItem(RawSource(SOURCE_TYPE_TELEMETRY, i).toString(model));
    if (!firmware->isTelemetrySourceAvailable(i)) {
      // disable item
      QModelIndex index = b->model()->index(i+1, 0);
      QVariant v(0);
      b->model()->setData(index, v, Qt::UserRole - 1);
    }
  }

  b->setCurrentIndex(value);
  b->setMaxVisibleItems(10);
}

TelemetryCustomScreen::~TelemetryCustomScreen()
{
  delete ui;
}

void TelemetryCustomScreen::update()
{
  lock = true;

  ui->screenType->setCurrentIndex(screen.type);
  ui->screenNums->setVisible(screen.type == 0);
  ui->screenBars->setVisible(screen.type != 0);

  for (int l=0; l<4; l++) {
    for (int c=0; c<firmware->getCapability(TelemetryCustomScreensFieldsPerLine); c++) {
      populateTelemetrySourceCB(fieldsCB[l][c], screen.body.lines[l].source[c], l==3, model.frsky.usrProto);
    }
  }

  for (int l=0; l<4; l++) {
    populateTelemetrySourceCB(barsCB[l], screen.body.bars[l].source, false, model.frsky.usrProto);
  }

  if (screen.type == 0) {
    for (int l=0; l<4; l++) {
      for (int c=0; c<firmware->getCapability(TelemetryCustomScreensFieldsPerLine); c++) {
        fieldsCB[l][c]->setCurrentIndex(screen.body.lines[l].source[c]);
      }
    }
  }
  else {
    for (int i=0; i<4; i++) {
      updateBar(i);
    }
  }

  lock = false;
}

void TelemetryCustomScreen::updateBar(int line)
{
  lock = true;

  int index = screen.body.bars[line].source;
  barsCB[line]->setCurrentIndex(index);
  if (index) {
    RawSource source = RawSource(SOURCE_TYPE_TELEMETRY, index-1);
    RawSourceRange range = source.getRange(model, generalSettings, RANGE_SINGLE_PRECISION);
    int max = round((range.max - range.min) / range.step);
    if (int(255-screen.body.bars[line].barMax) > max)
      screen.body.bars[line].barMax = 255 - max;
    minSB[line]->setEnabled(true);
    minSB[line]->setDecimals(range.decimals);
    minSB[line]->setMinimum(range.min);
    minSB[line]->setMaximum(range.max);
    minSB[line]->setSingleStep(range.step);
    minSB[line]->setValue(range.getValue(screen.body.bars[line].barMin));
    maxSB[line]->setEnabled(true);
    maxSB[line]->setDecimals(range.decimals);
    maxSB[line]->setMinimum(range.min);
    maxSB[line]->setMaximum(range.max);
    maxSB[line]->setSingleStep(range.step);
    maxSB[line]->setValue(range.getValue(255 - screen.body.bars[line].barMax));
  }
  else {
    minSB[line]->setDisabled(true);
    maxSB[line]->setDisabled(true);
  }

  lock = false;
}

void TelemetryCustomScreen::on_screenType_currentIndexChanged(int index)
{
  if (!lock) {
    memset(&screen.body, 0, sizeof(screen.body));
    screen.type = index;
    update();
    emit modified();
  }
}

void TelemetryCustomScreen::customFieldChanged(int value)
{
  if (!lock) {
    int index = sender()->property("index").toInt();
    screen.body.lines[index/256].source[index%256] = value;
    emit modified();
  }
}

void TelemetryCustomScreen::barSourceChanged(int index)
{
  if (!lock) {
    QComboBox * cb = qobject_cast<QComboBox*>(sender());
    int line = cb->property("index").toInt();
    screen.body.bars[line].source = index;
    screen.body.bars[line].barMin = 0;
    screen.body.bars[line].barMax = 0;
    updateBar(line);
    emit modified();
  }
}

void TelemetryCustomScreen::barMinChanged(double value)
{
  if (!lock) {
    int line = sender()->property("index").toInt();
    screen.body.bars[line].barMin = round((value-minSB[line]->minimum()) / minSB[line]->singleStep());
    // TODO set min (maxSB)
    emit modified();
  }
}

void TelemetryCustomScreen::barMaxChanged(double value)
{
  if (!lock) {
    int line = sender()->property("index").toInt();
    screen.body.bars[line].barMax = 255 - round((value-minSB[line]->minimum()) / maxSB[line]->singleStep());
    // TODO set max (minSB)
    emit modified();
  }
}

/******************************************************/

TelemetryPanel::TelemetryPanel(QWidget *parent, ModelData & model, GeneralSettings & generalSettings, FirmwareInterface * firmware):
  ModelPanel(parent, model, generalSettings, firmware),
  ui(new Ui::Telemetry)
{
  ui->setupUi(this);

  if (firmware->getCapability(NoTelemetryProtocol)) {
    model.frsky.usrProto = 1;
  }

  analogs[0] = new TelemetryAnalog(this, model.frsky.channels[0], model, generalSettings, firmware);
  ui->A1Layout->addWidget(analogs[0]);
  connect(analogs[0], SIGNAL(modified()), this, SLOT(onAnalogModified()));

  analogs[1] = new TelemetryAnalog(this, model.frsky.channels[1], model, generalSettings, firmware);
  ui->A2Layout->addWidget(analogs[1]);
  connect(analogs[1], SIGNAL(modified()), this, SLOT(onAnalogModified()));

  if (IS_ARM(firmware->getBoard())) {
    analogs[2] = new TelemetryAnalog(this, model.frsky.channels[2], model, generalSettings, firmware);
    ui->A3Layout->addWidget(analogs[2]);
    connect(analogs[2], SIGNAL(modified()), this, SLOT(onAnalogModified()));

    analogs[3] = new TelemetryAnalog(this, model.frsky.channels[3], model, generalSettings, firmware);
    ui->A4Layout->addWidget(analogs[3]);
    connect(analogs[3], SIGNAL(modified()), this, SLOT(onAnalogModified()));
  }
  else {
    ui->A3GB->hide();
    ui->A4GB->hide();
  }

  for (int i=0; i<firmware->getCapability(TelemetryCustomScreens); i++) {
    TelemetryCustomScreen * tab = new TelemetryCustomScreen(this, model, model.frsky.screens[i], generalSettings, firmware);
    ui->customScreens->addTab(tab, tr("Telemetry screen %1").arg(i+1));
    telemetryCustomScreens[i] = tab;
  }

  if (IS_ARM(firmware->getBoard())) {
    ui->bladesCount->setMinimum(1);
    ui->bladesCount->setMaximum(128);
  }

  disableMouseScrolling();

  setup();
}

TelemetryPanel::~TelemetryPanel()
{
  delete ui;
}

void TelemetryPanel::update()
{
  if (IS_TARANIS(firmware->getBoard())) {
    if (model.moduleData[0].RFprotocol == OFF && model.moduleData[1].RFprotocol == PPM) {
      ui->telemetryProtocol->setEnabled(true);
    }
    else {
      ui->telemetryProtocol->setEnabled(false);
      ui->telemetryProtocol->setCurrentIndex(0);
    }
  }
}

void TelemetryPanel::setup()
{
    QString firmware_id = g.profile[g.id()].fwType();

    lock = true;

    if (IS_ARM(firmware->getBoard())) {
      ui->telemetryProtocol->addItem(tr("FrSky S.PORT"), 0);
      ui->telemetryProtocol->addItem(tr("FrSky D"), 1);
      ui->telemetryProtocol->addItem(tr("MAVLINK"), 2);
      ui->telemetryProtocol->setCurrentIndex(model.telemetryProtocol);
    }
    else {
      ui->telemetryProtocolLabel->hide();
      ui->telemetryProtocol->hide();
    }

    ui->rssiAlarm1SB->setValue(model.frsky.rssiAlarms[0].value);
    ui->rssiAlarm2SB->setValue(model.frsky.rssiAlarms[1].value);
    if (!IS_TARANIS(firmware->getBoard())) {
      ui->rssiAlarm1CB->setCurrentIndex(model.frsky.rssiAlarms[0].level);
      ui->rssiAlarm2CB->setCurrentIndex(model.frsky.rssiAlarms[1].level);
    }
    else {
      ui->rssiAlarm1CB->hide();
      ui->rssiAlarm2CB->hide();
      ui->rssiAlarm1Label->setText(tr("Low Alarm"));
      ui->rssiAlarm2Label->setText(tr("Critical Alarm"));
    }

    if (!firmware->getCapability(HasAltitudeSel)) {
      ui->AltitudeGPS_ChkB->hide();
    }
    else {
      ui->AltitudeGPS_ChkB->setChecked(model.frsky.FrSkyGpsAlt);
    }
    
    if (IS_TARANIS(firmware->getBoard())) {
      ui->AltitudeToolbar_ChkB->setChecked(model.frsky.altitudeDisplayed);
    }
    else {
      ui->AltitudeToolbar_ChkB->hide();
    }

    int varioCap = firmware->getCapability(HasVario);
    if (!varioCap) {
      ui->varioLimitMax_DSB->hide();
      ui->varioLimitMin_DSB->hide();
      ui->varioLimitCenterMin_DSB->hide();
      ui->varioLimitCenterMax_DSB->hide();
      ui->varioLimit_label->hide();
      ui->VarioLabel_1->hide();
      ui->VarioLabel_2->hide();
      ui->VarioLabel_3->hide();
      ui->VarioLabel_4->hide();
      ui->varioSourceCB->hide();
      ui->varioSource_label->hide();
    }
    else {
      if (!firmware->getCapability(HasVarioSink)) {
        ui->varioLimitMin_DSB->hide();
        ui->varioLimitCenterMin_DSB->hide();
        ui->VarioLabel_1->hide();
        ui->VarioLabel_2->hide();
      }
      ui->varioLimitMin_DSB->setValue(model.frsky.varioMin-10);
      ui->varioLimitMax_DSB->setValue(model.frsky.varioMax+10);
      ui->varioLimitCenterMax_DSB->setValue((model.frsky.varioCenterMax/10.0)+0.5);
      ui->varioLimitCenterMin_DSB->setValue((model.frsky.varioCenterMin/10.0)-0.5);
    }

    ui->altimetryGB->setVisible(firmware->getCapability(HasAltitudeSel) || firmware->getCapability(HasVario)),
    ui->frskyProtoCB->setDisabled(firmware->getCapability(NoTelemetryProtocol));

    if (firmware->getCapability(Telemetry) & TM_HASWSHH) {
      ui->frskyProtoCB->addItem(tr("Winged Shadow How High"));
    }
    else {
      ui->frskyProtoCB->addItem(tr("Winged Shadow How High (not supported)"));
    }
    
    ui->variousGB->hide();
    if (!(firmware->getCapability(HasFasOffset)) && !(firmware_id.contains("fasoffset"))) {
      ui->fasOffset_label->hide();
      ui->fasOffset_DSB->hide();
    }
    else {
      ui->fasOffset_DSB->setValue(model.frsky.fasOffset/10.0);
      ui->variousGB->show();
    }

    if (!(firmware->getCapability(HasMahPersistent))) {
      ui->mahCount_label->hide();
      ui->mahCount_SB->hide();
      ui->mahCount_ChkB->hide();
    }
    else {
      if (model.frsky.mAhPersistent) {
        ui->mahCount_ChkB->setChecked(true);
        ui->mahCount_SB->setValue(model.frsky.storedMah);
      }
      else {
        ui->mahCount_SB->setDisabled(true);
      }
      ui->variousGB->show();
    }

    ui->frskyProtoCB->setCurrentIndex(model.frsky.usrProto);
    ui->bladesCount->setValue(model.frsky.blades);

    populateVoltsSource();
    populateCurrentSource();
    populateVarioSource();

    lock = false;
}

void TelemetryPanel::populateVarioSource()
{
  QUnsignedAutoComboBox * cb = ui->varioSourceCB;
  cb->setField(&model.frsky.varioSource, this);
  if (!IS_TARANIS(firmware->getBoard())) {
    cb->addItem(tr("Alti"), TELEMETRY_VARIO_SOURCE_ALTI);
    cb->addItem(tr("Alti+"), TELEMETRY_VARIO_SOURCE_ALTI_PLUS);
  }
  cb->addItem(tr("VSpeed"), TELEMETRY_VARIO_SOURCE_VSPEED);
  cb->addItem(tr("A1"), TELEMETRY_VARIO_SOURCE_A1);
  cb->addItem(tr("A2"), TELEMETRY_VARIO_SOURCE_A2);
  if (IS_TARANIS(firmware->getBoard())) {
    cb->addItem(tr("dTE"), TELEMETRY_VARIO_SOURCE_DTE);
  }
}

void TelemetryPanel::populateVoltsSource()
{
  QUnsignedAutoComboBox * cb = ui->frskyVoltCB;
  cb->setField(&model.frsky.voltsSource, this);
  cb->addItem(tr("A1"), TELEMETRY_VOLTS_SOURCE_A1);
  cb->addItem(tr("A2"), TELEMETRY_VOLTS_SOURCE_A2);
  if (IS_ARM(firmware->getBoard())) {
    cb->addItem(tr("A3"), TELEMETRY_VOLTS_SOURCE_A3);
    cb->addItem(tr("A4"), TELEMETRY_VOLTS_SOURCE_A4);
  }
  cb->addItem(tr("FAS"), TELEMETRY_VOLTS_SOURCE_FAS);
  cb->addItem(tr("Cells"), TELEMETRY_VOLTS_SOURCE_CELLS);
}

void TelemetryPanel::populateCurrentSource()
{
  QUnsignedAutoComboBox * cb = ui->frskyCurrentCB;
  cb->setField(&model.frsky.currentSource, this);
  cb->addItem(tr("---"), TELEMETRY_CURRENT_SOURCE_NONE);
  cb->addItem(tr("A1"), TELEMETRY_CURRENT_SOURCE_A1);
  cb->addItem(tr("A2"), TELEMETRY_CURRENT_SOURCE_A2);
  if (IS_ARM(firmware->getBoard())) {
    cb->addItem(tr("A3"), TELEMETRY_CURRENT_SOURCE_A3);
    cb->addItem(tr("A4"), TELEMETRY_CURRENT_SOURCE_A4);
  }
  cb->addItem(tr("FAS"), TELEMETRY_CURRENT_SOURCE_FAS);
}

void TelemetryPanel::on_telemetryProtocol_currentIndexChanged(int index) {
  if (!lock) {
    model.telemetryProtocol = index;
    emit modified();
  }
}

void TelemetryPanel::on_telemetryCom_currentIndexChanged(int index) {
  if (!lock) {
    model.telemetryCom = index;
    emit modified();
  }
}

void TelemetryPanel::on_telemetryBaud_currentIndexChanged(int index) {
  if (!lock) {
    model.telemetryBaud = index;
    emit modified();
  }
}

void TelemetryPanel::on_telemetryMirrorCom_currentIndexChanged(int index) {
  if (!lock) {
    model.telemetryMirrorCom = index;
    emit modified();
  }
}


void TelemetryPanel::onAnalogModified()
{
  emit modified();
}

void TelemetryPanel::on_bladesCount_editingFinished()
{
  if (!lock) {
    model.frsky.blades = ui->bladesCount->value();
    emit modified();
  }
}

void TelemetryPanel::on_frskyProtoCB_currentIndexChanged(int index)
{
  if (!lock) {
    model.frsky.usrProto = index;
    for (int i=0; i<firmware->getCapability(TelemetryCustomScreens); i++)
      telemetryCustomScreens[i]->update();
    emit modified();
  }
}

void TelemetryPanel::on_rssiAlarm1CB_currentIndexChanged(int index)
{
  model.frsky.rssiAlarms[0].level = index;
  emit modified();
}

void TelemetryPanel::on_rssiAlarm2CB_currentIndexChanged(int index)
{
  model.frsky.rssiAlarms[1].level = index;
  emit modified();
}

void TelemetryPanel::on_rssiAlarm1SB_editingFinished()
{
  model.frsky.rssiAlarms[0].value = ui->rssiAlarm1SB->value();
  emit modified();
}

void TelemetryPanel::on_rssiAlarm2SB_editingFinished()
{
  model.frsky.rssiAlarms[1].value = ui->rssiAlarm2SB->value();
  emit modified();
}

void TelemetryPanel::on_AltitudeGPS_ChkB_toggled(bool checked)
{
  model.frsky.FrSkyGpsAlt = checked;
  emit modified();
}

void TelemetryPanel::on_AltitudeToolbar_ChkB_toggled(bool checked)
{
  model.frsky.altitudeDisplayed = checked;
  emit modified();
}

void TelemetryPanel::on_varioLimitMin_DSB_editingFinished()
{
  model.frsky.varioMin = round(ui->varioLimitMin_DSB->value()+10);
  emit modified();
}

void TelemetryPanel::on_varioLimitMax_DSB_editingFinished()
{
  model.frsky.varioMax = round(ui->varioLimitMax_DSB->value()-10);
  emit modified();
}

void TelemetryPanel::on_varioLimitCenterMin_DSB_editingFinished()
{
  if (!lock) {
    if (ui->varioLimitCenterMin_DSB->value()>ui->varioLimitCenterMax_DSB->value()) {
      ui->varioLimitCenterMax_DSB->setValue(ui->varioLimitCenterMin_DSB->value());
    }
    model.frsky.varioCenterMin = round((ui->varioLimitCenterMin_DSB->value()+0.5)*10);
    emit modified();
  }
}

void TelemetryPanel::on_varioLimitCenterMax_DSB_editingFinished()
{
  if (!lock) {
    if (ui->varioLimitCenterMin_DSB->value()>ui->varioLimitCenterMax_DSB->value()) {
      ui->varioLimitCenterMax_DSB->setValue(ui->varioLimitCenterMin_DSB->value());
    }
    model.frsky.varioCenterMax = round((ui->varioLimitCenterMax_DSB->value()-0.5)*10);
    emit modified();
  }
}

void TelemetryPanel::on_fasOffset_DSB_editingFinished()
{
  model.frsky.fasOffset = ui->fasOffset_DSB->value() * 10;
  emit modified();
}

void TelemetryPanel::on_mahCount_SB_editingFinished()
{
  model.frsky.storedMah = ui->mahCount_SB->value();
  emit modified();
}

void TelemetryPanel::on_mahCount_ChkB_toggled(bool checked)
{
  model.frsky.mAhPersistent = checked;
  ui->mahCount_SB->setDisabled(!checked);
  emit modified();
}
