#include "../include/Library.h"
#include <iostream>
#include <iomanip>

using namespace std;

Book::Book() : id(0), price(0.0), rating(0.0)
{
    strcpy(name, "Unknown");
    strcpy(author, "Unknown");
    strcpy(category, "Unknown");
}

Book::Book(int id, const char *name, const char *author, const char *category, double price, float rating)
    : id(id), price(price), rating(rating)
{
    strcpy(this->name, name);
    strcpy(this->author, author);
    strcpy(this->category, category);
}

void Book::setDetails(int id, const char *name, const char *author, const char *category, double price, float rating)
{
    this->id = id;
    strcpy(this->name, name);
    strcpy(this->author, author);
    strcpy(this->category, category);
    this->price = price;
    this->rating = rating;
}

void Book::display() const
{
    cout << "\n[Book ID: " << id << "] " << name << " by " << author << " (" << category << ") ₹" << price << " ⭐" << rating << endl;
}

int Book::getID() const { return id; }
const char *Book::getName() const { return name; }

Library::Library() : count(0) {}

void Library::addBook(int id, const char *name, const char *author, const char *category, double price, float rating)
{
    if (count < 100)
    {
        books[count++].setDetails(id, name, author, category, price, rating);
    }
}

void Library::displayAll() const
{
    for (int i = 0; i < count; i++)
    {
        books[i].display();
    }
}
