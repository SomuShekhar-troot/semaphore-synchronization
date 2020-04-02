#ifndef _SYNCHPROBS_H_
#define _SYNCHPROBS_H_


enum Directions
  { 
    north = 0,
    east = 1,
    south = 2,
    west = 3
  };
typedef enum Directions Direction;


struct carList {

	Direction origin;
	Direction destination;
    struct carList *Next;
};



void intersection_sync_init(void);
void intersection_sync_cleanup(void);
void intersection_before_entry(Direction origin, Direction destination);
void intersection_after_exit(Direction origin, Direction destination);
void print_state_on(void);
void print_state_off(void);

#endif /* _SYNCHPROBS_H_ */
