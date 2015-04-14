#ifndef MAIN_H
#define MAIN_H
#include <QtGui>
#include <QAction>
#include <QTextEdit>
          class Notepad : public QMainWindow
          {
              Q_OBJECT

          public:
              Notepad();

         private slots:
              void open();
              void save();
              void quit();
              void Notepad();

         private:
             QTextEdit *textEdit;

             QAction *openAction;
             QAction *saveAction;
             QAction *exitAction;

             QMenu *fileMenu;
         };






class main
{
public:
    main();
    ~main();
};

#endif // MAIN_H
