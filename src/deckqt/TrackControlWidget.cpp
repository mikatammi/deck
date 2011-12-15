#include "TrackControlWidget.hpp"
#include "ui_TrackControlWidget.h"

TrackControlWidget::TrackControlWidget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::TrackControlWidget)
{
    ui_->setupUi(this);
}

TrackControlWidget::~TrackControlWidget()
{
    delete ui_;
}
