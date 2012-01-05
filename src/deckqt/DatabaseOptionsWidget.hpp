#ifndef DATABASEOPTIONSWIDGET_HPP
#define DATABASEOPTIONSWIDGET_HPP

#include <QWidget>
#include <QSet>
#include <QString>

namespace Ui {
class DatabaseOptionsWidget;
}

/// Database Options Tab for use in OptionsDialog
class DatabaseOptionsWidget : public QWidget
{
    Q_OBJECT
    
public:
    /// Constructor for DatabaseOptionsWidget
    /// @param selected_dirs Selected directories in tree view
    /// @param parent Parent Widget
    explicit DatabaseOptionsWidget(QSet <QString> selected_dirs,
                                   QWidget *parent = 0);
    ~DatabaseOptionsWidget();
    
private:
    Ui::DatabaseOptionsWidget *ui_;
};

#endif // DATABASEOPTIONSWIDGET_HPP
