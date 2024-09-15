#include "Matrix.h"
#include <iostream>

using namespace std;

bool passed = true;
int passCount = 0;
int failCount = 0;

void testConstructor1Invalid1() {
		// for constructor1
		int invalid_row1 = -1, invalid_col1 = -2;

		string row1="0 0 0 \n", row2="0 0 0 \n",row3="0 0 0 \n";
		string expected = row1 + row2 + row3;
   	 	// test constructor1; invalid inputs
		Matrix a = Matrix(invalid_row1,invalid_col1);

		if(expected.compare(a.toString()) == 0)
		{
			cout << "[OK] Test Constructor 1 Invalid 1 Passed" << endl;
			passCount++;			
		}
		else
		{
			cout << "[FAILED] Test Constructor 1 Invalid 1 Failed" << endl;
			failCount++;
			passed = false;	
		}		
	}

void testConstructor1Invalid2() {
		// for constructor1
		int invalid_row2 = 1, invalid_col2 = 0;
		string expected="0 0 0 \n";
		Matrix b = Matrix(invalid_row2,invalid_col2);

		if(expected.compare(b.toString()) == 0)
		{
			cout << "[OK] Test Constructor 1 Invalid 2 Passed" << endl;
			passCount++;			
		}
		else
		{
			cout << "[FAILED] Test Constructor 1 Invalid 2 Failed" << endl;
			failCount++;
			passed = false;	
		}	

	}

void testConstructor1Valid() {
    int valid_row = 3, valid_col = 4;
		// test constructor1; valid inputs
    string row1="0 0 0 0 \n", row2="0 0 0 0 \n",row3="0 0 0 0 \n";
    string expected=row1+row2+row3;
	Matrix d = Matrix(valid_row,valid_col);

	if(expected.compare(d.toString()) == 0)
	{
		cout << "[OK] Test Constructor 1 Valid Passed" << endl;	
		passCount++;		
	}
	else
	{
		cout << "[FAILED] Test Constructor 1 Valid Failed" << endl;
		failCount++;
		passed = false;	
	}	

}


void testConstructor1Valid2() {
    int valid_row = 1, valid_col = 1;
		// test constructor1; valid inputs
    string row1="0 \n";
    string expected=row1;
	Matrix d = Matrix(valid_row,valid_col);

	if(expected.compare(d.toString()) == 0)
	{
		cout << "[OK] Test Constructor 2 Valid 2 Passed" << endl;	
		passCount++;		
	}
	else
	{
		cout << "[FAILED] Test Constructor 2 Valid 2 Failed" << endl;
		failCount++;
		passed = false;	
	}
}


void testConstructor2() {
	  // for constructor2
	    int row=4,col=5;
        int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
        int*input_data[4];
        for (int i=0;i<4;i++){
        	input_data[i]=data[i];
        }
		Matrix f =  Matrix(row,col,input_data);

	    string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	    string expected=row1+row2+row3+row4;

		if(expected.compare(f.toString()) == 0)
		{
			cout << "[OK] Test Constructor 2 Passed" << endl;
			passCount++;			
		}
		else
		{
			cout << "[FAILED] Test Constructor 2 Failed" << endl;
			failCount++;
			passed = false;	
		}	
}


void testConstructor2_2() {
	  // for constructor2
	    int row=4,col=5;
        int data[4][5] = {{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1}};
        int*input_data[4];
        for (int i=0;i<4;i++){
        	input_data[i]=data[i];
        }
		Matrix f =  Matrix(row,col,input_data);

	    string row1="-1 -1 -1 -1 -1 \n", row2="-1 -1 -1 -1 -1 \n", row3="-1 -1 -1 -1 -1 \n",row4="-1 -1 -1 -1 -1 \n";
	    string expected=row1+row2+row3+row4;

		if(expected.compare(f.toString()) == 0)
		{
			cout << "[OK] Test Constructor 2_2 Passed" << endl;
			passCount++;			
		}
		else
		{
			cout << "[FAILED] Test Constructor 2_2 Failed" << endl;
			failCount++;
			passed = false;	
		}	
}


