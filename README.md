# todolist
# To-Do List Console Application

A simple console-based task management system written in C++ to help users efficiently manage their daily tasks. This application allows users to add, view, update, and delete tasks with associated metadata like deadlines and priority levels.

## Features

* Add new tasks with a name, deadline, and priority
* View all tasks or filter by incomplete tasks or priority
* Mark tasks as complete
* Update task details (name, deadline, priority)
* Delete tasks from the list
* User-friendly menu with categorized sections for ease of navigation

## Technologies Used

* **Language:** C++
* **Library:** Standard C++ Library (including `<iostream>`, `<string>`, and optionally `<ctime>` for date handling)

## Project Structure

```
main.cpp             # Main program file containing class definitions and menu logic
```

## How to Run

1. Compile the code using a C++ compiler (e.g. `g++`).

   ```sh
   g++ -o todo_app main.cpp
   ```

2. Run the executable:

   ```sh
   ./todo_app   # On Unix/Linux/macOS
   todo_app.exe # On Windows
   ```

## Future Improvements

* Support for saving and loading tasks from files (using file I/O)
* GUI integration for a more interactive experience
* Sorting tasks by priority or deadline
* Deadline input using proper `ctime`-based date structures

## Author

Developed by Faeyzar Ahnaf Musyarri

---

Feel free to modify and improve the project as you learn more about C++ and software development!

