/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file - stats.c 
 * @brief - This application performs statistical analytics on a dataset such as:
 *  - Minimum
 *  - Maximum
 *  - Mean 
 *  - Median. 
 *
 * @description - Main has a defined dataset as an array of 40 characters, array will sorted 
 * in a descending order in order to perform analytical functions. After statistics 
 * are calculated results are printed through print_array and print_statistics functions 
 *
 * @author <Juan Orlando Guzman Centeno>
 * @date <October 17 2023 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
	int median, mean, maximum, minimum;

  /* Statistics and Printing Functions Go Here */
	sort_array(test, SIZE);
	median = find_median(test, SIZE);
	mean = find_mean(test, SIZE);
	maximum = find_maximum(test, SIZE);
       	minimum = find_minimum(test, SIZE);	
	print_array(test, SIZE);
	print_statistics(minimum, maximum, mean, median);

}

int find_median(unsigned char *ptr, int array_length){
	int median_value = 0;
	unsigned char position_x, position_y;
	//if array size is pair, position resulted from division 
	if(ptr == NULL){
		return 0;
	}
	if((array_length % 2) == 0){
		position_y = array_length / 2;
		position_x = position_y - 1;
		median_value = ((ptr[position_x]) + (ptr[position_y])) / 2; 		
	}
	else{
		median_value = (ptr[(array_length / 2)]);
	}
	return median_value;
}

int find_mean(unsigned char *ptr, int array_length){
	int mean_value = 0, sum_value = 0;
	if(ptr == NULL){
		return 0;
	}
	for(int i = 0; i < array_length ; i++){
		sum_value += ptr[i]; 
	}
	mean_value = sum_value / array_length;
	return mean_value;
		
}

int find_maximum(unsigned char *ptr, int array_length){
	return ptr[0];
}

int find_minimum(unsigned char *ptr, int array_length){
	return ptr[39];
}

unsigned char sort_array(unsigned char *ptr, int array_length){
	unsigned char temp;
	for(int i = 0; i < array_length; i++){
		for(int j = i + 1 ; j < array_length ; j++){
			if(ptr[i] < ptr[j]){
				temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}	
		}

	}
}

void print_statistics(int minimum, int maximum, int mean, int median){
	printf("\nStatistical analytics on a dataset \n");
	printf(" \n");
	printf("Minimum value of dataset: %d \n", minimum);
	printf("Maximum value of dataset: %d \n", maximum);
	printf("Mean value of dataset: %d \n", mean);
	printf("Median value of dataset: %d \n", median);
	printf("\n\n");
}

void print_array(unsigned char *ptr, int array_length){
	printf("Descending order dataset \n");
	
	for(int i = 0 ; i < SIZE ; i++){
		if(i % 8 == 0){
			printf("\n");
		}
		if(i < 39){
			printf("%d, ",ptr[i]);
		}
		else{
			printf("%d \n", ptr[i]);
		}
	}

}
