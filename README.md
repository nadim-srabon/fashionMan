# Fashion Management System

## 📌 Overview
The **Fashion Management System** is a C-based project that efficiently manages fashion products, customers, orders, and wishlists using core data structures like **Binary Search Trees, Linked Lists, Queues, and Stacks**.

This project enables **product management, customer handling, order processing, and wishlist functionalities** through a menu-driven interface.

---

## 🔧 Features

✔ **Product Management**
- Add products (stored in a **Binary Search Tree** for efficient sorting)
- Display sorted products (In-order traversal)
- Update stock (optional)
- Delete/search product (optional improvement)

✔ **Customer Management**
- Add customers (stored in a **Singly Linked List**)
- Display customer list
- Search customer (optional improvement)

✔ **Order Processing**
- Orders placed in **Queue (FIFO)**
- Orders processed in order received
- View pending orders

✔ **Wishlist System**
- Uses **Stack (LIFO)**
- Adds favorite products
- Views wishlist (recent first)

---

## 🏗 Data Structures Used

| Feature               | Data Structure         | Description |
|----------------------|----------------------|-------------|
| **Product Management** | Binary Search Tree  | Allows sorted product insertion & retrieval |
| **Customer Management** | Singly Linked List  | Manages customer records dynamically |
| **Order Processing** | Queue (FIFO)  | Ensures first-come-first-serve processing |
| **Wishlist System** | Stack (LIFO)  | Displays most recently added item first |

---

## 🚀 How to Run

### **Prerequisites**
Ensure you have:
- A C compiler (GCC, Clang, etc.)
- Basic knowledge of terminal commands

### **Compilation & Execution**
```sh
gcc main.c -o fashion_system
./fashion_system
