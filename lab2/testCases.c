#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    

    
    
//=========Question 1==================================
void TestQ1_add(CuTest *tc){

	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double actual[5];
	double expected [5] = {5.10, 6.78, 9.30, 19.90, 1.01};
	add_vectors(input1,input2,actual,n);
	int i;
	for (i=0; i<n; i++)
		CuAssertDblEquals(tc, expected[i], actual[i],0.009);
}

void TestQ1_add_2(CuTest *tc){
	int n = 5;
	double input1[5] = {1, 2, 3, 4, 5};
	double input2[5] = {1, 2, 3, 4, 5};
	double actual[5];
	double expected [5] = {2, 4, 6, 8, 10};
	add_vectors(input1,input2,actual,n);
}

void TestQ1_scalar_prod(CuTest *tc){
	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double input2[5] = {1.50, 2.00, 3.30, 9.90, 1.00};
	double expected=133.770 ;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_scalar_prod_2(CuTest *tc){
	int n = 5;
	double input1[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	double input2[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	double expected = 55.0;
	double actual = scalar_prod(input1,input2,n);

	CuAssertDblEquals(tc, expected, actual, 0.009);
}

void TestQ1_norm(CuTest *tc) {
	int n = 5;
	double input1[5] = {3.60, 4.78, 6.00, 10.00, 0.01};
	double expected=13.108;
    double actual = norm2(input1,n);

    CuAssertDblEquals(tc, expected, actual,0.009);
}

void TestQ1_norm_2(CuTest *tc) {
	int n = 5;
	double input1[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	double expected = 7.416;
	double actual = norm2(input1,n);

	CuAssertDblEquals(tc, expected, actual, 0.009);
}

//===========================================================
//=================Question 2================================  

void TestQ2(CuTest *tc) {
	int n = 3;
	int input[3][3] = {{1, 2, 3},{ 5, 8, 9},{ 0, 3, 5}};
	int expected[9]= {1, 2, 5, 3, 8, 0, 9, 3, 5};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

// 1 2 4
// 8 9 10
// 0 5 6
void TestQ2_2(CuTest *tc){
	int n = 3;
	int input[3][3] = {{1, 2, 4}, {8, 9, 10}, {0, 5, 6}};
	int expected[9]= {1, 2, 8, 4, 9, 0, 10, 5, 6};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

//1 2 3
//4 5 6
//7 8 9
void TestQ2_3(CuTest *tc){
	int n = 3;
	int input[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int expected[9]= {1, 2, 4, 3, 5, 7, 6, 8, 9};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

//0 0 0
//0 0 0
//0 0 0
void TestQ2_4(CuTest *tc){
	int n = 3;
	int input[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int expected[9]= {0, 0, 0, 0, 0, 0, 0, 0, 0};
	int actual[9];
	diag_scan(input,actual);

	int i;
	for (i=0; i<n*n; i++)
		CuAssertIntEquals(tc, expected[i], actual[i]);
}

//===========================================================
//=================Question 3================================   
void TestQ3_1(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {{23, 2}, {-7, 4}, {48, 7}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_2(CuTest *tc){
	int n = 4;
	int input[] = {0, 0, 3, 4};
	struct Q3Struct actual[4] = {0};
	struct Q3Struct expected[4] = {{3, 2}, {4, 3}, {0, 0}, {0, 0}};
	efficient(input, actual, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_3(CuTest *tc){
	int n = 5;
	int input[] = {-999, 999, 1, 0, 0};
	struct Q3Struct actual[5] = {0};
	struct Q3Struct expected[5] = {{-999, 0}, {999, 1}, {1, 2}, {0, 0}, {0, 0}};
	efficient(input, actual, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_4(CuTest *tc){
	int n = 1;
	int input[] = {8};
	struct Q3Struct actual[4] = {0};
	struct Q3Struct expected[4] = {{8, 0}};
	efficient(input, actual, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_zeros(CuTest *tc) {
	int n=8;
	int input[]={0,0,0,0,0,0,0,0};
	struct Q3Struct actual[8] = {0};
	struct Q3Struct expected[8] = {0};
	efficient(input,actual,n);
    
	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i].val, actual[i].val);
		CuAssertIntEquals(tc, expected[i].pos, actual[i].pos);
	}
}

void TestQ3_combined(CuTest *tc) {
	int n=8;
	int input[]={0,0,23,0,-7,0,0,48};
	struct Q3Struct int_result[8] = {0};
	int expected[8] = {0,0,23,0,-7,0,0,48};
	int actual[8] = {0};
	efficient(input,int_result,n);
	reconstruct(actual, 8, int_result, 3);

	int i;
	for (i=0; i<n; i++){
		CuAssertIntEquals(tc, expected[i], actual[i]);
	}
}
    

//===========================================================
//=================Question 4================================   
void TestQ4_BubbleSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};		
	
	sortDatabyBubble(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_3(CuTest *tc){
	int n = 5;
	struct Q4Struct input[] = {{2, 'b'}, {3, 'c'}, {1, 'a'}, {5, 'e'}, {4, 'd'}};
	struct Q4Struct expected[] = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
	sortDatabyBubble(input, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_4(CuTest *tc){
	int n = 3;
	struct Q4Struct input[] = {{-999, '@'}, {-998, '#'}, {888, '&'}};
	struct Q4Struct expected[] = {{-999, '@'}, {-998, '#'}, {888, '&'}};
	sortDatabyBubble(input, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_BubbleSort_5(CuTest *tc){
	int n = 1;
	struct Q4Struct input[] = {{1, 'a'}};
	struct Q4Struct expected[] = {{1, 'a'}};
	sortDatabyBubble(input, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_1(CuTest *tc) 
{
	int n=6;
	struct Q4Struct input[]={{10, 'c'}, {2, 'B'}, {-5, 'k'}, {12, 'z'}, {77, 'a'}, {-42, '?'}};	
	struct Q4Struct expected[]={{-42, '?'}, {-5, 'k'}, {2, 'B'}, {10, 'c'}, {12, 'z'}, {77, 'a'}};		
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_2(CuTest *tc) 
{
	int n=8;
	struct Q4Struct input[]={{-23, '='}, {78, ' '}, {11, 'Y'}, {-2, '0'}, {41, '+'}, {0, 'm'}, {55, 'T'}, {-9, 'o'}};	
	struct Q4Struct expected[]={{-23, '='}, {-9, 'o'}, {-2, '0'}, {0, 'm'}, {11, 'Y'}, {41, '+'}, {55, 'T'}, {78, ' '}};			
	
	sortDatabySelection(input, n);
	
	int i;
	for (i=0; i<n; i++)
	{
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_3(CuTest *tc){
	int n = 5;
	struct Q4Struct input[] = {{2, 'b'}, {3, 'c'}, {1, 'a'}, {5, 'e'}, {4, 'd'}};
	struct Q4Struct expected[] = {{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}, {5, 'e'}};
	sortDatabySelection(input, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_4(CuTest *tc){
	int n = 3;
	struct Q4Struct input[] = {{-999, '@'}, {-998, '#'}, {888, '&'}};
	struct Q4Struct expected[] = {{-999, '@'}, {-998, '#'}, {888, '&'}};
	sortDatabySelection(input, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}

void TestQ4_SelectionSort_5(CuTest *tc){
	int n = 1;
	struct Q4Struct input[] = {{1, 'a'}};
	struct Q4Struct expected[] = {{1, 'a'}};
	sortDatabySelection(input, n);

	for(int i = 0; i < n; i++){
		CuAssertIntEquals(tc, expected[i].intData, input[i].intData);
		CuAssertIntEquals(tc, expected[i].charData, input[i].charData);
	}
}



CuSuite* Lab2GetSuite() {

	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, TestQ1_add);
	SUITE_ADD_TEST(suite, TestQ1_add_2);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod);
	SUITE_ADD_TEST(suite, TestQ1_scalar_prod_2);
	SUITE_ADD_TEST(suite, TestQ1_norm);
	SUITE_ADD_TEST(suite, TestQ1_norm_2);

	SUITE_ADD_TEST(suite, TestQ2);
	SUITE_ADD_TEST(suite, TestQ2_2);
	SUITE_ADD_TEST(suite, TestQ2_3);
	SUITE_ADD_TEST(suite, TestQ2_4);

	SUITE_ADD_TEST(suite, TestQ3_1);
	SUITE_ADD_TEST(suite, TestQ3_2);
	SUITE_ADD_TEST(suite, TestQ3_3);
	SUITE_ADD_TEST(suite, TestQ3_4);
	SUITE_ADD_TEST(suite, TestQ3_zeros);
	SUITE_ADD_TEST(suite, TestQ3_combined);

	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_1);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_2);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_3);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_4);
	SUITE_ADD_TEST(suite, TestQ4_BubbleSort_5);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_1);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_2);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_3);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_4);
	SUITE_ADD_TEST(suite, TestQ4_SelectionSort_5);

	return suite;
}
    
