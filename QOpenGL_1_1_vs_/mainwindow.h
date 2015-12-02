#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
    bool eventFilter(QObject *obj, QEvent *event);

private:
    void LoadMeshFile(QString filename);

private slots:

    void on_actionExit_triggered();

    void on_checkBoxLocator_clicked(bool checked);

    void on_checkBoxGrid_clicked(bool checked);

    void on_checkBoxTrackball_clicked(bool checked);

    void on_SaveVertex_clicked();

    void on_drawBorder_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
