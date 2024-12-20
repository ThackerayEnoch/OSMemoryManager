/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QGraphicsView *memoryView;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_4;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_4;
    QLabel *label;
    QLabel *allocLabel;
    QLabel *label_3;
    QLabel *freeLabel;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_5;
    QLabel *label00;
    QLabel *occupancyLabel;
    QTableWidget *blocksTabel;
    QGroupBox *controlBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *Label;
    QLineEdit *maxMemoryEdit;
    QPushButton *resetButton;
    QPushButton *confirmButton;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *Label_3;
    QComboBox *allocAlgorithmBox;
    QFormLayout *formLayout_2;
    QLabel *Label_4;
    QLabel *iDLabel;
    QLineEdit *processIdEdit;
    QLineEdit *requestMemoryEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *allocButton;
    QPushButton *deallocButton;
    QGroupBox *groupBox_5;
    QTextBrowser *logBrowser;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(700, 534);
        memoryView = new QGraphicsView(MainWindow);
        memoryView->setObjectName("memoryView");
        memoryView->setGeometry(QRect(10, 20, 681, 101));
        groupBox_2 = new QGroupBox(MainWindow);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(340, 130, 341, 91));
        groupBox_2->setStyleSheet(QString::fromUtf8("background:white;"));
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(0, 0, 341, 91));
        groupBox_4->setStyleSheet(QString::fromUtf8("background:white;"));
        formLayoutWidget_2 = new QWidget(groupBox_4);
        formLayoutWidget_2->setObjectName("formLayoutWidget_2");
        formLayoutWidget_2->setGeometry(QRect(10, 20, 160, 65));
        formLayout_4 = new QFormLayout(formLayoutWidget_2);
        formLayout_4->setObjectName("formLayout_4");
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget_2);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label);

        allocLabel = new QLabel(formLayoutWidget_2);
        allocLabel->setObjectName("allocLabel");
        allocLabel->setFont(font);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, allocLabel);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_3);

        freeLabel = new QLabel(formLayoutWidget_2);
        freeLabel->setObjectName("freeLabel");
        freeLabel->setFont(font);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, freeLabel);

        formLayoutWidget_4 = new QWidget(groupBox_4);
        formLayoutWidget_4->setObjectName("formLayoutWidget_4");
        formLayoutWidget_4->setGeometry(QRect(180, 20, 159, 61));
        formLayout_5 = new QFormLayout(formLayoutWidget_4);
        formLayout_5->setObjectName("formLayout_5");
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        label00 = new QLabel(formLayoutWidget_4);
        label00->setObjectName("label00");
        label00->setFont(font);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label00);

        occupancyLabel = new QLabel(formLayoutWidget_4);
        occupancyLabel->setObjectName("occupancyLabel");
        occupancyLabel->setFont(font);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, occupancyLabel);

        blocksTabel = new QTableWidget(MainWindow);
        if (blocksTabel->columnCount() < 4)
            blocksTabel->setColumnCount(4);
        if (blocksTabel->rowCount() < 25)
            blocksTabel->setRowCount(25);
        blocksTabel->setObjectName("blocksTabel");
        blocksTabel->setGeometry(QRect(20, 130, 301, 391));
        blocksTabel->setStyleSheet(QString::fromUtf8("background:white;"));
        blocksTabel->setFrameShape(QFrame::Shape::Box);
        blocksTabel->setShowGrid(true);
        blocksTabel->setGridStyle(Qt::PenStyle::SolidLine);
        blocksTabel->setSortingEnabled(false);
        blocksTabel->setRowCount(25);
        blocksTabel->setColumnCount(4);
        blocksTabel->horizontalHeader()->setDefaultSectionSize(65);
        controlBox = new QGroupBox(MainWindow);
        controlBox->setObjectName("controlBox");
        controlBox->setEnabled(true);
        controlBox->setGeometry(QRect(340, 320, 341, 201));
        controlBox->setStyleSheet(QString::fromUtf8("background:white;"));
        formLayoutWidget = new QWidget(controlBox);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 20, 321, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        Label = new QLabel(formLayoutWidget);
        Label->setObjectName("Label");
        Label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, Label);

        maxMemoryEdit = new QLineEdit(formLayoutWidget);
        maxMemoryEdit->setObjectName("maxMemoryEdit");
        maxMemoryEdit->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, maxMemoryEdit);

        resetButton = new QPushButton(formLayoutWidget);
        resetButton->setObjectName("resetButton");
        resetButton->setFont(font);
        resetButton->setAutoExclusive(false);
        resetButton->setAutoDefault(false);
        resetButton->setFlat(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, resetButton);

        confirmButton = new QPushButton(formLayoutWidget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, confirmButton);

        formLayoutWidget_3 = new QWidget(controlBox);
        formLayoutWidget_3->setObjectName("formLayoutWidget_3");
        formLayoutWidget_3->setGeometry(QRect(10, 90, 321, 101));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setObjectName("formLayout_3");
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        Label_3 = new QLabel(formLayoutWidget_3);
        Label_3->setObjectName("Label_3");
        Label_3->setFont(font);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, Label_3);

        allocAlgorithmBox = new QComboBox(formLayoutWidget_3);
        allocAlgorithmBox->addItem(QString());
        allocAlgorithmBox->addItem(QString());
        allocAlgorithmBox->addItem(QString());
        allocAlgorithmBox->addItem(QString());
        allocAlgorithmBox->setObjectName("allocAlgorithmBox");
        allocAlgorithmBox->setFont(font);
        allocAlgorithmBox->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, allocAlgorithmBox);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        Label_4 = new QLabel(formLayoutWidget_3);
        Label_4->setObjectName("Label_4");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, Label_4);

        iDLabel = new QLabel(formLayoutWidget_3);
        iDLabel->setObjectName("iDLabel");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, iDLabel);

        processIdEdit = new QLineEdit(formLayoutWidget_3);
        processIdEdit->setObjectName("processIdEdit");
        processIdEdit->setEnabled(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, processIdEdit);

        requestMemoryEdit = new QLineEdit(formLayoutWidget_3);
        requestMemoryEdit->setObjectName("requestMemoryEdit");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, requestMemoryEdit);


        formLayout_3->setLayout(1, QFormLayout::LabelRole, formLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        allocButton = new QPushButton(formLayoutWidget_3);
        allocButton->setObjectName("allocButton");

        verticalLayout->addWidget(allocButton);

        deallocButton = new QPushButton(formLayoutWidget_3);
        deallocButton->setObjectName("deallocButton");

        verticalLayout->addWidget(deallocButton);


        formLayout_3->setLayout(1, QFormLayout::FieldRole, verticalLayout);

        groupBox_5 = new QGroupBox(MainWindow);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(340, 220, 341, 91));
        groupBox_5->setStyleSheet(QString::fromUtf8("background:white;"));
        logBrowser = new QTextBrowser(groupBox_5);
        logBrowser->setObjectName("logBrowser");
        logBrowser->setGeometry(QRect(10, 20, 321, 71));
        logBrowser->setOpenLinks(true);

        retranslateUi(MainWindow);

        resetButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\273\237\350\256\241", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\273\237\350\256\241", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\210\206\351\205\215\345\206\205\345\255\230: ", nullptr));
        allocLabel->setText(QCoreApplication::translate("MainWindow", "500MB", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\251\272\351\227\262\345\206\205\345\255\230: ", nullptr));
        freeLabel->setText(QCoreApplication::translate("MainWindow", "500MB", nullptr));
        label00->setText(QCoreApplication::translate("MainWindow", "\345\206\205\345\255\230\345\215\240\347\224\250\347\216\207: ", nullptr));
        occupancyLabel->setText(QCoreApplication::translate("MainWindow", "3%", nullptr));
        controlBox->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234", nullptr));
        Label->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\345\206\205\345\255\230", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "\351\207\215\347\275\256", nullptr));
        confirmButton->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244", nullptr));
        Label_3->setText(QCoreApplication::translate("MainWindow", "\345\210\206\351\205\215\347\256\227\346\263\225", nullptr));
        allocAlgorithmBox->setItemText(0, QCoreApplication::translate("MainWindow", "\351\246\226\346\254\241\351\200\202\347\224\250\347\256\227\346\263\225", nullptr));
        allocAlgorithmBox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\276\252\347\216\257\351\246\226\346\254\241\351\200\202\347\224\250\347\256\227\346\263\225", nullptr));
        allocAlgorithmBox->setItemText(2, QCoreApplication::translate("MainWindow", "\346\234\200\344\275\263\351\200\202\347\224\250\347\256\227\346\263\225", nullptr));
        allocAlgorithmBox->setItemText(3, QCoreApplication::translate("MainWindow", "\346\234\200\345\235\217\351\200\202\347\224\250\347\256\227\346\263\225", nullptr));

        allocAlgorithmBox->setCurrentText(QCoreApplication::translate("MainWindow", "\351\246\226\346\254\241\351\200\202\347\224\250\347\256\227\346\263\225", nullptr));
        Label_4->setText(QCoreApplication::translate("MainWindow", "\351\234\200\346\261\202\345\206\205\345\255\230", nullptr));
        iDLabel->setText(QCoreApplication::translate("MainWindow", "\350\277\233\347\250\213ID", nullptr));
        allocButton->setText(QCoreApplication::translate("MainWindow", "\345\210\206\351\205\215\345\206\205\345\255\230", nullptr));
        deallocButton->setText(QCoreApplication::translate("MainWindow", "\345\233\236\346\224\266\345\206\205\345\255\230", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\346\227\245\345\277\227", nullptr));
        logBrowser->setMarkdown(QString());
        logBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
