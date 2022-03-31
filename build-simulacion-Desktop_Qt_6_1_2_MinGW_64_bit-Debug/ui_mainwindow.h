/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLineEdit *posix;
    QLineEdit *posiy;
    QLineEdit *vix;
    QLineEdit *viy;
    QLineEdit *masa;
    QLineEdit *radio;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *agregar;
    QPushButton *simular;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(40, 20, 871, 721));
        posix = new QLineEdit(centralwidget);
        posix->setObjectName(QString::fromUtf8("posix"));
        posix->setGeometry(QRect(960, 80, 81, 31));
        posiy = new QLineEdit(centralwidget);
        posiy->setObjectName(QString::fromUtf8("posiy"));
        posiy->setGeometry(QRect(1090, 80, 81, 31));
        vix = new QLineEdit(centralwidget);
        vix->setObjectName(QString::fromUtf8("vix"));
        vix->setGeometry(QRect(960, 180, 81, 31));
        viy = new QLineEdit(centralwidget);
        viy->setObjectName(QString::fromUtf8("viy"));
        viy->setGeometry(QRect(1090, 180, 81, 31));
        masa = new QLineEdit(centralwidget);
        masa->setObjectName(QString::fromUtf8("masa"));
        masa->setGeometry(QRect(960, 270, 81, 31));
        radio = new QLineEdit(centralwidget);
        radio->setObjectName(QString::fromUtf8("radio"));
        radio->setGeometry(QRect(1090, 270, 81, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(960, 50, 81, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1090, 50, 81, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(960, 140, 81, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1090, 140, 81, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(960, 240, 81, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1090, 240, 81, 21));
        agregar = new QPushButton(centralwidget);
        agregar->setObjectName(QString::fromUtf8("agregar"));
        agregar->setGeometry(QRect(1010, 380, 111, 41));
        simular = new QPushButton(centralwidget);
        simular->setObjectName(QString::fromUtf8("simular"));
        simular->setGeometry(QRect(1010, 450, 111, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "POSICION EN X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "POSICION EN Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "VELOCIDAD EN X", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "VELOCIDAD EN Y", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "MASA", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "RADIO", nullptr));
        agregar->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        simular->setText(QCoreApplication::translate("MainWindow", "simular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
