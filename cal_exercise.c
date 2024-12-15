//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES];
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    while (1) {
    	if(fscanf(file, "%s %d", exercise_list[exercise_list_size].exercise_name, 
			&exercise_list[exercise_list_size].calories_burned_per_minute) == EOF) //Read and save exercise name and calories burned per minute
    	{
    		break;
		}
		exercise_list_size++;
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
    }
    fclose(file);
    
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
	/*
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
	for(i=1; i<7; i++)
	{
		printf("%d. %s (%d kcal burned per min.)\n", i, exercise_list.exercise_name[i-1], exercise_list.calories_burned_per_minute[i-1]); //print exercise list 
	}
	printf("7. Exit\n"); //option to escape
	printf("choose (1-7): "); //options

    // ToCode: to enter the exercise to be chosen with exit option
	scanf("%d", &choice); //scan the choice a user made
	if(i ==  7)
	{
		break;
	} // condition to exit 
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    strcpy(health_data.exercises[health_data.exercise_count].exercise_name, "%s", exercise_list.exercise_name[i-1]); //save data of exercise name to health data
	health_data.exercises[health_data.exercise_count].calories_burned_per_minute = duration*(exercise_list[i-1].calories_burned_per_minute); //save data of colories burned to health data
	*/
}

