CS 300 – Data Structures and Algorithms Portfolio Submission
Southern New Hampshire University

Course: CS 300 – Data Structures and Algorithms
Student: Luis Tomassini
Project Components:

Project One: Runtime and Memory Analysis (Vector, Hash Table, Binary Search Tree)

Project Two: Working C++ Advising Assistance Program (BST implementation)

Project Overview

The goal of this course was to design and implement an advising assistance program for the ABCU Computer Science department. The program helps academic advisors quickly retrieve course information and prerequisites from a structured dataset.

In Project One, I analyzed how different data structures (Vector, Hash Table, and Binary Search Tree) perform in terms of runtime and memory efficiency. In Project Two, I implemented the program in C++ using a Binary Search Tree, which provided efficient course lookups and naturally ordered course listings. Together, these projects demonstrate practical understanding of algorithmic design, data structure selection, and software maintainability.

Problem and Approach

The main problem I solved was how to efficiently store and retrieve course information so advisors could view a full course list or quickly find details about a specific course. My approach centered on selecting a data structure that balances lookup speed, sorted traversal, and memory efficiency.

Understanding data structures is crucial because the way data is stored directly impacts how fast and flexible a program can be. By comparing runtime complexities (O(n), O(log n), and O(1)), I was able to justify why a Binary Search Tree was ideal for this program, offering fast searches while maintaining alphanumeric order without needing a separate sorting pass.

Roadblocks and Solutions

A key roadblock was ensuring consistent file input handling and correctly parsing comma-separated course data. Initially, output buffering in Windows PowerShell also caused the menu text to appear blank. I resolved these issues by adding flush commands to synchronize input and output streams and by applying detailed file validation checks to handle malformed or duplicate data lines gracefully.

These debugging experiences reinforced the importance of testing in multiple environments and building defensive code that anticipates user and system variability.

Impact on My Software Design Process

Working on this project expanded how I think about program design. Instead of jumping straight into code, I began with pseudocode and runtime analysis, which clarified my logic and made implementation smoother. I now appreciate the value of separating conceptual design from actual coding, especially when comparing how each data structure affects performance and scalability.

I also learned to prioritize clarity, consistency, and modularity by building each function with a clear, single responsibility. This approach made it easier to maintain and test each part of the program independently.

Evolution in Writing Maintainable, Readable, and Adaptable Code

Through iterative design and testing, I developed habits that improve code maintainability and readability. I used descriptive variable names, in-line comments, and consistent formatting. By keeping all logic in one self-contained .cpp file, I ensured simplicity while maintaining extensibility so future developers can easily adapt the program to use other data structures such as hash maps or balanced BSTs.

This project also reinforced the importance of producing user-friendly interfaces. The final version mirrors industry-standard practices, including clear prompts, error handling, and logical flow. These elements all contribute to a professional, maintainable codebase.

Repository Contents

ProjectTwo.cpp – Final working C++ program (BST implementation)

ABCU_Advising_Program_Input.csv – Input data file

Runtime_Analysis.pdf – Analysis from Project One (O(n), O(log n), and O(1) comparison)

README.md – Reflection and documentation (this file)

Summary

This project deepened my understanding of how data structures shape software efficiency and usability. It strengthened my ability to design with scalability in mind, debug in diverse environments, and write code that is both readable and adaptable. These are skills that directly apply to professional software development.
