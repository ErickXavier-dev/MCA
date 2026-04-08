// write a program using mongoose to define a schema for students and insert atleast five students into the database and display all the students in the collection

const mongoose = require('mongoose');

mongoose.connect("mongodb+srv://isitreal126:fHkNZJ8SeAk12Z8U@cluster0.lrxvx.mongodb.net/college")
.then(()=>console.log("Connected to MongoDB"))
.catch((err)=>console.log(err));

const studentsSchema = new mongoose.Schema({
    rollNo: Number,
    name: String,
    age: Number,
    course: String,
    semester: Number,
    mark: Number
});

const Student = mongoose.model('Students', studentsSchema);

const insertStudents = async () => {
    await Student.insertMany([
        { rollNo: 101, name: "Alice", age: 20, course: "Computer Science", semester: 4, mark: 85 },
        { rollNo: 102, name: "Bob", age: 22, course: "Mechanical Engineering", semester: 6, mark: 78 },
        { rollNo: 103, name: "Charlie", age: 21, course: "Electrical Engineering", semester: 5, mark: 92 },
        { rollNo: 104, name: "David", age: 23, course: "Civil Engineering", semester: 7, mark: 80 },
        { rollNo: 105, name: "Eve", age: 19, course: "Information Technology", semester: 3, mark: 88 }
    ]);
    console.log("Students inserted successfully");
    
};

insertStudents();

Student.find().then((students) => {
    console.log("All students in the collection:");
    console.log(students);
    mongoose.connection.close();
}).catch((err) => {
    console.log(err);
    mongoose.connection.close();
});

