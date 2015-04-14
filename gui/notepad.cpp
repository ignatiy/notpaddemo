#include "gui/notepad.h"
#include <QVBoxLayout>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QTextStream>
#include <QTextEdit>
#include <QFileDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QAction>

void notepad(QWidget *parent);

notepad::notepad(QWidget *parent) : QMainWindow(parent)
{
    textEdit = new QTextEdit;
                quitButton = new QPushButton(tr("Quit"));

                 connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));

                 QVBoxLayout *layout = new QVBoxLayout;
                 layout->addWidget(textEdit);
                 layout->addWidget(quitButton);

                 setLayout(layout);

                setWindowTitle(tr("Notepad"));






}

void notepad(QWidget *parent);

notepad::notepad(QWidget *parent) : QMainWindow(parent)
{
    saveAction = new QAction(tr("&Open"), this);
               saveAction = new QAction(tr("&Save"), this);
                exitAction = new QAction(tr("E&xit"), this);

                connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
                connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
                connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

                fileMenu = menuBar()->addMenu(tr("&File"));
                fileMenu->addAction(openAction);
                fileMenu->addAction(saveAction);
                fileMenu->addSeparator();
                fileMenu->addAction(exitAction);

                textEdit = new QTextEdit;
                setCentralWidget(textEdit);

                setWindowTitle(tr("Notepad"));
}



void Notepad::open()
     {
         QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
             tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

        if (fileName != "") {
             QFile file(fileName);
             if (!file.open(QIODevice::ReadOnly)) {
                 QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                 return;
             }
             QTextStream in(&file);
             textEdit->setText(in.readAll());
             file.close();
         }
     }

void Notepad::save()
     {
         QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
         tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

         if (fileName != "") {
            QFile file(fileName);
             if (!file.open(QIODevice::WriteOnly)) {

            } else {
                 QTextStream stream(&file);
                stream << textEdit->toPlainText();
                stream.flush();
                file.close();
            }
        }
   }
