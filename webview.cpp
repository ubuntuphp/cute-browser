#include "webview.h"
#include <QMessageBox>
webview::webview(QWidget *parent) :
    QWebView(parent)
{
    openlinkinnewtab = new QAction("open link in new tab" , this);
    connect(openlinkinnewtab , SIGNAL(triggered()) , this , SLOT(linknewtab()));
}
void webview::contextMenuEvent(QContextMenuEvent * event)
{
    QMenu * menu = new QMenu();
    menu->setVisible(true);
    QWebElement element = this->page()->mainFrame()->hitTestContent(event->pos()).element();
    QString tagname = this->page()->mainFrame()->hitTestContent(event->pos()).element().tagName().toLower();
    if(tagname == "img")
    {
        menu->addAction(this->pageAction(QWebPage::DownloadImageToDisk));
        menu->addAction(this->pageAction(QWebPage::CopyImageToClipboard));
        menu->addAction(this->pageAction(QWebPage::CopyImageUrlToClipboard));
    }
    if(tagname == "")
    {
        menu->addAction(this->pageAction(QWebPage::DownloadLinkToDisk));
        menu->addAction(this->pageAction(QWebPage::CopyLinkToClipboard));
        menu->addAction(this->pageAction(QWebPage::OpenLinkInNewWindow));
    }
    if(tagname == "input" || tagname == "textarea")
    {
        menu->addAction(this->pageAction(QWebPage::Copy));
        menu->addAction(this->pageAction(QWebPage::Cut));
        menu->addAction(this->pageAction(QWebPage::Paste));
        menu->addAction(this->pageAction(QWebPage::Undo));
        menu->addAction(this->pageAction(QWebPage::Redo));
        menu->addAction(this->pageAction(QWebPage::SelectAll));
    }
    menu->exec(event->globalPos());
}
void webview::linknewtab()
{
    emit linkinnewtab(openlinkinnewtab->data().toString());
}
