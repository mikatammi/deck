#include "DatabaseOptionsWidget.hpp"
#include "ui_DatabaseOptionsWidget.h"

#include "FileSystemModel.hpp"

DatabaseOptionsWidget::DatabaseOptionsWidget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::DatabaseOptionsWidget)
{
    ui_->setupUi(this);

    FileSystemModel* model = new FileSystemModel(QSet <QString> (), this);

    ui_->treeView->setModel(model);
}

DatabaseOptionsWidget::~DatabaseOptionsWidget()
{
    delete ui_;
}
