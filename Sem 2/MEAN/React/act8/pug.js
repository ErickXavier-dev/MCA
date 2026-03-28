const express = require('express')
const app = express()
const port = 3000

app.set('view engine', 'pug');

app.get('/', (req, res) => {
  res.render('index', { title: 'Welcome', message: 'Erick Xavier' });
});

// Write an Express.js program using pug to display employee id, name and salary.

app.get('/', (req, res) => res.send('Hello World!'))
app.listen(port, () => console.log(`Example app listening on port ${port}!`))