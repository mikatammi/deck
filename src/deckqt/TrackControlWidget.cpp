#include "TrackControlWidget.hpp"
#include "ui_TrackControlWidget.h"

#include <phonon/MediaObject>

TrackControlWidget::TrackControlWidget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::TrackControlWidget)
{
    ui_->setupUi(this);

    connect(ui_->btnPlay, SIGNAL(clicked()), SIGNAL(play()));
    connect(ui_->btnPause, SIGNAL(clicked()), SIGNAL(pause()));
    connect(ui_->btnStop, SIGNAL(clicked()), SIGNAL(stop()));
    connect(ui_->btnNext, SIGNAL(clicked()), SIGNAL(next()));
    connect(ui_->btnPrev, SIGNAL(clicked()), SIGNAL(prev()));
}

TrackControlWidget::~TrackControlWidget()
{
    delete ui_;
}
