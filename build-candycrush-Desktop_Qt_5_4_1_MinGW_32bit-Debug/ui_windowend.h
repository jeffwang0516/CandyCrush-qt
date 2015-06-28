/********************************************************************************
** Form generated from reading UI file 'windowend.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWEND_H
#define UI_WINDOWEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_windowEnd
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *windowEnd)
    {
        if (windowEnd->objectName().isEmpty())
            windowEnd->setObjectName(QStringLiteral("windowEnd"));
        windowEnd->resize(800, 800);
        windowEnd->setMinimumSize(QSize(800, 800));
        windowEnd->setMaximumSize(QSize(800, 800));
        label = new QLabel(windowEnd);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 110, 501, 101));
        label->setStyleSheet(QLatin1String("font: 75 40pt \"Snap ITC\";\n"
"color: rgb(255, 0, 4);"));
        label_2 = new QLabel(windowEnd);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 300, 541, 101));
        label_2->setStyleSheet(QLatin1String("font: 50pt \"Ravie\";\n"
"color: rgb(33, 140, 255);"));
        label_3 = new QLabel(windowEnd);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 480, 441, 111));
        label_3->setStyleSheet(QLatin1String("font: 50pt \"MV Boli\";\n"
"color: rgb(85, 255, 0);"));

        retranslateUi(windowEnd);

        QMetaObject::connectSlotsByName(windowEnd);
    } // setupUi

    void retranslateUi(QDialog *windowEnd)
    {
        windowEnd->setWindowTitle(QApplication::translate("windowEnd", "Dialog", 0));
        label->setText(QApplication::translate("windowEnd", "END OF GAME", 0));
        label_2->setText(QApplication::translate("windowEnd", "TextLabel", 0));
        label_3->setText(QApplication::translate("windowEnd", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class windowEnd: public Ui_windowEnd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWEND_H
