#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QtWidgets>
#include <QDialog>

//static const  = "addressbook";

class AddDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddDialog(QWidget *parent = nullptr);

     QLineEdit *nameText;
//QString choosedDB;

private:
     QLabel *nameLabel;
     QPushButton *okButton;
     QPushButton *cancelButton;


signals:


public slots:
};

#endif // ADDDIALOG_H
