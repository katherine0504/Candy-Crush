/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *scoreTitle;
    QLabel *scoreText;
    QPushButton *reset;
    QLabel *steps;
    QLabel *stepsText;
    QLabel *rule;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1500, 1000);
        MainWindow->setMinimumSize(QSize(1500, 1000));
        MainWindow->setMaximumSize(QSize(1500, 1000));
        MainWindow->setBaseSize(QSize(1500, 1000));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1300, 800, 150, 150));
        pushButton->setMinimumSize(QSize(150, 150));
        pushButton->setMaximumSize(QSize(150, 150));
        pushButton->setBaseSize(QSize(150, 150));
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/pic/PIC/end.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(250, 250));
        scoreTitle = new QLabel(centralWidget);
        scoreTitle->setObjectName(QStringLiteral("scoreTitle"));
        scoreTitle->setGeometry(QRect(1063, 40, 375, 100));
        scoreTitle->setMinimumSize(QSize(375, 100));
        scoreTitle->setMaximumSize(QSize(375, 100));
        scoreTitle->setBaseSize(QSize(375, 100));
        scoreTitle->setPixmap(QPixmap(QString::fromUtf8(":/pic/PIC/score.jpg")));
        scoreText = new QLabel(centralWidget);
        scoreText->setObjectName(QStringLiteral("scoreText"));
        scoreText->setGeometry(QRect(1063, 160, 375, 100));
        scoreText->setMinimumSize(QSize(375, 100));
        scoreText->setMaximumSize(QSize(375, 100));
        scoreText->setBaseSize(QSize(375, 100));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(36);
        scoreText->setFont(font);
        reset = new QPushButton(centralWidget);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(1150, 800, 150, 150));
        reset->setMinimumSize(QSize(150, 150));
        reset->setMaximumSize(QSize(150, 150));
        reset->setBaseSize(QSize(150, 150));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/pic/PIC/reset.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        reset->setIcon(icon1);
        reset->setIconSize(QSize(150, 150));
        steps = new QLabel(centralWidget);
        steps->setObjectName(QStringLiteral("steps"));
        steps->setGeometry(QRect(1063, 280, 375, 100));
        steps->setMinimumSize(QSize(375, 100));
        steps->setMaximumSize(QSize(375, 100));
        steps->setBaseSize(QSize(375, 100));
        steps->setPixmap(QPixmap(QString::fromUtf8(":/pic/PIC/steps.jpg")));
        stepsText = new QLabel(centralWidget);
        stepsText->setObjectName(QStringLiteral("stepsText"));
        stepsText->setGeometry(QRect(1063, 400, 375, 100));
        stepsText->setMinimumSize(QSize(375, 100));
        stepsText->setMaximumSize(QSize(375, 100));
        stepsText->setBaseSize(QSize(375, 100));
        stepsText->setFont(font);
        rule = new QLabel(centralWidget);
        rule->setObjectName(QStringLiteral("rule"));
        rule->setGeometry(QRect(1063, 520, 375, 254));
        rule->setMinimumSize(QSize(375, 254));
        rule->setMaximumSize(QSize(375, 254));
        rule->setBaseSize(QSize(375, 254));
        rule->setPixmap(QPixmap(QString::fromUtf8(":/pic/PIC/rule.jpg")));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 1000, 1000));
        label->setMinimumSize(QSize(1000, 1000));
        label->setMaximumSize(QSize(1000, 1000));
        label->setBaseSize(QSize(1000, 1000));
        label->setPixmap(QPixmap(QString::fromUtf8(":/pic/PIC/WIN.png")));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1500, 25));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QString());
        scoreTitle->setText(QString());
        scoreText->setText(QString());
        reset->setText(QString());
        steps->setText(QString());
        stepsText->setText(QString());
        rule->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
