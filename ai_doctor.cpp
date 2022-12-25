#include "ai_doctor.h"
#include "ui_ai_doctor.h"

Ai_Doctor::Ai_Doctor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ai_Doctor)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    db = QSqlDatabase :: addDatabase("QSQLITE") ;
    db.setDatabaseName("D:/DBForAiDoctor/SignUpDBForAiDoctor.db");
    //db2 = QSqlDatabase :: addDatabase("QSQLITE");//, "DOCTORS_LIST");
    //db2.setDatabaseName("D:/DBForAiDoctor/DOCTORS_LIST.db");
    db.open();
    //db2.open();
}

Ai_Doctor::~Ai_Doctor()
{
    db.close();
    //db.removeDatabase(QSqlDatabase::defaultConnection);
    db2.close();
    delete ui;
}


void Ai_Doctor::on_StartQuery_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Ai_Doctor::on_BackToWelcome_clicked()
{
    LoginEmail = ui->LoginEmail->text();
    LoginPassword = ui->LoginPassword->text();
    CityInfo = ui->CityComboBox->currentText();
    QSqlQuery query;
    query.exec(" SELECT * FROM SignUpDBForAiDoctor WHERE Email='"+LoginEmail+"' AND Password='"+LoginPassword+"' ");
    if( query.next() )
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if( LoginEmail==SignUpEmail && LoginPassword==SignUpPassword )
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if( LoginEmail=="AdminTamur" && LoginPassword=="C221098" )
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if( LoginEmail=="AdminFarhan" && LoginPassword=="C221115")
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        QMessageBox :: warning(this,"Login","Email or Password is Wrong!");
    }
    ui->LoginEmail->clear();
    ui->LoginPassword->clear();
}


void Ai_Doctor::on_InfoToProbelms_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Ai_Doctor::on_CloseFromInfo_clicked()
{
    close();
}


void Ai_Doctor::on_BackToInfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Ai_Doctor::on_CloseFromProblemsList_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}




void Ai_Doctor::on_GoToDoctorPage_clicked()
{
    if( ui->CheckDiabetes->isChecked() )
    {
        Disease = "Diabetes";
    }
    else if( ui->CheckCancer->isChecked() )
    {
        Disease = "Cancer";
    }
    else if( ui->CheckHeart->isChecked() )
    {
        Disease = "Heart";
    }
    else if( ui->CheckGynae->isChecked() )
    {
        Disease = "Gynae";
    }
    else
    {
        Disease = 0;
        QMessageBox :: warning(this, "Doctors", "Please select the kind of doctor you want to see.");
    }

    db2 = QSqlDatabase :: addDatabase("QSQLITE");
    db2.setDatabaseName("D:/DBForAiDoctor/DOCTORS_LIST.db");
    db2.open();
    QSqlQuery query1;

    query1.exec("SELECT * FROM DOCTORS_LIST WHERE Disease='"+Disease+"' AND ( City='"+CityInfo+"' OR City='"+Location_Info+"' ) ");
    for( int i=0; i<4; i++ )
    {
        if( query1.next() )
        {
            qDebug() <<"Passed";
            if( i==0 )
            {
                ui->DrPageTitle->setText( query1.value(7).toString() );
                ui->Dr1Name->setText( query1.value(0).toString() );
                ui->Dr1Time2->setText( query1.value(3).toString() );
                ui->Dr1Chamber2->setText( query1.value(2).toString() );
                ui->Dr1Contact2->setText( query1.value(4).toString() );
            }
            if( i==1 )
            {
                //ui->DrPageTitle->setText( query1.value(7).toString() );
                ui->Dr2Name->setText( query1.value(0).toString() );
                ui->Dr2Time2->setText( query1.value(3).toString() );
                ui->Dr2Chamber2->setText( query1.value(2).toString() );
                ui->Dr2Contact2->setText( query1.value(4).toString() );
            }
            if( i==2 )
            {
                //ui->DrPageTitle->setText( query1.value(7).toString() );
                ui->Dr3Name->setText( query1.value(0).toString() );
                ui->Dr3Time2->setText( query1.value(3).toString() );
                ui->Dr3Chamber2->setText( query1.value(2).toString() );
                ui->Dr3Contact2->setText( query1.value(4).toString() );
            }
            if( i==3 )
            {
                //ui->DrPageTitle->setText( query1.value(7).toString() );
                ui->Dr4Name->setText( query1.value(0).toString() );
                ui->Dr4Time2->setText( query1.value(3).toString() );
                ui->Dr4Chamber2->setText( query1.value(2).toString() );
                ui->Dr4Contact2->setText( query1.value(4).toString() );
            }
            ui->stackedWidget->setCurrentIndex(5);
            //ui->Dr1ForDiabetes_2->(query1.value(0).toString());
        }
        else
        {
            qDebug() << "Failed";
        }
    }
    qDebug() <<Disease<<" "<<CityInfo;
}


