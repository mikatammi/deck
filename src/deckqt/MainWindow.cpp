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

    // Splitter t
    splitter_ = new QSplitter(this);

    databasewidget_ = new DatabaseWidget(this);
    playlistwidget_ = new PlayListWidget(this);

    splitter_->addWidget(databasewidget_);
    splitter_->addWidget(playlistwidget_);

    splitter_->setLineWidth(10);

    layout_ = new QVBoxLayout();
    layout_->addWidget(splitter_);

    ui_->centralwidget->setLayout(layout_);


    QToolBar * controltoolbar = new QToolBar("Control Tool Bar", this);

    TrackControlWidget * controlwidget = new TrackControlWidget(controltoolbar);
    controltoolbar->addWidget(controlwidget);

    addToolBar(Qt::TopToolBarArea, controltoolbar);

    mainplayer_ = new deck::MainPlayer();

    Q_ASSERT(mainplayer != 0);

    connect(ui_->actionOptions, SIGNAL(triggered()), SLOT(showOptionsDialog()));
}

MainWindow::~MainWindow()
{
    delete mainplayer_;
    delete splitter_;
    delete layout_;
    delete ui_;
}

void MainWindow::showOptionsDialog()
{
    OptionsDialog options(mainplayer_);
    options.exec();
}
