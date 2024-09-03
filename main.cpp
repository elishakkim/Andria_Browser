#include "mainwindow.h"
#include "Browser.h"

#include <QApplication>
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QWebEngineView>
//#include <QWebEngineHistory>
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

    hLayout->addWidget(backButton);
    hLayout->addWidget(forwardButton);
    hLayout->addWidget(refreshButton);
    hLayout->addWidget(goButton);
    hLayout->addWidget(urlBar);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(webView);

    Browser browser(urlBar, goButton, backButton, forwardButton, refreshButton, webView);

    mainWindow.setCentralWidget(centralWidget);
    mainWindow.resize(800,600);
    mainWindow.show();
    return app.exec();
}
