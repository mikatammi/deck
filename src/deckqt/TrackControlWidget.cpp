#include "TrackControlWidget.hpp"
#include "ui_TrackControlWidget.h"

TrackControlWidget::TrackControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrackControlWidget)
{
    ui->setupUi(this);
}

TrackControlWidget::~TrackControlWidget()
{
    delete ui;
}
