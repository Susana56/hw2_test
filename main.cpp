#include "grade_calc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    grade_calc w;
    w.show();

    return a.exec();
}
