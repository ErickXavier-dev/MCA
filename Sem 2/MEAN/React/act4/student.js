const express = require('express')
const router = express.Router()

router.use((req, res, next) => {
  console.log(`Router level middleware executed`);
  next(); // Call the next middleware or route handler
});

router.get('/', (req, res) => res.send('All students.'))
router.get('/:id', (req, res) => res.send(`Student with id ${req.params.id}`))

module.exports = router