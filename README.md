#  CS 300 – Data Analysis and Designs Portfolio Submission  

### Southern New Hampshire University  
**Course:** CS 300 – Data Analysis and Design
**Student:** Luis Tomassini  
**Projects Included:**  
- **Project One:** Runtime and Memory Analysis (Vector, Hash Table, Binary Search Tree)  
- **Project Two:** Working C++ Advising Assistance Program (BST implementation)  

---

##  Project Overview  

This course focused on designing and implementing an advising assistance program for the ABCU Computer Science department. The goal was to help academic advisors quickly access course information and prerequisites using efficient data structures.  

In **Project One**, I analyzed how different data structures performed in terms of runtime and memory use. In **Project Two**, I used C++ to build a working version of the program that stored and retrieved course data using a Binary Search Tree (BST). This structure made it possible to print the courses in alphanumeric order while keeping lookups fast and organized.

---

##  Problem and Approach  

The main problem I needed to solve was how to store and retrieve course data efficiently so advisors could view a full course list or search for a specific course. My approach focused on balancing search speed, memory use, and code simplicity.  

Understanding data structures is key to writing efficient programs. Each option—Vector, Hash Table, and BST—has strengths and weaknesses depending on the situation. After comparing their Big O performance, I found that a Binary Search Tree gave me the best mix of fast lookups and sorted output without needing an extra sort function.

---

##  Roadblocks and How I Solved Them  

One of the main issues I ran into was getting the file input to work smoothly. The CSV data needed to be parsed correctly, and I had to make sure prerequisites matched valid courses in the file. Another challenge came from PowerShell’s output buffering, which caused the menu text to appear blank when I first ran the program.  

To fix it, I added `cout.flush()` and re-tied the input/output streams to make sure everything displayed right away. I also added clear validation checks for file formatting and duplicates. These fixes made the program stable and user-friendly, which felt great after hours of debugging.

---

##  What I Learned About Software Design  

Working on this project changed the way I design programs. I learned to start with pseudocode and plan out logic before jumping into coding. That approach made it much easier to identify which data structure would fit the problem best.  

It also taught me how to think about scalability early on—how one choice in structure or algorithm can change performance dramatically. By designing with clarity and testing in small steps, I built a more reliable and readable program.

---

##  How My Coding Style Has Evolved  

Before this course, I focused mostly on getting programs to work. Now, I focus on *how* they work. I write code that’s organized, commented, and easy for others to read or improve later. Keeping all logic in one `.cpp` file helped me keep things simple but still structured.  

I’ve also started paying more attention to naming conventions, modular design, and consistent formatting. These details make a huge difference in readability and maintenance. The project ended up feeling like something that could actually be used in a real advising office, which was a big confidence boost.

---

##  Repository Contents  

- `ProjectTwo.cpp` — Final C++ source code (Binary Search Tree implementation)  
- `ABCU_Advising_Program_Input.csv` — Course input file  
- `Runtime_Analysis.pdf` — Project One runtime and memory comparison  
- `README.md` — Reflection and portfolio documentation (this file)  

---

##  Final Reflection  

This project helped me grow as both a programmer and a problem solver. It showed me how important it is to understand data structures and algorithms before writing a single line of code. I learned how to plan, debug, and refine my design so the end result was not only functional but efficient and maintainable.  

It was rewarding to see the program finally load, sort, and print every course exactly as expected. That moment tied together everything I learned in this course—from analyzing Big O performance to implementing a complete working solution.  

Overall, this experience gave me a stronger foundation for writing clean, adaptable, and professional-quality code that I can be proud to showcase in my portfolio.

---
