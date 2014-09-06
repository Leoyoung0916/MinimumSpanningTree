/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "getpoint.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Load;
    QAction *action_bigger;
    QAction *action_smaller;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLCDNumber *pointNumber;
    QSpacerItem *verticalSpacer_2;
    QPushButton *biggerbutton;
    QPushButton *smallerbutton;
    QSpacerItem *verticalSpacer;
    QPushButton *cleanallbutton;
    Getpoint *getpoint;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Graph;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 490);
        MainWindow->setMinimumSize(QSize(600, 490));
        action_Load = new QAction(MainWindow);
        action_Load->setObjectName(QStringLiteral("action_Load"));
        action_bigger = new QAction(MainWindow);
        action_bigger->setObjectName(QStringLiteral("action_bigger"));
        action_smaller = new QAction(MainWindow);
        action_smaller->setObjectName(QStringLiteral("action_smaller"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(420, 20, 164, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        label->setFont(font);

        verticalLayout->addWidget(label);

        pointNumber = new QLCDNumber(verticalLayoutWidget);
        pointNumber->setObjectName(QStringLiteral("pointNumber"));

        verticalLayout->addWidget(pointNumber);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        biggerbutton = new QPushButton(verticalLayoutWidget);
        biggerbutton->setObjectName(QStringLiteral("biggerbutton"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        biggerbutton->setFont(font1);

        verticalLayout->addWidget(biggerbutton);

        smallerbutton = new QPushButton(verticalLayoutWidget);
        smallerbutton->setObjectName(QStringLiteral("smallerbutton"));
        smallerbutton->setFont(font1);

        verticalLayout->addWidget(smallerbutton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        cleanallbutton = new QPushButton(verticalLayoutWidget);
        cleanallbutton->setObjectName(QStringLiteral("cleanallbutton"));
        cleanallbutton->setFont(font1);

        verticalLayout->addWidget(cleanallbutton);

        getpoint = new Getpoint(centralWidget);
        getpoint->setObjectName(QStringLiteral("getpoint"));
        getpoint->setGeometry(QRect(10, 20, 400, 400));
        getpoint->setMinimumSize(QSize(0, 0));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Graph = new QMenu(menuBar);
        menu_Graph->setObjectName(QStringLiteral("menu_Graph"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Graph->menuAction());
        menu_File->addAction(action_Load);
        menu_Graph->addAction(action_bigger);
        menu_Graph->addAction(action_smaller);

        retranslateUi(MainWindow);
        QObject::connect(biggerbutton, SIGNAL(clicked()), action_bigger, SLOT(trigger()));
        QObject::connect(smallerbutton, SIGNAL(clicked()), action_smaller, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "tree.exe", 0));
        action_Load->setText(QApplication::translate("MainWindow", "&LoadFile", 0));
#ifndef QT_NO_TOOLTIP
        action_Load->setToolTip(QApplication::translate("MainWindow", "LoadFile", 0));
#endif // QT_NO_TOOLTIP
        action_bigger->setText(QApplication::translate("MainWindow", "&bigger", 0));
        action_bigger->setShortcut(QApplication::translate("MainWindow", "Ctrl+=", 0));
        action_smaller->setText(QApplication::translate("MainWindow", "&smaller", 0));
        action_smaller->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0));
        label->setText(QApplication::translate("MainWindow", "Number of Points", 0));
        biggerbutton->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        smallerbutton->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        cleanallbutton->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Graph->setTitle(QApplication::translate("MainWindow", "&Graph", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
