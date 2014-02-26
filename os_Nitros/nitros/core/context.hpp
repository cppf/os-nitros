#ifndef _CORE_CONTEXT_HPP_
#define _CORE_CONTEXT_HPP_

uint context_RtosStack;
uint context_TaskStack;

void context_Save(void);
void context_Save(void)
{
	assembly(
	line("push r0")
	line("in r0, __SREG__")
	line("push r0")
	line("push r1")
	line("push r2")
	line("push r3")
	line("push r4")
	line("push r5")
	line("push r6")
	line("push r7")
	line("push r8")
	line("push r9")
	line("push r10")
	line("push r11")
	line("push r12")
	line("push r13")
	line("push r14")
	line("push r15")
	line("push r16")
	line("push r17")
	line("push r18")
	line("push r19")
	line("push r20")
	line("push r21")
	line("push r22")
	line("push r23")
	line("push r24")
	line("push r25")
	line("push r26")
	line("push r27")
	line("push r28")
	line("push r29")
	line("push r30")
	line("push r31")
	);
	context_TaskStack = SP;
	SP = context_RtosStack;
}


void context_Load(void);
void context_Load(void)
{
	context_RtosStack = SP;
	SP = context_TaskStack;
	assembly(
	line("pop r31")
	line("pop r30")
	line("pop r29")
	line("pop r28")
	line("pop r27")
	line("pop r26")
	line("pop r25")
	line("pop r24")
	line("pop r23")
	line("pop r22")
	line("pop r21")
	line("pop r20")
	line("pop r19")
	line("pop r18")
	line("pop r17")
	line("pop r16")
	line("pop r15")
	line("pop r14")
	line("pop r13")
	line("pop r12")
	line("pop r11")
	line("pop r10")
	line("pop r9")
	line("pop r8")
	line("pop r7")
	line("pop r6")
	line("pop r5")
	line("pop r4")
	line("pop r3")
	line("pop r2")
	line("pop r1")
	line("pop r0")
	line("out __SREG__, r0")
	line("pop r0")
	);
}


#endif /* _CORE_CONTEXT_HPP_ */