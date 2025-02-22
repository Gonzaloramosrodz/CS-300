# CS 300 Final Project - Advising Assistance Program

## Overview
The Advising Assistance Program is a command-line application designed to help students at ABC University navigate course offerings and prerequisites. It allows users to:
- Load course data from a CSV file.
- View an alphanumeric list of all courses.
- Search for a specific course to see its details and prerequisites.

## Features
- **Load Data Structure:** Reads and stores course data from a CSV file.
- **Print Course List:** Displays all available courses in alphanumeric order.
- **Print Course:** Retrieves and displays information about a specific course, including prerequisites.
- **User-Friendly Menu:** Simple text-based interface for easy navigation.

## Installation
1. Clone this repository to your local machine:
   ```bash
   git clone <repository-url>
   ```
2. Open the project folder in your preferred IDE or text editor.
3. Compile the program using a C++ compiler.
   ```bash
   g++ -o AdvisingProgram FinaProject.cpp
   ```

## Usage
1. Run the compiled program:
   ```bash
   ./AdvisingProgram
   ```
2. Follow the on-screen menu prompts to:
   - Load course data
   - View available courses
   - Search for specific courses
   - Exit the program

## File Structure
- `FinaProject.cpp` - Main program file containing the logic for loading and displaying course data.
- `CS 300 ABCU_Advising_Program_Input.csv` - Input file containing course details (ensure correct path is set in `main`).

## Dependencies
- C++ Standard Library (`iostream`, `fstream`, `sstream`, `vector`, `map`, `algorithm`, `string`)
- Windows-specific directory functions (`direct.h` for `_getcwd()`)

## Notes
- The program is configured to read course data from:
  ```
  \\apporto.com\dfs\SNHU\Users\gonzaloramosr_snhu\Documents\CS 300 Final Project\FinaProject\Debug\CS 300 ABCU_Advising_Program_Input.csv
  ```
  Modify this path if using a different environment.
- Ensure the CSV file is correctly formatted:
  ```
  CourseNumber,CourseTitle,Prerequisite1,Prerequisite2,...
  ```

## Future Improvements
- Implement error handling for invalid file paths and input formats.
- Add support for saving user-selected courses.
- Enhance UI with a graphical interface.

## Author
Gonzalo Ramos

