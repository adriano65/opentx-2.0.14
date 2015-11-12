#include "customfunctions.h"
#include "helpers.h"
#include "appdata.h"

RepeatComboBox::RepeatComboBox(QWidget *parent, int & repeatParam):
  QComboBox(parent),
  repeatParam(repeatParam)
{
  unsigned int step = IS_ARM(GetEepromInterface()->getBoard()) ? 1 : 10;
  int value = repeatParam/step;

  if (step == 1) {
    addItem(QObject::tr("Played once, not during startup"), -1);
    value++;
  }

  addItem(QObject::tr("No repeat"), 0);

  for (unsigned int i=step; i<=60; i+=step) {
    addItem(QObject::tr("%1s").arg(i), i);
  }

  setCurrentIndex(value);

  connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(onIndexChanged(int)));
}

void RepeatComboBox::onIndexChanged(int index)
{
  repeatParam = itemData(index).toInt();
  emit modified();
}

void RepeatComboBox::update()
{
  unsigned int step = IS_ARM(GetEepromInterface()->getBoard()) ? 1 : 10;
  int value = repeatParam/step;
  if (step == 1) {
    value++;
  }
  setCurrentIndex(value);
}

CustomFunctionsPanel::CustomFunctionsPanel(QWidget * parent, ModelData & model, GeneralSettings & generalSettings, FirmwareInterface * firmware):
  ModelPanel(parent, model, generalSettings, firmware),
  initialized(false)
#if defined(PHONON)
  ,
  phononCurrent(-1),
  clickObject(NULL),
  clickOutput(NULL)
