#include "OptionsDialog.hpp"
#include "ui_OptionsDialog.h"

#include "GenericOptionsWidget.hpp"
#include "DatabaseOptionsWidget.hpp"
#include "PeerOptionsWidget.hpp"

#include "MainPlayer.hpp"

#include <QPushButton>

OptionsDialog::OptionsDialog(deck::MainPlayer* mainplayer, QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::OptionsDialog),
    mainplayer_(mainplayer),
    genericoptions_(0),
    databaseoptions_(0),
    peeroptions_(0)
{
    ui_->setupUi(this);

    // TODO: Get database directories from mainplayer class
    QSet <QString> database_selected_dirs;

    // Allocate tab widgets
    genericoptions_ = new GenericOptionsWidget(this);
    databaseoptions_ = new DatabaseOptionsWidget(database_selected_dirs, this);
    peeroptions_ = new PeerOptionsWidget(this);

    // Add new widgets as tabs
    ui_->tabWidget->addTab(genericoptions_, tr("Generic"));
    ui_->tabWidget->addTab(databaseoptions_, tr("Database"));
    ui_->tabWidget->addTab(peeroptions_, tr("Peers"));

    // Connect OK and Cancel buttons
    connect(ui_->buttonBox, SIGNAL(accepted()), SLOT(onOK()));
    connect(ui_->buttonBox, SIGNAL(rejected()), SLOT(reject()));

    // Connect Apply button
    QPushButton * btnApply = ui_->buttonBox->button(QDialogButtonBox::Apply);
    connect(btnApply, SIGNAL(clicked()), SLOT(onApply()));
}

OptionsDialog::~OptionsDialog()
{
    delete genericoptions_;
    delete databaseoptions_;
    delete peeroptions_;

    delete ui_;
}

void OptionsDialog::onOK()
{
    // Apply settings
    onApply();

    accept();
}

void OptionsDialog::onApply()
{
    // TODO: Save settings
}
