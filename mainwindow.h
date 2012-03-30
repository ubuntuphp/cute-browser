#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void newtab(QString url);
    void newtab();
    void webinspector();
private slots:
    void on_actionNew_tab_triggered();

private:
    Ui::MainWindow *ui;
    QTabWidget * tabs;
};

#endif // MAINWINDOW_H
