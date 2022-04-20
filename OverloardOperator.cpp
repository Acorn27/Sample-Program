/*
Demonstrate the use of copy overload operator
Declaration const className operation=(const classname &right)
only proceed if this != right, whcih will check for self-assignment (left != right)
inside function: Do the same work as copy constructor
return *this at the end of function

IMPORTANCE:
When copy constructor and Operation overload of = both declare:
Student student1 = student2 (copy constructor is called)
student1 = student2(overloaded operation is called)
Look at the end of this code for more information

Note:
It is very complicated to work with pointer, avoid as much as possible
*/

#include <iostream>
using namespace std;

class Student {

	// private member variable
	private:
		string studentName;
		double* testScore;
		int numTestScore;
		
		// dynamically create an array with input size
		void createArray(int size) {

			// this is important
			// we can not assume that test score will be a proper size array with new opertion
			// because we use size in the set up of default test score
			numTestScore = size;

			// dynamically allocate testScore array
			testScore = new double[size];

			// initialize default test score
			for (int i = 0; i < size; i++) {
				testScore[i] = 0;
			}
		}

	public:
		// constructor, take name and number of test score as parameter
		Student(string name, int numScore) {

			studentName = name;
			createArray(numScore);
		}

		// coppy constructor
		Student(Student& obj) {

			studentName = "Coppied Student";
			numTestScore = obj.numTestScore;

			//createArray(numTestScore);
			testScore = new double[numTestScore];

			for (int i = 0; i < numTestScore; i++) {

				testScore[i] = obj.testScore[i];

			}
		}
		

		// overload = operator
		const Student operator=(const Student& right) {
			if (this != &right) {

				studentName = "Overloaded Operator";
				numTestScore = right.numTestScore;
				testScore = new double[numTestScore];
				for (int i = 0; i < numTestScore; i++) {
					testScore[i] = right.testScore[i];
				}
				return *this;
			}
		}

		// destructor
		~Student() {
			delete[] testScore;
		}

		void setTestScore(double score, int index) {
			
			testScore[index] = score;

		}

		void setStudentName(string name) {

			studentName = name;
		}

		double getTestScore(int index) {
			return(testScore[index]);
		}

		string getStudentName() {

			return (studentName);
		}

		double getTestNum() {

			return (numTestScore);
		}


};

int main() {


	Student No1("Huy", 3);

	cout << "Student name is: " << No1.getStudentName() << endl;
	cout << "Score of exam 3 is: " << No1.getTestScore(2) << endl;
	cout << "Number of test score is: " << No1.getTestNum() << endl;
	cout << "Change score of exam 3 to 10";
	No1.setTestScore(10, 2);

	Student No2 = No1;
	cout << "\nName of studetn 2 is: " << No2.getStudentName() << endl;
	cout << "Score of exam 3 of student 1 is: " << No1.getTestScore(2) << endl;
	cout << "Score of exam 3 of student 2 is: " << No2.getTestScore(2) << endl;

	No2 = No1;
	cout << "\nName of studetn 2 is: " << No2.getStudentName() << endl;
	cout << "Score of exam 3 of student 1 is: " << No1.getTestScore(2) << endl;
	cout << "Score of exam 3 of student 2 is: " << No2.getTestScore(2) << endl;
}
