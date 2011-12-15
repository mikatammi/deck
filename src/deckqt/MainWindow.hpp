#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QVBoxLayout;
class QSplitter;
class DatabaseWidget;
class PlayListWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow* ui_;

    QVBoxLayout* layout_;
    QSplitter* splitter_;

    DatabaseWidget* databasewidget_;
    PlayListWidget* playlistwidget_;
};

#endif // MAINWINDOW_HPP