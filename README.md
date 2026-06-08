# Bank Management System (OOP Version) 🏦

A robust, enterprise-level console application built using Object-Oriented Programming (OOP) principles in C++. This updated version transitions from a single-file structural approach to a clean, modular, architecture utilizing distinct UI screen classes and encapsulated domain models. It features comprehensive client/user management and an integrated Currency Exchange system.

## 🌟 Key Features

* **Secure Authentication & Authorization:** Multi-user login system with granular, role-based system permissions.
* **Complete Client CRUD Operations:** Add, Update, Delete, and Find client accounts seamlessly.
* **Advanced Transaction Module:** Supports automated deposits, withdrawals, transfers between accounts, and real-time balance tracking.
* **Integrated Currency Exchange System:** * List available global currencies and official rates.
  * Update currency exchange rates dynamically.
  * Built-in Currency Calculator for instant conversions.
* **System Auditing:** Dedicated Login Register screen to track user sessions and timestamps.
* **File-Based Persistence:** Fully automated local storage using optimized flat files (`.txt`), eliminating the need for heavy external databases.

## 🔐 Default Credentials 

To log in and explore all administrative features and system permissions, use the following default credentials:
* **Username:** `Admin`
* **Password:** `1234`

## 🛠️ Architecture & Technologies

* **Language:** C++ (Standard 11/14/17)
* **Programming Paradigm:** Full Object-Oriented Programming (OOP) with clean encapsulation and inheritance for screen flows.
* **Architecture Pattern:** Modular UI Separation (Each subsystem/screen is isolated in its own header component).
* **Platform:** Windows (Optimized for Visual Studio)
* **Storage:** Local file-based text databases (`Clients.txt`, `Users.txt`, `Currencies.txt`).

### Project Components Matrix 📂
The project is built on top of strong reusable modules, including:
* `clsBankClient.h` & `clsUser.h`: Core business logic and data encapsulation templates.
* `clsInputValidate.h`: Robust, type-safe data entry validation layers.
* `clsCurrency.h` & `clsCurrencyExchangeScreen.h`: Monetary arithmetic and currency interaction logic.
* *UI Screens Hierarchy:* Isolated execution contexts for every platform module (e.g., `clsClientsListScreen.h`, `clsDeleteUserScreen.h`, `clsTransferScreen.h`).

## 🚀 How to Run

1. Clone or download the source files.
2. Open the project folder or source files inside **Visual Studio** or any C++ standard compliant IDE.
3. Ensure the text database files are in the designated execution or relative build directory.
4. Compile and run the main entry file.
5. Log in using the default credentials above to navigate through the interactive menus.
