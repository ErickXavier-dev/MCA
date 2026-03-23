const express = require('express')
const app = express()
const port = 3000

// Middleware function to log request details
app.use((req, res, next) => {
  console.log(`Request received: ${new Date()}`);
  next(); // Call the next middleware or route handler
});

app.get('/', (req, res) => res.send('Welcome to Home Page!'))
app.listen(port, () => console.log(`Example app listening on port ${port}!`))