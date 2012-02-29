#ifndef OPTIONSDIALOG_HPP
#define OPTIONSDIALOG_HPP

#include <QDialog>

namespace deck {
class MainPlayer;
}

namespace Ui {
class OptionsDialog;
}

class GenericOptionsWidget;
class DatabaseOptionsWidget;
class PeerOptionsWidget;

/// Class for Options Dialog
class OptionsDialog : public QDialog
{
    Q_OBJECT
    
public:
    /// Constructor for OptionsDialog
    /// @param mainplayer Pointer to MainPlayer-class
    /// @param parent Parent QWidget
    explicit OptionsDialog(deck::MainPlayer* mainplayer, QWidget *parent = 0);
    ~OptionsDialog();

private slots:
    /// Activated when user clicks Ok
    void onOK();

    /// Activated when user clicks Apply (or Ok)
    void onApply();

private:
    Ui::OptionsDialog* ui_;
    deck::MainPlayer* mainplayer_;

    GenericOptionsWidget* genericoptions_;
    DatabaseOptionsWidget* databaseoptions_;
    PeerOptionsWidget* peeroptions_;
};

#endif // OPTIONSDIALOG_HPP