#endif
{
  QGridLayout * gridLayout = new QGridLayout(this);

  addLabel(gridLayout, tr("Switch"), 1);
  addLabel(gridLayout, tr("Action"), 2);
  addLabel(gridLayout, tr("Parameters"), 3);
  addLabel(gridLayout, tr("Enable"), 4, true );
  addEmptyLabel(gridLayout, 5 );

  lock = true;
  int num_fsw = firmware->getCapability(CustomFunctions);

  if (!firmware->getCapability(VoicesAsNumbers)) {
    tracksSet = getFilesSet(getSoundsPath(generalSettings), QStringList() << "*.wav" << "*.WAV", firmware->getCapability(VoicesMaxLength));
    for (int i=0; i<num_fsw; i++) {
      if (model.funcSw[i].func==FuncPlayPrompt || model.funcSw[i].func==FuncBackgroundMusic) {
        QString temp = model.funcSw[i].paramarm;
        if (!temp.isEmpty()) {
          tracksSet.insert(temp);
        }
      }
    }
    qDebug() << tracksSet;
  }

  if (IS_TARANIS(firmware->getBoard())) {
    scriptsSet = getFilesSet(g.profile[g.id()].sdPath() + "/SCRIPTS", QStringList() << "*.lua", firmware->getCapability(VoicesMaxLength));
    for (int i=0; i<num_fsw; i++) {
      if (model.funcSw[i].func==FuncPlayScript) {
        QString temp = model.funcSw[i].paramarm;
        if (!temp.isEmpty()) {
          scriptsSet.insert(temp);
        }
      }
    }
    qDebug() << scriptsSet;
  }

  CompanionIcon playIcon("play.png");

  for (int i=0; i<num_fsw; i++) {
    // The label
    QLabel * label = new QLabel(this);
    label->setContextMenuPolicy(Qt::CustomContextMenu);
    label->setMouseTracking(true);
    label->setProperty("index", i);
    label->setText(tr("SF%1").arg(i+1));
    label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
    connect(label, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(fsw_customContextMenuRequested(QPoint)));
    gridLayout->addWidget(label, i+1, 0);

    // The switch
    fswtchSwtch[i] = new QComboBox(this);
    fswtchSwtch[i]->setProperty("index", i);
    fswtchSwtch[i]->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    connect(fswtchSwtch[i], SIGNAL(currentIndexChanged(int)), this, SLOT(customFunctionEdited()));
    gridLayout->addWidget(fswtchSwtch[i], i+1, 1);

    // The function
    fswtchFunc[i] = new QComboBox(this);
    fswtchFunc[i]->setProperty("index", i);
    connect(fswtchFunc[i], SIGNAL(currentIndexChanged(int)), this, SLOT(functionEdited()));
    gridLayout->addWidget(fswtchFunc[i], i+1, 2);

    QHBoxLayout *paramLayout = new QHBoxLayout();
    gridLayout->addLayout(paramLayout, i+1, 3);

    fswtchGVmode[i] = new QComboBox(this);
    fswtchGVmode[i]->setProperty("index", i);
    connect(fswtchGVmode[i], SIGNAL(currentIndexChanged(int)), this, SLOT(customFunctionEdited()));
    paramLayout->addWidget(fswtchGVmode[i]);

    fswtchParamGV[i] = new QCheckBox(this);
    fswtchParamGV[i]->setProperty("index", i);
    fswtchParamGV[i]->setText("GV");
    fswtchParamGV[i]->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    connect(fswtchParamGV[i], SIGNAL(stateChanged(int)), this, SLOT(customFunctionEdited()));
    paramLayout->addWidget(fswtchParamGV[i]);

    fswtchParam[i] = new QDoubleSpinBox(this);
    fswtchParam[i]->setProperty("index", i);
    fswtchParam[i]->setAccelerated(true);
    fswtchParam[i]->setDecimals(0);
    connect(fswtchParam[i], SIGNAL(editingFinished()), this, SLOT(customFunctionEdited()));
    paramLayout->addWidget(fswtchParam[i]);

    fswtchParamTime[i] = new QTimeEdit(this);
    fswtchParamTime[i]->setProperty("index", i);
    fswtchParamTime[i]->setAccelerated(true);
    fswtchParamTime[i]->setDisplayFormat("hh:mm:ss");
    connect(fswtchParamTime[i], SIGNAL(editingFinished()), this, SLOT(customFunctionEdited()));
    paramLayout->addWidget(fswtchParamTime[i]);

    fswtchParamT[i] = new QComboBox(this);
    fswtchParamT[i]->setProperty("index", i);
    paramLayout->addWidget(fswtchParamT[i]);
    connect(fswtchParamT[i], SIGNAL(currentIndexChanged(int)), this, SLOT(customFunctionEdited()));

    fswtchParamArmT[i] = new QComboBox(this);
    fswtchParamArmT[i]->setProperty("index", i);
    fswtchParamArmT[i]->setEditable(true);
    paramLayout->addWidget(fswtchParamArmT[i]);

    connect(fswtchParamArmT[i], SIGNAL(currentIndexChanged(int)), this, SLOT(customFunctionEdited()));
    connect(fswtchParamArmT[i], SIGNAL(editTextChanged ( const QString)), this, SLOT(customFunctionEdited()));

    fswtchBLcolor[i] = new QSlider(this);
    fswtchBLcolor[i]->setProperty("index", i);
    fswtchBLcolor[i]->setMinimum(0);
    fswtchBLcolor[i]->setMaximum(100);
    fswtchBLcolor[i]->setSingleStep(1);
    fswtchBLcolor[i]->setOrientation(Qt::Horizontal);
    paramLayout->addWidget(fswtchBLcolor[i]);
    connect(fswtchBLcolor[i], SIGNAL(sliderReleased()), this, SLOT(customFunctionEdited()));

#ifdef PHONON
    playBT[i] = new QPushButton(this);
    playBT[i]->setProperty("index", i);
    playBT[i]->setIcon(playIcon);
    paramLayout->addWidget(playBT[i]);
    connect(playBT[i], SIGNAL(pressed()), this, SLOT(playMusic()));
#endif

    QHBoxLayout *repeatLayout = new QHBoxLayout();
    gridLayout->addLayout(repeatLayout, i+1, 4);
    fswtchRepeat[i] = new RepeatComboBox(this, model.funcSw[i].repeatParam);
    repeatLayout->addWidget(fswtchRepeat[i], i+1);
    connect(fswtchRepeat[i], SIGNAL(modified()), this, SLOT(onChildModified()));

    fswtchEnable[i] = new QCheckBox(this);
    fswtchEnable[i]->setProperty("index", i);
    fswtchEnable[i]->setText(tr("ON"));
    fswtchEnable[i]->setFixedWidth( 50 );
    repeatLayout->addWidget(fswtchEnable[i], i+1);
    connect(fswtchEnable[i], SIGNAL(stateChanged(int)), this, SLOT(customFunctionEdited()));
  }

  // Push rows upward
  addDoubleSpring(gridLayout, 5, num_fsw+1);

  disableMouseScrolling();

  lock = false;
}

