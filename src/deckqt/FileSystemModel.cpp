#include "FileSystemModel.hpp"

FileSystemModel::FileSystemModel(QSet <QString> selected_directories,
        QObject *parent) :
    QFileSystemModel(parent),
    selected_directories_(selected_directories)
{
    // Setting read only mode
    setReadOnly(true);

    // Setting filter for showing only directories and not links to parent
    // directory
    setFilter(QDir::AllDirs | QDir::NoDotAndDotDot);

    // Set view to root
    setRootPath(QDir::rootPath());
}

QSet <QString> FileSystemModel::getSelectedDirectories() const
{
    // Returns checked directories
    return selected_directories_;
}

QVariant FileSystemModel::data(const QModelIndex &index, int role) const
{
    // This data function implements checking of checkbox state
    if (index.isValid() && role == Qt::CheckStateRole)
    {
        // If checkbox is checked, directory is contained in
        // set containing checked directories.
        if(selected_directories_.contains(filePath(index)))
        {
            return Qt::Checked;
        }

        return Qt::Unchecked;
    }

    // Use parent class data function to get any other types of data
    return QFileSystemModel::data(index, role);
}


Qt::ItemFlags FileSystemModel::flags(const QModelIndex& index) const
{
    // Everything visible is checkable
    return QFileSystemModel::flags(index) | Qt::ItemIsUserCheckable;
}

bool FileSystemModel::setData(const QModelIndex &index, const QVariant &value,
                              int role)
{
    // This data function implements setting of checkbox state
    if (index.isValid() && role == Qt::CheckStateRole)
    {
        // When user checks a box, add directory to set containing
        // checked directories. When unchecked, remove directory from
        // set.
        if(value.toInt() == Qt::Checked)
        {
            selected_directories_ += filePath(index);
        }
        else
        {
            selected_directories_ -= filePath(index);
        }

        return true;
    }

    // Use parent class setData function to set any other types of data
    return QFileSystemModel::setData(index, value, role);
}