void Ai_Doctor::on_BackToInfo_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Ai_Doctor::on_AboutAiDoctor_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Ai_Doctor::on_FromAiDoctorToInfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Ai_Doctor::on_SignUp_clicked()
{
    QSqlQuery query;
    Name_Info = ui->Name_Info->text();
    Age_Info = ui->Age_Info->text();
    Location_Info = ui->LocationComboBox->currentText();
    SignUpEmail  = ui->SignUpEmail->text();
    SignUpPassword = ui->SignUpPassword->text();
    int check=0, x = SignUpEmail.size();
    for( int i=0; i<x; i++ )
    {
        if( SignUpEmail[i]=='@' )
        {
            check=1;
            for( int j=i+2; j<x; j++ )
            {
                if( (SignUpEmail[j]=='.') && (SignUpEmail[j+1]=='c') && (SignUpEmail[j+2]=='o') && (SignUpEmail[j+3]=='m') )
                {
                    check=1;
                    break;
                }
                else
                    check=0;
            }
            break;
        }
        else
            check=0;
    }
    query.exec(" SELECT * FROM SignUpDBForAiDoctor WHERE Email='"+SignUpEmail+"' ");
    if( query.next() )
    {
        check=0;
        QMessageBox :: warning(this, "SignUp", "Account exists using this Email!");
    }
    query.exec(" SELECT * FROM SignUpDBForAiDoctor WHERE Password='"+SignUpPassword+"' ");
    if( query.next() )
    {
        //check=0;
        QMessageBox :: warning(this, "SignUp", "Weak Password!");
    }
    if( check==1 && SignUpPassword.size()>3 && Name_Info.size()>3 && Age_Info.size()>0 && Location_Info.size()>0 )
    {
        SignUpEmail  = ui->SignUpEmail->text();
        SignUpPassword = ui->SignUpPassword->text();
        Name_Info = ui->Name_Info->text();
        Age_Info = ui->Age_Info->text();
        Location_Info = ui->LocationComboBox->currentText();
        query.exec("INSERT INTO SignUpDBForAiDoctor (Name, Email, Password, Location, Age) VALUES ( '"+Name_Info+"', '"+SignUpEmail+"', '"+SignUpPassword+"', '"+Location_Info+"', '"+Age_Info+"' )");
        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        QMessageBox :: warning(this, "SignUp", "Please share ur correct information!");
        SignUpEmail = "21";
        SignUpPassword = "21";
    }

    ui->Name_Info->clear();
    ui->Age_Info->clear();
    ui->SignUpEmail->clear();
    ui->SignUpPassword->clear();
}


void Ai_Doctor::on_BackToLogin_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Ai_Doctor::on_CloseFromSignUp_clicked()
{
    close();
}


void Ai_Doctor::on_BackFromDOCTORS_LIST_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void Ai_Doctor::on_LogOutFromDOCTORS_LIST_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