CustomFunctionsPanel::~CustomFunctionsPanel()
{
}

#ifdef PHONON
void CustomFunctionsPanel::mediaPlayer_state(Phonon::State newState, Phonon::State oldState)
{
  if (!lock) {
    lock = true;
    if ((newState==Phonon::ErrorState || newState==Phonon::StoppedState || newState==Phonon::PausedState) && oldState==Phonon::PlayingState) {
      clickObject->stop();
      clickObject->clearQueue();
      clickObject->clear();
      if (phononCurrent >= 0) {
        playBT[phononCurrent]->setIcon(CompanionIcon("play.png"));
        phononCurrent = -1;
      }
    }
    lock = false;
  }
}

void CustomFunctionsPanel::playMusic()
{
  if (!clickObject) {
    clickObject = new Phonon::MediaObject(this);
    clickOutput = new Phonon::AudioOutput(Phonon::NoCategory, this);
    Phonon::createPath(clickObject, clickOutput);
    connect(clickObject, SIGNAL(stateChanged(Phonon::State, Phonon::State)), this, SLOT(mediaPlayer_state(Phonon::State, Phonon::State)));
  }

  QPushButton * button = qobject_cast<QPushButton*>(sender());
  int index = button->property("index").toInt();
  QString path = g.profile[g.id()].sdPath();
  QDir qd(path);
  QString track;
  if (qd.exists()) {
    if (firmware->getCapability(VoicesAsNumbers)) {
      track = path + QString("/%1.wav").arg(int(fswtchParam[index]->value()), 4, 10, (const QChar)'0');
    }
    else {
      path.append("/SOUNDS/");
      QString lang = generalSettings.ttsLanguage;
      if (lang.isEmpty())
        lang = "en";
      path.append(lang);
      if (fswtchParamArmT[index]->currentText() != "----") {
        track = path + "/" + fswtchParamArmT[index]->currentText() + ".wav";
      }
    }
    QFile file(track);
    if (!file.exists()) {
      QMessageBox::critical(this, tr("Error"), tr("Unable to find sound file %1!").arg(track));
      return;
    }

    if (phononCurrent == index) {
      clickObject->stop();
      clickObject->clear();
      playBT[index]->setIcon(CompanionIcon("play.png"));
      phononCurrent = -1;
    }
    else {
      phononCurrent = index;
      clickObject->clear();
#ifdef __APPLE__
      clickObject->setCurrentSource(QUrl("file://"+track));
#else
      clickObject->setCurrentSource(QUrl(track));
#endif
      clickObject->play();
      playBT[index]->setIcon(CompanionIcon("stop.png"));
    }
  }
}
#endif

#define CUSTOM_FUNCTION_NUMERIC_PARAM  (1<<0)
#define CUSTOM_FUNCTION_SOURCE_PARAM   (1<<1)
#define CUSTOM_FUNCTION_FILE_PARAM     (1<<2)
#define CUSTOM_FUNCTION_TIME_PARAM     (1<<3)
#define CUSTOM_FUNCTION_GV_MODE        (1<<4)
#define CUSTOM_FUNCTION_GV_TOOGLE      (1<<5)
#define CUSTOM_FUNCTION_ENABLE         (1<<6)
#define CUSTOM_FUNCTION_REPEAT         (1<<7)
#define CUSTOM_FUNCTION_PLAY           (1<<8)
#define CUSTOM_FUNCTION_BL_COLOR       (1<<9)

void CustomFunctionsPanel::customFunctionEdited()
{
  if (!lock) {
    lock = true;
    int index = sender()->property("index").toInt();
    refreshCustomFunction(index, true);
    emit modified();
    lock = false;
  }
}

void CustomFunctionsPanel::functionEdited()
{
  if (!lock) {
    lock = true;
    int index = sender()->property("index").toInt();
    fswtchParamArmT[index]->setCurrentIndex(0);
    refreshCustomFunction(index, true);
    emit modified();
    lock = false;
  }
}

