#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtGui>
#include <QTextEdit>
#include <QPushButton>
#include <QMainWindow>
#include <QAction>

class notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit notepad(QWidget *parent = 0);
    ~notepad();
signals:

private slots:
  //  void quit();

private:
    QTextEdit *textEdit;
    QPushButton *quitButton;
};
#endif // NOTEPAD_H
/*
class notepad : public QMainWindow
{
    Q_OBJECT
public:
    explicit notepad(QWidget *parent = 0);
    ~notepad();

signals:

public slots:
};
*/



