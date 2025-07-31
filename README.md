# 🔄 Pipex

This project aims to recreate the functionality of shell pipes (`|`) in C. It handles the redirection of standard input and output between multiple processes, similar to how the shell processes the command `< infile cmd1 | cmd2 > outfile`.

---
> 🚧 **Status:** In Progress

## ⭐ Features
This project aims to recreate the functionality of shell pipes (`|`) in C. It handles the redirection of standard input and output between multiple processes, similar to how the shell processes the command `< infile cmd1 | cmd2 > outfile`.

## Features

- Handles input/output redirection
- Executes commands in separate processes
- Manages pipe communication between processes
- Proper error handling and memory management
- Environment variable path resolution for commands

## 🛠️ Installation

```bash
git clone https://github.com/Ertugrul-Pakdamar/42_ring2_pipex.git
cd pipex
make
```

## 📖 Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

### Example:

```bash
./pipex infile "ls -l" "wc -l" outfile
```
This is equivalent to: `< infile ls -l | wc -l > outfile`

## 📁 Project Structure

```
.
├── ft_main.c          # Main program entry
├── includes/          # Header files
├── libft/            # Core utility functions
├── ft_printf/        # Printf implementation
├── get_next_line/    # File reading utilities
└── srcs/             # Source files
    ├── ft_free_funcs.c    # Memory management
    ├── ft_init_env.c      # Environment setup
    ├── ft_pipex.c         # Core pipe functionality
    └── ft_validations.c   # Input validation
```

## ⚠️ Error Handling

The program handles various error cases:
- Invalid number of arguments
- File permission issues
- Command not found
- Memory allocation failures
- Pipe creation errors
- Fork failures

## 🔧 Technical Details

- Uses Unix system calls: pipe(), fork(), dup2(), execve()
- Implements proper memory management
- Handles environment variables
- Process creation and management
- File descriptor manipulation

## 🏗️ Building

The project includes a Makefile with the following rules:
- `make`: Compiles the project
- `make clean`: Removes object files
- `make fclean`: Removes object files and executable
- `make re`: Rebuilds the project from scratch
