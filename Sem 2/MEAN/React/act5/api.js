// write a program to perform the following - Display all books, add a new book, update book details, delete book.

const express = require('express');
const app = express();

// Middleware to parse JSON bodies
app.use(express.json());

let books = [
    { id: 1, title: 'Book One', author: 'Author One' },
    { id: 2, title: 'Book Two', author: 'Author Two' }
]; 

// Display all books
app.get('/books', (req, res) => {
    res.json(books);
});

app.post('/books', (req, res) => {
    const newBook = {
        id: books.length + 1,
        title: req.body.title,
        author: req.body.author
    };
    books.push(newBook);
    res.status(201).json(newBook);
});

// Update book details
app.put('/books/:id', (req, res) => {
    const bookId = parseInt(req.params.id);
    const book = books.find(b => b.id === bookId);
    if (book) {
        book.title = req.body.title || book.title;
        book.author = req.body.author || book.author;
        res.json(book);
    } else {
        res.status(404).json({ message: 'Book not found' });
    }
});

// Delete book
app.delete('/books/:id', (req, res) => {
    const bookId = parseInt(req.params.id);
    const bookIndex = books.findIndex(b => b.id === bookId);
    if (bookIndex !== -1) {
        const deletedBook = books.splice(bookIndex, 1);
        res.json(deletedBook);
    } else {
        res.status(404).json({ message: 'Book not found' });
    }
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Server is running on port ${PORT}`);
});