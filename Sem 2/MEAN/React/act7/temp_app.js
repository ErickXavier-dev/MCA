const express = require('express')
const app = express()
const port = 3000

app.use(express.json());
app.set('view engine', 'ejs');

app.get('/', (req, res) => {
  res.render('index', { title: 'Welcome', message: 'Hello, this is a simple Express app with EJS!' });
});

app.get('/student', (req, res) => {
  res.render('stud', { title: 'Student Details', name: 'John Doe', course: 'Computer Science' });
});

app.listen(port, () => console.log(`app listening on port ${port}!`))