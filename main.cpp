#include <QApplication>
#include "gui/notepad.h"
#include <QTextEdit>
#include <QtGui>
#include <QVBoxLayout>
#include <QPushButton>


                int main(int argv, char **args)
               {
                    QApplication app(argv, args);

                    QTextEdit textEdit;
                    QPushButton quitButton("Quit");

                   QObject::connect(&quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

                   QVBoxLayout layout;
                   layout.addWidget(&textEdit);
                   layout.addWidget(&quitButton);

                   QWidget window;
                   window.setLayout(&layout);

                  window.show();

                  return app.exec();
              }
