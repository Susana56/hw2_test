#ifndef GRADE_CALC_H
#define GRADE_CALC_H

#include <QMainWindow>

namespace Ui {
class grade_calc;
}

class grade_calc : public QMainWindow
{
    Q_OBJECT

public:
    explicit grade_calc(QWidget *parent = 0);
    ~grade_calc();

private:
    Ui::grade_calc *ui;

private slots:
    void on_pushButton_calculate_clicked();
    void on_comboBox_course_currentIndexChanged(const QString &arg1);
    void on_checkBox_clicked(bool checked);
};

#endif // GRADE_CALC_H
