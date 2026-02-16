/**
 * Expense Tracker Application Logic
 */

// DOM Elements
const form = document.getElementById('expense-form');
const list = document.getElementById('expense-list');
const totalExpensesEl = document.getElementById('total-expenses');
const headerBalanceEl = document.getElementById('header-balance');
const searchInput = document.getElementById('search');
const submitBtn = document.getElementById('submit-btn');
const cancelEditBtn = document.getElementById('cancel-edit');
const emptyState = document.getElementById('empty-state');
const resetBtn = document.getElementById('reset-btn');

// Toast Elements
const toast = document.getElementById('toast');
const toastTitle = document.getElementById('toast-title');
const toastMessage = document.getElementById('toast-message');
const toastIcon = document.getElementById('toast-icon');

// Icons map
const categoryIcons = {
  'Food': '🍔',
  'Transport': '🚗',
  'Utilities': '💡',
  'Entertainment': '🎬',
  'Health': '🏥',
  'Shopping': '🛍️',
  'Others': '📦'
};

const categoryColors = {
  'Food': 'bg-orange-500/20 text-orange-500',
  'Transport': 'bg-blue-500/20 text-blue-500',
  'Utilities': 'bg-yellow-500/20 text-yellow-500',
  'Entertainment': 'bg-purple-500/20 text-purple-500',
  'Health': 'bg-red-500/20 text-red-500',
  'Shopping': 'bg-pink-500/20 text-pink-500',
  'Others': 'bg-gray-500/20 text-gray-400'
};

// State
let transactions = JSON.parse(localStorage.getItem('transactions')) || [];
let editId = null;

// Init
document.addEventListener('DOMContentLoaded', () => {
  // Set default date to today
  document.getElementById('date').valueAsDate = new Date();
  updateUI();
});

// Event Listeners
form.addEventListener('submit', addTransaction);
searchInput.addEventListener('input', (e) => updateUI(e.target.value));
cancelEditBtn.addEventListener('click', exitEditMode);
resetBtn.addEventListener('click', () => {
  form.reset();
  document.getElementById('date').valueAsDate = new Date();
  exitEditMode();
});

// Add / Update Transaction
function addTransaction(e) {
  e.preventDefault();

  const text = document.getElementById('desc').value.trim();
  const amount = +document.getElementById('amount').value;
  const category = document.getElementById('category').value;
  const date = document.getElementById('date').value;

  if (!text || !amount || !category || !date) {
    showToast('Error', 'Please fill all fields correctly', 'error');
    return;
  }

  if (amount <= 0) {
    showToast('Error', 'Amount must be positive', 'error');
    return;
  }

  if (editId) {
    // Update existing
    const index = transactions.findIndex(t => t.id === editId);
    if (index !== -1) {
      transactions[index] = { id: editId, text, amount, category, date };
      showToast('Updated', 'Transaction updated successfully', 'success');
    }
    exitEditMode();
  } else {
    // Add new
    const transaction = {
      id: generateID(),
      text,
      amount,
      category,
      date
    };
    transactions.push(transaction);
    showToast('Added', 'Transaction added successfully', 'success');
  }

  saveToLocalStorage();
  updateUI();

  // Reset form but keep date as today if adding new
  if (!editId) {
    form.reset();
    document.getElementById('date').valueAsDate = new Date();
  }
}

// Generate ID
function generateID() {
  return Math.floor(Math.random() * 1000000000);
}

// Delete Transaction
function removeTransaction(id) {
  if (confirm('Delete this transaction?')) {
    transactions = transactions.filter(transaction => transaction.id !== id);

    // If getting deleted item was being edited, exit edit mode
    if (editId === id) {
      exitEditMode();
    }

    saveToLocalStorage();
    updateUI();
    showToast('Deleted', 'Transaction removed', 'success');
  }
}

// Prepare Edit
function editTransaction(id) {
  const transaction = transactions.find(t => t.id === id);
  if (!transaction) return;

  document.getElementById('edit-id').value = transaction.id;
  document.getElementById('desc').value = transaction.text;
  document.getElementById('amount').value = transaction.amount;
  document.getElementById('category').value = transaction.category;
  document.getElementById('date').value = transaction.date;

  editId = id;

  submitBtn.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
            <path d="M13.586 3.586a2 2 0 112.828 2.828l-.793.793-2.828-2.828.793-.793zM11.379 5.793L3 14.172V17h2.828l8.38-8.379-2.83-2.828z" />
        </svg>
        <span>Update Transaction</span>
    `;
  submitBtn.classList.remove('from-blue-600', 'to-blue-700');
  submitBtn.classList.add('from-emerald-600', 'to-emerald-700');

  cancelEditBtn.classList.remove('hidden');

  window.scrollTo({ top: 0, behavior: 'smooth' });
}

function exitEditMode() {
  editId = null;
  document.getElementById('edit-id').value = '';

  submitBtn.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
            <path fill-rule="evenodd" d="M10 3a1 1 0 011 1v5h5a1 1 0 110 2h-5v5a1 1 0 11-2 0v-5H4a1 1 0 110-2h5V4a1 1 0 011-1z" clip-rule="evenodd" />
        </svg>
        <span>Add Transaction</span>
    `;
  submitBtn.classList.add('from-blue-600', 'to-blue-700');
  submitBtn.classList.remove('from-emerald-600', 'to-emerald-700');

  cancelEditBtn.classList.add('hidden');
  form.reset();
  document.getElementById('date').valueAsDate = new Date();
}

