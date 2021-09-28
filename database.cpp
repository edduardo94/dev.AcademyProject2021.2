#include "database.h"

#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QTextStream>

const static QString DB_CONNECTION_NAME = "dev_db";

Database::Database()
{
    openDatabase();
}

bool Database::isConected()
{
    return QSqlDatabase::contains(DB_CONNECTION_NAME);
}

QSqlDatabase &Database::database()
{
    return m_db;
}

bool Database::openDatabase()
{
    QDir dataDir = QDir::currentPath();
    qDebug() << dataDir.absolutePath();
    QString dbFileName = dataDir.absolutePath() + "/" + DB_CONNECTION_NAME + ".db3";

    if(isConected()){
        m_db = QSqlDatabase::database(DB_CONNECTION_NAME);
    } else {
        m_db = QSqlDatabase::addDatabase("QSQLITE", DB_CONNECTION_NAME);
    }
    qDebug() << "driver available" << QSqlDatabase::isDriverAvailable("QSQLITE");
    m_db.setDatabaseName(dbFileName);

    bool needCreateDb = !dataDir.exists(dbFileName);
    bool open = m_db.open();

    if(open && needCreateDb){
        runSqlCreate(m_db, ":/create_db.sql");
    }

    return open;
}

bool Database::runSqlCreate(QSqlDatabase db, QString filePath)
{
    QFile scriptFile(filePath);
    bool allQueriesOk = false;
    if(scriptFile.exists() && db.open() && db.isValid()){
        if(scriptFile.open(QIODevice::ReadOnly)){
            QStringList queries = QTextStream(&scriptFile).readAll().split(";");
            for(auto query : queries){
                if(query.trimmed().isEmpty()){
                    continue;
                }

                if(db.exec(query.trimmed()).lastError().isValid()){
                    qDebug() << "QUERY FALHOU" << query << db.lastError();
                    allQueriesOk = false;
                } else {
                    qDebug() << "QUERY DEU CERTO";
                    allQueriesOk = true;
                }
            }
        }
    }
    return allQueriesOk;
}
