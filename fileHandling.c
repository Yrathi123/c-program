/*
 ============================================================================
 Roll no.    		: 23141
 Class          	: SE - 9
 Batch              : G - 9
 Name         	    : Sahil Naphade
 Assignment no.     : Assignment 5 - B
 Problem Statement  :


*/

////Inclusion of header files
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definition of structure date
typedef struct date
{
	int dd;
	int mm;
	int yy;
}Date;

//definition of structure Student
typedef struct stud
{
	int roll_no;
	char name[30];
	Date DoB;
	//Date DoAdmission;
	char email[30];
	char address[50];
	char mob_no[11];
}Student;

//definition of functions to add, update, delete and display the database

void createNew();

void display();  // passing array and total no. of count

void display_single(Student s,int location); //passing array and location of the student to display

int check(Student s,int count); //checks for roll no. and if found, will return location


//MAIN FUNCTION
int main(void) {

	// statics for total count, locations, no. of deleted and non deleted student
	static int count, stud_location,loc,display_count;
	// num is no. of student to add, choice, loop param, choice to delete and for loop

	int num,choice,i,delete_c,choice_loop;
    Student s;	//declaration of variable to read the data to file

		//start of do-while loop
	do{
		//provision of choice to user for running of program
			printf("\nPlease enter the choice you want to add\n");
			printf("Enter\n1. To create the file\n");
			printf("2. To display the database\n");
//			printf("3. To add new student\n");
//			printf("4. To search for a student\n");
//			printf("5. To delete a student\n");
			printf("6. To exit\n");
			scanf("%d",&choice_loop);
			switch(choice_loop){	//start of switch-case

			case 1:	//case to add students to database
				printf("\nWARNING!!\nThis will delete all the previously existing record!\n");
				printf("Enter\n0 if you want to abort\nElse anything to continue\n");
				scanf("%d",&choice);

				if(choice){
					createNew();
					count++;			// Incrementing the count of student.
				}
				break;

			case 2:  //case 2 to display the database
					display();
				break; //end of case 2 of display
//
//				case 3:	//Update a record
//					printf("Enter the roll no. of student you want to Update\n");
//					loc = check(s,count);	//will check for the record.
//											//if available, will return the location
//											//if not, will return -1
//
//					printf("Update the student\t::\n");
//					createNew(s,1,loc);
//					printf("The updated student is as follows\n");
//					display_single(s,loc);
//
//					break;//end of case 3 for update
//
//				case 4:
//					// DELETION OF A RECORD
//					printf("Enter the roll no. of student you want to delete.\n");
//					loc = check(s,count);
//
//					printf("Do you want to delete the record?\n");
//					printf("\nEnter\n1. to proceed to delete\n0. to abort\n");
//					scanf("%d",&delete_c);
//					if(delete_c){
//							//replacing that record with following one
//							for(i = loc;i<count;i++)
//							{
//								s[i+1] = s[i];
//							}
//							display_count--;
//							count--;
//							stud_location--;
//					}
//					break;// end of case 4 for deleted


				default:break;

			} //end of switch case
	}while(choice_loop != 6); //end of do-while loop of program
	return EXIT_SUCCESS;
} //END OF MAIN FUNCTION


//FUNCTION DEFINITION TO ACCEPT DATABASE

//Function to accept attributes for student using validations
void createNew()
	{
		int i,j,num;
		char name[30];
	//	Student s;
		int r;
		FILE *fp;
		printf("How many records you want to add\t::\t");
		scanf("%d",&num);
	//	printf("Enter name of file\t::\t");
	//	scanf("%s",name);
		fp = fopen("record","wb");

		for(i=0;i<num;i++)
		{
			printf("Enter roll number\t::\t");
			scanf("%d",&r/*s.roll_no*/);

//			printf("Enter name of student\t::\t");
//			scanf("%s",s.name);
//
//			printf("Enter day of birth\t::\t");
//			scanf("%d",&s.DoB.dd);
//
//			printf("Enter month of birth\t::\t");
//			scanf("%d",&s.DoB.mm);
//
//			printf("Enter year of birth\t::\t");
//			scanf("%d",&s.DoB.yy);

			fwrite(&r,sizeof(int),1,fp);
		}

		fclose(fp);
	}  //end of createNew function

void display()
{
	FILE *fp;
	fp = fopen("record","rb");
	//Student s;
	int i,r;
	while(!feof)
	{
			fread(&r,sizeof(int),1,fp);
			printf("=====================================================================\n");
			printf("The information of student %d is as follows\n",i+1);
			printf("Roll No\t\t::\t%d\n",/*s[i].name,*/r);
	/*		printf("Date Of Birth\t::\t%d-%d-%d\n",s[i].DoB.dd,s[i].DoB.mm,s[i].DoB.yy);
			printf("Mobile Number\t::\t%s\n",s[i].mob_no);
			printf("Email ID\t::\t%s\n",s[i].email);
			printf("Address\t\t::\t%s\n",s[i].address);
	*/		printf("=====================================================================\n");
	}
	fclose(fp);
}
//// checks if the student record exist and if yes, will return the location
//int check(Student s[],int count)
//{
//	int num,i;
//
//	do{
//		scanf("%d",&num);
//		for(i=0;i<count;i++)
//		{
//			if(s[i].roll_no == num)
//				break;
//		}
//
//		if(i==count)
//		{
//			printf("No student exist\n");
//			return 0;
//			break;
//		}
//		else
//		{
//			printf("The student is found, the details are as follows ::\n");
//			display_single(s,i);
//			return i;
//			break;
//		}
//
//	}while(1);
//} //end of check function
//
//display of all the database


////display of single student according to location
//void display_single(Student s[],int loc)
//{
//	if(s[loc].roll_no > 0){
//		printf("=====================================================================\n");
//		printf("The information of student is as follows\n");
//		printf("Name\t\t::\t%s\nRoll No\t\t::\t%d\n" ,s[loc].name,s[loc].roll_no);
//		printf("Date Of Birth\t::\t%d-%d-%d\n",s[loc].DoB.dd,s[loc].DoB.mm,s[loc].DoB.yy);
//		printf("Mobile Number\t::\t%s\n",s[loc].mob_no);
//		printf("Email ID\t::\t%s\n",s[loc].email);
//		printf("Address\t\t::\t%s\n",s[loc].address);
//		printf("=====================================================================\n");
//	}
//}
