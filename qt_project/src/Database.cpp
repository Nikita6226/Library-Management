#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

bool connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("library_db");
    db.setUserName("root");
    db.setPassword("your_password"); // 🔐 Replace with your actual password

    if (!db.open())
    {
        qDebug() << "❌ Database connection failed:" << db.lastError().text();
        return false;
    }

    qDebug() << "✅ Connected to MySQL database!";
    return true;
}

void showAllBooksFromDB()
{
    QSqlQuery query("SELECT * FROM books");
    while (query.next())
    {
        int id = query.value("id").toInt();
        QString name = query.value("name").toString();
        QString author = query.value("author").toString();
        QString category = query.value("category").toString();
        double price = query.value("price").toDouble();
        float rating = query.value("rating").toFloat();

        qDebug() << "📘 Book ID:" << id
                 << ", Name:" << name
                 << ", Author:" << author
                 << ", Category:" << category
                 << ", Price:" << price
                 << ", Rating:" << rating;
    }
}
