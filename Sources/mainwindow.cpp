#include "../Headers/mainwindow.h"
#include "ui_mainwindow.h"
#include "../MemoryManager/MemoryException.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // 控件状态初始化
    ui->resetButton->setDisabled(true);
    // 设置Label文字
    resetComponent();
    // 创建 QGraphicsScene
    auto *scene = new QGraphicsScene(this);
    ui->memoryView->setScene(scene);
    // 重置内存视图 显示未分配
    resetMemoryView();
    // 创建manageToQt中间类
    manage = new ManageToQt();

    // 信号与槽 button事件
    // 内存管理器初始化
    connect(ui->confirmButton, &QPushButton::clicked, [=]() {
        if (!checkInput(ui->maxMemoryEdit->text())) {
            return;
        }
        // 获取输入的最大内存和最小内存
        int maxMemory = ui->maxMemoryEdit->text().toInt();
        int minMemory = 1;
        // 非法输入检查
        if (maxMemory == 0) {
            ui->logBrowser->append("最大内存不能为0!");
            return;
        }
        // 禁用按钮
        ui->confirmButton->setDisabled(true);
        ui->resetButton->setDisabled(false);
        ui->maxMemoryEdit->setDisabled(true);
//        ui->minMemoryEdit->setDisabled(true);
        // 初始化内存管理器
        manage->initializeManager(maxMemory, minMemory);
        // 更新视图
        updateTable();
        updateMemoryView();
        updateStatistics();
        // 日志处理
        ui->logBrowser->clear();
        ui->logBrowser->append("初始化成功!");
    });
    // 内存管理器重置
    connect(ui->resetButton, &QPushButton::clicked, [=]() {
        // 重置内存管理器
        resetMemoryView();
        resetComponent();
        manage->resetManager();
        // 清空日志
        ui->logBrowser->clear();
        // 重置按钮状态
        ui->confirmButton->setDisabled(false);
        ui->resetButton->setDisabled(true);
        ui->maxMemoryEdit->setDisabled(false);
//        ui->minMemoryEdit->setDisabled(false);
    });
    // 分配算法选择
    connect(ui->allocAlgorithmBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        if (manage->isManagerNull()) {
            ui->logBrowser->append("请先初始化内存!");
            return;
        }
        if (index != 1) {
            manage->resetNextFitConfig();
        }
        // 设置分配算法
        manage->setStrategy(index);
    });
    // 分配内存
    connect(ui->allocButton, &QPushButton::clicked, [=]() {
        if (manage->isManagerNull()) {
            ui->logBrowser->append("请先初始化内存!");
            return;
        }
        if (!checkInput(ui->processIdEdit->text()) | !checkInput(ui->requestMemoryEdit->text())) {
            return;
        }
        // 获取输入的进程ID和请求大小
        int processID = ui->processIdEdit->text().toInt();
        int requestSize = ui->requestMemoryEdit->text().toInt();
        // 分配内存
        try {
            ui->logBrowser->append(QString::fromStdString(manage->allocate(processID, requestSize)));
            updateMemoryView();
            updateTable();
            updateStatistics();
        } catch (MemoryException &e) {
            ui->logBrowser->append(QString::fromStdString(e.what()));
        }
    });
    // 回收内存
    connect(ui->deallocButton, &QPushButton::clicked, [=]() {
        if (manage->isManagerNull()) {
            ui->logBrowser->append("请先初始化内存!");
            return;
        }
        if (!checkInput(ui->processIdEdit->text())) {
            return;
        }
        int processID = ui->processIdEdit->text().toInt();
        // 回收内存
        try {
            ui->logBrowser->append(QString::fromStdString(manage->deallocate(processID)));
            updateMemoryView();
            updateTable();
            updateStatistics();
        } catch (MemoryException &e) {
            ui->logBrowser->append(QString::fromStdString(e.what()));
        }
    });

}

MainWindow::~MainWindow() {
    delete ui;
    delete manage;
}

void MainWindow::visualizeMemory(QGraphicsScene *scene, const std::list<MemoryBlock> &blocks) {
    scene->clear();
    int xOffset = 0;       // x 方向偏移
    const int sceneWidth = 660; // QGraphicsView的最大宽度
    const int sceneHeight = 75; // 场景高度

    // 计算内存总大小
    int totalSize = manage->getMaxMemory();

    // 遍历每个内存块进行可视化
    for (const auto &block: blocks) {
        // 计算当前内存块的宽度
        int blockWidth = static_cast<int>((block.size / static_cast<double>(totalSize)) * sceneWidth);

        // 设置颜色，空闲块为绿色，占用块为红色
        QColor color = block.isFree ? Qt::green : Qt::red;

        // 创建矩形表示内存块
        scene->addRect(xOffset, 0, blockWidth, sceneHeight, QPen(Qt::black), QBrush(color));

        // 在矩形内添加显示文字
        QString blockText = block.isFree ? block.size >= manage->getMinMemory() ? "空闲" : "碎片" : QString("P%1").arg(
                block.processID);
        QGraphicsTextItem *text = scene->addText(blockText);
        text->setDefaultTextColor(Qt::white);
        text->setPos(xOffset + blockWidth / 2 - text->boundingRect().width() / 2,
                     sceneHeight / 2 - text->boundingRect().height() / 2);

        // 更新偏移量，准备绘制下一个块
        xOffset += blockWidth;
    }
}

