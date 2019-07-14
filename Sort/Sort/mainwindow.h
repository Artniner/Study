#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_bubble_clicked();

    void on_btn_selection_clicked();

    void on_btn_insertion_clicked();

private:
    Ui::MainWindow *ui;

private:
    QVector<int> data;
    QVector<int> sorted;

    void Init(QString str);
    void GetInput();
    void ShowResult(QVector<int> diff);
};

#endif // MAINWINDOW_H
