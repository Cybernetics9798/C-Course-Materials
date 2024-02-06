#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"


int my_strlen(const char * const str1)
{
	// Returns the length of the string - the number of characters, but IGNORING the terminating NULL character
	int count = 0;
	while(str1[count] != '\0'){
		count++;
	}
	return count;
}

int my_strcmp(const char * const str1, const char * const str2)
{
	// Return 0 if the two strings are not identical.  Return 1 otherwise.
	// Criteria 1: Check their lenghts.  If not the same length, not equal
	if (my_strlen(str1) != my_strlen(str2)){
		return 0;
	}
	// Criteria 2: Check their contents char-by-char.  If mismatch found, not equal
	for (int i = 0; i < my_strlen(str1); i++){
		if (str1[i] != str2[i]){
			return 0;
		}
	}
	// if passing the two criteria, strings equal
	return 1;
}

int my_strcmpOrder(const char * const str1, const char * const str2)
{
	/*compare_str alphabetically compares two strings.
    	If str2 is alphabetically smaller than str1 (comes before str1),
    	the function returns a 1, else if str1 is smaller than str2, the
    	function returns a 0.*/
	int length1 = my_strlen(str1);
	int length2 = my_strlen(str2);
	int length = length1;
	if(length1 < length2){
		length = length1;
	}
	else if(length1 > length2){
		length = length2;
	}
	// if two strings are completely identical in order, return -1.
	if(my_strcmp(str1, str2) == 1){
		return -1;
	}
	// We are NOT looking for any custom alphabetical order - just use the integer values of ASCII character
	for(int i = 0; i < length; i++){
		if(str1[i] < str2[i]){
			return 0;
		}
		else if(str1[i] > str2[i]){
			return 1;
		}
	}
	// failsafe for two strings that are identical in order but not in length
	if(length1 < length2){
		return 0;
	}
	else{
		return 1;
	}
}

char *my_strcat(const char * const str1, const char * const str2){
	/* this is the pointer holding the string to return */
	char *z = NULL;
	/*write your implementation here*/
	int count = 0;
	int length1 = my_strlen(str1);
	int length2 = my_strlen(str2);
	int length = length1 + length2;
	z = (char *)malloc((length + 1) * sizeof(char));

	for(int i = 0; i < length1; i++){
		z[i] = str1[i];
		count++;
	}
	for(int j = 0; j < length2; j++){
		z[count] = str2[j];
		count++;
	}
	z[length] = '\0';

	/* finally, return the string*/
	return z;
	// IMPORTANT!!  Where did the newly allocated memory being released?
	// THINK ABOUT MEMORY MANAGEMENT
}