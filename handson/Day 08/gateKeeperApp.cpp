/*
Gate keeper log application
Menu Based Gate Keeper App:
Sample Logs 
3:30PM teacher Name:Manikanda
3:35PM student 1030					Anil
3:40PM student 4012					Shrikant
4:00PM parent 3456 7898 7323   		Maheswaran

Avinash is the programmer 
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>

using namespace std;

union persons_t {
	char teacherName[256];
	int studentRollNum;
	long long parentAadhaar;
};					 
struct log_t {
	char time[10];
	int personType; //1-teacher, 2-student, 3-parent
	union persons_t person;
};

void readLog(struct log_t& entry) {
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "Enter Log:" << endl;
	
	cout << "Time:";
	cin >> entry.time;

	cout << "Person(1-Teacher,2-Student,3-Parent):";
	cin >> entry.personType;

	switch (entry.personType) {
	case 1:
		cout << "Teacher Name:";
		cin >> entry.person.teacherName;
		break;
	case 2:
		cout << "Student Roll Number:";
		cin >> entry.person.studentRollNum;
		break;
	case 3:
		cout << "Parent aadhaar number:";
		cin >> entry.person.parentAadhaar;
		break;
	}
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
}

void printLog(struct log_t& entry) {
	
	cout << entry.time << "\t";
	switch (entry.personType) {
	case 1:
		cout << "Teacher Name:" << entry.person.teacherName;
		break;
	case 2:
		cout << "Student Roll Number:" << entry.person.studentRollNum;
		break;
	case 3:
		cout << "Parent aadhaar number:" << entry.person.parentAadhaar;
		break;
	}
	cout << endl;
}
int main() {
	struct log_t logs[100];
	//struct log_t* logs = (struct log_t*)malloc(100 * sizeof(struct log_t));
	int count = 0;
	
	//1-Entry, 2-View all
	int menu;

	do{
		cout << "Choices(1-Entry, 2-View all):" << endl;
		cout << "Your choice:";
		cin >> menu;

		switch(menu){
		case 1:
			readLog(logs[count]);
			count++;
			break;
		case 2:
			cout << "**************************************************" << endl;
			cout << "Time" << "\tDetail" << endl;
			cout << "**************************************************" << endl;
			for (int I = 0;I < count;I++) {
				printLog(logs[I]);
			}
			cout << "**************************************************" << endl;
		}
	} while (menu == 1 || menu == 2);

	return EXIT_SUCCESS;
}