void CustomFunctionsPanel::onChildModified()
{
  emit modified();
}

void CustomFunctionsPanel::refreshCustomFunction(int i, bool modified)
{
    unsigned int widgetsMask = 0;
    if (modified) {
      model.funcSw[i].swtch = RawSwitch(fswtchSwtch[i]->itemData(fswtchSwtch[i]->currentIndex()).toInt());
      model.funcSw[i].func = (AssignFunc)fswtchFunc[i]->currentIndex();
      model.funcSw[i].enabled = fswtchEnable[i]->isChecked();
      model.funcSw[i].adjustMode = (AssignFunc)fswtchGVmode[i]->currentIndex();
    }

    int index = fswtchFunc[i]->currentIndex();

    if (index>=FuncOverrideCH1 && index<=FuncOverrideCH32) {
      int channelsMax = model.getChannelsMax(true);
      fswtchParam[i]->setDecimals(0);
      fswtchParam[i]->setSingleStep(1);
      fswtchParam[i]->setMinimum(-channelsMax);
      fswtchParam[i]->setMaximum(channelsMax);
      if (modified) {
        model.funcSw[i].param = fswtchParam[i]->value();
      }
      fswtchParam[i]->setValue(model.funcSw[i].param);
      widgetsMask |= CUSTOM_FUNCTION_NUMERIC_PARAM + CUSTOM_FUNCTION_ENABLE;
    }
    else if (index==FuncLogs) {
      fswtchParam[i]->setDecimals(1);
      fswtchParam[i]->setMinimum(0);
      fswtchParam[i]->setMaximum(25.5);
      fswtchParam[i]->setSingleStep(0.1);
      if (modified) model.funcSw[i].param = fswtchParam[i]->value()*10.0;
      fswtchParam[i]->setValue(model.funcSw[i].param/10.0);
      widgetsMask |= CUSTOM_FUNCTION_NUMERIC_PARAM;
    }
    else if (index>=FuncAdjustGV1 && index<=FuncAdjustGVLast) {
      if (modified) model.funcSw[i].adjustMode = fswtchGVmode[i]->currentIndex();
      widgetsMask |= CUSTOM_FUNCTION_GV_MODE + CUSTOM_FUNCTION_ENABLE;
      if (model.funcSw[i].adjustMode==0) {
        if (modified) model.funcSw[i].param = fswtchParam[i]->value();
        fswtchParam[i]->setDecimals(0);
        fswtchParam[i]->setSingleStep(1);
        if (IS_ARM(GetEepromInterface()->getBoard())) {
          fswtchParam[i]->setMinimum(-500);
          fswtchParam[i]->setMaximum(500);
        }
        else {
          fswtchParam[i]->setMinimum(-125);
          fswtchParam[i]->setMaximum(125);
        }
        fswtchParam[i]->setValue(model.funcSw[i].param);
        widgetsMask |= CUSTOM_FUNCTION_NUMERIC_PARAM;
      }
      else {
        if (modified) model.funcSw[i].param = fswtchParamT[i]->itemData(fswtchParamT[i]->currentIndex()).toInt();
        populateFuncParamCB(fswtchParamT[i], model, index, model.funcSw[i].param, model.funcSw[i].adjustMode);
        widgetsMask |= CUSTOM_FUNCTION_SOURCE_PARAM;
      }
    }
    else if (index==FuncReset) {
      if (modified) model.funcSw[i].param = (uint8_t)fswtchParamT[i]->currentIndex();
      populateFuncParamCB(fswtchParamT[i], model, index, model.funcSw[i].param);
      widgetsMask |= CUSTOM_FUNCTION_SOURCE_PARAM | CUSTOM_FUNCTION_ENABLE;
    }
    else if (index>=FuncSetTimer1 && index<=FuncSetTimer2) {
      if (modified) model.funcSw[i].param = QTimeS(fswtchParamTime[i]->time()).seconds();
      fswtchParamTime[i]->setMinimumTime(QTime(0, 0, 0));
      fswtchParamTime[i]->setMaximumTime(QTime(0, 59, 59));
      fswtchParamTime[i]->setTime(QTimeS(model.funcSw[i].param));
      widgetsMask |= CUSTOM_FUNCTION_TIME_PARAM + CUSTOM_FUNCTION_ENABLE;
    }
    else if (index==FuncVolume) {
      if (modified) model.funcSw[i].param = fswtchParamT[i]->itemData(fswtchParamT[i]->currentIndex()).toInt();
      populateFuncParamCB(fswtchParamT[i], model, index, model.funcSw[i].param);
      widgetsMask |= CUSTOM_FUNCTION_SOURCE_PARAM + CUSTOM_FUNCTION_ENABLE;
    }
    else if (index==FuncPlaySound || index==FuncPlayHaptic || index==FuncPlayValue || index==FuncPlayPrompt || index==FuncPlayBoth || index==FuncBackgroundMusic) {
      if (index != FuncBackgroundMusic) {
        widgetsMask |= CUSTOM_FUNCTION_REPEAT;
        fswtchRepeat[i]->update();
      }
      if (index==FuncPlayValue) {
        if (modified) model.funcSw[i].param = fswtchParamT[i]->itemData(fswtchParamT[i]->currentIndex()).toInt();
        populateFuncParamCB(fswtchParamT[i], model, index, model.funcSw[i].param);
        widgetsMask |= CUSTOM_FUNCTION_SOURCE_PARAM + CUSTOM_FUNCTION_REPEAT;
      }
      else if (index==FuncPlayPrompt || index==FuncPlayBoth) {
        if (firmware->getCapability(VoicesAsNumbers)) {
          fswtchParam[i]->setDecimals(0);
          fswtchParam[i]->setSingleStep(1);
          fswtchParam[i]->setMinimum(0);
          if (index==FuncPlayPrompt) {
            widgetsMask |= CUSTOM_FUNCTION_NUMERIC_PARAM + CUSTOM_FUNCTION_REPEAT + CUSTOM_FUNCTION_GV_TOOGLE;
          }
          else {
            widgetsMask |= CUSTOM_FUNCTION_NUMERIC_PARAM + CUSTOM_FUNCTION_REPEAT;
            fswtchParamGV[i]->setChecked(false);
          }
          fswtchParam[i]->setMaximum(index==FuncPlayBoth ? 254 : 255);
          if (modified) {
            if (fswtchParamGV[i]->isChecked()) {
              fswtchParam[i]->setMinimum(1);
              model.funcSw[i].param = std::min(fswtchParam[i]->value(),5.0)+(fswtchParamGV[i]->isChecked() ? 250 : 0);
            }
            else {
              model.funcSw[i].param = fswtchParam[i]->value();
            }
          }
          if (model.funcSw[i].param>250 && (index!=FuncPlayBoth)) {
            fswtchParamGV[i]->setChecked(true);
            fswtchParam[i]->setValue(model.funcSw[i].param-250);
            fswtchParam[i]->setMaximum(5);
          }
          else {
            fswtchParamGV[i]->setChecked(false);
            fswtchParam[i]->setValue(model.funcSw[i].param);
          }
          if (model.funcSw[i].param < 251)
            widgetsMask |= CUSTOM_FUNCTION_PLAY;
        }
        else {
          widgetsMask |= CUSTOM_FUNCTION_FILE_PARAM;
          if (modified) {
            memset(model.funcSw[i].paramarm, 0, sizeof(model.funcSw[i].paramarm));
            int vml = firmware->getCapability(VoicesMaxLength);
            if (fswtchParamArmT[i]->currentText() != "----") {
              widgetsMask |= CUSTOM_FUNCTION_PLAY;
              for (int j=0; j<std::min(fswtchParamArmT[i]->currentText().length(), vml); j++) {
                model.funcSw[i].paramarm[j] = fswtchParamArmT[i]->currentText().toAscii().at(j);
              }
            }
          }
          populateFuncParamArmTCB(fswtchParamArmT[i], model.funcSw[i].paramarm, tracksSet);
          if (fswtchParamArmT[i]->currentText() != "----") {
            widgetsMask |= CUSTOM_FUNCTION_PLAY;
          }
        }
      }
      else if (index==FuncBackgroundMusic) {
        widgetsMask |= CUSTOM_FUNCTION_FILE_PARAM;
        if (modified) {
          memset(model.funcSw[i].paramarm, 0, sizeof(model.funcSw[i].paramarm));
          int vml=firmware->getCapability(VoicesMaxLength);
          if (fswtchParamArmT[i]->currentText() != "----") {
            widgetsMask |= CUSTOM_FUNCTION_PLAY;
            for (int j=0; j<std::min(fswtchParamArmT[i]->currentText().length(),vml); j++) {
              model.funcSw[i].paramarm[j] = fswtchParamArmT[i]->currentText().toAscii().at(j);
            }
          }
        }
        populateFuncParamArmTCB(fswtchParamArmT[i], model.funcSw[i].paramarm, tracksSet);
      }
      else if (index==FuncPlaySound) {
        if (modified) model.funcSw[i].param = (uint8_t)fswtchParamT[i]->currentIndex();
        populateFuncParamCB(fswtchParamT[i], model, index, model.funcSw[i].param);
        widgetsMask |= CUSTOM_FUNCTION_SOURCE_PARAM;
      }
      else if (index==FuncPlayHaptic) {
        if (modified) model.funcSw[i].param = (uint8_t)fswtchParamT[i]->currentIndex();
        populateFuncParamCB(fswtchParamT[i], model, index, model.funcSw[i].param);
        widgetsMask |= CUSTOM_FUNCTION_SOURCE_PARAM;
      }
    }
    else if (index==FuncPlayScript) {
      widgetsMask |= CUSTOM_FUNCTION_FILE_PARAM;
      if (modified) {
        memset(model.funcSw[i].paramarm, 0, sizeof(model.funcSw[i].paramarm));
        int vml = 8/*TODO*/;
        if (fswtchParamArmT[i]->currentText() != "----") {
          for (int j=0; j<std::min(fswtchParamArmT[i]->currentText().length(), vml); j++) {
            model.funcSw[i].paramarm[j] = fswtchParamArmT[i]->currentText().toAscii().at(j);
          }
        }
      }
      populateFuncParamArmTCB(fswtchParamArmT[i], model.funcSw[i].paramarm, scriptsSet);
    }
    else if (index==FuncBacklight && IS_TARANIS_PLUS(GetEepromInterface()->getBoard())) {
      if (modified) model.funcSw[i].param = (uint8_t)fswtchBLcolor[i]->value();
      fswtchBLcolor[i]->setValue(model.funcSw[i].param);
      widgetsMask |= CUSTOM_FUNCTION_BL_COLOR;
    }
    else {
      if (modified) model.funcSw[i].param = fswtchParam[i]->value();
      fswtchParam[i]->setDecimals(0);
      fswtchParam[i]->setSingleStep(1);
      fswtchParam[i]->setValue(model.funcSw[i].param);
      if (index <= FuncInstantTrim) {
        widgetsMask |= CUSTOM_FUNCTION_ENABLE;
      }
    }

    fswtchParam[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_NUMERIC_PARAM);
    fswtchParamTime[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_TIME_PARAM);
    fswtchParamGV[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_GV_TOOGLE);
    fswtchParamT[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_SOURCE_PARAM);
    fswtchParamArmT[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_FILE_PARAM);
    fswtchEnable[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_ENABLE);
    if (widgetsMask & CUSTOM_FUNCTION_ENABLE)
      fswtchEnable[i]->setChecked(model.funcSw[i].enabled);
    else
      fswtchEnable[i]->setChecked(false);
    fswtchRepeat[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_REPEAT);
    fswtchGVmode[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_GV_MODE);
    fswtchBLcolor[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_BL_COLOR);
#ifdef PHONON
    playBT[i]->setVisible(widgetsMask & CUSTOM_FUNCTION_PLAY);
#endif
}

