# 🎓 University Admission System

A console-based University Admission System built in **C++** that simulates a real-world admission workflow using five core Data Structures. Each data structure is chosen for a specific purpose — not just for demonstration, but for logical, efficient operation.

> 📌 Built as a Data Structures course project — demonstrates practical application of DSA in a real-world system.

---

## 📸 Preview

<img width="539" height="295" alt="ProjectSS" src="https://github.com/user-attachments/assets/6804e226-3355-4ed9-8385-9600c26323c5" />



---

## 🔧 Data Structures Used

| Data Structure | Class | Purpose |
|---|---|---|
| Array-Based Queue | `ApplicationQueue` | FIFO processing of incoming applications |
| Singly Linked List | `AdmittedList` | Dynamic storage of admitted students |
| Linked List Queue | `WaitingQueue` | Waiting list when program seats are full |
| Binary Search Tree | `MeritBST` | Merit list sorted by marks (auto-sorted) |
| Graph (Adjacency Matrix) | `TransferGraph` | Department transfer rules & validation |

---

## ⚙️ System Features

- **Application Submission** — Students apply with ID, name, marks, and selected program
- **FIFO Processing** — Applications processed in first-come-first-serve order via queue
- **Merit-Based Seat Allocation** — BST maintains sorted merit list; seats assigned by availability
- **Waiting List** — Full programs place applicants in a dynamic waiting queue
- **Auto-Promotion** — When a seat frees up (via transfer), the first waiting applicant is auto-admitted
- **Department Transfers** — Graph validates allowed transfer paths between programs
- **Merit List Display** — View sorted merit list for all programs or a specific one
- **Color-Coded Console UI** — Color highlights for admitted, waiting, and error states

---

## 🏫 Programs Available

| Program | Seats |
|---|---|
| CS — Computer Science | 5 |
| IT — Information Technology | 5 |
| BBA — Business Administration | 5 |
| LAW | 5 |
| MEDICINE | 5 |

---

## 🔄 Allowed Department Transfers

```
CS  ↔  IT
CS  →  BBA
CS  →  LAW
MEDICINE  →  LAW
MEDICINE  →  BBA
```

---

## 📁 Project Structure

```
UniversityAdmissionSystem/
├── main.cpp                  # Entry point
├── SystemController.h/.cpp   # Central coordinator / menu handler
├── AdmissionManager.h/.cpp   # Core logic — connects all modules
├── ApplicationQueue.h/.cpp   # Array-based FIFO queue
├── AdmittedList.h/.cpp       # Linked list of admitted students
├── WaitingQueue.h/.cpp       # Linked list queue for waiting applicants
├── MeritBST.h/.cpp           # Binary Search Tree for merit list
├── TransferGraph.h/.cpp      # Graph for transfer validation
├── Applicant.h/.cpp          # Applicant data model
├── Application.h             # Wrapper for queue operations
├── Program.h/.cpp            # Program seat management
├── Node.h                    # Linked list node
├── TreeNode.h/.cpp           # BST node
├── ConsoleColor.h            # Console color utility
└── .gitignore
```

---

## ▶️ How to Run

### Requirements
- **Dev C++** (Recommended) or any C++ compiler (g++, MSVC)
- Windows OS (for console color support)

### Using Dev C++
1. Open Dev C++
2. `File → Open Project or File` → select `main.cpp`
3. Add all `.cpp` and `.h` files to the project
4. Press **F11** to compile and run

### Using g++ (Command Line)
```bash
g++ *.cpp -o admission_system
./admission_system
```

---

## 📊 Complexity Analysis

| Module | Operation | Time Complexity | Space Complexity |
|---|---|---|---|
| ApplicationQueue | Enqueue / Dequeue | O(1) | O(n) |
| MeritBST | Insert / Traversal | Avg O(log n) / Worst O(n) | O(n) |
| AdmittedList | Add / Remove | O(1) / O(n) | O(n) |
| WaitingQueue | Enqueue / Dequeue | O(1) / O(n) | O(n) |
| TransferGraph | Transfer Validation | O(1) | O(n²) |

---

## 💡 Key Design Principles

- **Modularity** — Each data structure is an independent class
- **Encapsulation** — Data and operations grouped within classes
- **Separation of Concerns** — Each module handles one responsibility
- **OOP** — Classes, constructors, destructors, dynamic memory management

---

## 🛠️ Built With

![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows%20Console-lightgrey?style=flat-square)
![IDE](https://img.shields.io/badge/IDE-Dev%20C++-blue?style=flat-square)

---

## 👩‍💻 Author

**Nayab Naeem**  
[GitHub](https://github.com/Nayab-Naeem) • [Portfolio](https://nayabnaeem.netlify.app)
