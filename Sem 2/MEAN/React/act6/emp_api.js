const express = require('express')
const app = express()
const port = 3000

app.use(express.json());

let employees = [
    { id: 1, name: 'John Doe', department: "HR", salary: 50000 },
    { id: 2, name: 'Jane Smith', department: "IT", salary: 60000 }
];

app.get('/employees', (req, res) => {
    res.json(employees);
});

app.get('/employees/:id', (req, res) => {
    const employeeId = parseInt(req.params.id);
    const employee = employees.find(e => e.id === employeeId);
    if (employee) {
        res.json(employee);
    } else {
        res.status(404).json({ message: 'Employee not found' });
    }
});

app.post('/employees', (req, res) => {
    const newEmployee = {
        id: employees.length + 1,
        name: req.body.name,
        department: req.body.department,
        salary: req.body.salary
    };
    employees.push(newEmployee);
    res.status(201).json(newEmployee);
});

app.put('/employees/:id', (req, res) => {
    const employeeId = parseInt(req.params.id);
    const employee = employees.find(e => e.id === employeeId);
    if (employee) {
        employee.name = req.body.name || employee.name;
        employee.department = req.body.department || employee.department;
        employee.salary = req.body.salary || employee.salary;
        res.json(employee);
    } else {
        res.status(404).json({ message: 'Employee not found' });
    }
});

app.delete('/employees/:id', (req, res) => {
    const employeeId = parseInt(req.params.id);
    const employeeIndex = employees.findIndex(e => e.id === employeeId);
    if (employeeIndex !== -1) {
        const deletedEmployee = employees.splice(employeeIndex, 1);
        res.json(deletedEmployee);
    } else {
        res.status(404).json({ message: 'Employee not found' });
    }
});

app.listen(port, () => console.log(`Example app listening on port ${port}!`))