void CustomFunctionsPanel::update()
{
  lock = true;
  for (int i=0; i<firmware->getCapability(CustomFunctions); i++) {
    if (!initialized) {
      populateSwitchCB(fswtchSwtch[i], model.funcSw[i].swtch, generalSettings, CustomFunctionsContext);
      populateFuncCB(fswtchFunc[i], model.funcSw[i].func);
      populateGVmodeCB(fswtchGVmode[i], model.funcSw[i].adjustMode);
      populateFuncParamCB(fswtchParamT[i], model, model.funcSw[i].func, model.funcSw[i].param, model.funcSw[i].adjustMode);
    }
    refreshCustomFunction(i);
  }
  initialized = true;
  lock = false;
}

void CustomFunctionsPanel::fswPaste()
{
  const QClipboard *clipboard = QApplication::clipboard();
  const QMimeData *mimeData = clipboard->mimeData();
  if (mimeData->hasFormat("application/x-companion-fsw")) {
    QByteArray fswData = mimeData->data("application/x-companion-fsw");
    FuncSwData *fsw = &model.funcSw[selectedFunction];
    memcpy(fsw, fswData.mid(0, sizeof(FuncSwData)).constData(), sizeof(FuncSwData));
    lock = true;
    populateSwitchCB(fswtchSwtch[selectedFunction], model.funcSw[selectedFunction].swtch, generalSettings, CustomFunctionsContext);
    populateFuncCB(fswtchFunc[selectedFunction], model.funcSw[selectedFunction].func);
    populateGVmodeCB(fswtchGVmode[selectedFunction], model.funcSw[selectedFunction].adjustMode);
    populateFuncParamCB(fswtchParamT[selectedFunction], model, model.funcSw[selectedFunction].func, model.funcSw[selectedFunction].param, model.funcSw[selectedFunction].adjustMode);
    refreshCustomFunction(selectedFunction);
    lock = false;
    emit modified();
  }
}

