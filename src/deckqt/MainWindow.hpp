#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "../libdeck/MainPlayer.hpp"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QVBoxLayout;
class QSplitter;
class DatabaseWidget;
class PlayListWidget;

/// Class for Main Window of the application
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /// Constructor for MainWindow
    /// @param parent Parent widget
    explicit MainWindow(QWidget *parent = 0);

    /// Destructor
    ~MainWindow();
    
private slots:
    void showOptionsDialog();

private:
    deck::MainPlayer * mainplayer_;

    Ui::MainWindow* ui_;

    QVBoxLayout* layout_;
    QSplitter* splitter_;

    DatabaseWidget* databasewidget_;
    PlayListWidget* playlistwidget_;
};

#endif // MAINWINDOW_HPP
