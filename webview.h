#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWebView>
#include <QAction>
#include <QMenu>
#include <QUrl>
#include <QContextMenuEvent>
#include <QWebFrame>
#include <QWebElement>
#include <QWebHitTestResult>
#include "tab.h"
class webview : public QWebView
{
    Q_OBJECT
public:
    explicit webview(tab * parent);
signals:
    void linkinnewtab(QString url);
public slots:
    void contextMenuEvent(QContextMenuEvent * event);
private slots:
    void linknewtab();
private:
    QAction * openlinkinnewtab;
};

#endif // WEBVIEW_H
