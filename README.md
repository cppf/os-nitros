nitros
=========

A simple, easy to use OS for AVR microcontrollers.


## Design requirements
1. Minimal simple, and yet a strong OS concept
1. Ensure minimal RAM overhead (Flash overhead is a non-issue)
1. Ensure proper event handling, and fast execution.
1. Support driver installation and removel.
1. No fifth requirement.

Non-preemtive task switching is a simple concept, and has low overhead. It removes the randomness is execution, which can be a necessary evil in certain types of embedded systems.

### Events
* Simple
* Easy to implement.
* Similar to interrupt.

### Tasks
* Foreground tasks
* Non-preemtive
* Require Synchronization


### Named Object
* Reduce module to module dependency
* Uses a hashing technique.



