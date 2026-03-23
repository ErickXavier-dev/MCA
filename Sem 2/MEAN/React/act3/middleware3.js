// Check if /admin is accessed if not autorized send not authorized message

const express = require('express')
const app = express()
const port = 3000

// Middleware function to log request details
app.use((req, res, next) => {
  if (req.query.user !== 'admin' && req.path === '/admin') {
    res.send('Not Authorized!');
  } else {
    next(); // Call the next middleware or route handler
  }
});

app.get('/', (req, res) => res.send('Welcome to Home Page!<br>Go to <a href="/admin">/admin</a> for admin page.'))
app.get('/admin', (req, res) => res.send('Welcome to Admin Page!'))
app.listen(port, () => console.log(`Example app listening on port ${port}!`))