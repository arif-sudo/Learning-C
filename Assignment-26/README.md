## Assignment
Now that we've successfully used syscalls and we know how to parse arguments with some research, let's move onto something a little bit more complicated but still very doable. We're going to create a C program that binds a command shell to a listening port, also known as a bind shell. (in TCP!)

I'm going to tell you the syscalls we need to make in order to accomplish this and also try and drop some hints about potential sticking points. I won't be fully walking through this one like our previous excercise, but as always there will be a solution made available should you get stuck (`assignment26.c`). 

A good resource throughout this excercise will be the socket programming tutorial here: http://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html

## Getting Started

### Header Files
We're going to need to include the following header files:
```c
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
```

Pull these header files up and read through them, learn what they're for and why we need them. You should be finding man pages for all of these syscalls and reading about their parameters and finding their definitions. 

## Syscalls

### Socket()
The first syscall we're going to make is `socket()`. The explanation for socket is not very difficult, you can do this! Make sure you pay attention to the return value, this value will be needed for subsequent syscalls. 

### Bind()
The next syscall will be `bind()`. This one is a bit of a doozie so I will help you with this one. We first need to build a struct which we're used to. The struct definition we'll be using is the one for `sockaddr_in`. This is because `bind()` takes an argument that is a pointer to a struct of type `sockaddr`; however, we actually use `sockaddr_in` as our struct type because they are the same size and according to the manpage for bind, "the only purpose of \[the sockaddr structure\] is to cast the structure pointer passed in addr in order to avoid compiler warnings."

We first need to create an instace of the `sockaddr_in` struct called `server_addr` as this code will be run on the server in a client-server paradigm of network connections:
```c
struct sockaddr_in server_addr;
```
Next, we need to start assigning values to the members of this struct. The relevant members for us are:
+ `sin_family`,
+ `sin_port`, and
+ `sin_addr`. 

`sin_family`, if we read the manpages **like we always do**, can take values defined inside of `<sys/socket.h>`. We're interested in creating a TCP bind shell, so we'll need to use the `AF_INET` value for this struct member as it's for 'internetwork: UDP, TCP, etc' addresses families. So we can give this a value with our dot notation we learned with: `server_adder.sin_family = AF_INET;`. Easy! We've done that a bunch already.

Next, we need to set `sin_addr`. The `sin_addr` member is actually of type `struct in_addr` which is also defined in `<netinet/in.h>`. The struct `in_addr` contains only one member, an unsigned long `s_addr`. So we'll need to double up our dot notation for this one since we're creating a value for a member that is a struct of another struct. (We did this already as well.) 



 