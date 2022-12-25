#ifndef AI_DOCTOR_H
#define AI_DOCTOR_H

#include <QMainWindow>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class Ai_Doctor; }
QT_END_NAMESPACE

class Ai_Doctor : public QMainWindow
{
    Q_OBJECT

public:
    Ai_Doctor(QWidget *parent = nullptr);
    ~Ai_Doctor();

private slots:
    void on_StartQuery_clicked();

    void on_BackToWelcome_clicked();

    void on_InfoToProbelms_clicked();

    void on_CloseFromInfo_clicked();

    void on_BackToInfo_clicked();

    void on_CloseFromProblemsList_clicked();

    void on_GoToDoctorPage_clicked();

    void on_BackToInfo_2_clicked();

    void on_AboutAiDoctor_clicked();

    void on_FromAiDoctorToInfo_clicked();

    void on_SignUp_clicked();

    void on_BackToLogin_clicked();

    void on_CloseFromSignUp_clicked();

    void on_BackFromDOCTORS_LIST_clicked();


    void on_LogOutFromDOCTORS_LIST_clicked();

private:
    Ui::Ai_Doctor *ui;
    QString Name_Info, Age_Info, Disease, Location_Info, CityInfo, SignUpEmail="21", SignUpPassword="21";
    QString LoginEmail="12", LoginPassword="12";
    QSqlDatabase db, db2;

};
#endif // AI_DOCTOR_H
