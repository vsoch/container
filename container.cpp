/** 
   container.cpp
   -------------

   Attempting to make a leetle container. To understand what in the world is 
   going on :)

   @author
    - Vanessa Sochat

   @references
    - http://cesarvr.github.io/post/2018-05-22-create-containers/
    - http://man7.org/linux/man-pages/man2/clone.2.html

   @version
    - October 16, 2018

   @usage
      g++ container.cpp -o container
      ./container
*/


#include <iostream>
#include <stdlib.h>
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


// Function prototypes

int jail(void *);


// Function declarations


//we can call it like this: run("/bin/sh");
int run(const char *name) {
  char *_args[] = {(char *)name, (char *)0 };
  execvp(name, _args);
}


char* stack_memory() {

  const int stackSize = 65536;
  char *stack = new (std::nothrow) char[stackSize];

  if (stack == NULL) {
      std::cout << "Cannot allocate memory" << std::endl;
      exit(255);
  }  

  return stack+stackSize;    //move the pointer to the end of the array because the stack grows backward. 
}

/**
    The jail is the process that will be called via the chroot, it is abstractly
    like a "jailed" process as it only "sees" the root of itself and below
    (but not really)
*/

int jail(void *) { 
    std::cout << "[child ] Hello Dinosaur!" << std::endl;
    std::cout << "Child process " << getpid() << std::endl;
    run("/bin/sh");
    return 0;
}

int main() { 

    // Announce we are in the parent process
    std::cout << "[parent] Hello Dinosaur!" << std::endl;

    int pid; 

    // Clone
    pid = clone(jail, stack_memory(), SIGCHLD, 0);
    std::cout << "[parent] Cloning process." << std::endl;
    wait(NULL);
    std::cout << "[parent] Process Exit." << std::endl;
    return 0;
}
