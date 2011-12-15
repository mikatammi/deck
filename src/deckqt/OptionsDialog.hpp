#ifndef OPTIONSDIALOG_HPP
#define OPTIONSDIALOG_HPP

#include <QWidget>

namespace Ui {
class OptionsDialog;
}

class OptionsDialog : public QWidget
{
    Q_OBJECT
    
public:
    explicit OptionsDialog(QWidget *parent = 0);
    ~OptionsDialog();
    
private:
    Ui::OptionsDialog *ui;
};

#endif // OPTIONSDIALOG_HPP
