#ifndef GENERALEDIT_H
#define GENERALEDIT_H

#include <QDialog>
#include "eeprominterface.h"

namespace Ui {
    class GeneralEdit;
}

class GeneralEdit : public QDialog
{
    Q_OBJECT

  public:
    explicit GeneralEdit(RadioData &radioData, QWidget *parent = 0);
    ~GeneralEdit();
    void updateSettings();

  private:
    Ui::GeneralEdit *ui;
    RadioData &radioData;
    GeneralSettings g_eeGeneral;

    bool switchDefPosEditLock;
    bool voiceLangEditLock;
    void getGeneralSwitchDefPos(int i, bool val);
    void setSwitchDefPos();
    void updateVarioPitchRange();
    void disableMouseScrolling();

  protected:
    virtual bool eventFilter(QObject *obj, QEvent *event);
    
  signals:
    void modelValuesChanged();

  private slots:
    void on_faimode_CB_stateChanged(int );
    void on_speakerPitchSB_editingFinished();
    void on_timezoneSB_editingFinished();
    void on_hapticStrength_valueChanged();
    void on_soundModeCB_currentIndexChanged(int index);
    void on_beeperlenCB_currentIndexChanged(int index);
    void on_volume_SB_editingFinished();
    void on_hapticmodeCB_currentIndexChanged(int index);
    void on_hapticLengthCB_currentIndexChanged(int index);
    void on_PPM_MultiplierDSB_editingFinished();
    void on_splashScreenChkB_stateChanged(int);
    void on_splashScreenDuration_currentIndexChanged(int index);
    void on_alarmwarnChkB_stateChanged(int );
    void on_gpsFormatCB_currentIndexChanged(int index);
    void on_tabWidget_currentChanged(int index);
    void on_displayTypeCB_currentIndexChanged(int index);
    void on_BLBright_SB_editingFinished();
    void on_backlightColor_SL_valueChanged();
    void on_re_CB_currentIndexChanged(int index);
    void on_countrycode_CB_currentIndexChanged(int index);
    void on_units_CB_currentIndexChanged(int index);
    void on_trnMode_1_currentIndexChanged(int index);
    void on_trnChn_1_currentIndexChanged(int index);
    void on_trnWeight_1_editingFinished();
    void on_trnMode_2_currentIndexChanged(int index);
    void on_trnChn_2_currentIndexChanged(int index);
    void on_trnWeight_2_editingFinished();
    void on_trnMode_3_currentIndexChanged(int index);
    void on_trnChn_3_currentIndexChanged(int index);
    void on_trnWeight_3_editingFinished();
    void on_trnMode_4_currentIndexChanged(int index);
    void on_trnChn_4_currentIndexChanged(int index);
    void on_trnWeight_4_editingFinished();

    void on_CurrentCalib_SB_editingFinished();

    void on_ana1Neg_editingFinished();
    void on_ana2Neg_editingFinished();
    void on_ana3Neg_editingFinished();
    void on_ana4Neg_editingFinished();
    void on_ana5Neg_editingFinished();
    void on_ana6Neg_editingFinished();
    void on_ana7Neg_editingFinished();
    void on_ana8Neg_editingFinished();

    void on_ana1Mid_editingFinished();
    void on_ana2Mid_editingFinished();
    void on_ana3Mid_editingFinished();
    void on_ana4Mid_editingFinished();
    void on_ana5Mid_editingFinished();
    void on_ana6Mid_editingFinished();
    void on_ana7Mid_editingFinished();
    void on_ana8Mid_editingFinished();

    void on_ana1Pos_editingFinished();
    void on_ana2Pos_editingFinished();
    void on_ana3Pos_editingFinished();
    void on_ana4Pos_editingFinished();
    void on_ana5Pos_editingFinished();
    void on_ana6Pos_editingFinished();
    void on_ana7Pos_editingFinished();
    void on_ana8Pos_editingFinished();

    void on_PPM1_editingFinished();
    void on_PPM2_editingFinished();
    void on_PPM3_editingFinished();
    void on_PPM4_editingFinished();
    void on_beepVolume_SL_valueChanged();
    void on_bgVolume_SL_valueChanged();
    void on_varioVolume_SL_valueChanged();
    void on_wavVolume_SL_valueChanged();
    
    void on_varioP0_SB_editingFinished();
    void on_varioPMax_SB_editingFinished();
    void on_varioR0_SB_editingFinished();
    
    void on_pot1Type_currentIndexChanged(int index);
    void on_pot2Type_currentIndexChanged(int index);
    void on_pot3Type_currentIndexChanged(int index);

    void on_stickmodeCB_currentIndexChanged(int index);
    void on_channelorderCB_currentIndexChanged(int index);
    void on_beeperCB_currentIndexChanged(int index);
    void on_memwarnChkB_stateChanged(int );
    void on_inactimerSB_editingFinished();
    void on_backlightautoSB_editingFinished();
    void on_backlightswCB_currentIndexChanged(int index);
    void on_voiceLang_CB_currentIndexChanged(int index);
    void on_battCalibDSB_editingFinished();
    void on_battwarningDSB_editingFinished();
    void on_contrastSB_editingFinished();
    void on_calretrieve_PB_clicked();
    void on_calstore_PB_clicked();
    void unlockSwitchEdited();
    void setValues();
    void shrink();
    void stickReverseEdited();
    void on_switchesDelay_valueChanged();
    void on_blAlarm_ChkB_stateChanged();
};

#endif // GENERALEDIT_H