void CustomFunctionsPanel::fswDelete()
{
  model.funcSw[selectedFunction].clear();
  // TODO update switch and func
  lock = true;
  populateSwitchCB(fswtchSwtch[selectedFunction], model.funcSw[selectedFunction].swtch, generalSettings, CustomFunctionsContext);
  populateFuncCB(fswtchFunc[selectedFunction], model.funcSw[selectedFunction].func);
  refreshCustomFunction(selectedFunction);
  lock = false;
  emit modified();
}

void CustomFunctionsPanel::fswCopy()
{
  QByteArray fswData;
  fswData.append((char*)&model.funcSw[selectedFunction], sizeof(FuncSwData));
  QMimeData *mimeData = new QMimeData;
  mimeData->setData("application/x-companion-fsw", fswData);
  QApplication::clipboard()->setMimeData(mimeData, QClipboard::Clipboard);
}

void CustomFunctionsPanel::fswCut()
{
  fswCopy();
  fswDelete();
}

void CustomFunctionsPanel::fsw_customContextMenuRequested(QPoint pos)
{
    QLabel *label = (QLabel *)sender();
    selectedFunction = label->property("index").toInt();

    QPoint globalPos = label->mapToGlobal(pos);

    const QClipboard *clipboard = QApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();
    bool hasData = mimeData->hasFormat("application/x-companion-fsw");

    QMenu contextMenu;
    contextMenu.addAction(CompanionIcon("copy.png"), tr("&Copy"),this,SLOT(fswCopy()),tr("Ctrl+C"));
    contextMenu.addAction(CompanionIcon("cut.png"), tr("&Cut"),this,SLOT(fswCut()),tr("Ctrl+X"));
    contextMenu.addAction(CompanionIcon("paste.png"), tr("&Paste"),this,SLOT(fswPaste()),tr("Ctrl+V"))->setEnabled(hasData);
    contextMenu.addAction(CompanionIcon("clear.png"), tr("&Delete"),this,SLOT(fswDelete()),tr("Delete"));

    contextMenu.exec(globalPos);
}

