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
void MainWindow::getInput()
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

void MainWindow::setIndexes()
{
    for(int i=0; i<sorted.length(); i++){
        indexes.push_back(i);
    }
}

// 显示结果
void MainWindow::showResult(QVector<int> red, QVector<int> orange, QVector<int> array)
{
    QString res = "";
    if(array.isEmpty()) array=sorted;
    if(!red.isEmpty() || !orange.isEmpty()){
        for(int i=0;i<array.length();i++){
            if(red.indexOf(i) != -1)
                res = res + "<font style='color:red;'>" + QString::number(array[i]) + "</font>" + " ";
            else if(orange.indexOf(i) != -1)
                res = res + "<font style='color:orange;'>" + QString::number(array[i]) + "</font>" + " ";
            else
                res = res + QString::number(array[i]) + " ";
        }
        ui->edt_output->append(res);
    }else{
        ui->edt_output->append("-----------------------");
    }
}

void MainWindow::swap(QVector<int> &array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

void MainWindow::init(QString str)
{
    getInput();
    sorted = data;
    setIndexes();
    ui->edt_output->setText(str);
}

// 冒泡排序(Bubble Sort)
// 最佳情况：T(n) = O(n)   最差情况：T(n) = O(n2)   平均情况：T(n) = O(n2)
void MainWindow::on_btn_bubble_clicked()
{
    init("冒泡排序(Bubble Sort)\n最佳情况：T(n) = O(n)\n最差情况：T(n) = O(n2)\n平均情况：T(n) = O(n2)");

    if(sorted.length() == 0)return;
    for(int i=0;i<sorted.length()-1;i++){
        for(int j=0;j<sorted.length()-1-i;j++){
            if(sorted[j]>sorted[j+1]){
                int temp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = temp;

                showResult({j+1}, {j});//////////////////////
            }
        }
        showResult({}, {});//////////////////////
    }
}

// 选择排序(Selection Sort)
// 最佳情况：T(n) = O(n2)  最差情况：T(n) = O(n2)  平均情况：T(n) = O(n2)
void MainWindow::on_btn_selection_clicked()
{
    init("选择排序(Selection Sort)\n最佳情况：T(n) = O(n2)\n最差情况：T(n) = O(n2)\n平均情况：T(n) = O(n2)");

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

        showResult({minIndex}, {i});////////////////////
        showResult({}, {});//////////////////
    }
}

// 插入排序(Insertion Sort)
// 最佳情况：T(n) = O(n)   最坏情况：T(n) = O(n2)   平均情况：T(n) = O(n2)
void MainWindow::on_btn_insertion_clicked()
{
    init("插入排序(Insertion Sort)\n最佳情况：T(n) = O(n)\n最坏情况：T(n) = O(n2)\n平均情况：T(n) = O(n2)");

    if(sorted.length() == 0)return;
    for(int i=0;i<sorted.length()-1;i++){
        int current = sorted[i+1];
        int preIndex = i;
        while(preIndex>=0 && sorted[preIndex]>current){
            sorted[preIndex+1] = sorted[preIndex];
            preIndex--;

            showResult({}, {preIndex+1, preIndex+2});////////////////////
        }
        sorted[preIndex+1] = current;

        showResult({preIndex+1}, {});/////////////////////////
        showResult({}, {});/////////////////////
    }
}

// 希尔排序(Shell Sort)
// 最佳情况：T(n) = O(nlog2n)\n最坏情况：T(n) = O(nlog2n)\n平均情况：T(n) =O(nlog2n)
void MainWindow::on_btn_shell_clicked()
{
    init("希尔排序(Shell Sort)\n最佳情况：T(n) = O(nlog2n)\n最坏情况：T(n) = O(nlog2n)\n平均情况：T(n) = O(nlog2n)");

    int len = sorted.length();
    int gap = len/2;
    if(len == 0)return;
    while(gap>0){
        for(int i=gap;i<len;i++){
            // 循环里是插入排序
            int temp = sorted[i];
            int preIndex = i-gap;
            while(preIndex>=0 && sorted[preIndex]>temp){
                sorted[preIndex+gap] = sorted[preIndex];
                preIndex -= gap;

                showResult({}, {preIndex+gap, preIndex+gap+gap});///////////////////////
            }
            sorted[preIndex+gap] = temp;

            showResult({preIndex+gap},{});///////////////////////
        }
        gap /= 2;

        showResult({}, {});//////////////////////
    }
}

