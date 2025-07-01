// 📁 File: src/MainWindow.cpp
#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // You can connect buttons here like:
    // connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddBookClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
