//
// Created by ThackerayEnoch on 24-12-15.
//

#ifndef OPERATINGSYSTEMWORKQTVERSION_MAINWINDOW_H
#define OPERATINGSYSTEMWORKQTVERSION_MAINWINDOW_H

#include <QWidget>
#include <QGraphicsScene>
#include "manageToQt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

    void visualizeMemory(QGraphicsScene *scene, const std::list<MemoryBlock> &blocks);

    void updateMemoryView();
    void updateTable();
    void updateStatistics();
    void resetComponent();
    void resetMemoryView();
    bool checkInput(const QString &input);

private:
    Ui::MainWindow *ui;
    ManageToQt *manage;
};


#endif //OPERATINGSYSTEMWORKQTVERSION_MAINWINDOW_H
