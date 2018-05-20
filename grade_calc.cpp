#include "grade_calc.h"
#include "ui_grade_calc.h"

grade_calc::grade_calc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calc)
{
    ui->setupUi(this);
}

grade_calc::~grade_calc()
{
    delete ui;
}
