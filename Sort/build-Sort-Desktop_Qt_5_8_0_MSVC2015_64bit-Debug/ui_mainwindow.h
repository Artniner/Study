/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *edt_input;
    QTextEdit *edt_output;
    QGridLayout *gridLayout;
    QPushButton *btn_shell;
    QPushButton *btn_selection;
    QPushButton *btn_heap;
    QPushButton *btn_insertion;
    QPushButton *btn_merge;
    QPushButton *btn_quick;
    QPushButton *btn_bubble;
    QPushButton *btn_count;
    QPushButton *btn_bucket;
    QPushButton *btn_radix;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(425, 607);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        edt_input = new QLineEdit(centralWidget);
        edt_input->setObjectName(QStringLiteral("edt_input"));
        edt_input->setEnabled(true);

        verticalLayout->addWidget(edt_input);

        edt_output = new QTextEdit(centralWidget);
        edt_output->setObjectName(QStringLiteral("edt_output"));
        edt_output->setEnabled(true);
        edt_output->setReadOnly(true);

        verticalLayout->addWidget(edt_output);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        btn_shell = new QPushButton(centralWidget);
        btn_shell->setObjectName(QStringLiteral("btn_shell"));

        gridLayout->addWidget(btn_shell, 1, 0, 1, 1);

        btn_selection = new QPushButton(centralWidget);
        btn_selection->setObjectName(QStringLiteral("btn_selection"));

        gridLayout->addWidget(btn_selection, 0, 1, 1, 1);

        btn_heap = new QPushButton(centralWidget);
        btn_heap->setObjectName(QStringLiteral("btn_heap"));

        gridLayout->addWidget(btn_heap, 2, 0, 1, 1);

        btn_insertion = new QPushButton(centralWidget);
        btn_insertion->setObjectName(QStringLiteral("btn_insertion"));

        gridLayout->addWidget(btn_insertion, 0, 2, 1, 1);

        btn_merge = new QPushButton(centralWidget);
        btn_merge->setObjectName(QStringLiteral("btn_merge"));

        gridLayout->addWidget(btn_merge, 1, 1, 1, 1);

        btn_quick = new QPushButton(centralWidget);
        btn_quick->setObjectName(QStringLiteral("btn_quick"));

        gridLayout->addWidget(btn_quick, 1, 2, 1, 1);

        btn_bubble = new QPushButton(centralWidget);
        btn_bubble->setObjectName(QStringLiteral("btn_bubble"));

        gridLayout->addWidget(btn_bubble, 0, 0, 1, 1);

        btn_count = new QPushButton(centralWidget);
        btn_count->setObjectName(QStringLiteral("btn_count"));

        gridLayout->addWidget(btn_count, 2, 1, 1, 1);

        btn_bucket = new QPushButton(centralWidget);
        btn_bucket->setObjectName(QStringLiteral("btn_bucket"));

        gridLayout->addWidget(btn_bucket, 2, 2, 1, 1);

        btn_radix = new QPushButton(centralWidget);
        btn_radix->setObjectName(QStringLiteral("btn_radix"));

        gridLayout->addWidget(btn_radix, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 425, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        edt_input->setText(QApplication::translate("MainWindow", "5 6 4 8 2 15 23 55 15 23 59 74 23 6 21 54 86 21 35 4 2 3 88 4", Q_NULLPTR));
        btn_shell->setText(QApplication::translate("MainWindow", "\345\270\214\345\260\224\346\216\222\345\272\217", Q_NULLPTR));
        btn_selection->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\346\216\222\345\272\217", Q_NULLPTR));
        btn_heap->setText(QApplication::translate("MainWindow", "\345\240\206\346\216\222\345\272\217", Q_NULLPTR));
        btn_insertion->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245\346\216\222\345\272\217", Q_NULLPTR));
        btn_merge->setText(QApplication::translate("MainWindow", "\345\275\222\345\271\266\346\216\222\345\272\217", Q_NULLPTR));
        btn_quick->setText(QApplication::translate("MainWindow", "\345\277\253\351\200\237\346\216\222\345\272\217", Q_NULLPTR));
        btn_bubble->setText(QApplication::translate("MainWindow", "\345\206\222\346\263\241\346\216\222\345\272\217", Q_NULLPTR));
        btn_count->setText(QApplication::translate("MainWindow", "\350\256\241\346\225\260\346\216\222\345\272\217", Q_NULLPTR));
        btn_bucket->setText(QApplication::translate("MainWindow", "\346\241\266\346\216\222\345\272\217", Q_NULLPTR));
        btn_radix->setText(QApplication::translate("MainWindow", "\345\237\272\346\225\260\346\216\222\345\272\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
