const express = require('express')
const student = require('./student')
const app = express()
const port = 3000

app.use('/student', student) // Use the student router for /student routes

app.get('/', (req, res) => res.send('Hello World!'))
app.listen(port, () => console.log(`Example app listening on port ${port}!`))