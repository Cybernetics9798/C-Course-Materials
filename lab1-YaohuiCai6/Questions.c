#include "Questions.h"


int Q1_for(int num){
	int sum = 0;
	// calculate your sum below..this has to use for loop
	for(int i = 1; i < 1001; i++){
		if(i % num == 0){
			sum = sum + i;
		}
	}
	// here, we return the calcualted sum:
	return sum;
}

int Q1_while(int num){
	int sum = 0;
	int counter = 1;
	// calculate your sum below..this has to use while loop
	while(counter < 1001){
		if(counter%num == 0){
			sum = sum + counter;
		}
		counter++;
	}
	// here, we return the calcualted sum:
	return sum;
}

int Q1_dowhile(int num){
	int sum = 0;
	int counter = 1;
	// calculate your sum below..this has to use do-while loop
	do{
		if(counter%num == 0){
			sum = sum + counter;
		}
		counter++;
	}while(counter <= 1000);
	// here, we return the calcualted sum:
	return sum;
}

//===============================================================================================
int Q2_FPN(float Q2_input, float Q2_threshold){
	// Determine which range does Q2_input fall into.  Keep in mind the floating point number range.
	// Assign the correct output to the result.
	if(Q2_input >= -2*Q2_threshold && Q2_input < -1*Q2_threshold){
		return 0;
	}
	if(Q2_input >= -1*Q2_threshold && Q2_input < 0){
		return 1;
	}            
	if(Q2_input >= 0 && Q2_input < Q2_threshold){
		return 2;
	}  
	if(Q2_input >= Q2_threshold && Q2_input <= 2*Q2_threshold){
		return 3;
	}
	// Finally, return the result.
	return -999;
}

//===============================================================================================
int Q3(int Q3_input, int perfect[]){
	//counts is the variable that should hold the total number of found perfect numbers
	//you should update it within your code and return it at the end
	int counts = 0;
	/*
	*perfect is an array that you need to add into it any perfect number you find
	*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
	*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
	*autmoatically reflect in the main calling function.
	*/

	if(Q3_input < 0){
		return 0;
	}

	for(int i = 1; i < Q3_input + 1; i++){
	int sum = 0;
		for(int j = 1; j < i; j++){
			if(i % j == 0){
				sum = sum + j;
			}
		}
		if(sum == i){
			perfect[counts] = i;
			counts++;
		}
	}
	return counts;
}

//===============================================================================================
int Q4_Bubble(int array[], int size){
	// This variable tracks the number of passes done on the array to sort the array.
	int passes = 0;
	int i = 0;
	int sorted = 0;
	int swapped = 0;
	// Pseudocode
	// 	1. Given an array and its size, visit every single element in the array up to size-2 (i.e. up to the second last element, omit the last element)
	//  2. For every visited element (current element), check its subsequent element (next element).  
	//     If the next element is smaller, swap the current element and the next element. 
	//  3. Continue until reaching size-2 element.  This is considered One Pass => increment pass count by one.
	//  4. Repeat 1-3 until encountering a pass in which no swapping was done.
	//   -> Sorting Completed.
	while(i < size - 1  && sorted != 1){
		int swapped = 0;
		for(int j = 0; j < size - 1; j++){
			int temp;
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
				swapped = 1;
			}
		}
		if(swapped == 0){
			sorted = 1;
		}
		passes++;
		i++;
	}
	// Finally, return the number of passes used to complete the Bubble Sort
	return passes;	
}