void MainWindow::updateMemoryView() {
    visualizeMemory(ui->memoryView->scene(), manage->getBlocks());
}

void MainWindow::resetMemoryView() {
    // 清空场景
    QGraphicsScene *scene = ui->memoryView->scene();
    scene->clear();

    // 添加提示文本
    QString message = "请设置内存";
    QGraphicsTextItem *textItem = scene->addText(message, QFont("Arial", 16));
    textItem->setDefaultTextColor(Qt::black);

    // 将文本居中显示
    QRectF sceneRect = scene->sceneRect(); // 获取当前场景的范围
    textItem->setPos(sceneRect.width() / 2 - textItem->boundingRect().width() / 2,
                     sceneRect.height() / 2 - textItem->boundingRect().height() / 2);
}

void MainWindow::updateTable() {

    QTableWidget *tableWidget = ui->blocksTabel;

    const std::list<MemoryBlock> &memoryBlocks = manage->getBlocks();
    // 清空表格内容
    tableWidget->clear();

    // 设置表头
    QStringList headers;
    headers << "进程 ID" << "地址" << "大小 (MB)" << "可用";
    tableWidget->setColumnCount(headers.size());
    tableWidget->setHorizontalHeaderLabels(headers);

    // 设置行数
    tableWidget->setRowCount(static_cast<int>(memoryBlocks.size()));

    // 填充数据
    int row = 0;
    for (const auto &block: memoryBlocks) {
        // 进程ID
        QTableWidgetItem *processIDItem = new QTableWidgetItem(block.isFree ? "-" : QString::number(block.processID));
        processIDItem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(row, 0, processIDItem);

        // 起始地址
        QTableWidgetItem *addressItem = new QTableWidgetItem(QString::number(block.address));
        addressItem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(row, 1, addressItem);

        // 大小
        QTableWidgetItem *sizeItem = new QTableWidgetItem(QString::number(block.size));
        sizeItem->setTextAlignment(Qt::AlignCenter);
        tableWidget->setItem(row, 2, sizeItem);

        // 是否可用
        bool flag = block.isFree;
        QTableWidgetItem *statusItem = new QTableWidgetItem(flag ? "是" : "否");
        statusItem->setTextAlignment(Qt::AlignCenter);
        statusItem->setBackground(block.isFree ? Qt::green : Qt::red); // 设置背景颜色
        tableWidget->setItem(row, 3, statusItem);

        row++;
    }

    // 调整列宽
    tableWidget->resizeColumnsToContents();
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void MainWindow::updateStatistics() {
    if (manage->isManagerNull()) {
        return;
    }
    // 更新统计信息
    auto memoryBlocks = manage->getBlocks();
    int freeMemory = 0, fragmentMemory = 0;
    for (const auto &block: memoryBlocks) {
        if (block.isFree) {
            freeMemory += block.size;
        }
        if (block.size < manage->getMinMemory() && block.isFree) {
            fragmentMemory += block.size;
        }
    }
    ui->allocLabel->setText(QString("%1 MB").arg(manage->getMaxMemory() - freeMemory));
    ui->freeLabel->setText(QString("%1 MB").arg(freeMemory));
    double occupancyRate = (manage->getMaxMemory() - freeMemory) / static_cast<double>(manage->getMaxMemory()) * 100;
    ui->occupancyLabel->setText(QString("%1%").arg(QString::number(occupancyRate, 'f', 2)));
//    ui->fragmentLabel->setText(QString("%1 MB").arg(fragmentMemory));
//    double fragmentRate = fragmentMemory / static_cast<double>(manage->getMaxMemory()) * 100;
//    ui->fragmentRateLabel->setText(QString("%1%").arg(QString::number(fragmentRate, 'f', 2)));
}

void MainWindow::resetComponent() {
    ui->allocLabel->setText("0 MB");
    ui->freeLabel->setText("0 MB");
    ui->occupancyLabel->setText("0%");
//    ui->fragmentLabel->setText("0 MB");
//    ui->fragmentRateLabel->setText("0%");
    QTableWidget *tableWidget = ui->blocksTabel;
    tableWidget->clear();
}

bool MainWindow::checkInput(const QString &input) {
    // 判空
    if (input.isEmpty()) {
        ui->logBrowser->append("输入为空!");
        return false;
    }
    // 确保输入是纯数字
    for (const QChar &c: input) {
        if (!c.isDigit()) {
            ui->logBrowser->append("输入数字不合法!");
            return false;
        }
    }
    // 使用 toLong() 只做一次转换
    bool ok;
    input.toInt(&ok);
    // 检查转换是否成功
    if (!ok) {
        ui->logBrowser->append("输入数字过大!");
        return false;
    }
    return true;
}


