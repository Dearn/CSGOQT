#include "qt.h"
#include <iostream>
void UIForm::setupUi(QWidget *Form)
{

  if(Form->objectName().isEmpty())
    Form->setObjectName(QStringLiteral("Form"));
  Form->resize(800,600);
  pushButton = new QPushButton(Form);
  downloadButton = new QPushButton(Form);
  textEdit = new QTextEdit(Form);
  textEdit->setGeometry(QRect(20, 20, 600, 100));
  // pushButton->setObjectName(QStringLiteral("pushButton"));
  // downloadButton->setObjectName(QStringLiteral("Redownload"));
  
  csgo.parsejson(false);
  retranslateUi(Form);


  layout.addWidget(textEdit);
  layout.addWidget(pushButton);
  layout.addWidget(downloadButton);
  // buttonClicked();
  QMetaObject::connectSlotsByName(Form);
  connect(pushButton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
  connect(downloadButton, SIGNAL(clicked()), this, SLOT(buttonClicked2()));
}

void UIForm::buttonClicked()
{
  csgo.parsejson(false);
  std::string tempStr;
  std::ostringstream ss;
  for(unsigned int i=0;i<this->csgo.jdata.size();i++)
    {
      tempStr+=this->csgo.jdata[i].get("name", 0).asString();
      if(this->csgo.jdata[i].get("name", 0).asString().length() < 12)
	tempStr+=":\t\t";
      else
	tempStr+=":\t";
      ss << this->csgo.jdata[i].get("value", 0).asInt();
      tempStr+= ss.str();

      ss.clear();
      ss.str("");
      tempStr+="\n";
    }
  this->textEdit->setText(tempStr.c_str());
  // textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
}


void UIForm::buttonClicked2()
{
  csgo.parsejson(true);
  std::string tempStr;
  std::ostringstream ss;
  for(unsigned int i=0;i<this->csgo.jdata.size();i++)
    {
      tempStr+=this->csgo.jdata[i].get("name", 0).asString();
      if(this->csgo.jdata[i].get("name", 0).asString().length() < 12)
	tempStr+=":\t\t";
      else
	tempStr+=":\t";
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
  downloadButton->setText(QApplication::translate("Form", "reDownload + Parse", 0));
  pushButton->setText(QApplication::translate("Form", "Parse", 0));


}




