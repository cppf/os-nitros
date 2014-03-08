nitros
======

A simple, easy to use OS for AVR microcontrollers.



### Design requirements

1.  Minimal simple, and yet a strong OS concept

2.  Ensure minimal RAM overhead (Flash overhead is a non-issue)

3.  Ensure proper event handling, and fast execution.

4.  Support driver installation and removel.

5.  No fifth requirement.

Non-preemtive task switching is a simple concept, and has low overhead. It
removes the randomness is execution, which can be a necessary evil in certain
types of embedded systems.



### Events

1.  Simple

2.  Easy to implement.

3.  Similar to interrupt.



### Tasks

1.  Foreground tasks.

2.  Non-preemtive.

3.  Require Synchronization



### Named Object

1.  Reduce module to module dependency

2.  Uses a hashing technique.






