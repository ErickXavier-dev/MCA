// write a program using mongoose to define a schema for students and insert atleast five students into the database and display all the students in the collection

const mongoose = require('mongoose');

mongoose.connect("mongodb+srv://isitreal126:fHkNZJ8SeAk12Z8U@cluster0.lrxvx.mongodb.net/college")
.then(()=>console.log("Connected to MongoDB"))
.catch((err)=>console.log(err));

const studentsSchema = new mongoose.Schema({
    rollno: Number,
    name: String,
    age: Number,
    course: String,
    semester: Number,
    mark: Number
});

const Student = mongoose.model('Students', studentsSchema);

Student.find({}, { name:1, course:1, _id:0}).then((students) => {
    console.log("All students in the collection:");
    console.log(students);
    mongoose.connection.close();
}).catch((err) => {
    console.log(err);
    mongoose.connection.close();
});

