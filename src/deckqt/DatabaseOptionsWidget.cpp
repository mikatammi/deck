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
    fsmodel_ = new FileSystemModel(selected_dirs);
    ui_->treeView->setModel(fsmodel_);
}

DatabaseOptionsWidget::~DatabaseOptionsWidget()
{
    delete fsmodel_;
    fsmodel_ = 0;

    delete ui_;
    ui_ = 0;
}

QSet <QString> DatabaseOptionsWidget::getSelectedDirectories() const
{
    return fsmodel_->getSelectedDirectories();
}
