/*
 ============================================================================
 Name        : file.c
 Author      : 23261
 Version     :
 Copyright   : Your copyright notice
 Description : Pointer and Structure, Ansi-style
 ============================================================================
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stud
{
	int rollno;
	char name[20];
	int division;
	char mob[9];
};



//function declaration
void details(struct stud ,int );
void display(struct stud );
void delete(struct stud ,int );
int search(struct stud ,int );
void update(struct stud ,int );

//start of main function...
int main()
{
	//structure variable declaration..
	struct stud s1;
	FILE *fp = NULL;

	//variable declaration...
	int  ch = 1,  num = 0, no = 0;

	if (!(fp = fopen("rr.txt", "r+")))  //if file doesn't exist then create it!
		fp = fopen("rr.txt", "w+");

	if (fp == NULL)
		printf("File not opened!");

	while (ch > 0)
     {
		//displaying the menu and taking input from user...
		printf("\nMenu:\n1.Add Details\n2.Display\n3.Update\n4.Search\n5.Delete\n6.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			//taking number of students whose data is to be entered...

			printf("Enter the number of students whose data is to be entered:");
			scanf("%d", &num);
			details(s1,num);
			break;

		case 2:
			//displaying the data
			//printf("Roll_no\tName\tDivision\tMobile No.\n");
			printf("Roll_no|Name     |Division|Mobile No.\n");
			printf("----------------------------------------------------\n");
	        display(s1);
			printf("-----------------------------------------------------\n");
			break;

		case 3:
			//updating the input data using roll number of student

			printf("Enter the roll number to be updated:");
			scanf("%d", &no);
			update(s1, no);
			break;

		case 4:
			//searching the data by roll number
			printf("Enter the roll number of student to be searched : ");
			scanf("%d", &no);

			no = search(s1,no);
			if (no == 1)
				printf("Record Searched !");
			else
				printf("Record not found !");
			break;

		case 5:
			//deleting the data using roll number as input ..
			printf("Enter roll number whose record is to be deleted: ");
			scanf("%d", &no);
			delete(s1,no);

			break;

		case 6:
			printf("\n\nProgram Closed ...");
			ch = 0;
			break;

		}
	}
}  //end of main function...

void details(struct stud s1,  int num)
{

	int i, l = 0;

  FILE *fp = NULL;

	fp=fopen("rr.txt","a");

	//fseek(fp, 0, 2);  //go to end of file

	//taking the details of student...
	for (i = 0; i < num; i++)
	{
		printf("\n*******************************************\n");
		printf("\nEnter Roll number: ");
		scanf("%d", &s1.rollno);

		printf("\nEnter Name : ");
		scanf("%s", s1.name);

		printf("\nEnter Division : ");
		scanf("%d", &s1.division);

		printf("\nEnter Mobile number : ");

		//validation of mobile number if number of digits are not equal to 10
		while (1)
		{
			scanf("%s", s1.mob);
			//calculating length of string...
			l = strlen(s1.mob);
			//if length not equal to 10 taking the input again...
			if (l != 10)
			{
				printf("Invalid mobile number !\nEnter valid number:");
				continue;
			} else
				//if length equal to 10 break the loop and proceed...
				break;
		}

		fprintf(fp, "%d\t%s\t%d\t%s\n", s1.rollno, s1.name,s1.division, s1.mob);
	}
	fclose(fp);

	//fp = fopen("rr.txt", "r+");

}

void display(struct stud s1)
{
  FILE *fp = NULL;
  fp = fopen("rr.txt","r");
	//rewind(fp);

//scanning file and displaying
	while (fscanf(fp, "%d\t%s\t%d\t%s\n",&s1.rollno,s1.name,&s1.division, s1.mob)!=EOF)
	{
		 printf("%-7d|%-9s|%-8d|%s\n",s1.rollno,s1.name,s1.division,s1.mob);

	}

}

int search(struct stud s1,int no)
{
	int  cnt = 0;
    FILE *fp = NULL;
    fp = fopen("rr.txt","r");
	//rewind(fp);

//scanning file and displaying the found data

	while (fscanf(fp, "%d\t%s\t%d\t%s\n", &s1.rollno, s1.name,&s1.division, s1.mob)!=EOF)

	{
			if (s1.rollno == no)
			{
				printf("\nStudent Found !\n\nStudent details are:");
				printf("Roll_no|Name     |Division|Mobile No.\n");
			   printf("----------------------------------------------------\n");
				 printf("%-7d|%-9s|%-8d|%s\n",s1.rollno,s1.name,s1.division,s1.mob);
				cnt = 1;
				break;
			}
	}
	return cnt;
}

void delete(struct stud s1,int no)
{
	int  cnt = 0;

  	  FILE *ft = NULL;
	  FILE *fp = NULL;

  ft = fopen("temp.txt", "w+");
//opening temporary file in w+ mode and source file in read mode.
	
    fp = fopen("rr.txt", "r+");

	//rewind(fp);

	while(fscanf(fp, "%d\t%s\t%d\t%s\n", &s1.rollno, s1.name,&s1.division, s1.mob)!=EOF)

	{
		if (s1.rollno == no)
		cnt++;

	}

	if (cnt == 0)
	{
		printf("***Roll number not found***");
		return ;
	}

	else

	{
		rewind(fp);
//scanning all records and printing records except the one to be deleted in temporary file.
	while(fscanf(fp,"%d\t%s\t%d\t%s\n", &s1.rollno, s1.name,&s1.division, s1.mob)!=EOF)
	{
		if(s1.rollno!=no)
		fprintf(ft, "%d\t%s\t%d\t%s\n", s1.rollno, s1.name,s1.division, s1.mob);
	}
	fclose(fp);
	fclose(ft);
//copying all data from temporary to original file.
	ft = fopen("temp.txt", "r");
	fp = fopen("rr.txt", "w+");

	while(!feof(ft))
	{
	fscanf(ft,"%d\t%s\t%d\t%s\n", &s1.rollno, s1.name,&s1.division, s1.mob);
	fprintf(fp, "%d\t%s\t%d\t%s\n", s1.rollno, s1.name,s1.division, s1.mob);
	}
  }
	fclose(ft);
    fclose(fp);

	//fp=fopen("rr.txt", "r+");
}



void update(struct stud s1, int no)
{
	int l = 0, cnt = 0;

	FILE *fp = NULL;
    FILE *ft = NULL;

	ft = fopen("temp.txt", "w+");
	
	fp = fopen("rr.txt", "r");
	//rewind(fp);

//getting the position of roll num to be updated
		while(fscanf(fp, "%d\t%s\t%d\t%s\n", &s1.rollno, s1.name,&s1.division, s1.mob)!=EOF)
		 {
		if (s1.rollno == no)
		cnt++;
	      }

	if (cnt == 0)
	{
		printf("**roll no not found**");
		return;
	}
	else
	{
		rewind(fp);
		
//printing data before the number to be updated,in temporary file

			while(fscanf(fp, "%d\t%s\t%d\t%s\n", &s1.rollno, s1.name,&s1.division, s1.mob)!=EOF)
			{
			   if(s1.rollno==no)
			   {
				   printf("\n*******************************************\n");

				   		printf("\nEnter Name : ");
				   		scanf("%s", s1.name);

				   		printf("\nEnter Division : ");
				   		scanf("%d", &s1.division);

				   		printf("\nEnter Mobile number : ");

				   		//validation of mobile number if number of digits are not equal to 10

				   		while (1)
				   		{
				   			scanf("%s", s1.mob);
				   			//calculating length of string...
				   			l = strlen(s1.mob);
				   			//if length not equal to 10 taking the input again...
				   			if (l != 10)
				   			{
				   				printf("Invalid mobile number !\nEnter valid number:");
				   				continue;
				   			} else
				   				//if length equal to 10 break the loop and proceed...
				   				break;
				   		}


				   		s1.rollno=no;


			   }

                        fprintf(ft,"%d\t%s\t%d\t%s\n", s1.rollno, s1.name,s1.division, s1.mob);

			}
	}
			    fclose(fp);
				fclose(ft);
  //copying the data in original file.
				ft = fopen("temp.txt", "r");
				fp = fopen("rr.txt", "w+");

				while(!feof(ft))
{
				fscanf(ft,"%d\t%s\t%d\t%s\n", &s1.rollno, s1.name,&s1.division, s1.mob);
				fprintf(fp,"%d\t%s\t%d\t%s\n", s1.rollno, s1.name,s1.division, s1.mob);
}

				fclose(ft);
				fclose(fp);

				//fp=fopen("rr.txt", "r+");

}
