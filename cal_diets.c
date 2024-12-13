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
    int i = 0;
    while (i < 6) {
    	fgets(diet_list[i].food_name, MAX_FOOD_NAME_LEN, file); //Read and save food name
		fscanf(file,"%d\n",diet_list[i].calories_intake);  //Read and save calories intake
    	i++;
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
    for(i=1; i<7; i++)
	{
		printf("%d. %s (%d kcal)\n", i, diet_list[i-1].food_name, diet_list[i-1].calories_intake); //print diet list 
	}
	printf("7. Exit\n"); //option to escape
	printf("choose (1-7): "); //options
    
	// ToCode: to enter the diet to be chosen with exit option
    scanf("%d", &choice); //scan the choice a user made
	if(i ==  7)
	{
		break;
	} // condition to exit 
    // ToCode: to enter the selected diet in the health data
    strcpy(health_data.diet[health_data.diet_count].food_name, "%s", diet_list[i-1].food_name); //save data of food name to health data
    // ToCode: to enter the total calories intake in the health data
	health_data.diet[health_data.diet_count].calories_intake = diet_list[i-1].calories_intake; //save data of calories  intake to health data
}