void testGetElementValid_2() {
	  // for constructor2
    int row=4,col=5;
    int data[4][5] = {{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1}};
    int*input_data[4];
    for (int i=0;i<4;i++){
    	input_data[i]=data[i];
    }
	Matrix f = Matrix(row,col,input_data);

	int expected= -1;

	if(expected == f.getElement(1, 3))
	{
		cout << "[OK] Test Get Element Valid_2 Passed" << endl;
		passCount++;			
	}
	else
	{
		cout << "[FAILED] Test Get Element Valid_2 Failed" << endl;
		failCount++;
		passed = false;	
	}
}


void testGetElementValid() {
	  // for constructor2
    int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    int*input_data[4];
    for (int i=0;i<4;i++){
    	input_data[i]=data[i];
    }
	Matrix f = Matrix(row,col,input_data);

	int expected= 9;

	if(expected == f.getElement(1, 3))
	{
		cout << "[OK] Test Get Element Valid Passed" << endl;
		passCount++;			
	}
	else
	{
		cout << "[FAILED] Test Get Element Valid Failed" << endl;
		failCount++;
		passed = false;	
	}
}

void testGetElementInvalid() {
	// for constructor2
    int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
    int* input_data[4];
	int output = 0;

    for (int i=0;i<4;i++){
    	input_data[i]=data[i];
    }

	string actual;
	Matrix f =  Matrix(row,col,input_data);

	try {
			output = f.getElement(10, 2);	// invalid indexes
	}
	catch (std::out_of_range& e){
			actual = e.what();
	}

    string expected= "Invalid indexes.";

	if(expected.compare(actual) == 0)
	{
		cout << "[OK] Test Get Element Invalid Passed" << endl;
		passCount++;			
	}
	else
	{
		cout << "[FAILED] Test Get Element Invalid Failed" << endl;
		failCount++;
		passed = false;	
	}

}


void testSetElementValid() {
	  int value = 100;
	  int setvalid_row = 0, setvalid_col = 0;
	    int row=4,col=5;
	    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	    int*input_data[4];
	    for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	    }
		Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setvalid_row,setvalid_col);
	  string row1="100 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	  string expected=row1+row2+row3+row4;

	if(expected.compare(f.toString()) == 0 && check == true)
	{
		cout << "[OK] Test Set Element Valid Passed" << endl;
		passCount++;			
	}
	else
	{
		cout << "[FAILED] Test Set Element Valid Failed" << endl;
		failCount++;
		passed = false;	
	}


}


void testSetElementInvalid_2() {
	  int value = 100;
	  int setinvalid_row = -1, setinvalid_col = -1;
	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	    for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	    }
	  Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setinvalid_row,setinvalid_col);
	  string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	  string expected=row1+row2+row3+row4;

	if(expected.compare(f.toString()) == 0 && check == false)
	{
		cout << "[OK] Test Set Element Valid Passed" << endl;
		passCount++;			
	}
	else
	{
		cout << "[FAILED] Test Set Element Valid Failed" << endl;
		failCount++;
		passed = false;	
	}

}


void testSetElementInvalid() {
	  int value = 100;
	  int setinvalid_row = 10, setinvalid_col = 10;
	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	    for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	    }
	  Matrix f =  Matrix(row,col,input_data);
	  bool check = f.setElement(value,setinvalid_row,setinvalid_col);
	  string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	  string expected=row1+row2+row3+row4;

	if(expected.compare(f.toString()) == 0 && check == false)
	{
		cout << "[OK] Test Set Element Valid Passed" << endl;
		passCount++;			
	}
	else
	{
		cout << "[FAILED] Test Set Element Valid Failed" << endl;
		failCount++;
		passed = false;	
	}

}


void testCopy() {
	int row=4,col=5;
    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	int*input_data[4];
	for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	}
	Matrix origin =  Matrix(row,col,input_data);
    Matrix copied = origin.copy(); // make a copy
	string row1="1 2 3 4 5 \n", row2="6 7 8 9 0 \n", row3="0 0 1 2 3 \n",row4="0 0 0 4 5 \n";
	string expected=row1+row2+row3+row4;

	if(expected.compare(copied.toString()) == 0)
	{
		cout << "[OK] Test Copy Passed" << endl;
		passCount++;			
	}
	else
	{
		cout << "[FAILED] Test Copy Failed" << endl;
		failCount++;
		passed = false;	
	}
}


