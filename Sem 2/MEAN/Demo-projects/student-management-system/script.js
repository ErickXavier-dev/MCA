/**
 * Student Management System Logic
 * Handles CRUD operations, Validation, Storage, and DOM updates
 */

// DOM Elements
const studentForm = document.getElementById('student-form');
const studentsTableBody = document.getElementById('student-table-body');
const searchInput = document.getElementById('search-input');
const totalCountElement = document.getElementById('total-count');
const formTitle = document.getElementById('form-title');
const submitBtnText = document.getElementById('submit-btn-text');
const cancelEditBtn = document.getElementById('cancel-edit');
const editIndexInput = document.getElementById('edit-index');
const idError = document.getElementById('id-error');
const noRecordsDiv = document.getElementById('no-records');
const emptyStateDiv = document.getElementById('empty-state');
const toast = document.getElementById('toast');
const toastMessage = document.getElementById('toast-message');
const toastIcon = document.getElementById('toast-icon');

// Custom Icons
const checkIcon = '<svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-green-400" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M5 13l4 4L19 7" /></svg>';
const errorIcon = '<svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-red-400" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M12 9v2m0 4h.01m-6.938 4h13.856c1.54 0 2.502-1.667 1.732-3L13.732 4c-.77-1.333-2.694-1.333-3.464 0L3.34 16c-.77 1.333.192 3 1.732 3z" /></svg>';
const trashIcon = '<svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5 text-red-600 hover:text-red-900" viewBox="0 0 20 20" fill="currentColor"><path fill-rule="evenodd" d="M9 2a1 1 0 00-.894.553L7.382 4H4a1 1 0 000 2v10a2 2 0 002 2h8a2 2 0 002-2V6a1 1 0 100-2h-3.382l-.724-1.447A1 1 0 0011 2H9zM7 8a1 1 0 012 0v6a1 1 0 11-2 0V8zm5-1a1 1 0 00-1 1v6a1 1 0 102 0V8a1 1 0 00-1-1z" clip-rule="evenodd" /></svg>';
const editIcon = '<svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5 text-indigo-600 hover:text-indigo-900" viewBox="0 0 20 20" fill="currentColor"><path d="M13.586 3.586a2 2 0 112.828 2.828l-.793.793-2.828-2.828.793-.793zM11.379 5.793L3 14.172V17h2.828l8.38-8.379-2.83-2.828z" /></svg>';

// State
let students = JSON.parse(localStorage.getItem('students')) || [];

// Initialization
document.addEventListener('DOMContentLoaded', () => {
    renderTable();
    updateStats();
});

// Create / Update Student
studentForm.addEventListener('submit', (e) => {
    e.preventDefault();

    const id = document.getElementById('student-id').value.trim();
    const name = document.getElementById('student-name').value.trim();
    const email = document.getElementById('student-email').value.trim();
    const age = document.getElementById('student-age').value;
    const course = document.getElementById('student-course').value;
    const editIndex = editIndexInput.value;

    // Additional Validation
    if (!validateName(name)) {
        showToast('Name should only contain letters and spaces', 'error');
        return;
    }

    // Check for duplicate ID (only if adding new student or changing ID)
    if (editIndex === '' && students.some(s => s.id === id)) {
        idError.classList.remove('hidden');
        document.getElementById('student-id').classList.add('border-red-500', 'focus:ring-red-500', 'focus:border-red-500');
        showToast('Student ID already exists!', 'error');
        return;
    } else {
        idError.classList.add('hidden');
        document.getElementById('student-id').classList.remove('border-red-500', 'focus:ring-red-500', 'focus:border-red-500');
    }

    const studentData = { id, name, email, age, course };

    if (editIndex === '') {
        // Add Mode
        students.push(studentData);
        showToast('Student added successfully!', 'success');
    } else {
        // Edit Mode
        // Check if ID changed and conflicts with another existing student (excluding self)
        if (students.some((s, i) => s.id === id && i != editIndex)) {
            showToast('New ID conflicts with existing student', 'error');
            return;
        }
        
        students[editIndex] = studentData;
        showToast('Student updated successfully!', 'success');
        resetFormState();
    }

    saveData();
    renderTable();
    updateStats();
    if (editIndex === '') studentForm.reset();
});

// Delete Student
function deleteStudent(index) {
    if (confirm('Are you sure you want to delete this student data?')) {
        students.splice(index, 1);
        saveData();
        renderTable();
        updateStats();
        showToast('Student removed successfully', 'success');
        
        // If we were editing this student, cancel edit mode
        if (editIndexInput.value == index) {
            resetFormState();
        }
    }
}

