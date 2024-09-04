# Crypto Encryption Project

This project demonstrates a simple file encryption process using C and a shell script. The project allows you to encrypt multiple files stored in a directory and save the encrypted files in a separate directory.

## Features

- **File Encryption:** Encrypts files using a simple XOR-based encryption algorithm.
- **Directory Management:** Automatically checks and manages the input (upload) and output (encrypted) directories.
- **Error Handling:** Provides robust error handling for missing directories, empty directories, and file access issues.

## Project Structure

```plaintext
crypto-encryption-project/
├── README.md           
├── LICENSE             
├── encrypt.c           
├── encrypt_files.sh    
├── upload/             
│   ├── example.txt    
├── encrypted/          # Directory where encrypted files are saved (created by script)
└── .gitignore
```
## Requirements

- **GCC :** To compile the C program.
- **Bash :** To run the shell script.

## Setup and Usage

   **1. Clone the Repository :**
      
  ```bash
  git clone https://github.com/techiuv/crypto-encryption-project.git
  cd crypto-encryption-project    
 ```
   **2. Compile the C Program :**

  ```bash
   gcc -o encrypt encrypt.c
  ```
   **3. Prepare Files for Encryption :**
      Place the files you want to encrypt into the `upload/ directory`.    Example file (`example.txt`) is already provided.

  **4. Run the Shell Script :**
     ```bash
     ./encrypt_files.sh
     ```
The script will:

Check if the `upload directory` exists and contains files.
Create the `encrypted directory` if it doesn’t exist.
Encrypt each file in the `upload directory` and save the `encrypted files` in the `encrypted directory`.
**5. Check Encrypted Files**
    After running the script, you can find the encrypted files in the encrypted/ directory.

**6. Customization**
You can change the encryption key by editing the ENCRYPTION_KEY variable in the `encrypt_files.sh` script.

## Error Handling 

The script and C program handle various errors, including:

- Missing or unreadable directories.
- Files that cannot be read or written.
- General encryption failures.

## License 
This project is licensed under the `MIT License`. You are free to use, modify, and distribute this software in your own projects.

## Contribution 
Contributions are welcome! Please fork this repository and submit a pull request with your changes.


## Explanation of Sections:

1. **Features:** Summarizes what the project does.
2. **Project Structure:** Shows how files and directories are organized.
3. **Requirements:** Lists the necessary software.
4. **Setup and Usage:** Provides step-by-step instructions on how to set up and use the project.
5. **Error Handling:** Briefly mentions how errors are managed.
6. **License:** Specifies the licensing terms.
7. **Contributions:** Invites others to contribute to the project.
8. **Contact:** Provides ways for users to get in touch or report issues.

This `README.md` file should provide all necessary information for users and contributors to understand and use your project effectively.




      
     
