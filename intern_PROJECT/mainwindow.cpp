#include "mainwindow.h"
#include "adddialog.h"


static const QString databaseName = "addressbook";

//static const QString choozedName = choosedDB;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , menuBar(new QMenuBar)
    , tableView(new QTreeView)
    , sqlView(new QTableView)
    , sqlEdit(new QTextEdit)
    , sqlResults(new QTextEdit)

    , sqlModel(new QSqlQueryModel(sqlView))

{

    initMenus();

    sqlResults->setReadOnly(true);
    sqlResults->setMaximumHeight(100);

    sqlView->setModel(sqlModel);

    QSplitter* vSplitter = new QSplitter(Qt::Vertical);
    vSplitter->addWidget(sqlView);
    vSplitter->addWidget(sqlEdit);
    vSplitter->setStretchFactor(0, 3);
    vSplitter->setStretchFactor(1, 1);

    QSplitter* hSplitter = new QSplitter(Qt::Horizontal);

    hSplitter->addWidget(vSplitter);


    QVBoxLayout* vlayo = new QVBoxLayout;
    vlayo->setMargin(0);
    vlayo->setSpacing(5);
    vlayo->addWidget(menuBar);
    vlayo->addWidget(hSplitter);
    vlayo->addWidget(sqlResults);

    this->setLayout(vlayo);
}

void MainWindow::initMenus()
{
    auto menuDatabase = menuBar->addMenu("&Database");
    menuDatabase->addAction("Connect", this, &MainWindow::onConnection);
    menuDatabase->addAction("Disconnect", this, &MainWindow::onDisconnection);


    auto menuQuery = menuBar->addMenu("Queries");
    menuQuery->addAction("Run", this, &MainWindow::onRunning, Qt::Key_F5);
}

void MainWindow::onConnection()
{
    onDisconnection();

   // fileModel->setRootPath("");
    //tableModel->setQuery("QSQLITE", databaseName);

    auto db = QSqlDatabase::addDatabase("QSQLITE", databaseName);
    db.setDatabaseName("addressbook.db");

    AddDialog nDialog;// = new AddDialog;
    nDialog.show();

   if (nDialog.exec())
   {
       db.setDatabaseName(nDialog.nameText->text());
   }

    if(!db.open())
    {
        QMessageBox::critical(this, "DB Error", db.lastError().text());
    }

    //tableModel->s

}

void MainWindow::onDisconnection()
{
    {
        auto db = QSqlDatabase::database(databaseName, false);
        if(db.isValid())
        {
            if(db.isOpen())
            {
                db.close();
            }


        }
    }
    QSqlDatabase::removeDatabase(databaseName);
}

void MainWindow::onRunning()
{
    auto db = QSqlDatabase::database(databaseName, false);

    //tableModel->setHeaderData(0,Qt::Horizontal,tr("table"));


    sqlModel->setQuery(sqlEdit->document()->toPlainText(), db);
    qDebug()<<sqlEdit->document()->toPlainText();

    sqlResults->append(sqlModel->lastError().text());

    //sqlResults->append(tableModel->lastError().text());
}
