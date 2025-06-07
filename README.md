# 🔐 C++ Password Generator & Strength Checker

A simple yet effective command-line utility written in C++ that generates secure passwords and evaluates their strength based on character diversity and length.

---

## 📌 Features

- 🧠 Intelligent password generation with:
  - Uppercase letters
  - Lowercase letters
  - Digits
  - Special characters
- ✅ Password strength checker
  - Categorizes as **Weak**, **Moderate**, or **Strong**
- 🔄 Ensures at least one of each type for better security
- 🖥️ Cross-platform (Windows, Linux, macOS)

---

## 📷 Sample Output
==== Password Generator and Strength Checker ====
Enter desired password length (min 4): 12

Generated Password: X$1uFd0@Ea2r

Password Strength: Strong


---

## 🛠️ Tech Stack

- Language: **C++**
- Compiler: `g++`, `clang++`, or any C++11+ compatible compiler
- No external dependencies

---

## 🚀 Getting Started

### 🔧 Requirements

- A C++ compiler (e.g., MinGW, g++, clang++)
- Git (for version control)

### 💻 How to Compile and Run (Windows)

Open **Git Bash** or **Command Prompt**:

g++ strong_password_generator.cpp -o password.exe

./password.exe

On Linux/macOS:

g++ strong_password_generator.cpp -o password

./password

🧠 Password Strength Criteria

Strength	Requirements

Strong	  ≥ 12 characters with upper, lower, digit, symbol

Moderate	≥ 8 characters with upper, lower, digit

Weak	    Anything else

📄 License

This project is open-source and available under the MIT License.

👤 Author

Joseph Fernandes (JJF🙂)

GitHub: @josephjonathanfernandes

💬 Feedback & Contributions

Pull requests and stars are always welcome!

Feel free to open issues if you encounter bugs or want features.