void CustomFunctionsPanel::populateFuncCB(QComboBox *b, unsigned int value)
{
  b->clear();
  for (unsigned int i=0; i<FuncCount; i++) {
    b->addItem(FuncSwData(AssignFunc(i)).funcToString());
    if (((i>=FuncOverrideCH1 && i<=FuncOverrideCH32) && !firmware->getCapability(SafetyChannelCustomFunction)) ||
        ((i==FuncVolume || i==FuncBackgroundMusic || i==FuncBackgroundMusicPause) && !firmware->getCapability(HasVolume)) ||
        ((i==FuncPlayScript && !IS_TARANIS(firmware->getBoard()))) ||
        ((i==FuncPlayHaptic) && !firmware->getCapability(Haptic)) ||
        ((i==FuncPlayBoth) && !firmware->getCapability(HasBeeper)) ||
        ((i==FuncLogs) && !firmware->getCapability(HasSDLogs)) ||
        ((i>=FuncAdjustGV1 && i<=FuncAdjustGVLast) && !firmware->getCapability(Gvars))
        ) {
      QModelIndex index = b->model()->index(i, 0);
      QVariant v(0);
      b->model()->setData(index, v, Qt::UserRole - 1);
    }
  }
  b->setCurrentIndex(value);
  b->setMaxVisibleItems(10);
}

