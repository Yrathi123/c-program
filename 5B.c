/*
============================================================================
Roll no:23141     Class:SE9     Batch:G9

Name: Sahil Naphade

Assignment no.:: 5[B]

Assignment name: File handling in Structure 
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct record
{
	char name[15];
	int roll_no;
	char address[50];
}record;

void Input(record*);
void Display(record*);
int Modify(int);
int Delete(int);
int validateRoll(int);
int validateName(char*);
void ModifiedInput(record* r);
 
int main(void)
{
	FILE *fptr;
	
	int choice,temp;
	record r1;
	record r2;
	do{
		printf("Enter 1 to Add\n2 to display\n3 to search\n4 to modify\n5 to delete\n 6 to exit\n");
		printf("\nEnter the choice::");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			Input(&r1);
			fptr=fopen("Db.txt","a");
			fwrite(&r1,sizeof(r1), 1, fptr);
			fclose(fptr);
			break;
		case 2:
			fptr=fopen("Db.txt","r");
			while(fread(&r2,sizeof(r2),1,fptr))
				Display(&r2);
			fclose(fptr);
			break;
		case 3:
			printf("Enter roll number you want to search::");
			scanf("%d",&temp);
			fptr=fopen("Db.txt","r");
			while(fread(&r2,sizeof(r2),1,fptr))
			{
				if(r2.roll_no==temp)
				{
					printf("Record found!");
					Display(&r2);
					break;
				}
			}
			if(getc(fptr)==EOF)
			{
				printf("Not found!\n");
			}
			fclose(fptr);
			break;
		case 4:
			printf("Enter roll number of the record you want to modify::");
			scanf("%d",&temp);
			if(Modify(temp))
				printf("Modify operation successful!\n ");
			else
				printf("Modify unsuccessful");
			break;
		case 5:
			printf("Enter roll number of the record you want to delete::");
			scanf("%d",&temp);
			if(Delete(temp))
				printf("Delete operation successful!\n ");
			else
				printf("Delete unsuccessful");
			break;
		case 6:return 0;
		default:printf("You have entered invalid option! Try again!\n");
		}
	}while(1);
	return 0;
}

void Display(record* r)
{
	printf("Name=%s\tRoll no=%d\tAddress=%s\n",r->name,r->roll_no,r->address);
}

int Delete(int key)
{
	FILE *fptr1=NULL;
	FILE *fptr2=NULL;
	record r;
	if((fptr1=fopen("Db.txt","r"))==NULL)
		printf("Error in opening file!\n");
	fptr2=fopen("copy.txt","w");
	while(fread(&r,sizeof(struct record),1,fptr1))
	{
		if(r.roll_no!=key)
			fwrite(&r,sizeof(struct record),1,fptr2);
	}
	fclose(fptr1);
	fclose(fptr2);
	int check1=remove("Db.txt");
	int check2=rename("copy.txt","Db.txt");
	if(check1==0 && check2==0)
		return 1;
	else
		return 0;
}



int Modify(int key)
{
	FILE *fptr1=NULL;
	FILE *fptr2=NULL;
	record r;
	if((fptr1=fopen("Db.txt","r"))==NULL)
		printf("Error in opening file!\n");
	fptr2=fopen("copy.txt","w");
	while(fread(&r,sizeof(struct record),1,fptr1))
	{
		if(r.roll_no==key)
			ModifiedInput(&r);
		fwrite(&r,sizeof(struct record),1,fptr2);
	}
	fclose(fptr1);
	fclose(fptr2);
	int check1=remove("Db.txt");
	int check2=rename("copy.txt","Db.txt");
	if(check1==0 && check2==0)
		return 1;
	else
		return 0;
}

void Input(record* s)
{
	//Roll number validations
	int flag=0;
	do{
		if(flag==1)
			printf("You have entered invalid roll number!\n");
		printf("\nEnter roll number::");
		scanf("%d",&s->roll_no);
		if(validateRoll(s->roll_no))
			flag=1;
		else
			flag=0;
	}while(flag==1);
	//Name validations
	flag=0;
	do{
		if(flag==1)
			printf("\nCannot contain numbers!\n");
		printf("\nEnter name::");
		scanf("%s",s->name);
		if(validateName(s->name))
			flag=1;
		else
			flag=0;
	}while(flag==1);
		
		printf("\nEnter address::");
		scanf("%s",s->address);
		
}

void ModifiedInput(record* r)
{
	int choice,flag=0;
	printf("Which field do you want to modify?\n");
	printf("1-Roll number\n2-Name\n3-Address\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			//Roll number validations
			do{
				if(flag==1)
					printf("You have entered invalid roll number!\n");
				printf("Enter roll number:");
				scanf("%d",&r->roll_no);
				if(validateRoll(r->roll_no))
					flag=1;
				else
					flag=0;
			}while(flag==1);
			break;
		case 2:
			//Name validations
			flag=0;
			do{
				if(flag==1)
					printf("Cannot contain numbers!\n");
				printf("Enter name:");
				scanf("%s",r->name);
				if(validateName(r->name))
					flag=1;
				else
					flag=0;
			}while(flag==1);
			break;
		case 3:
	
				printf("Enter percentage");
				scanf("%s",r->address);
				
	}
}

int validateRoll(int rollno)
{
	if(rollno>65538||rollno<0)
		return 1;
	else
		return 0;
}

int validateName(char* str) 
{
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='0'||str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9')
			return 1;
	}
	return 0;
}


/*OUTPUT

itsnasa@nasa:~/Downloads$ gcc 5B.c
itsnasa@nasa:~/Downloads$ ./a.out
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::1

Enter roll number::23141

Enter name::sahil

Enter address::pune
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::2
Name=sahil	Roll no=23141	Address=pune
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::1

Enter roll number::23242

Enter name::nikita

Enter address::pune
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::1

Enter roll number::23143

Enter name::nishita

Enter address::pune
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::2
Name=sahil	Roll no=23141	Address=pune
Name=nikita	Roll no=23242	Address=pune
Name=nishita	Roll no=23143	Address=pune
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::3
Enter roll number you want to search::23141
Record found!Name=sahil	Roll no=23141	Address=pune
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::4
Enter roll number of the record you want to modify::23143
Which field do you want to modify?
1-Roll number
2-Name
3-Address
2
Enter name:atharv
Modify operation successful!
 Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::2
Name=sahil	Roll no=23141	Address=pune
Name=nikita	Roll no=23242	Address=pune
Name=atharv	Roll no=23143	Address=pune
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::5
Enter roll number of the record you want to delete::23242
Delete operation successful!
 Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::2
Name=sahil	Roll no=23141	Address=pune
Name=atharv	Roll no=23143	Address=pune
Enter 1 to Add
2 to display
3 to search
4 to modify
5 to delete
 6 to exit

Enter the choice::6
*/
