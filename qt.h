#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QTextEdit>
#include "json.h"


class UIForm : public QWidget
{
  Q_OBJECT
 
private:
  Jsonowanie csgo;
  QTextEdit *textEdit;
  QPushButton *pushButton;
  void retranslateUi(QWidget *Form);

public:
  void setupUi(QWidget *Form);
  ~UIForm();

public slots:
  void buttonClicked();
};
