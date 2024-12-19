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
    while (fscanf(file, "%s %d", exercise_list[exercise_list_size].exercise_name, &exercise_list[exercise_list_size].calories_burned_per_minute) != EOF) {
    	//Read exercise name and calories burned per minute from exercise.txt and save them to exercise_list/ if it meets the end of the file, then it stops
		exercise_list_size++; //increase exercise_list_size for next input
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

    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
	for(i=0; i<exercise_list_size; i++)
	{
		printf("%d. %s (%d kcal burned per min.)\n", i+1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute); //print exercise_list to screen
	}
	printf("7. Exit\n"); //suggest an option to escape this function
	printf("choose (1-7): "); //to make users choose one of the options

    // ToCode: to enter the exercise to be chosen with exit option
	scanf("%d", &choice); //scan the choice a user made
	if(choice ==  7)
	{
		return;
	} // condition to exit this function
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): "); 
    scanf("%d", &duration); //scan the duration of exercise

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    strcpy(health_data->exercises[health_data->exercise_count].exercise_name, exercise_list[choice-1].exercise_name); //save data of exercise name to health_data
	health_data->exercises[health_data->exercise_count].calories_burned_per_minute = duration*(exercise_list[choice-1].calories_burned_per_minute); //save data of calories burned(not per minute/don't confuse because of the name) to health_data
	health_data->total_calories_burned = health_data->total_calories_burned + health_data->exercises[health_data->exercise_count].calories_burned_per_minute; //save total calories burned to health_data
	health_data->exercise_count++; //increase exercise_count for next input
}

