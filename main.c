//
//  main.c
//  Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define EXERCISEFILEPATH "exercises.txt"
#define DIETFILEPATH "diets.txt"
#define HEALTHFILEPATH "health_data.txt"

static int choice;

int main() {
	// To initialize the health data object
    HealthData health_data = {0};
    
    // Tocode: to read the list of the exercises and diets
    loadDiets(DIETFILEPATH); //read diet.txt and save data to diet_list
    loadExercises(EXERCISEFILEPATH); //read exercise.txt and save data to exercise_list

    // ToCode: to run the "Healthcare Management Systems" until all calories are used up or the user wants to exit the system
    do {
    	if (health_data.total_calories_intake - BASAL_METABOLIC_RATE - health_data.total_calories_burned == 0/*calculate remaining calories*/){ //condition to check if total calories = 0 and if it's 0, then exit this program
            printf("You have consumed all your calories for today! \n"); //notice that he/her have consumed all his/her calories for today
            break; //exit this program
		} 
		else{
			printf("\n=======================================================================\n");
        	printf("[Healthcare Management Systems] \n");
        	printf("1. Exercise \n");
        	printf("2. Diet \n");
        	printf("3. Show logged information \n");
        	printf("4. Exit \n");
        	printf("Select the desired number: ");
        	scanf("%d", &choice);
        	printf("=======================================================================\n");
        }
        
		// ToCode: to run the sysmtem based on the user's choice
        switch (choice) {
            case 1:
            	inputExercise(&health_data); //save the chosen exercise and total calories burned to health_data
            	saveData(HEALTHFILEPATH, &health_data); //save data to health_data.txt
                break;
                
            case 2:
    			inputDiet(&health_data); // save the chosen diet and total calories intake to health_data
    			saveData(HEALTHFILEPATH, &health_data); //save data to health_data.txt
                break;
                
            case 3:
            	printHealthData(&health_data); //print history of food name, exercise name, each calories, total calories intake, total calories burned, remaining calories and recommendation to screen 
                break;
                
            case 4:
            	
    			printf("Exit the system.\n");
    			printf("=======================================================================\n");
                break;
                
            default:
                printf("[Error] Invalid option. \n");
                printf("Please try again! \n");
        }
    } while (choice != 4); //set condition to exit program if a user choice is 4

    return 0;
}

