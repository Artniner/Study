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

    void on_btn_shell_clicked();

    void on_btn_merge_clicked();

    void on_btn_quick_clicked();

    void on_btn_heap_clicked();

    void on_btn_count_clicked();

    void on_btn_bucket_clicked();

    void on_btn_radix_clicked();

private:
    Ui::MainWindow *ui;

private:
    QVector<int> data;
    QVector<int> sorted;
    QVector<int> indexes;

    void init(QString str);
    void getInput();
    void setIndexes();
    void showResult(QVector<int> red, QVector<int> orange, QVector<int> array = {});
    void swap(QVector<int> &array, int x, int y);

    void mergeSort(QVector<int> &array);
    void quickSort(QVector<int> &array, int start, int end);
    void buildMaxHeap(QVector<int> &array, int len);
    void adjustHeap(QVector<int> &array, int i, int len);
    void countSort(QVector<int> &array);
    QVector<int> bucketSort(QVector<int> &array, int bucketSize);
    void radixSort(QVector<int> &array);
};

#endif // MAINWINDOW_H
