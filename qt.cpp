#include "qt.h"
#include <iostream>
void UIForm::setupUi(QWidget *Form)
{

  if(Form->objectName().isEmpty())
    Form->setObjectName(QStringLiteral("Form"));
  Form->resize(800,600);
  pushButton = new QPushButton(Form);
  textEdit = new QTextEdit(Form);
  textEdit->setGeometry(QRect(20, 20, 600, 100));
  pushButton->setObjectName(QStringLiteral("pushButton"));
  pushButton->setGeometry(QRect(20, 180, 91, 27));
  csgo.parsejson(false);
  retranslateUi(Form);
  connect(pushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  QMetaObject::connectSlotsByName(Form);
}

void UIForm::buttonClicked()
{
  std::string tempStr;
  std::ostringstream ss;
  for(int i=0;i<10;i++)
    {
      tempStr+=this->csgo.jdata[i].get("name", 0).asString();
      if(this->csgo.jdata[i].get("name", 0).asString().length() < 12)
	tempStr+=" :\t\t";
      else
	tempStr+=" :\t";
      ss << this->csgo.jdata[i].get("value", 0).asInt();
      tempStr+= ss.str();

      ss.clear();
      ss.str("");
      tempStr+="\n";
    }
  this->textEdit->setText(tempStr.c_str());
  // textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
}

UIForm::~UIForm()
{
  delete pushButton;
  delete textEdit;

}

void UIForm::retranslateUi(QWidget *Form)
{
  Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
  pushButton->setText(QApplication::translate("Form", "PushButton", 0));
}




