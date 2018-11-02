#include "adddialog.h"
#include "mainwindow.h"

AddDialog::AddDialog(QWidget *parent) : QDialog(parent)

  ,nameText (new QLineEdit)
  //,choosedDB(new QString)
  ,nameLabel (new QLabel("Name"))
  ,okButton (new QPushButton("OK"))
  ,cancelButton (new QPushButton("Cancel"))

{


       QGridLayout *gLayout = new QGridLayout;
       gLayout->setColumnStretch(1, 2);
       gLayout->addWidget(nameLabel, 0, 0);
       gLayout->addWidget(nameText, 0, 1);
       gLayout->addWidget(okButton, 1, 0);
       gLayout->addWidget(cancelButton, 1, 1);


       setLayout(gLayout);

       connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
       connect(cancelButton, &QPushButton::clicked, this, &QDialog::close);

       setWindowTitle(tr("Create/Choose database"));
}
