#include "ai_doctor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ai_Doctor w;
    w.show();
    return a.exec();
}
