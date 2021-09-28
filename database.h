#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database
{
public:
    Database();
    bool isConected();
    QSqlDatabase &database();
    bool openDatabase();

private:
    bool runSqlCreate(QSqlDatabase db, QString filePath);
    QSqlDatabase m_db;
};

#endif // DATABASE_H
