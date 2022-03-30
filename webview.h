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
class webview : public QWebViewsdsd
{
    Q_OBJECT
public:
    explicit webview(QWidget *parent = 0);
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
