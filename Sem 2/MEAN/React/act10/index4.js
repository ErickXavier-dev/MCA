// Write a nodejs program using mongoose to update the course of rollno 103 to MSc CS from students collection in college database

const mongoose = require('mongoose');
const url = "mongodb+srv://isitreal126:fHkNZJ8SeAk12Z8U@cluster0.lrxvx.mongodb.net/college"
mongoose.connect(url)
.then(() => console.log("Connected to MongoDB"))
.catch((err) => console.log(err));

const studentsSchema = new mongoose.Schema({
    rollNo: Number,
    name: String,
    age: Number,
    course: String,
    semester: Number,
    mark: Number
});

const Student = mongoose.model('Students', studentsSchema);

Student.deleteMany({})
.then(() => {
    console.log("Student deleted successfully");
})
.catch((err) => {
    console.log(err);
});

Student.find().then((students) => {
    console.log("All students in the collection:");
    console.log(students);
    mongoose.connection.close();
}).catch((err) => {
    console.log(err);
    mongoose.connection.close();
});