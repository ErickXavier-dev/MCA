const express  = require('express');
const app = express();

app.get('/search', (req, res) => {
    const name = req.query.name;
    const age = req.query.age;

    res.send(`<h1>Name: ${name}, Age: ${age}</h1>`);
});

app.listen(3000, () => {
    console.log('Server is running on port 3000');
});