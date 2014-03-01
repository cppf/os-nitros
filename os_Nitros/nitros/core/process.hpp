#ifndef _PROCESS_HPP_
#define _PROCESS_HPP_

// Status
#define process_ready		0
#define process_blocked		1
#define	process_running		2


typedef struct _process
{
	void*	Addr;
	void*	State;
}process;


#endif /* _PROCESS_HPP_ */