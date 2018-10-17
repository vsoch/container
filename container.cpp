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


/**
    The jail is the process that will be called via the chroot, it is abstractly
    like a "jailed" process as it only "sees" the root of itself and below
    (but not really)
*/

int jail(void *) { 
    std::cout << "[child ] Hello Dinosaur!" << std::endl;
    run("/bin/sh");
    return 0;
}

int main() { 

    // Announce we are in the parent process
    std::cout << "[parent] Hello Dinosaur!" << std::endl;

    // Clone
    clone(jail, 0, SIGCHLD, 0);
    wait(NULL);
    std::cout << "[parent] Cloned process." << std::endl;
    return 0;
}
