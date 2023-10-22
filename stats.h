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
 * @file stats.h>
 * @brief Includes declarations and documentation for functions from stats.c file
 *
 * Declaration of functions that will analyze an array of char data items as a data set
 * and report analytics:
 * 	Maximum 
 * 	Minimum 
 * 	Mean 
 * 	Median 
 * 	Reorder data set from large to small 
 * 	Print all statistics
 * 	Print array
 * 
 * 	ALL STATISTICS SHOULD BE ROUNDED DOWN TO THE NEAREST INTEGER
 * 
 * @author <Juan Orlando Guzman Centeno>
 * @date <October 17 2023 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Given an array of data and a length, returns the median.
 *
 * This functon takes a descending ordered unsigned char array of n 
 * length and will  determine the median value of the array. 
 * If length of array is odd, the median is the middle value.
 * If length of array is even, the median is the result of the sum of
 * the two middle values divided by 2.
 *
 * @param unsigned char array_dataset[] - Ordered array to determine median 
 * @param unsigned char array_length - Length of array_dataset
 * 
 * @return int median_value
 *
 */

int find_median(unsigned char array_dataset[], unsigned char array_length);

/**
 * @brief Given an array of data and a length, returns the mean
 *
 * This function takes an array of n length and determine the mean by
 * summing all the values in the array and dividing by the length of the 
 * array.
 *
 * @param unsigned array_dataset[] - Array of data mean will be calculated
 * @param unsigned array_length - Length of array_dataset
 *
 * @return int mean_value - Result from the average of array_dataset values
 */
 
int mean(unsigned char array_dataset[], unsigned char array_length);


/**
 * @brief Given an array of data and a length, return the maximum
 *
 * This function takes an array of n length and validates which is the maximum value
 * by comparing each value in the array, storing the highest between both values, looping
 * until ending the array. 
 *
 * @param unsigned array_dataset[] - Array of data to determine maximum value
 * @param unsigned array_length - Length of array_dataset
 *
 * @return int maximum_value
 */

int find_maximum(unsigned char array_dataset[], unsigned char array_length);



/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * This function takes an array of n length and loops from the beginning to 
 * end comparing each value in the array, storing the smallest values between 
 * two values.
 *
 * @param unsigned array_dataset[] - Array of data to determine minimum value
 * @param unsigned array_length - Length array_dataset
 *
 * @return int minimum_value
 *
 */

int find_minimum(unsigned char array_dataset[], unsigned char array_length);


/**
 * @brief Given an array of data and a length, sorts the array from largest 
 * to smallest. Array[0] being the largest value & Array[n-1] the smallest.
 *
 * Function takes an array with a determined length, in a nested for loop, first
 * loop will compare the first position of the array and compare to the rest values 
 * of the* remaining positions in the second loop to determine if the value is smaller, 
 * if so interchange positions in array. First loop will increment it's position
 * once the second loop goes through all comparisions and interchanges positions.
 * When first loop goes through all the positions of the array this will be sorted
 * and returned. 
 *
 * @param unsigned char array_dataset[] -  Array to be sorted
 * @param unsigned char array_length - Length of array_dataset
 *
 *
 * @return unsigned char array_dataset 
 */

unsigned char sort_array(unsigned char array_dataset[], unsigned char array_length);



/**
 * @brief Prints the statistics of an array including minimum, maximum,
 * mean and median.
 *
 * Function is given the minimum, maximum, mean and median values of an array
 * and prints in a new line the name of the analytic along with the value. 
 *
 * @param int minimum - Smallest value of the dataset.
 * @param int maximum - Largest value of the dataset.
 * @param int mean - Average value of the dataset.
 * @param int median - Middle value of an arranged dataset.
 *
 * @return No return 
 */

void print_statistics(int minimum, int maximum, int mean, int median);



/**
 * @brief Given an array of data and a length, prints the array to the
 * screen.
 *
 * Function print a given array to the screen. 
 *
 * @param unsigned char array_dataset - Array to be printed
 * @param unsigned char array_length - Size of array
 *
 * @return No return
 */
void print_array(unsigned char array_dataset[], unsigned char array_length);




#endif /* __STATS_H__ */
