_This project has been created as part of the 42 curriculum by timtan._

# Minitalk

## Description

**Minitalk** is a data exchange project built to establish communication between a client and a server using only UNIX signals.

The primary goal of this project is to deepen the understanding of Inter-Process Communication (IPC) by restricting communication to just two signals: `SIGUSR1` and `SIGUSR2`. Since these signals cannot carry data payloads themselves, the project requires the implementation of a custom protocol to transmit strings bit-by-bit.

**Key features and learning outcomes:**
* **Signal Handling:** Utilizing `sigaction` to capture signals and inspect `siginfo_t` to identify the sender's PID.
* **Bitwise Operations:** Decomposing characters into binary (0s and 1s) for transmission and reconstructing them on the receiving end.
* **Process Synchronization:** Using `pause()` to efficiently wait for signals without consuming CPU, and `sleep()`/`usleep()` to manage timing between signals.
* **Global Variables:** Managing state (current bit, current character) within signal handlers where standard argument passing is not possible.

## Instructions

### Compilation
To compile the project, clone the repository and run the `Makefile` at the root:

```
make
```

### Execution
1. Start the Server Run the server first. It will print its Process ID (PID) and wait for incoming signals.

```
./server
```

Example Output:
```
PID: 4242
```

2. Run the Client Open a new terminal window. execute the client with the Server's PID and the string you wish to send.

```
./client 4242 "Hello, 42!"
```
The server should print "Hello, 42!" and the client should exit gracefully after the message is sent.

### Cleanup
To remove object files and executables:

```
make fclean
```

## Resources

### References
**UNIX Manuals:**

man sigaction: For detailed behavior of signal handling structs.

man signal: Overview of signal management.

man pause: For understanding how to suspend the process until a signal arrives.

man getpid: To understand process identification.

**Bitwise Operations:**

Bitwise Operators in C - Wikipedia overview of bit manipulation.

### AI Usage
This project utilized Artificial Intelligence tools for the following tasks:

**Documentation:** Used an LLM (Large Language Model) to generate the structure and content of this README.md file.

**Concept Explanation:** Used AI to explain the differences between signal() and sigaction() to better understand why sigaction is preferred for this project.
