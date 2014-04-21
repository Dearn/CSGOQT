// #include "json.h"
#include "qt.h"
#include <QtWidgets/QApplication>
// #include <QTextEdit>
// #include <QObject>
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <iostream>
// #include "main.moc"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
  size_t written;
  written = fwrite(ptr, size, nmemb, stream);
  return written;
}


int main(int argc, char **args)
{


  QApplication app(argc, args);
  QWidget *widget = new QWidget;
  UIForm ui;
  ui.setupUi(widget);
  widget->show();

  return app.exec();
}