void testCopy_2() {
	int row=4,col=5;
    int data[4][5] = {{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1}};
	int*input_data[4];
	for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	}
	Matrix origin =  Matrix(row,col,input_data);
    Matrix copied = origin.copy(); // make a copy
	string row1="-1 -1 -1 -1 -1 \n", row2="-1 -1 -1 -1 -1 \n", row3="-1 -1 -1 -1 -1 \n",row4="-1 -1 -1 -1 -1 \n";
	string expected=row1+row2+row3+row4;

	if(expected.compare(copied.toString()) == 0)
	{
		cout << "[OK] Test Copy 2 Passed" << endl;
		passCount++;			
	}
	else
	{
		cout << "[FAILED] Test Copy Failed" << endl;
		failCount++;
		passed = false;	
	}
}


void testAddToInvalid() {

	   /*Add-to Matrix*/
	    int row_to_add=4; int col_to_add=3;


		int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match

	 	int*add_input_data[4];
	 	for (int i=0;i<4;i++){
	 	    	add_input_data[i]=add_to_data[i];
	 	}

	 	/*Original Matrix*/
	    int row=4;int col=5;
	    int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	 	int*input_data[4];
	 	for (int i=0;i<4;i++){
	 	    	input_data[i]=data[i];
	 	}
	 	Matrix origin =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Invalid operation.";
        Matrix m = Matrix(row_to_add,col_to_add,add_input_data);


        try{
           m.addTo(origin);

        }
        catch (const std::invalid_argument& e) {
    	   actual = e.what();
        }

		if(expected.compare(actual) == 0)
		{
			cout << "[OK] Test AddTo Invalid Passed" << endl;
			passCount++;			
		}
		else
		{
			cout << "[FAILED] Test AddTo Invalid Failed" << endl;
			failCount++;
			passed = false;	
		}

}


void testAddToValid() {
	   int add_to_data[4][3] = {{3,4,5}, {1,2,3}, {0,0,0},{1,2,1}}; // add to 'data' matrix, dimension not match
	   int add_to_above[4][3] = {{1,0,-1}, {2,1,0}, {2,2,2},{0,-1,0}}; // add to 'add_to_data' matrix
	   int row=4;int col=3;

	   int*input_data[4];
	   for (int i=0;i<4;i++){
	 	    input_data[i]=add_to_data[i];
	   }
	   Matrix m = Matrix(row,col,input_data);

	   for (int i=0;i<4;i++){
	 	    	input_data[i]=add_to_above[i];
	   }
	   Matrix m1 = Matrix(row,col,input_data);
	   string row1="4 4 4 \n", row2="3 3 3 \n", row3="2 2 2 \n",row4="1 1 1 \n";
       string expected = row1+row2+row3+row4;

		try{
			m.addTo(m1);
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "supposed to be a valid input: " << e.what() << '\n';
			cout << "[FAILED] Test SubMatrix Valid Failed" << endl;
			failCount++;
			passed = false;	
			return;
		}

		if(expected.compare(m.toString()) == 0)
		{
			cout << "[OK] Test AddTo Valid Passed" << endl;	
			passCount++;		
		}
		else
		{
			cout << "[FAILED] Test AddTo Valid Failed" << endl;
			failCount++;
			passed = false;	
		}
}


void testAddToValid_2() {
	   int add_to_data[2][3] = {{999,444,555}, {111,222,333}}; // add to 'data' matrix, dimension not match
	   int add_to_above[2][3] = {{111,100,-100}, {222,100,100}}; // add to 'add_to_data' matrix
	   int row=2;int col=3;

	   int*input_data[4];
	   for (int i=0;i<2;i++){
	 	    input_data[i]=add_to_data[i];
	   }
	   Matrix m = Matrix(row,col,input_data);

	   for (int i=0;i<2;i++){
	 	    input_data[i]=add_to_above[i];
	   }
	   Matrix m1 = Matrix(row,col,input_data);
	   string row1="1110 544 455 \n", row2="333 322 433 \n";
       string expected = row1+row2;

		try{
			m.addTo(m1);
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "supposed to be a valid input: " << e.what() << '\n';
			cout << "[FAILED] Test SubMatrix Valid Failed" << endl;
			failCount++;
			passed = false;	
			return;
		}

		if(expected.compare(m.toString()) == 0)
		{
			cout << "[OK] Test AddTo Valid Passed" << endl;	
			passCount++;		
		}
		else
		{
			cout << "[FAILED] Test AddTo Valid Failed" << endl;
			failCount++;
			passed = false;	
		}
}


