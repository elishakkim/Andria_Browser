#include "Browser.h"

Browser::Browser(QLineEdit *urlBar, QPushButton *goButton,
                 QPushButton *backButton, QPushButton *forwardButton,
                 QPushButton *refreshButton, QWebEngineView *webView)
    : urlBar(urlBar), goButton(goButton), backButton(backButton),
    forwardButton(forwardButton), refreshButton(refreshButton), webView(webView)
{
    connectSignals();
}

void Browser::connectSignals()
{
    QObject::connect(goButton, &QPushButton::clicked, [this]() {
        QString url = urlBar->text();

        if(!url.startsWith("http://") && !url.startsWith("https://")) {
            url = "http://" + url;
        }

        webView->setUrl(QUrl(url));
    });

    QObject::connect(backButton, &QPushButton::clicked, [this]() {
        QWebEngineHistory* history = webView->history();

        if(history->canGoBack()) {
            history->back();
        }
    });

    QObject::connect(forwardButton, &QPushButton::clicked, [this]() {
        QWebEngineHistory* history = webView->history();
        if(history->canGoForward()) {
            history->forward();
        }
    });

    QObject::connect(refreshButton, &QPushButton::clicked, [this]() {
        webView->reload();
    });

    QObject::connect(webView, &QWebEngineView::urlChanged, [this](const QUrl &url) {
        urlBar->setText(url.toString());
    });
}
