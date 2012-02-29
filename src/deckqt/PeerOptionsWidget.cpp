#include "PeerOptionsWidget.hpp"
#include "ui_PeerOptionsWidget.h"

PeerOptionsWidget::PeerOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::PeerOptionsWidget)
{
    ui_->setupUi(this);
}

PeerOptionsWidget::~PeerOptionsWidget()
{
    // Free dynamically allocated objects
    delete ui_;
    ui_ = 0;
}

void PeerOptionsWidget::setNodeName(QString nodename)
{
    // Set name of node into line edit field
    ui_->nodeName->setText(nodename);
}

QString PeerOptionsWidget::getNodeName() const
{
    // Get name of node from line edit field
    return ui_->nodeName->text();
}
