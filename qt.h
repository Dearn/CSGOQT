#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>


class UIForm : public QWidget
{
  Q_OBJECT
 
private:
  QPushButton *pushButton;
  void retranslateUi(QWidget *Form);
public:
  void setupUi(QWidget *Form);

};
