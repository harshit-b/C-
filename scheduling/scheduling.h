/* scheduling.h
 *
 * abstract data type crew
 * abstract data type maintenance
 *
 * Type planet_t has these components:
 * int number, int skill, int cost_hour, int hours, int num, int id[AIRCRAFT_IDS]
 *
 * Operators:
 * scan_crew, check_lowest_crew, check_schedule_crew, scan_maintenance, crew_hours
 */
 
// AUTHOR: Harshit Bhargava
// FILENAME: scheduling.h
// SPECIFICATION: header file for personal library scheduling.c
// FOR: CS 1412 Programming Principles II Section 002

#define AIRCRAFT_IDS 8

typedef struct { /* crew structure */
	int number;
	int skill;
	int cost_hour;
	int hours;
	int num;
	int id[AIRCRAFT_IDS];
} crew_t;

typedef struct {
    int aircraft_id;
	int level;
	int hours;
} maintenance_t;

/*
* Displays with labels all components of a crew_t structure
*/
extern void
print_crew(crew_t crew[], int total_crew); /* input - one crew structure*/

/*
* Displays with labels all components of a crew_t structure
*/

extern void
print_maintenance(maintenance_t maintenance[], int total_crew); /* input - one crew structure */
/*
* Checks maintenance level required against the crew abilities and returns the number of the lowest-cost
* crew that can perform the maintenance. 
*/
extern int
check_lowest_crew(maintenance_t maintenance); /* input - maintenance*/

/*
* checks the maintenance level required against the crew abilities and current schedule and returns the
* number of the qualified crew that will be free to perform the maintenance at the earliest time. If more than one crew
* satisfies the function’s constraints, the number of the lowest-cost qualified crew is returned
*/
extern int
check_schedule_crew(maintenance_t maintenance, crew_t *crew); /* input - maintenance*/


/*
* Fills a type maintenence_t structure with input data. Integer returned as
* function result is success/failure/EOF indicator.
* 1 => successful input of planet
* 0 => error encountered
* EOF => insufficient data before end of file
* In case of error or EOF, value of type maintenance_t output argument is
* undefined.
*/
extern void
scan_maintenance(maintenance_t *maintenance, int number_maintenance); /* output - address of planet_t structure to fill */

/*
* Fills a type crew_t structure with input data. Integer returned as
* function result is success/failure/EOF indicator.
* 1 => successful input of planet
* 0 => error encountered
* EOF => insufficient data before end of file
* In case of error or EOF, value of type maintenance_t output argument is
* undefined.
*/
extern void
scan_crew(crew_t *crew, int total_crew); /* output - address of crew_t structure to fill */