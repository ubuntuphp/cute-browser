#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tab.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tabs = new QTabWidget();
    newtab("http://www.google.com/");
    setCentralWidget(tabs);
    showMaximized();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newtab(QString url)
{
    tab * tabv = new tab(this);
    tabv->loadadress(url);
    tabs->addTab(tabv , url);
}

void MainWindow::on_actionNew_tab_triggered()
{
    newtab();
}
void MainWindow::newtab()
{
    QWidget * win = new QWidget();
    tabs->addTab(win , "new tab");
}
void MainWindow::webinspector()
{

}
