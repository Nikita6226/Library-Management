#ifndef ADDBOOKFORM_H
#define ADDBOOKFORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QString>
#include "../include/Library.h"

class AddBookForm : public QWidget
{
    Q_OBJECT

private:
    QLineEdit *idInput, *nameInput, *authorInput, *categoryInput, *priceInput, *ratingInput;
    QPushButton *addButton;
    Library *library;

public:
    AddBookForm(Library *lib, QWidget *parent = nullptr) : QWidget(parent), library(lib)
    {
        setWindowTitle("Add Book");

        idInput = new QLineEdit();
        nameInput = new QLineEdit();
        authorInput = new QLineEdit();
        categoryInput = new QLineEdit();
        priceInput = new QLineEdit();
        ratingInput = new QLineEdit();
        addButton = new QPushButton("Add Book");

        QFormLayout *form = new QFormLayout();
        form->addRow("Book ID:", idInput);
        form->addRow("Name:", nameInput);
        form->addRow("Author:", authorInput);
        form->addRow("Category:", categoryInput);
        form->addRow("Price:", priceInput);
        form->addRow("Rating:", ratingInput);
        form->addWidget(addButton);

        setLayout(form);

        connect(addButton, &QPushButton::clicked, this, [=]()
                {
            int id = idInput->text().toInt();
            QString name = nameInput->text();
            QString author = authorInput->text();
            QString category = categoryInput->text();
            double price = priceInput->text().toDouble();
            float rating = ratingInput->text().toFloat();

            library->addBookFromGUI(id, name.toStdString().c_str(), author.toStdString().c_str(), category.toStdString().c_str(), price, rating); });
    }
};

#endif
