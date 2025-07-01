-- Create the database
CREATE DATABASE IF NOT EXISTS library_db;
USE library_db;

-- Drop tables if already exist
DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS books;

-- Books Table
CREATE TABLE books (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    author VARCHAR(100),
    category VARCHAR(50),
    price DOUBLE,
    rating FLOAT
);

-- Students Table
CREATE TABLE students (
    id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    book_id INT,
    FOREIGN KEY (book_id) REFERENCES books(id)
);

-- Sample books
INSERT INTO books VALUES
(101, 'C++ Programming', 'Bjarne Stroustrup', 'Programming', 599.99, 4.8),
(102, 'Data Structures', 'Mark Allen Weiss', 'Computer Science', 499.99, 4.5),
(103, 'Operating Systems', 'Galvin', 'Computer Science', 699.99, 4.7);

-- Sample students
INSERT INTO students VALUES
(1, 'Ravi Kumar', 'ravi@example.com', 101),
(2, 'Anjali Shah', 'anjali@example.com', 102);
