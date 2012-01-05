#ifndef FILESYSTEMMODEL_HPP
#define FILESYSTEMMODEL_HPP

#include <QFileSystemModel>
#include <QSet>
#include <QString>

/// Class implementing custom file system model that supports
/// checkboxes for directories.
class FileSystemModel : public QFileSystemModel
{
    Q_OBJECT
public:
    /// Constructor for File System Model
    /// @param selected_directories Pre-set selected directories
    /// @param parent Parent QObject
    explicit FileSystemModel(QSet<QString> selected_directories,
                             QObject *parent = 0);

    /// Gets selected directories.
    /// @return Set containing strings of directories selected.
    QSet <QString> getSelectedDirectories() const;

    // Reimplemented from QFileSystemModel
    QVariant data(const QModelIndex& index, int role) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role);
    int columnCount(const QModelIndex &parent) const;

private:
    QSet <QString> selected_directories_;
    
};

#endif // FILESYSTEMMODEL_HPP
