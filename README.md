# EXPENSE TRACKER


###### This is a menu-driven Expense Tracker in C++ that helps users manage and analyze expenses across multiple accounts .The project is designed using Object-Oriented Programming and STL containers.


## ✨ Features

**📥 Add multiple expenses (same or different account IDs)**.  
**👀 View all expenses for a specific account**.  
**🔍 Filter expenses:**  
-By category   
-By amount range.  
**📑 View transactions category-wise.**  
**💾 Persistent storage using files (data remains after restarting the program)**.  
**♻️ Reset all stored data (in-memory and file)**



## 🧠 Concepts Used

**🧱 Object-Oriented Programming (Classes & Encapsulation).**  
**🏷 enum class for expense categories.**  
**📦 STL Containers:**   
-vector to store expenses.  
-unordered_map for account-wise expense tracking.  
**📂 File Handling:**   
-Save expenses to a file.  
-Load expenses on program start.  
**✅ Input validation (prevents invalid expenses)**


### ▶️ How It Works

**1. The program loads previously saved expenses from a file**.  
**2. A menu is displayed repeatedly to the user**.  
**3. The user selects an option-**.  
-Add expense.  
-View expenses.  
-Filter expenses.  
-View transactions.  
-Reset data   
-Exit.  
**4. Expenses are stored account-wise using an unordered_map**.  
**5. Any changes are saved to a file automatically**.  
**6. The program exits when the user chooses the exit option**.  


## 📁 File Structure


**expense.txt** — Stores all expense data persistently.  
**main.cpp** — Contains the complete implementation.


