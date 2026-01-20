# 🔗 Pipex

## 📝 Description

**Pipex** is a project from **School 42**.  
The goal is to reproduce the behavior of shell pipelines using UNIX system calls.  
This project introduces process creation, inter-process communication, and file descriptor manipulation.

---

## 🎯 Objectives

- Understand UNIX processes
- Use `fork`, `pipe`, `dup2`, and `execve`
- Handle input/output redirections
- Manage multiple processes
- Write clean and norm-compliant C code (42 Norm)
- Handle errors properly

---

## 📌 Program Behavior

The program must reproduce the following shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

Equivalent execution:

```bash
./pipex infile "cmd1" "cmd2" outfile
```

---

### 🛠️ Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

Example:

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

Or check the file `test`

---

### ⚙️ How It Works

1. Open the input and output files
2. Create a pipe
3. Fork the process
4. Redirect input/output using dup2
5. Execute commands using execve
6. Wait for child processes to finish

---

### ⚙️ Compilation


```bash
make
```

Additional rules:

```bash
make clean
make fclean
make re
```

--- 

### 📐 Norm

- Fully compliant with the 42 Norm
- No forbidden functions used
- No memory leaks
- Proper error handling

---

### 👤 Author

42 Login: fmotte
School: 42

---

### ✅ Status

⭐ Project validated: 125 / 125 