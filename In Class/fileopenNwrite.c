/*

Show a file read and write operating system simple c program 
using linux read() write() apis. use open() and write() for the 
smae file
ChatGPT
Certainly! Below is a simple C program that demonstrates file read 
and write operations using the open() and write() system calls 
for the same file:

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
  int file_fd;
  char buffer[BUFFER_SIZE];
  
  // Open or create the file
  file_fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

  // Write content to the file
  const char* content = "Hello, this is demo using write() system call.\n";
  write(file_fd, content, strlen(content));
  
  // Close the file
  close(file_fd);
  
  printf("Content written to file successfully.\n");
  return EXIT_SUCCESS;
}
/*
int main() {
    int file_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_written;

    // Open or create the file
    file_fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd == -1) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Write content to the file
    const char* content = "Hello, this is some content written using write() system call.\n";
    bytes_written = write(file_fd, content, strlen(content));
    if (bytes_written == -1) {
        perror("Error writing to file");
        close(file_fd);
        return EXIT_FAILURE;
    }

    // Close the file
    close(file_fd);

    printf("Content written to file successfully.\n");
    return EXIT_SUCCESS;
}
*/
/*
gcc your_code.c -o your_executable
./your_executable

This program does the following:

Opens or creates a file named "file.txt" for writing using open() 
with flags O_WRONLY, O_CREAT, and O_TRUNC. 
If the file exists, its content will be truncated.

Writes the content to the file using the write() system call.
Closes the file using close().
This example writes the content directly to the file 
using the write() system call without reading from any other source file.

how to get trace of system calls:
sudo apt-get install strace
strace ./your_executable

how do I get memory info about the above code
ps aux | grep your_executable

how can I see the pages of the above code
1. Find the Process ID (PID):
ps aux | grep your_executable

2. Once you have the PID, you can use the pmap command 
to see the memory pages used by your program
Run the following command, replacing PID with 
the process ID you found in step 1:
pmap -x PID

This command will display detailed information about the memory pages used 
by your program, including the address range, 
permissions, and mapped files or libraries.

How do I see file system information of above code
To see file system information related to your program, 
you can use the stat command in Linux
stat your_executable

  File: your_executable
  Size: 4096       	Blocks: 8          IO Block: 4096   regular file
Device: 801h/2049d	Inode: 28836363    Links: 1
Access: (0755/-rwxr-xr-x)  Uid: ( 1000/  user)   Gid: ( 1000/  user)
Access: 2024-03-28 10:00:00.000000000 +0000
Modify: 2024-03-28 10:00:00.000000000 +0000
Change: 2024-03-28 10:00:00.000000000 +0000
 Birth: -
 In this output, you can see various information about the file, such as its size,
 permissions (-rwxr-xr-x), 
 inode number, timestamps (access, modify, change), and more.

 Also try the following
 strace cat hello.txt

*/