// Update UI (Values & List)
function updateUI(searchTerm = '') {
  // Update Totals
  const amounts = transactions.map(t => t.amount);
  const total = amounts.reduce((acc, item) => (acc += item), 0).toFixed(2);

  totalExpensesEl.innerText = `$${total}`;
  headerBalanceEl.innerText = `$${total}`; // Assuming balance = total expenses for now, or could be (Budget - Expenses) if budget was dynamic

  // Render List
  list.innerHTML = '';

  const filtered = transactions.filter(t =>
    t.text.toLowerCase().includes(searchTerm.toLowerCase()) ||
    t.category.toLowerCase().includes(searchTerm.toLowerCase())
  );

  if (filtered.length === 0) {
    emptyState.classList.remove('hidden');
  } else {
    emptyState.classList.add('hidden');

    // Sort by date new -> old
    filtered.sort((a, b) => new Date(b.date) - new Date(a.date));

    filtered.forEach(t => {
      const item = document.createElement('div');
      item.className = 'bg-gray-900/50 hover:bg-black/40 border border-gray-700 rounded-xl p-4 flex items-center justify-between transition-all item-animate group';

      const icon = categoryIcons[t.category] || '📦';
      const colorClass = categoryColors[t.category] || categoryColors['Others'];

      item.innerHTML = `
                <div class="flex items-center gap-4">
                    <div class="h-12 w-12 rounded-full ${colorClass} flex items-center justify-center text-xl shadow-sm">
                        ${icon}
                    </div>
                    <div>
                        <h4 class="font-semibold text-white group-hover:text-brand transition-colors">${t.text}</h4>
                        <p class="text-xs text-gray-500">${formatDate(t.date)} • ${t.category}</p>
                    </div>
                </div>
                <div class="flex items-center gap-4">
                    <span class="font-bold text-white text-lg">-$${t.amount.toFixed(2)}</span>
                    <div class="flex gap-2 opacity-0 group-hover:opacity-100 transition-opacity">
                        <button onclick="editTransaction(${t.id})" class="p-2 bg-gray-800 hover:bg-gray-700 rounded-lg text-indigo-400 transition-colors" title="Edit">
                            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                <path d="M13.586 3.586a2 2 0 112.828 2.828l-.793.793-2.828-2.828.793-.793zM11.379 5.793L3 14.172V17h2.828l8.38-8.379-2.83-2.828z" />
                            </svg>
                        </button>
                        <button onclick="removeTransaction(${t.id})" class="p-2 bg-gray-800 hover:bg-red-900/30 rounded-lg text-red-500 transition-colors" title="Delete">
                            <svg xmlns="http://www.w3.org/2000/svg" class="h-4 w-4" viewBox="0 0 20 20" fill="currentColor">
                                <path fill-rule="evenodd" d="M9 2a1 1 0 00-.894.553L7.382 4H4a1 1 0 000 2v10a2 2 0 002 2h8a2 2 0 002-2V6a1 1 0 100-2h-3.382l-.724-1.447A1 1 0 0011 2H9zM7 8a1 1 0 012 0v6a1 1 0 11-2 0V8zm5-1a1 1 0 00-1 1v6a1 1 0 102 0V8a1 1 0 00-1-1z" clip-rule="evenodd" />
                            </svg>
                        </button>
                    </div>
                </div>
            `;
      list.appendChild(item);
    });
  }
}

// Local Storage
function saveToLocalStorage() {
  localStorage.setItem('transactions', JSON.stringify(transactions));
}

// Helpers
function formatDate(dateStr) {
  const options = { year: 'numeric', month: 'short', day: 'numeric' };
  return new Date(dateStr).toLocaleDateString('en-US', options);
}

function showToast(title, message, type) {
  toastTitle.innerText = title;
  toastMessage.innerText = message;

  const borderColor = type === 'success' ? 'border-brand' : 'border-red-500';
  toast.className = `fixed top-5 right-5 transform translate-y-0 opacity-100 transition-all duration-300 z-50 bg-gray-800 border-l-4 ${borderColor} text-white px-6 py-4 rounded shadow-2xl flex items-center gap-3 min-w-[300px]`;

  if (type === 'success') {
    toastIcon.innerHTML = `<svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-green-400" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M5 13l4 4L19 7" /></svg>`;
  } else {
    toastIcon.innerHTML = `<svg xmlns="http://www.w3.org/2000/svg" class="h-6 w-6 text-red-400" fill="none" viewBox="0 0 24 24" stroke="currentColor"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M6 18L18 6M6 6l12 12" /></svg>`;
  }

  setTimeout(() => {
    toast.classList.remove('translate-y-0', 'opacity-100');
    toast.classList.add('-translate-y-20', 'opacity-0');
  }, 3000);
}
