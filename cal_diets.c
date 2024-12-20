//
//  cal_diets.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }
	
     // ToCode: to read a list of the diets from the given file
    while (fscanf(file, "%s %d", diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) != EOF) {
    	//Read food name and calories intake from diets.txt and save them to diet_list/ if it meets the end of the file, then it stops
    	diet_list_size++; //increase diet_list_size for next input
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* health_data) {
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for(i=0; i<diet_list_size; i++)
	{
		printf("%d. %s (%d kcal)\n", i+1, diet_list[i].food_name, diet_list[i].calories_intake); //print diet_list to screen
	}
	printf("7. Exit\n"); //suggest an option to escape this function
	printf("choose (1-7): "); //to make users choose one of the options
    
	// ToCode: to enter the diet to be chosen with exit option
    scanf("%d", &choice); //scan the choice that a user made
	if(choice == 7)
	{
		return; 
	} // condition to exit this function 
    // ToCode: to enter the selected diet in the health data
    strcpy(health_data->diet[health_data->diet_count].food_name, diet_list[choice-1].food_name); //save data of food name to health_data
    // ToCode: to enter the total calories intake in the health data
	health_data->diet[health_data->diet_count].calories_intake = diet_list[choice-1].calories_intake; //save data of calories  intake to health_data
	health_data->total_calories_intake = health_data->total_calories_intake + health_data->diet[health_data->diet_count].calories_intake; //save total calories intake to health_data
	health_data->diet_count++; //increase diet_count for next input
}

