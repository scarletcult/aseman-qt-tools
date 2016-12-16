/*
    Copyright (C) 2017 Aseman Team
    http://aseman.co

    AsemanQtTools is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    AsemanQtTools is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ASEMANFILESYSTEMMODEL_H
#define ASEMANFILESYSTEMMODEL_H

#include "asemanabstractlistmodel.h"
#include <QStringList>
#include <QFileInfo>

class AsemanFileSystemModelPrivate;
class AsemanFileSystemModel : public AsemanAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(SortFlag)
    Q_ENUMS(DataRole)

    Q_PROPERTY(bool showDirs READ showDirs WRITE setShowDirs NOTIFY showDirsChanged)
    Q_PROPERTY(bool showDotAndDotDot READ showDotAndDotDot WRITE setShowDotAndDotDot NOTIFY showDotAndDotDotChanged)
    Q_PROPERTY(bool showDirsFirst READ showDirsFirst WRITE setShowDirsFirst NOTIFY showDirsFirstChanged)
    Q_PROPERTY(bool showFiles READ showFiles WRITE setShowFiles NOTIFY showFilesChanged)
    Q_PROPERTY(bool showHidden READ showHidden WRITE setShowHidden NOTIFY showHiddenChanged)
    Q_PROPERTY(QStringList nameFilters READ nameFilters WRITE setNameFilters NOTIFY nameFiltersChanged)
    Q_PROPERTY(QString folder READ folder WRITE setFolder NOTIFY folderChanged)
    Q_PROPERTY(QString parentFolder READ parentFolder NOTIFY parentFolderChanged)
    Q_PROPERTY(int sortField READ sortField WRITE setSortField NOTIFY sortFieldChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    enum SortFlag {
        Name,
        Size,
        Date
    };

    enum DataRole {
        FilePath = Qt::UserRole,
        FileUrl,
        FileName,
        FileMime,
        FileSize,
        FileSuffix,
        FileBaseName,
        FileIsDir,
        FileModifiedDate,
        FileCreatedDate
    };

    AsemanFileSystemModel(QObject *parent = 0);
    ~AsemanFileSystemModel();

    void setShowDirs(bool stt);
    bool showDirs() const;

    void setShowDotAndDotDot(bool stt);
    bool showDotAndDotDot() const;

    void setShowDirsFirst(bool stt);
    bool showDirsFirst() const;

    void setShowFiles(bool stt);
    bool showFiles() const;

    void setShowHidden(bool stt);
    bool showHidden() const;

    void setNameFilters(const QStringList &list);
    QStringList nameFilters() const;

    void setFolder(const QString &url);
    QString folder() const;

    void setSortField(int field);
    int sortField() const;

    QString parentFolder() const;

    const QFileInfo &id( const QModelIndex &index ) const;

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QHash<qint32,QByteArray> roleNames() const;
    int count() const;

public slots:
    void refresh();

signals:
    void countChanged();
    void showDirsChanged();
    void showDotAndDotDotChanged();
    void showDirsFirstChanged();
    void showFilesChanged();
    void showHiddenChanged();
    void nameFiltersChanged();
    void folderChanged();
    void parentFolderChanged();
    void sortFieldChanged();
    void listChanged();

private slots:
    void reinit_buffer();

private:
    void changed(const QList<QFileInfo> &list);

private:
    AsemanFileSystemModelPrivate *p;
};

#endif // ASEMANFILESYSTEMMODEL_H
