/********************************************************************************
** Form generated from reading UI file 'ATM_Graphics.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATM_GRAPHICS_H
#define UI_ATM_GRAPHICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATM_Graphics
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QFrame *line_2;
    QFrame *line_4;
    QFrame *line;
    QFrame *line_3;
    QLabel *label;
    QPushButton *pushButton_help1;
    QPushButton *pushButton_help2;
    QPushButton *pushButton_help3;
    QPushButton *pushButton_help6;
    QPushButton *pushButton_help5;
    QPushButton *pushButton_help4;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_Enter;
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_num9;
    QPushButton *pushButton_num6;
    QPushButton *pushButton_num4;
    QPushButton *pushButton_num8;
    QPushButton *pushButton_num2;
    QPushButton *pushButton_num5;
    QPushButton *pushButton_num7;
    QPushButton *pushButton_num1;
    QPushButton *pushButton_ok;
    QPushButton *pushButton_num3;
    QPushButton *pushButton_X;
    QPushButton *pushButton_num0;
    QFrame *line_5;
    QFrame *line_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ATM_Graphics)
    {
        if (ATM_Graphics->objectName().isEmpty())
            ATM_Graphics->setObjectName(QStringLiteral("ATM_Graphics"));
        ATM_Graphics->resize(738, 447);
        centralWidget = new QWidget(ATM_Graphics);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(120, 50, 331, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 1, 0, 1, 1);

        line_4 = new QFrame(gridLayoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 0, 1, 1, 1);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 3, 1, 1, 1);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label, 1, 1, 1, 1);

        pushButton_help1 = new QPushButton(centralWidget);
        pushButton_help1->setObjectName(QStringLiteral("pushButton_help1"));
        pushButton_help1->setGeometry(QRect(70, 70, 41, 23));
        pushButton_help2 = new QPushButton(centralWidget);
        pushButton_help2->setObjectName(QStringLiteral("pushButton_help2"));
        pushButton_help2->setGeometry(QRect(70, 120, 41, 23));
        pushButton_help3 = new QPushButton(centralWidget);
        pushButton_help3->setObjectName(QStringLiteral("pushButton_help3"));
        pushButton_help3->setGeometry(QRect(70, 170, 41, 23));
        pushButton_help6 = new QPushButton(centralWidget);
        pushButton_help6->setObjectName(QStringLiteral("pushButton_help6"));
        pushButton_help6->setGeometry(QRect(460, 170, 41, 23));
        pushButton_help5 = new QPushButton(centralWidget);
        pushButton_help5->setObjectName(QStringLiteral("pushButton_help5"));
        pushButton_help5->setGeometry(QRect(460, 120, 41, 23));
        pushButton_help4 = new QPushButton(centralWidget);
        pushButton_help4->setObjectName(QStringLiteral("pushButton_help4"));
        pushButton_help4->setGeometry(QRect(460, 70, 41, 23));
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(550, 10, 171, 251));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(gridLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setMaxLength(4);
        lineEdit->setEchoMode(QLineEdit::Normal);

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);

        pushButton_Enter = new QPushButton(gridLayoutWidget_2);
        pushButton_Enter->setObjectName(QStringLiteral("pushButton_Enter"));

        gridLayout_2->addWidget(pushButton_Enter, 1, 0, 1, 1);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(140, 250, 340, 121));
        gridLayout_3 = new QGridLayout(formLayoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_num9 = new QPushButton(formLayoutWidget);
        pushButton_num9->setObjectName(QStringLiteral("pushButton_num9"));

        gridLayout_3->addWidget(pushButton_num9, 2, 2, 1, 1);

        pushButton_num6 = new QPushButton(formLayoutWidget);
        pushButton_num6->setObjectName(QStringLiteral("pushButton_num6"));

        gridLayout_3->addWidget(pushButton_num6, 1, 2, 1, 1);

        pushButton_num4 = new QPushButton(formLayoutWidget);
        pushButton_num4->setObjectName(QStringLiteral("pushButton_num4"));

        gridLayout_3->addWidget(pushButton_num4, 1, 0, 1, 1);

        pushButton_num8 = new QPushButton(formLayoutWidget);
        pushButton_num8->setObjectName(QStringLiteral("pushButton_num8"));

        gridLayout_3->addWidget(pushButton_num8, 2, 1, 1, 1);

        pushButton_num2 = new QPushButton(formLayoutWidget);
        pushButton_num2->setObjectName(QStringLiteral("pushButton_num2"));

        gridLayout_3->addWidget(pushButton_num2, 0, 1, 1, 1);

        pushButton_num5 = new QPushButton(formLayoutWidget);
        pushButton_num5->setObjectName(QStringLiteral("pushButton_num5"));

        gridLayout_3->addWidget(pushButton_num5, 1, 1, 1, 1);

        pushButton_num7 = new QPushButton(formLayoutWidget);
        pushButton_num7->setObjectName(QStringLiteral("pushButton_num7"));

        gridLayout_3->addWidget(pushButton_num7, 2, 0, 1, 1);

        pushButton_num1 = new QPushButton(formLayoutWidget);
        pushButton_num1->setObjectName(QStringLiteral("pushButton_num1"));

        gridLayout_3->addWidget(pushButton_num1, 0, 0, 1, 1);

        pushButton_ok = new QPushButton(formLayoutWidget);
        pushButton_ok->setObjectName(QStringLiteral("pushButton_ok"));

        gridLayout_3->addWidget(pushButton_ok, 0, 3, 1, 1);

        pushButton_num3 = new QPushButton(formLayoutWidget);
        pushButton_num3->setObjectName(QStringLiteral("pushButton_num3"));

        gridLayout_3->addWidget(pushButton_num3, 0, 2, 1, 1);

        pushButton_X = new QPushButton(formLayoutWidget);
        pushButton_X->setObjectName(QStringLiteral("pushButton_X"));

        gridLayout_3->addWidget(pushButton_X, 2, 3, 1, 1);

        pushButton_num0 = new QPushButton(formLayoutWidget);
        pushButton_num0->setObjectName(QStringLiteral("pushButton_num0"));

        gridLayout_3->addWidget(pushButton_num0, 1, 3, 1, 1);

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(520, 20, 20, 391));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(0, 10, 741, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        ATM_Graphics->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ATM_Graphics);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ATM_Graphics->setStatusBar(statusBar);

        retranslateUi(ATM_Graphics);

        QMetaObject::connectSlotsByName(ATM_Graphics);
    } // setupUi

    void retranslateUi(QMainWindow *ATM_Graphics)
    {
        ATM_Graphics->setWindowTitle(QApplication::translate("ATM_Graphics", "Interface", 0));
        label->setText(QApplication::translate("ATM_Graphics", "\n"
"Check balance\n"
"\n"
"\n"
"\n"
"Withdraw\n"
"\n"
"\n"
"\n"
" Transfer                                                                      End session", 0));
        pushButton_help1->setText(QApplication::translate("ATM_Graphics", "1", 0));
        pushButton_help1->setShortcut(QApplication::translate("ATM_Graphics", "F1", 0));
        pushButton_help2->setText(QApplication::translate("ATM_Graphics", "2", 0));
        pushButton_help2->setShortcut(QApplication::translate("ATM_Graphics", "F2", 0));
        pushButton_help3->setText(QApplication::translate("ATM_Graphics", "3", 0));
        pushButton_help3->setShortcut(QApplication::translate("ATM_Graphics", "F3", 0));
        pushButton_help6->setText(QApplication::translate("ATM_Graphics", "6", 0));
        pushButton_help6->setShortcut(QApplication::translate("ATM_Graphics", "F6", 0));
        pushButton_help5->setText(QApplication::translate("ATM_Graphics", "5", 0));
        pushButton_help5->setShortcut(QApplication::translate("ATM_Graphics", "F5", 0));
        pushButton_help4->setText(QApplication::translate("ATM_Graphics", "4", 0));
        pushButton_help4->setShortcut(QApplication::translate("ATM_Graphics", "F4", 0));
        lineEdit->setPlaceholderText(QApplication::translate("ATM_Graphics", "\320\235\320\276\320\274\320\265\321\200 \320\272\320\260\321\200\321\202\320\272\320\270", 0));
        pushButton_Enter->setText(QApplication::translate("ATM_Graphics", "Enter", 0));
        pushButton_Enter->setShortcut(QApplication::translate("ATM_Graphics", "Return", 0));
        pushButton_num9->setText(QApplication::translate("ATM_Graphics", "9", 0));
        pushButton_num9->setShortcut(QApplication::translate("ATM_Graphics", "9", 0));
        pushButton_num6->setText(QApplication::translate("ATM_Graphics", "6", 0));
        pushButton_num6->setShortcut(QApplication::translate("ATM_Graphics", "6", 0));
        pushButton_num4->setText(QApplication::translate("ATM_Graphics", "4", 0));
        pushButton_num4->setShortcut(QApplication::translate("ATM_Graphics", "4", 0));
        pushButton_num8->setText(QApplication::translate("ATM_Graphics", "8", 0));
        pushButton_num8->setShortcut(QApplication::translate("ATM_Graphics", "8", 0));
        pushButton_num2->setText(QApplication::translate("ATM_Graphics", "2", 0));
        pushButton_num2->setShortcut(QApplication::translate("ATM_Graphics", "2", 0));
        pushButton_num5->setText(QApplication::translate("ATM_Graphics", "5", 0));
        pushButton_num5->setShortcut(QApplication::translate("ATM_Graphics", "5", 0));
        pushButton_num7->setText(QApplication::translate("ATM_Graphics", "7", 0));
        pushButton_num7->setShortcut(QApplication::translate("ATM_Graphics", "7", 0));
        pushButton_num1->setText(QApplication::translate("ATM_Graphics", "1", 0));
        pushButton_num1->setShortcut(QApplication::translate("ATM_Graphics", "1", 0));
        pushButton_ok->setText(QApplication::translate("ATM_Graphics", "OK", 0));
        pushButton_ok->setShortcut(QApplication::translate("ATM_Graphics", "Shift+Return", 0));
        pushButton_num3->setText(QApplication::translate("ATM_Graphics", "3", 0));
        pushButton_num3->setShortcut(QApplication::translate("ATM_Graphics", "3", 0));
        pushButton_X->setText(QApplication::translate("ATM_Graphics", "X", 0));
        pushButton_X->setShortcut(QApplication::translate("ATM_Graphics", "Backspace", 0));
        pushButton_num0->setText(QApplication::translate("ATM_Graphics", "0", 0));
        pushButton_num0->setShortcut(QApplication::translate("ATM_Graphics", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class ATM_Graphics: public Ui_ATM_Graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATM_GRAPHICS_H
