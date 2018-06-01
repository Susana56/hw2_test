#include "grade_calc.h"
#include "ui_grade_calc.h"

#include <vector>
#include <algorithm>


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




void grade_calc::on_pushButton_calculate_clicked()
{
    int homeworks, low_hw, midterm_1, midterm_2 ,final, grade, final_project;

    if(ui->comboBox_course->currentText() == "PIC 10B. Intermediate Programming"){

        //trying to find lowest hw
        std::vector<int> values;
        values.push_back(ui->spinBox_hw1->value());
        values.push_back(ui->spinBox_hw2->value());
        values.push_back(ui->spinBox_hw3->value());
        values.push_back(ui->spinBox_hw4->value());
        values.push_back(ui->spinBox_hw5->value());
        values.push_back(ui->spinBox_hw6->value());
        values.push_back(ui->spinBox_hw7->value());

        if(ui->checkBox->isChecked()){   // if there is only 7 assignments

         std::vector<int>::iterator it= std::min_element(std::begin(values), std::end(values));
         low_hw = std::distance(std::begin(values), it);


            if(low_hw == 0){
                homeworks = (values[1] + values[2] +values[3] +values[4] + values[5]+ values[6])/6;
            }
            else if(low_hw ==1){
                homeworks = (values[0] + values[2] +values[3] +values[4] + values[5]+ values[6])/6;
            }
            else if (low_hw == 2){
                homeworks = (values[1] + values[0] +values[3] +values[4] + values[5]+ values[6])/6;
            }
            else if (low_hw ==3 ){
                homeworks = (values[1] + values[2] +values[0] +values[4] + values[5]+ values[6])/6;
            }
            else if (low_hw == 4){
                homeworks = (values[1] + values[2] +values[3] +values[0] + values[5]+ values[6])/6;
            }
            else if (low_hw == 5){
                homeworks = (values[1] + values[2] +values[3] +values[4] + values[0]+ values[6])/6;
            }
            else if (low_hw == 6){
                homeworks = (values[1] + values[2] +values[3] +values[4] + values[5]+ values[0])/6;
            }
        }

        else{ // there are 8 assignments
            values.push_back(ui->spinBox_hw8->value());
            std::vector<int>::iterator it= std::min_element(std::begin(values), std::end(values));
            low_hw = std::distance(std::begin(values), it);


            if(low_hw == 0){
                homeworks = (values[1] + values[2] +values[3] +values[4] + values[5]+ values[6] + values[7])/7;
            }
            else if(low_hw ==1){
                homeworks = (values[0] + values[2] +values[3] +values[4] + values[5]+ values[6]+ values[7])/7;
            }
            else if (low_hw == 2){
                homeworks = (values[1] + values[0] +values[3] +values[4] + values[5]+ values[6]+ values[7])/7;
            }
            else if (low_hw ==3 ){
                homeworks = (values[1] + values[2] +values[0] +values[4] + values[5]+ values[6]+ values[7])/7;
            }
            else if (low_hw == 4){
                homeworks = (values[1] + values[2] +values[3] +values[0] + values[5]+ values[6]+ values[7])/7;
            }
            else if (low_hw == 5){
                homeworks = (values[1] + values[2] +values[3] +values[4] + values[0]+ values[6]+ values[7])/7;
            }
            else if (low_hw == 6){
                homeworks = (values[1] + values[2] +values[3] +values[4] + values[5]+ values[0]+ values[7])/7;
            }

            else if (low_hw == 7){
                homeworks = (values[1] + values[2] +values[3] +values[4] + values[5]+ values[6]+ values[0])/7;
            }
        }

        midterm_1 = ui->spinBox_Mt1->value();
        midterm_2 = ui->spinBox_Mt2->value();
        final= ui->spinBox_Final->value();

        if(ui->radioButton_A->isChecked()){

            grade = homeworks*(.25)+ midterm_1*(.20) + midterm_2*(.20) +final*(.35);
        }
        else { // schema b is selected
            if(midterm_2 > midterm_1){
                midterm_1 = midterm_2;
            }
            grade = homeworks*(.25)+ midterm_1*(.30) +final*(.45);
        }
    }
    else{ // if course is for PIC 10C
        homeworks = ui->spinBox_hw1->value() + ui->spinBox_hw2->value() + ui->spinBox_hw3->value() ;
        midterm_1 = ui->spinBox_Mt1->value();
        final_project = ui->spinBox_hw4->value();
        final= ui->spinBox_Final->value();

        if(ui->radioButton_A->isChecked()){
            grade = homeworks*(.15)+ midterm_1*(.25) +final*(.30) + final_project*(.35) ;
        }

        else{ // schema B is selected
            grade = homeworks*(.15)+ final*(.50) + final_project*(.35) ;
        }
    }
    ui->Overall_score->setNum(grade);
}

void grade_calc::on_comboBox_course_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "PIC 10C. Advanced Programming"){
        ui->label_hw4->setText("Final Project");
        ui->label_hw5->setText("HW 5/ N.A.");
        ui->label_hw6->setText("Hw 6 / N.A.");
        ui->label_hw7->setText("Hw 7 / N.A.");
        ui->label_hw8->setText("Hw 8 / N.A.");
        ui->checkBox->setText("N/A");


        ui->label_Mt2->setText("Midterm 2 / N.A.");
    }
    else if (arg1 == "PIC 10B. Intermediate Programming" ) {
        ui->label_hw4->setText("Hw 4");
        ui->label_hw5->setText("Hw 5");
        ui->label_hw6->setText("Hw 6");
        ui->label_hw7->setText("Hw 7");
        ui->label_hw8->setText("Hw 8");
        ui->checkBox->setText("Are there 7 total homeworks?");

        ui->label_Mt2->setText("Midterm 2");

    }
}

void grade_calc::on_checkBox_clicked(bool checked)
{
    if (checked == 1){
        ui->label_hw8->setText("Hw 8 / N.A.");
    }
    else{
        ui->label_hw8->setText("Hw 8");
    }
}
