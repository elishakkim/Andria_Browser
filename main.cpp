#include "mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QWebEngineView>
#include <QWebEngineHistory>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.setWindowTitle("Andria");

    QWidget *centralWidget = new QWidget(&mainWindow);
    QVBoxLayout *vLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *hLayout = new QHBoxLayout();

    QLineEdit *urlBar = new QLineEdit(centralWidget);
    QPushButton *goButton = new QPushButton("Go", centralWidget);
    QPushButton *backButton = new QPushButton("Back", centralWidget);
    QPushButton *forwardButton = new QPushButton("Forward", centralWidget);
    QPushButton *refreshButton = new QPushButton("Refresh", centralWidget);
    QWebEngineView *webView = new QWebEngineView(centralWidget);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(webView);
    vLayout->addWidget(urlBar);
    vLayout->addWidget(goButton);
    hLayout->addWidget(backButton);
    hLayout->addWidget(forwardButton);
    hLayout->addWidget(refreshButton);

    QObject::connect(goButton, &QPushButton::clicked, [urlBar, webView]() {
        QString url = urlBar->text();

        if(!url.startsWith("http://") && !url.startsWith("https://")) {
            url = "http://" + url;
        }

        webView->setUrl(QUrl(url));
    });

    QObject::connect(backButton, &QPushButton::clicked, [urlBar, webView]() {
        QWebEngineHistory* history = webView->history();

        if(history->items().length() != 0) {
            history->back();
        }
    });

    QObject::connect(forwardButton, &QPushButton::clicked, [urlBar, webView]() {
        QWebEngineHistory* history = webView->history();
        if(history->canGoForward()) {
            history->forward();
        }
    });

    QObject::connect(refreshButton, &QPushButton::clicked, [urlBar, webView]() {
        webView->reload();
    });

    mainWindow.setCentralWidget(centralWidget);
    mainWindow.resize(800,600);
    mainWindow.show();
    return app.exec();
}
