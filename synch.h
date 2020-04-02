#ifndef _SYNCH_H_
#define _SYNCH_H_


#include <spinlock.h>


struct semaphore {
        char *sem_name;
	struct wchan *sem_wchan;
	struct spinlock sem_lock;
        volatile int sem_count;
};

struct semaphore *sem_create(const char *name, int initial_count);
void sem_destroy(struct semaphore *);


void P(struct semaphore *);
void V(struct semaphore *);



struct lock {
        char *lk_name;
        struct wchan *lk_wchan;
        struct spinlock lk_lock;
        volatile struct thread *lk_owner;
        volatile bool lk_held;
        
};

struct lock *lock_create(const char *name);
void lock_acquire(struct lock *);

/*
 * Operations:
 *    lock_acquire - Get the lock. Only one thread can hold the lock at the
 *                   same time.
 *    lock_release - Free the lock. Only the thread holding the lock may do
 *                   this.
 *    lock_do_i_hold - Return true if the current thread holds the lock; 
 *                   false otherwise.
 *
 * These operations must be atomic.
 */
void lock_release(struct lock *);
bool lock_do_i_hold(struct lock *);
void lock_destroy(struct lock *);

struct cv {
        char *cv_name;
        struct wchan *cv_wchan;
       
};

struct cv *cv_create(const char *name);
void cv_destroy(struct cv *);
void cv_wait(struct cv *cv, struct lock *lock);
void cv_signal(struct cv *cv, struct lock *lock);
void cv_broadcast(struct cv *cv, struct lock *lock);


#endif /* _SYNCH_H_ */
