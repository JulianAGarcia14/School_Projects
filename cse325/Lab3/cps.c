// current process status
int
cps()
{
	struct proc *p;

	// Enable interrupts on this processor
	sti();

	// Loop over process table looking for process with pid
	acquire(&ptable.lock);
	cprintf("name \t pid \t state \t priority \n");
	for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){
		if(p->state == SLEEPING)
			cprintf("%s \t %d \t SLEEEPING \t %d \n", p->name, p->pid, p->priority);
		else if(p->state == RUNNING)
			cprintf("%s \t %d \t RUNNING \t %d \n", p->name, p->pid, p->priority);
		else if(p->state == RUNNABLE)
			cprintf("%s \t %d \t RUNNABLE \t %d \n", p->name, p->pid, p->priority);
	}

	release(&ptable.lock);

	return 22;
}
