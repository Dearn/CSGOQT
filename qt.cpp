#include "qt.h"
void UIForm::setupUi(QWidget *Form)
{

  if(Form->objectName().isEmpty())
    Form->setObjectName(QStringLiteral("Form"));
  Form->resize(400,300);
  pushButton = new QPushButton(Form);
  pushButton->setObjectName(QStringLiteral("pushButton"));
  pushButton->setGeometry(QRect(60, 180, 91, 27));
   
  retranslateUi(Form);
  QMetaObject::connectSlotsByName(Form);
}
void UIForm::retranslateUi(QWidget *Form)
{
  Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
  pushButton->setText(QApplication::translate("Form", "PushButton", 0));
}




