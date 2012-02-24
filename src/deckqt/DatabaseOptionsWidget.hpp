#ifndef DATABASEOPTIONSWIDGET_HPP
#define DATABASEOPTIONSWIDGET_HPP

#include <QWidget>
#include <QSet>
#include <QString>

namespace Ui {
class DatabaseOptionsWidget;
}

class FileSystemModel;

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

    /// Gets selected directories from widget
    /// @return Selected directories in tree view
    QSet <QString> getSelectedDirectories() const;
    
private:
    Ui::DatabaseOptionsWidget* ui_;
    FileSystemModel* fsmodel_;
};

#endif // DATABASEOPTIONSWIDGET_HPP