// Edit Student - Populate Form
function editStudent(index) {
    const student = students[index];
    
    document.getElementById('student-id').value = student.id;
    document.getElementById('student-name').value = student.name;
    document.getElementById('student-email').value = student.email;
    document.getElementById('student-age').value = student.age;
    document.getElementById('student-course').value = student.course;
    
    editIndexInput.value = index;
    
    // UI Updates for Edit Mode
    formTitle.textContent = 'Edit Student';
    submitBtnText.textContent = 'Update Student';
    cancelEditBtn.classList.remove('hidden');
    
    // Scroll to form on mobile
    studentForm.scrollIntoView({ behavior: 'smooth' });
}

// Cancel Edit
cancelEditBtn.addEventListener('click', () => {
    resetFormState();
    studentForm.reset();
});

function resetFormState() {
    formTitle.textContent = 'Add New Student';
    submitBtnText.textContent = 'Add Student';
    cancelEditBtn.classList.add('hidden');
    editIndexInput.value = '';
    idError.classList.add('hidden');
    document.getElementById('student-id').classList.remove('border-red-500', 'focus:ring-red-500', 'focus:border-red-500');
}

// Search Functionality
searchInput.addEventListener('input', (e) => {
    const term = e.target.value.toLowerCase();
    renderTable(term);
});

// Render Table
function renderTable(searchTerm = '') {
    studentsTableBody.innerHTML = '';
    
    // Filter students based on search term (ID or Name)
    const filteredStudents = students.filter(student => 
        student.name.toLowerCase().includes(searchTerm) || 
        student.id.toLowerCase().includes(searchTerm)
    );

    // Filtered Empty State
    if (filteredStudents.length === 0 && students.length > 0) {
        noRecordsDiv.classList.remove('hidden');
        studentsTableBody.innerHTML = '';
        return;
    } else {
        noRecordsDiv.classList.add('hidden');
    }

    // Global Empty State
    if (students.length === 0) {
        emptyStateDiv.classList.remove('hidden');
        return;
    } else {
        emptyStateDiv.classList.add('hidden');
    }

    filteredStudents.forEach((student, index) => {
        // Find the original index to ensure edit/delete works on the correct item
        // when searching
        const originalIndex = students.indexOf(student);
        
        const row = document.createElement('tr');
        row.className = 'hover:bg-gray-50 fade-in';
        row.innerHTML = `
            <td class="px-6 py-4 whitespace-nowrap text-sm font-medium text-gray-900">${student.id}</td>
            <td class="px-6 py-4 whitespace-nowrap text-sm text-gray-700">
                <div class="flex items-center">
                    <div class="h-8 w-8 rounded-full bg-indigo-100 flex items-center justify-center text-indigo-700 font-bold mr-3 border border-indigo-200">
                        ${student.name.charAt(0).toUpperCase()}
                    </div>
                    ${student.name}
                </div>
            </td>
            <td class="px-6 py-4 whitespace-nowrap text-sm text-gray-500">${student.email}</td>
            <td class="px-6 py-4 whitespace-nowrap text-sm text-gray-500">${student.age}</td>
            <td class="px-6 py-4 whitespace-nowrap text-sm text-gray-500">
                <span class="px-2 inline-flex text-xs leading-5 font-semibold rounded-full bg-green-100 text-green-800 border border-green-200">
                    ${student.course}
                </span>
            </td>
            <td class="px-6 py-4 whitespace-nowrap text-right text-sm font-medium">
                <button onclick="editStudent(${originalIndex})" class="text-indigo-600 hover:text-indigo-900 mr-3 transition-colors duration-200" title="Edit">
                    ${editIcon}
                </button>
                <button onclick="deleteStudent(${originalIndex})" class="text-red-600 hover:text-red-900 transition-colors duration-200" title="Delete">
                    ${trashIcon}
                </button>
            </td>
        `;
        studentsTableBody.appendChild(row);
    });
}

// Helpers
function saveData() {
    localStorage.setItem('students', JSON.stringify(students));
}

function updateStats() {
    totalCountElement.textContent = students.length;
}

function validateName(name) {
    const regex = /^[A-Za-z\s]+$/;
    return regex.test(name);
}

// Toast Notification
function showToast(message, type = 'success') {
    toastMessage.textContent = message;
    
    if (type === 'success') {
        toastIcon.innerHTML = checkIcon;
    } else {
        toastIcon.innerHTML = errorIcon;
    }

    toast.classList.remove('translate-y-20', 'opacity-0');
    
    setTimeout(() => {
        toast.classList.add('translate-y-20', 'opacity-0');
    }, 3000);
}
