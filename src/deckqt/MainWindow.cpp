#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include "DatabaseWidget.hpp"
#include "PlayListWidget.hpp"
#include "TrackControlWidget.hpp"

#include "OptionsDialog.hpp"

#include <QSplitter>
#include <QVBoxLayout>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    mainplayer_(0),
    ui_(new Ui::MainWindow),
    layout_(0),
    splitter_(0),
    databasewidget_(0),
    playlistwidget_(0)
{
    ui_->setupUi(this);

    // Add new splitter for database and playlist widgets
    splitter_ = new QSplitter(this);

    // Create database and playlist widgets
    databasewidget_ = new DatabaseWidget(this);
    playlistwidget_ = new PlayListWidget(this);

    // Add widgets to splitter
    splitter_->addWidget(databasewidget_);
    splitter_->addWidget(playlistwidget_);

    splitter_->setLineWidth(10);

    // Create new layout and add splitter to it
    layout_ = new QVBoxLayout();
    layout_->addWidget(splitter_);

    ui_->centralwidget->setLayout(layout_);

    // Add control widget tool bar
    QToolBar * controltoolbar = new QToolBar("Control Tool Bar", this);

    TrackControlWidget * controlwidget = new TrackControlWidget(controltoolbar);
    controltoolbar->addWidget(controlwidget);

    addToolBar(Qt::TopToolBarArea, controltoolbar);

    // Create instance of MainPlayer
    mainplayer_ = new deck::MainPlayer();

    Q_ASSERT(mainplayer != 0);

    // Connect signal for action opening options dialog
    connect(ui_->actionOptions, SIGNAL(triggered()), SLOT(showOptionsDialog()));
}

MainWindow::~MainWindow()
{
    // Free dynamically allocated objects
    delete mainplayer_;
    mainplayer_ = 0;

    delete splitter_;
    splitter_ = 0;

    delete layout_;
    layout_ = 0;

    delete ui_;
    ui_ = 0;
}

void MainWindow::showOptionsDialog()
{
    // Show options dialog
    OptionsDialog options(mainplayer_);
    options.exec();
}