void CustomFunctionsPanel::populateGVmodeCB(QComboBox *b, unsigned int value)
{
  b->clear();
  b->addItem(QObject::tr("Value"));
  b->addItem(QObject::tr("Source"));
  b->addItem(QObject::tr("GVAR"));
  b->addItem(QObject::tr("Increment"));
  b->setCurrentIndex(value);
}

void CustomFunctionsPanel::populateFuncParamArmTCB(QComboBox *b, char * value, const QSet<QString> &paramsList)
{
  b->clear();
  b->addItem("----");

  bool added = false;
  QString currentvalue(value);
  foreach (QString entry, paramsList) {
    b->addItem(entry);
    if (entry==currentvalue) {
      b->setCurrentIndex(b->count()-1);
      added = true;
    }
  }

  if (!added && strlen(value)) {
    b->addItem(value);
    b->setCurrentIndex(b->count()-1);
  }
}

void CustomFunctionsPanel::populateFuncParamCB(QComboBox *b, const ModelData & model, uint function, unsigned int value, unsigned int adjustmode)
{
  QStringList qs;
  b->clear();
  if (function==FuncPlaySound) {
    qs <<"Beep 1" << "Beep 2" << "Beep 3" << "Warn1" << "Warn2" << "Cheep" << "Ratata" << "Tick" << "Siren" << "Ring" ;
    qs << "SciFi" << "Robot" << "Chirp" << "Tada" << "Crickt"  << "AlmClk"  ;
    b->addItems(qs);
    b->setCurrentIndex(value);
  }
  else if (function==FuncPlayHaptic) {
    qs << "0" << "1" << "2" << "3";
    b->addItems(qs);
    b->setCurrentIndex(value);
  }
  else if (function==FuncReset) {
    qs.append( QObject::tr("Timer1"));
    qs.append( QObject::tr("Timer2"));
    qs.append( QObject::tr("All"));
    qs.append( QObject::tr("Telemetry"));
    int reCount = firmware->getCapability(RotaryEncoders);
    if (reCount == 1) {
      qs.append( QObject::tr("Rotary Encoder"));
    }
    else if (reCount == 2) {
      qs.append( QObject::tr("REa"));
      qs.append( QObject::tr("REb"));
    }
    b->addItems(qs);
    b->setCurrentIndex(value);
  }
  else if (function==FuncVolume) {
    populateSourceCB(b, RawSource(value), model, POPULATE_SOURCES|POPULATE_VIRTUAL_INPUTS|POPULATE_TRIMS);
  }
  else if (function==FuncPlayValue) {
    populateSourceCB(b, RawSource(value), model, POPULATE_SOURCES|POPULATE_VIRTUAL_INPUTS|POPULATE_SWITCHES|POPULATE_GVARS|POPULATE_TRIMS|POPULATE_TELEMETRYEXT);
  }
  else if (function>=FuncAdjustGV1 && function<=FuncAdjustGVLast) {
    switch (adjustmode) {
      case 1:
        populateSourceCB(b, RawSource(value), model, POPULATE_SOURCES|POPULATE_VIRTUAL_INPUTS|POPULATE_TRIMS|POPULATE_SWITCHES);
        break;
      case 2:
        populateSourceCB(b, RawSource(value), model, POPULATE_GVARS);
        break;
      case 3:
        b->clear();
        b->addItem("-1", 0);
        b->addItem("+1", 1);
        b->setCurrentIndex(value);
        break;
    }
  }
  else {
    b->hide();
  }
}
