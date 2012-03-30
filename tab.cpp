#include "tab.h"
tab::tab(MainWindow *parent) :
    QWidget(parent)
{
    QVBoxLayout * layout = new QVBoxLayout(this);
    locationbar = new QLineEdit();
    searchbar = new QLineEdit();
    searchbar->setFixedWidth(300);
    toparea = new QWidget();
    QHBoxLayout * toplayout = new QHBoxLayout(toparea);
    toplayout->addWidget(locationbar);
    toplayout->addWidget(searchbar);
    layout->addWidget(toparea);
    view = new webview(this);
    layout->addWidget(view);
    QObject::connect(locationbar , SIGNAL(returnPressed()) , this , SLOT(loadadress()));
    QObject::connect(searchbar , SIGNAL(returnPressed()) , this , SLOT(search()));
    QObject::connect(view ,SIGNAL(urlChanged(QUrl)) , this , SLOT(updatelocation(QUrl)));
    QObject::connect(view , SIGNAL(linkinnewtab(QString)) , parent , SLOT(newtab(QString)));
}
void tab::loadadress(QString url)
{
    view->load(QUrl(url));
}
void tab::search(QString url)
{
    view->load(QUrl(("https://www.google.com/search?q=") + url));
}
void tab::loadadress()
{
QString url = locationbar->text();
    if(url.isEmpty()) return;
    loadadress(url);
}
void tab::search()
{
QString query = searchbar->text();
    if(query.isEmpty()) return;
    search(query);
}
QWidget * tab::returnwidget()
{
    return this;
}
void tab::updatelocation(QUrl url)
{
    locationbar->setText(url.toString());
}
void tab::webinspector()
{
    QWebInspector * webi = new QWebInspector(this);
    this->show();
}
