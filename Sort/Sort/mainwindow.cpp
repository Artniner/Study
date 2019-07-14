#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 获取输入
void MainWindow::GetInput()
{
    data = {};
    QString s_data = ui->edt_input->text();
    s_data = s_data.trimmed();
    QStringList sl_data = s_data.split(" ");

    QMutableListIterator<QString> itr(sl_data);
    while(itr.hasNext()){
        data.push_back(itr.next().toInt());
    }
}

// 显示结果
void MainWindow::ShowResult(QVector<int> diff)
{
    QString res = "";
    for(int i=0;i<sorted.length();i++){
        if(diff.indexOf(i)!=-1)
            res = res + "<font style='color:red;'>" + QString::number(sorted[i]) + "</font>" + " ";
        else
            res = res + QString::number(sorted[i]) + " ";
    }
    ui->edt_output->append(res);
}

void MainWindow::Init(QString str)
{
    GetInput();
    sorted = data;
    ui->edt_output->setText(str);
}

// 冒泡排序
// 最佳情况：T(n) = O(n)   最差情况：T(n) = O(n2)   平均情况：T(n) = O(n2)
void MainWindow::on_btn_bubble_clicked()
{
    Init("冒泡排序\n最佳情况：T(n) = O(n)\n最差情况：T(n) = O(n2)\n平均情况：T(n) = O(n2)");

    if(sorted.length() == 0)return;
    for(int i=0;i<sorted.length()-1;i++){
        for(int j=0;j<sorted.length()-1-i;j++){
            if(sorted[j]>sorted[j+1]){
                int temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;

                QVector<int> diff = {j,j+1};
                ShowResult(diff);
            }
        }
    }
}

// 选择排序
// 最佳情况：T(n) = O(n2)  最差情况：T(n) = O(n2)  平均情况：T(n) = O(n2)
void MainWindow::on_btn_selection_clicked()
{
    Init("选择排序\n最佳情况：T(n) = O(n2)\n最差情况：T(n) = O(n2)\n平均情况：T(n) = O(n2)");

    if(sorted.length() == 0)return;
    for(int i=0;i<sorted.length()-1;i++){
        int minIndex = i;
        for(int j=i+1;j<sorted.length();j++){
            if(sorted[minIndex]>sorted[j]){
                minIndex = j;
            }
        }
        int temp = sorted[i];
        sorted[i] = sorted[minIndex];
        sorted[minIndex] = temp;

        QVector<int> diff = {i, minIndex};
        ShowResult(diff);
    }
}

// 插入排序
// 最佳情况：T(n) = O(n)   最坏情况：T(n) = O(n2)   平均情况：T(n) = O(n2)
void MainWindow::on_btn_insertion_clicked()
{
    Init("插入排序\n最佳情况：T(n) = O(n)\n最坏情况：T(n) = O(n2)\n平均情况：T(n) = O(n2)");

    if(sorted.length() == 0)return;
    for(int i=0;i<sorted.length()-1;i++){
        int current = sorted[i+1];
        int preIndex = i;
        while(preIndex>=0 && sorted[preIndex]>current){
            sorted[preIndex+1] = sorted[preIndex];
            preIndex--;
        }
        sorted[preIndex+1] = current;

        QVector<int> diff = {preIndex+1};
        ShowResult(diff);
    }
}


