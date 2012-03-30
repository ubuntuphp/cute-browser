#ifndef TAB_H
#define TAB_H

#include <QWidget>
#include "webview.h"
#include <QLineEdit>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWebInspector>
class tab : public QWidget
{
    Q_OBJECT
public:
    explicit tab(QWidget *parent = 0);
    QWidget getwidget();
signals:
    
public slots:
    void loadadress(QString url);
    void search(QString url);
    void loadadress();
    void search();
    void updatelocation(QUrl url);
    void webinspector();
    QWidget * returnwidget();
private:
    QWidget * toparea;
    webview * view;
    QLineEdit * locationbar;
    QLineEdit * searchbar;
};
#endif // TAB_H
