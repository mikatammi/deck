#include "OptionsDialog.hpp"
#include "ui_OptionsDialog.h"

#include "GenericOptionsWidget.hpp"
#include "DatabaseOptionsWidget.hpp"
#include "PeerOptionsWidget.hpp"

#include "MainPlayer.hpp"
#include "Settings.hpp"

#include <QPushButton>
#include <boost/foreach.hpp>
#include <set>
#include <string>

OptionsDialog::OptionsDialog(deck::MainPlayer* mainplayer, QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::OptionsDialog),
    mainplayer_(mainplayer),
    genericoptions_(0),
    databaseoptions_(0),
    peeroptions_(0)
{
    ui_->setupUi(this);

    deck::Settings* s = mainplayer_->getSettings();

    // Conversion from std::set<std::string> to QSet<QString>
    QSet <QString> database_selected_dirs;
    BOOST_FOREACH(std::string str, s->getDatabaseDirectories())
    {
        database_selected_dirs.insert(QString(str.c_str()));
    }

    // Allocate tab widgets
    genericoptions_ = new GenericOptionsWidget(this);
    databaseoptions_ = new DatabaseOptionsWidget(database_selected_dirs, this);
    peeroptions_ = new PeerOptionsWidget(this);

    // Set Peer Options
    peeroptions_->setNodeName(s->getNodeName().c_str());

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
    // Free dynamically allocated objects
    delete genericoptions_;
    genericoptions_ = 0;

    delete databaseoptions_;
    databaseoptions_ = 0;

    delete peeroptions_;
    peeroptions_ = 0;

    delete ui_;
    ui_ = 0;
}

void OptionsDialog::onOK()
{
    // Apply settings
    onApply();

    accept();
}

void OptionsDialog::onApply()
{
    // Save database options
    deck::Settings* s = mainplayer_->getSettings();

    // Conversion from QSet<QString> to std::set<std::string>
    std::set <std::string> selecteddirs;
    BOOST_FOREACH(QString str, databaseoptions_->getSelectedDirectories())
    {
        selecteddirs.insert(str.toStdString());
    }

    s->setDatabaseDirectories(selecteddirs);

    // Save peer options
    s->setNodeName(peeroptions_->getNodeName().toStdString());

    // Save settings
    s->save();
}
