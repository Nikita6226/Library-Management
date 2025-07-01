#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <cstring>

class Book
{
    int id;
    char name[50];
    char author[50];
    char category[30];
    double price;
    float rating;

public:
    Book();
    Book(int, const char *, const char *, const char *, double, float);
    void setDetails(int, const char *, const char *, const char *, double, float);
    void display() const;
    int getID() const;
    const char *getName() const;
};

class Library
{
    Book books[100];
    int count;

public:
    Library();
    void addBook(int, const char *, const char *, const char *, double, float);
    void displayAll() const;
};

#endif