// 归并排序(Merge Sort)
// 最佳情况：T(n) = O(n)  最差情况：T(n) = O(nlogn)  平均情况：T(n) = O(nlogn)
void MainWindow::on_btn_merge_clicked()
{
    init("归并排序(Merge Sort)\n最佳情况：T(n) = O(n)\n最差情况：T(n) = O(nlogn)\n平均情况：T(n) = O(nlogn)");

    mergeSort(sorted);
}

void MainWindow::mergeSort(QVector<int> &array)
{
    if(array.length()<2) return;
    int mid = array.length() / 2;
    QVector<int> left = array.mid(0, mid);
    QVector<int> right = array.mid(mid, -1);
    showResult(indexes.mid(0,mid), indexes.mid(mid,array.length()-1), array);////////////////////////
    mergeSort(left);
    mergeSort(right);

    for(int index=0, i=0,j=0; index<array.length(); index++){
        if(i>=left.length()) array[index]=right[j++];
        else if(j>=right.length()) array[index]=left[i++];
        else if(left[i]>right[j]) array[index]=right[j++];
        else array[index]=left[i++];
    }

    showResult({-1}, {}, array);///////////////////////
}

// 快速排序(Quick Sort)
// 最佳情况：T(n) = O(nlogn)   最差情况：T(n) = O(n2)   平均情况：T(n) = O(nlogn)
void MainWindow::on_btn_quick_clicked()
{
    init("快速排序(Quick Sort)\n最佳情况：T(n) = O(nlogn)\n最差情况：T(n) = O(n2)\n平均情况：T(n) = O(nlogn)");

    quickSort(sorted, 0, sorted.length()-1);
}

void MainWindow::quickSort(QVector<int> &array, int start, int end)
{
    if(start>=end) return;
    int i = start;
    int j = end;
    int key = array[start];
    while(i<j){
        while(i<j && array[j]>=key){
            showResult({j}, {start});//////////////////////
            j--;
        }
        array[i] = array[j];
        showResult({i,j}, {start});///////////////////////
        while(i<j && array[i]<=key){
            showResult({i}, {start});/////////////////////
            i++;
        }
        array[j] = array[i];
        showResult({i,j}, {start});//////////////////////
    }
    array[i] = key;
    showResult({i}, {start});////////////////////////////
    showResult({}, {});//////////////////////////////////

    quickSort(array, start, i-1);
    quickSort(array, i+1, end);
}

// 堆排序(Heap Sort)
// 最佳情况：T(n) = O(nlogn) 最差情况：T(n) = O(nlogn) 平均情况：T(n) = O(nlogn)
void MainWindow::on_btn_heap_clicked()
{
    init("堆排序(Heap Sort)\n最佳情况：T(n) = O(nlogn)\n最差情况：T(n) = O(nlogn)\n平均情况：T(n) = O(nlogn)");

    int len = sorted.length();
    if(len == 1)return;
    buildMaxHeap(sorted, len);
    while(len>0){
        swap(sorted, 0, len-1);
        showResult({0, len-1},{});//////////////////////
        len--;
        adjustHeap(sorted, 0, len);
    }
}

void MainWindow::buildMaxHeap(QVector<int> &array, int len)
{
    for(int i=(len-1)/2; i>=0; i--){
        adjustHeap(array, i, len);
    }
}

void MainWindow::adjustHeap(QVector<int> &array, int i, int len)
{
    int maxIndex = i;
    if(i*2<len && array[i*2]>array[maxIndex])
        maxIndex = i*2;
    if(i*2+1<len && array[i*2+1]>array[maxIndex])
        maxIndex = i*2+1;

    if(maxIndex != i){
        swap(array, maxIndex, i);
        if(maxIndex == i*2)
            showResult({i, i*2},{i*2+1});///////////////////////
        else
            showResult({i, i*2+1}, {i*2});//////////////////////
        adjustHeap(array, maxIndex, len);
    }else{
        showResult({},{i, i*2, i*2+1});/////////////////////////
        showResult({},{});//////////////////////////////////////
    }
}

