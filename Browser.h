#ifndef BROWSER_H
#define BROWSER_H

#include <QObject>
#include <QLineEdit>
#include <QPushButton>
#include <QWebEngineView>
#include <QWebEngineHistory>

class Browser : public QObject
{
    Q_OBJECT

public:
    Browser(QLineEdit *urlBar, QPushButton *goButton, QPushButton *backButton,
            QPushButton *forwardButton, QPushButton *refreshButton, QWebEngineView *webView);
private:
    void connectSignals();

    QLineEdit *urlBar;
    QPushButton *goButton;
    QPushButton *backButton;
    QPushButton *forwardButton;
    QPushButton *refreshButton;
    QWebEngineView *webView;
};

#endif // BROWSER_H
