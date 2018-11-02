#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtSql>
#include <adddialog.h>



class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

protected:
    QMenuBar* menuBar;

    QTreeView* tableView;
    QTableView* sqlView;

    QTextEdit* sqlEdit;
    QTextEdit* sqlResults;

protected:
    QSqlTableModel* tableModel;
    QSqlQueryModel* sqlModel;
    QFileSystemModel* fileModel;

protected:
    void initMenus();

    void onConnection();
    void onDisconnection();

    void onRunning();
};

#endif // MAINWINDOW_H