// 计数排序(Count Sort)
// 最佳情况：T(n) = O(n+k)  最差情况：T(n) = O(n+k)  平均情况：T(n) = O(n+k)
void MainWindow::on_btn_count_clicked()
{
    init("计数排序(Count Sort)\n最佳情况：T(n) = O(n+k)\n最差情况：T(n) = O(n+k)\n平均情况：T(n) = O(n+k)\n只能用于非负整数");

    countSort(sorted);
}

void MainWindow::countSort(QVector<int> &array)
{
    int len = array.length();
    if(len == 0) return;
    const int range = 100;
    int count[range] = {0};
    QVector<int> temp = array;

    for(int i=0;i<len;i++){
        ++count[array[i]];
    }

    for(int i=1;i<range;i++){
        count[i]+=count[i-1];
    }
    for(int i=len-1;i>=0;i--){
        array[--count[temp[i]]] = temp[i];
    }
    showResult({-1},{});
}

// 桶排序(Bucket Sort)
// 最佳情况：T(n) = O(n+k)   最差情况：T(n) = O(n+k)   平均情况：T(n) = O(n2)
void MainWindow::on_btn_bucket_clicked()
{
    init("桶排序(Bucket Sort)\n最佳情况：T(n) = O(n+k)\n最差情况：T(n) = O(n+k)\n平均情况：T(n) = O(n2)");

    bucketSort(sorted, 4);
    showResult({-1},{}, sorted);
}

QVector<int> MainWindow::bucketSort(QVector<int> &array, int bucketSize)
{
    int len = array.length();
    if(len<2) return array;

    QVector<int> *result = new QVector<int>();
    int max = array[0];
    int min = array[0];
    for(int i=0;i<len;i++){
        if(array[i]>max) max=array[i];
        if(array[i]<min) min=array[i];
    }
    if(max == min) return array;

    int bucketCount = (max - min)/bucketSize + 1;
    QVector<QVector<int>> *bucketArray = new QVector<QVector<int>>(bucketCount);
    for(int i=0;i<len;i++){
        (*bucketArray)[(array[i]-min)/bucketSize].push_back(array[i]);
    }

    for(int i=0;i<bucketCount;i++){
        if(bucketCount == 1) bucketSize--;
        QVector<int> temp = bucketSort((*bucketArray)[i], bucketSize);
        for(int i=0;i<temp.length();i++){
            result->push_back(temp[i]);
        }
    }
    array = *result;

    return *result;
}

// 基数排序
// 最佳情况：T(n) = O(n * k)   最差情况：T(n) = O(n * k)   平均情况：T(n) = O(n * k)
void MainWindow::on_btn_radix_clicked()
{
    init("基数排序(Radix Sort)\n最佳情况：T(n) = O(n * k)\n最差情况：T(n) = O(n * k)\n平均情况：T(n) = O(n * k))");
    radixSort(sorted);
}

void MainWindow::radixSort(QVector<int> &array)
{
    int len = array.length();
    if(len < 2) return;

    //找到最大值
    int max = array[0];
    for(int i=0;i<len;i++){
        max = array[i]>max?array[i]:max;
    }

    //最大值的位数
    int maxDigit = 0;
    while(max!=0){
        max /= 10;
        maxDigit++;
    }

    int mod = 10;
    int div = 1;
    QVector<QVector<int>> *bucketArray = new QVector<QVector<int>>(10);
    for(int i=0;i<maxDigit;i++,mod*=10,div*=10){
        for(int j=0;j<len;j++){
            int num = (array[j]%mod)/div;
            (*bucketArray)[num].push_back(array[j]);
        }
        for(int j=0;j<bucketArray->length();j++){       ///////////////////////
            if(!((*bucketArray)[j].isEmpty()))          ///////////////////////
                showResult({-1},{},(*bucketArray)[j]);  ///////////////////////
        }                                               ///////////////////////
        int index = 0;
        for(int j=0;j<bucketArray->length();j++){
            for(int k=0;k<(*bucketArray)[j].length();k++){
                array[index++] = (*bucketArray)[j][k];
            }
            (*bucketArray)[j].clear();
        }
        showResult({-1},{});    /////////////////////
        showResult({},{});      /////////////////////
    }
}