void testSubMatrixValid() {
    int subvalid_row = 3, subvalid_col = 3;


	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string row1="1 2 3 4 \n", row2="6 7 8 9 \n", row3="0 0 1 2 \n",row4="0 0 0 4 \n";
		string expected=row1+row2+row3+row4;
		string actual;

		try{
			Matrix y = f.subMatrix(subvalid_row,subvalid_col);	
			actual = y.toString();			
		}
		catch (std::out_of_range& e){
			std::cerr << "supposed to be a valid input: " << e.what() << '\n';
			cout << "[FAILED] Test SubMatrix Valid Failed" << endl;
			failCount++;
			passed = false;	
			return;
		}

		if(expected.compare(actual) == 0)
		{
			cout << "[OK] Test SubMatrix Valid Passed" << endl;	
			passCount++;		
		}
		else
		{
			cout << "[FAILED] Test SubMatrix Valid Failed" << endl;
			failCount++;
			passed = false;	
		}

}


void testSubMatrixInvalid() {

    int subinvalid_row = 3, subinvalid_col = 6;

	  int row=4,col=5;
      int data[4][5] = {{1,2,3,4,5},{6,7,8,9,0},{0,0,1,2,3},{0,0,0,4,5}};
	  int*input_data[4];
	  for (int i=0;i<4;i++){
	    	input_data[i]=data[i];
	  }
	  Matrix f =  Matrix(row,col,input_data);

		string actual ="Empty for Now";
		string expected = "Submatrix not defined.";

		try{
			Matrix y = f.subMatrix(subinvalid_row,subinvalid_col);
		}
		catch (std::out_of_range& e){

			actual = e.what();
		}

		if(expected.compare(actual) == 0)
		{
			cout << "[OK] Test SubMatrix Valid Passed" << endl;	
			passCount++;		
		}
		else
		{
			cout << "[FAILED] Test SubMatrix Valid Failed" << endl;
			failCount++;
			passed = false;	
		}	


}


int main(int argc, char const *argv[]) {
	
	testConstructor1Invalid1();
	testConstructor1Invalid2();
	testConstructor1Valid();
	testConstructor1Valid2();
	testConstructor2();
	testConstructor2_2();

	testGetElementValid();
	testGetElementInvalid();
	testGetElementValid_2();

	testSetElementValid();
	testSetElementInvalid();

	testCopy();
	testCopy_2();

	testAddToInvalid();
	testAddToValid();
	testAddToValid_2();
	
	testSubMatrixValid();
	testSubMatrixInvalid();

	
	if(passed)
		cout << "ALL TEST PASSED : " << passCount << " Passes." << endl;
	else
		cout << "TEST FAILED : " << passCount << " Passes, " << failCount << " Fails."  << endl;

    return passed;
}



/*


bool runAllTests(int argc, char const *argv[]) {
	cute::suite s;
    s.push_back(CUTE(testConstructor1Invalid1));

	s.push_back(CUTE(testConstructor1Invalid2));

	s.push_back(CUTE(testConstructor1Valid));

	s.push_back(CUTE(testConstructor2));
	s.push_back(CUTE(testGetElementValid));
	s.push_back(CUTE(testGetElementInvalid));
	s.push_back(CUTE(testSetElementValid));
	s.push_back(CUTE(testSetElementInvalid));
	s.push_back(CUTE(testCopy));
	s.push_back(CUTE(testAddToInvalid));
	s.push_back(CUTE(testAddToValid));
	s.push_back(CUTE(testSubMatrixValid));
	s.push_back(CUTE(testSubMatrixInvalid));

	//TODO add your test here

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}


*/