#include "DatabaseOptionsWidget.hpp"
#include "ui_DatabaseOptionsWidget.h"

#include "FileSystemModel.hpp"

DatabaseOptionsWidget::DatabaseOptionsWidget(QSet <QString> selected_dirs,
                                             QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::DatabaseOptionsWidget)
{
    ui_->setupUi(this);

    // Create filesystem model for treeview to show file structure
    FileSystemModel* fsmodel = new FileSystemModel(selected_dirs, this);
    ui_->treeView->setModel(fsmodel);
}

DatabaseOptionsWidget::~DatabaseOptionsWidget()
{
    delete ui_;
    ui_ = 0;
}
