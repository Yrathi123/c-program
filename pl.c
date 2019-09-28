/*
 ============================================================================
 Name        : Assign4.c
 Author      : Rucha Shinde
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>



typedef struct
{
	int day,month,year;
}date;

typedef struct
{
  int bookno;
  char bookname[100];
  char author[100];
  int price;
  char publisher[100];
  date dissue;
  date dret;

}library;

void create( library[],int);
void display( library[],int);
void insert(library[],int);
void search(library[],int,int);
void update(library[],int,int);
void delete(library[],int,int);

void main()
{
  int no,ch,i,insbook,sbook,upbook,b,delbook;
  library s[100];

  printf("Enter no. of records you want to enter");

  scanf("%d",&no);

	  create(s,no);



do
{
  printf("\n1.Display\n 2.insert \n 3.search \n 4.update \n 5.Delete \n 6.Exit");
//  fflush(0);
  printf(" \n Enter your choice");
 // fflush(0);
  scanf("%d",&ch);


  switch(ch)
  {
  case 1:
	 printf("\n BOOK ID \t name\t author \t price \t publisher \t date issue \t date ret");
	 display(s,no);
	 break;

  case 2:


	  insert(s,no);
      no++;
       display(s,no);



	  break;
  case 3:
      printf("Enter Id of book which you want to search");
      scanf("%d",&sbook);
      search(s,no,sbook);
      break;




  case 4:
	  printf("Enter Id of a book which you want to update");
	  scanf("%d",&upbook);
	  if(upbook<=no)
	  {
	  update(s,no,upbook);
	  }
	  else

	  printf("Enter correct book id between 1 to %d",no);
	  break;

  case 5:
 	  printf("Enter Id of a book which you want to delete");
 	  scanf("%d",&delbook);
 	  delete(s,no,delbook);
 	   no--;
      display(s,no);
 	  break;


  }

}while(ch!=6);


}


//to input records
void create( library s[100],int no)
{
	int i;
	 for(i=0;i<no;i++)
	  {  printf("Enter data for book no %d",i+1);
		 /// fflush(0);

	    	printf("\n Enter Title of book");
	    	//fflush(0);

	    	scanf("%s",s[i].bookname);

	    	printf("\n Enter author of book");
	    	//fflush(0);
	       //scanf("\n");
	       scanf("%s",s[i].author);

	       printf(" \nEnter price of book");
	       //fflush(0);
	       scanf("%d",&s[i].price);

	       printf(" \n Enter publisher of book");
	       //fflush(0);
	      // scanf("\n");
	       scanf("%s",s[i].publisher);
//date of issue

	       printf("\n Enter date of issue");
	       	//       	       fflush(0);
	       	       	       printf("\n Enter day");
	       	  //     	       	       fflush(0);
	       	       	       scanf("%d",&s[i].dissue.day);
	       	       	       printf("\n Enter month");
	       	    //   	       	       fflush(0);

	       	       	       scanf("%d",&s[i].dissue.month);
	       	       	       printf("\n Enter year");
	       	      // 	       	       fflush(0);
	       	       	       scanf("%d",&s[i].dissue.year);

//date of return

	       printf("\n Enter date of return");
	       	       //fflush(0);
	       	       printf("\n Enter day");
	       	       	 //      fflush(0);
	       	       scanf("%d",&s[i].dret.day);
	       	       printf("\n Enter month");
	       	       //	       fflush(0);

	       	       scanf("%d",&s[i].dret.month);
	       	       printf("\n Enter year");
	       	       	 ///      fflush(0);
	       	       scanf("%d",&s[i].dret.year);

		}
}

void display(library s[100],int no)
{
	int i;
	for(i=0;i<no;i++)
	{
		printf(" \n %d \t",i+1);
		fflush(0);
		printf("    %s ",s[i].bookname);
		fflush(0);
		printf("  %s \t",s[i].author);
		fflush(0);
		printf("%d \t",s[i].price);
		fflush(0);
		printf("%s \t\t",s[i].publisher);
		fflush(0);
		printf("%d-",s[i].dissue.day);
		fflush(0);
		printf("%d-",s[i].dissue.month);
		fflush(0);
		printf("%d \t",s[i].dissue.year);
		fflush(0);
		printf("%d-",s[i].dret.day);
		fflush(0);
		printf("%d-",s[i].dret.month);
		fflush(0);
		printf("%d ",s[i].dret.year);
		fflush(0);

	}
}

void insert (library s[100],int no)


{
	 printf("Enter data for book no %d",no+1);
		 /// fflush(0);

	    	printf("\n Enter Title of book");
	    	//fflush(0);

	    	scanf("%s",s[no].bookname);

	    	printf("\n Enter author of book");
	    	//fflush(0);
	       scanf("\n");
	       scanf("%s",s[no].author);

	       printf(" \nEnter price of book");
	       //fflush(0);
	       scanf("%d",&s[no].price);

	       printf(" \n Enter publisher of book");
	       //fflush(0);
	      scanf("\n");
	       scanf("%s",s[no].publisher);
//date of issue

	       printf("\n Enter date of issue");
	       	//       	       fflush(0);
	       	       	       printf("\n Enter day");
	       	  //     	       	       fflush(0);
	       	       	       scanf("%d",&s[no].dissue.day);
	       	       	       printf("\n Enter month");
	       	    //   	       	       fflush(0);

	       	       	       scanf("%d",&s[no].dissue.month);
	       	       	       printf("\n Enter year");
	       	      // 	       	       fflush(0);
	       	       	       scanf("%d",&s[no].dissue.year);

//date of return

	       printf("\n Enter date of return");
	       	       //fflush(0);
	       	       printf("\n Enter day");
	       	       	 //      fflush(0);
	       	       scanf("%d",&s[no].dret.day);
	       	       printf("\n Enter month");
	       	       //	       fflush(0);

	       	       scanf("%d",&s[no].dret.month);
	       	       printf("\n Enter year");
	       	       	 //      fflush(0);
	       	       scanf("%d",&s[no].dret.year);





}

void search(library s[100],int no,int sbook)
{
	int i,flag=0;
	for(i=0;i<=no;i++)
	{

		if(sbook==i)
		{
          flag=1;

		}

	}
	if(flag==1)
    {

        printf("Book found");
    }
    else{
        printf("Book not found");
    }
}

void update(library s[100],int no,int upbook)
{
	int ch,i;
	for(i=0;i<=no;i++)
	{
		if(upbook==i)
		{
	printf("Enter the field you want to update \n");
	printf("1.TITLE \n 2.AUTHOR \n 3.PRICE \n 4.PUBLISHER \n 5.DATE OF ISSUE \n 6.DATE OF RETURN \n");
	scanf("%d",&ch);;
	switch(ch)
	{
	case 1:
		  printf("\n Enter Title of book");
		  scanf("%s",s[i-1].bookname);
		  break;
	case 2:
		printf("\n Enter author of book");
		scanf("%s",s[i-1].author);
		break;
	case 3:
		  printf(" \nEnter price of book");
		 scanf("%d",&s[i-1].price);
		break;
	case 4:
		 printf(" \n Enter publisher of book");
		scanf("%s",s[i].publisher);
			break;
	case 5:
		 printf("\n Enter date of issue");

			  printf("\n Enter day");
			  scanf("%d",&s[i].dissue.day);
			  printf("\n Enter month");
			  scanf("%d",&s[i].dissue.month);
			  printf("\n Enter year");
			  scanf("%d",&s[i].dissue.year);
			  break;
	case 6:
		  printf("\n Enter date of return");

		 printf("\n Enter day");
	     scanf("%d",&s[i].dret.day);
		  printf("\n Enter month");
	    scanf("%d",&s[i].dret.month);
	     printf("\n Enter year");
		scanf("%d",&s[i].dret.year);
		break;

	}
}

	}
}

void delete(library s[100],int no,int delbook)
{
	  int i;
	while(delbook<=no)
	{
	  s[delbook-1]=s[delbook];
	  delbook++;

      }

}
