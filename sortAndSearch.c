/*
 ============================================================================
 Roll no.    		: 23141
 Class          	: SE - 9
 Batch              : G - 9
 Name         	    : Sahil Naphade
 Assignment no.     : Assignment 6
 Problem Statement  :

=============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct student							//structure creation
	{
        char name[50];
    	int roll_no;
        float per;
	}student;     						    //function declerations
void create(student s[],int n);
void display(student s[],int n);
int binarysearch(int size,struct student s[],int key);
int binarysearchR(int key,struct student s[],int n,int first,int last,int pass,int tcmp);
void bubblesort(struct student s[],int n);
void selectionsort(struct student s[],int n);
void selectionsortN(struct student s[],int n);
void insertionsort(struct student s[],int n);

int main()									//main function
{
	int n,ch,key,c,l,choice1;
	 char temp[5];
	 	int first,last;

    struct student  s[50];
	do{
		 printf("Menu\n1)Create Database\n2)Display Database\n3)bin search\n4)bubble sort\n5)selection sort\n");
		 printf("6)insertion sort\n7)selection sort using name\n8)exit\nEnter your choice::");
         scanf("%d",&ch);
         switch(ch)
         	{
         		case 1:
                         printf("enter the no of students to create database :: ");
	                     scanf("%d",&n);      									 	//create the record
			             create(s,n);
                           break;
         	     case 2:printf("-----------------------------------\n");
				        printf("|NAME      |ROLL NO  |PERCENTAGE  |\n");
				        printf("-----------------------------------\n");			//display record
         			     display(s,n);
         		        printf("-----------------------------------\n");
         			     break;

         		case 3:
         			bubblesort(s,n);

				printf("enter choice\n");
				printf("1 for non-recursive binary search\n2 for recursive binary search\n3)exit");
				scanf("%d",&choice1);


						if(	choice1==1)
						{													    //non recursive binary search
         			  printf("Enter the rollno to be search \n");
         			   scanf("%d",&key);

         			    c=binarysearch(n,s,key);

         			  if(c!=-1)
         			       printf("record found at %d location\n",c+1);
         			  else
         			      printf("record not found\n");

						}
						if(choice1==2)
						{												   // recursive binary search
         			  printf("Enter the rollno to be search \n");
         			   scanf("%d",&key);
         			    first=0;last=n-1;
         			    c=binarysearchR(key,s,n,first,last,0,0);
         			  if(c!=-1)
         			      printf("record found at %d location\n",c+1);
         			  else
         			       printf("record not found\n");
				          }

			    break;
         		case 4:
         			printf("bubble sort is\n");									//bubble sort
         			bubblesort(s,n);
 				    printf("After sorting the database is::\n");
			        display(s,n);
         			break;
         		case 5:
         			printf("selection sort is\n");
         			selectionsort(s,n);											//selection sort
         			printf("After sorting the database is::\n");
         			 display(s,n);
         			break;
                case 6:
         			printf("insertion sort is\n");
         			printf("After sorting the database is::\n");
         			insertionsort(s,n);											//insertion sort
         			 display(s,n);
         			break;
                case 7:
                     printf("selection sort by name is\n");
                    selectionsortN(s,n);							     //selection sort name
                    printf("After sorting the database is::\n");
                    display(s,n);
                     break;
         		case 8:
         		    		 	printf("EXIT");
         		    		   return 0;
         		  default:
         		    			printf("Enter valid choice\n");
          }
         	 }while(1);
    }
void swapss(struct student *s1,struct student *s2)  				//swap function
{
	struct student temp;
	temp=*s1;
	*s1=*s2;
	*s2=temp;

}
void create(student s[],int n)									//create function defination
{
	int i,j;
	for(i=0;i<n;i++)
 	{
   	 printf("Enter the name of students    ::");
   	 scanf("%s",s[i].name);									//scanning name
       printf("Enter the Roll Number of the student\t::\t");
			do{
				scanf("%d",&s[i].roll_no);
				for(j=0;j<=i;j++)
				{
					if(s[i].roll_no == s[j].roll_no) //checking if roll no. are repeated
						break;
				}
			
				if(j<i)
				{
					printf("Roll no. cannot be repeated\n");
					printf("Enter roll no. again\t::\t");
				}
				else break;
			}while(1);

    do
		{													//validation for percentage
      	 puts("Enter the percentage::");
       	 scanf("%f",&s[i].per);						//scanning percentage
    	  	 if(s[i].per>=100.00)
    	    	 printf("Please,Enter the valid percentage\n");
    	}while(s[i].per>100.00);
	}// end of for
}
void display(student s[],int n)								//display function defination
{   int i;
 for(i=0;i<n;i++)
	{
printf("|  %-8s| %-8d|  %-10f |\n",s[i].name,s[i].roll_no,s[i].per);
	}
}

int binarysearch(int n,struct student s[],int key)		//binary search function defination
{
	int low=0,high=n-1,mid;
	int pass=0;
	int cmp;
	int tcmp=0;
	while(low<=high)
	{   cmp=0;
	    pass++;
		mid=(low+high)/2;
		printf("pass\tlow\thigh\tmid\ts[mid]\tcomparisons\n");
		printf("%d\t%d\t%d\t%d\t%d\t",pass,low,high,mid,s[mid].roll_no);
		if(s[mid].roll_no==key)
		{
		    cmp++;
			tcmp++;
			printf("%d\n",cmp);
			printf("BINARY SEARCH ANALYSIS\n");
			printf("TOTAL DATABASE::%d\nTotal comparisons::%d\n",n,tcmp);
			return mid;
		}
	    else
	    {
	    cmp++;
		tcmp++;
	    }
			
		if(s[mid].roll_no<key)
		{
		 cmp++;
		 tcmp++;
		 low=mid+1;		  
	    }
		else
		{  
		    cmp++;
		    tcmp++;
			high=mid-1;
		}
		printf("%d\n",cmp);
	}
	return -1;
}
int binarysearchR(int key,struct student s[],int n,int first,int last,int pass,int tcmp) //binary search recurrsive function defination
{ int cmp,mid;
	while(first<=last) 
	{
		cmp=0;
	    pass++;
		 mid=(first+last)/2;
		printf("pass\tfirst\tlast\tmid\ts[mid]\tcomparisons\n");
		printf("%d\t%d\t%d\t%d\t%d\t",pass,first,last,mid,s[mid].roll_no);
		if(s[mid].roll_no==key)
		{
		    cmp++;
			tcmp++;
			printf("%d\n",cmp);
			printf("BINARY SEARCH ANALYSIS\n");
			printf("TOTAL DATABASE::%d\nTotal comparisons::%d\n",n,tcmp);
			return mid;
		}
	    else
	    {
	    cmp++;
		tcmp++;
	    }
			
		if(s[mid].roll_no<key)
		{
		 cmp++;
		 tcmp++;
		 printf("%d\n",cmp);
		  return binarysearchR(key,s,n,mid+1,last,pass,tcmp);		  
	    }
		else
		{  
		    cmp++;
		    tcmp++;
		    printf("%d\n",cmp);
			return binarysearchR(key,s,n,first,mid-1,pass,tcmp);	
		}
	}
	return -1;
}
void bubblesort(struct student s[],int n)										//bubble sort function defination
	{   int j,i,k,pass=0,swaps,cmp=0,w=0,m=0;
	    struct student temp;
			for(i=0;i<n-1;i++) 													//outer loop for no. of pass
				{ swaps=0;cmp=0;
				if(pass==0)
				{

				   printf("pass\tlist\t\t\tswap\tcomparisons\t\n");
		           printf("%d\t",pass);
					for(k=0;k<n;k++)
		        {
		           printf("%d ",s[k].roll_no);

				}
			    	printf("\t\t");
		            printf("%d\t%d\t\n",swaps,cmp);
				}
		                 pass++;
					for(j=0;j<n-i-1;j++) 										//inner loop for no. of comparison
					{ cmp++;m++;
						if(s[j].roll_no>s[j+1].roll_no)
						 {     swaps++;w++;
							temp=s[j];
							s[j]=s[j+1];
							s[j+1]=temp;
						  }
					}
		printf("%d\t",pass);
		for(k=0;k<n;k++)
		{
			printf("%d ",s[k].roll_no);
		}
		printf("\t\t");
		printf("%d\t%d\t\n",swaps,cmp);
		if(swaps==0)
		{
			break;
		}
				}
				printf("total swaps are %d\n",w);
				printf("total comparisons are %d\n",m);
				if(w==1)
				printf("best case algorithm\n");
				else if(m==(n*(n-1))/2)
				printf("worst case algorithm\n");
				else
				printf("average case algorithm\n");
	}
	void selectionsort(struct student s[],int n)						//selection sort function defination
	{    int j,i,min_idx,k,pass=0,swaps,cmp=0,w=0,m=0;
		 for(i=0;i<n-1;i++) 										//outer loop for no. of pass
			{
			swaps=0;cmp=0;
				if(pass==0)
				{
				   printf("pass\tlist\t\t\tswap\tcomparisons\t\n");
		           printf("%d\t",pass);
					for(k=0;k<n;k++)
		        {
		           printf("%d ",s[k].roll_no);
				}
			    	printf("\t\t");
		            printf("%d\t%d\t\n",swaps,cmp);
				}
		                 pass++;
						 min_idx=i;
					for(j=i+1;j<n;j++) 									//inner loop for no. of comparison
					{  cmp++;m++;
						if(s[min_idx].roll_no>s[j].roll_no)
							min_idx=j;
					}
					 swaps++;w++;
					swapss(&s[i],&s[min_idx]);
						printf("%d\t\t",pass);
		for(k=0;k<n;k++)
		{
			printf("%d ",s[k].roll_no);
		}
		printf("\t\t");
		printf("%d\t\t%d\t\n",swaps,cmp);
		if(swaps==0)
		{
			break;
		}
			}
			     printf("total swaps are %d\n",w);
				printf("total comparisons are %d\n",m);
				if(w==0)
				printf("best case algorithm\n");
				else if(m==(n*(n-1))/2)
				printf("worst case algorithm\n");
				else
				printf("average case algorithm\n");
	}
	 void selectionsortN(struct student s[],int n)					//selection sort name function defination
	 { 	int j,i,min_idx,k,pass=0,swaps,cmp=0,w=0,m=0;
		 for(i=0;i<n-1;i++) 										//outer loop for no. of pass
			{
			swaps=0;cmp=0;
				if(pass==0)
				{
				   printf("pass\tlist\t\t\tswap\t\tcomparisons\t\n");
		           printf("%d\t",pass);
					for(k=0;k<n;k++)
		        {
		           printf("%s  ",s[k].name);
				}
			    	printf("\t\t");
		            printf("%d\t%d\t\n",swaps,cmp);
				}
		                 pass++;
						 min_idx=i;
					for(j=i+1;j<n;j++) 									//inner loop for no. of comparison
					{  cmp++;m++;
						if((strcmp(s[j].name,s[min_idx].name)>0))
							min_idx=j;
					}
					 swaps++;w++;
					swapss(&s[min_idx],&s[i]);
						printf("%d\t\t",pass);
		for(k=0;k<n;k++)
		{
			printf("%s  ",s[k].name);
		}
		printf("\t\t");
		printf("%d\t\t%d\t\n",swaps,cmp);
		if(swaps==0)
		{
			break;
		}
			}
			     printf("total swaps are %d\n",w);
				printf("total comparisons are %d\n",m);
				if(w==0)
				printf("best case algorithm\n");
				else if(m==(n*(n-1))/2)
				printf("worst case algorithm\n");
				else
				printf("average case algorithm\n");
	 }
void insertionsort(struct student s[],int n)							//insertion sort function defination
{
	int j=1,i,k,q,pass=0,swaps,cmp=0,w=0,m=0;
	struct student temp;
	for(i=0;i<n-1;i++)												//outer loop for no. of pass
	  {     swaps=0;cmp=0;
				if(pass==0)
				{
				   printf("pass\tlist\t\t\tswap\t\tcomparisons\t\n");
		           printf("%d\t",pass);
					for(q=0;q<n;q++)
		        {
		           printf("%d ",s[q].roll_no);
				}
			    	printf("\t\t");
		            printf("%d\t%d\t\n",swaps,cmp);
				}
		          pass++;
		       k=j-1;
		      temp=s[j];
	    while(k>=0&&s[k].roll_no>temp.roll_no)				     //inner loop for no. of comparison
		   {   cmp++;m++;
		       swaps++;w++;
			   s[k+1]=s[k];			  
		       k--;
		    }	         
	            s[k+1]=temp;
	            j++;
	          printf("%d\t\t",pass);
		      for(q=0;q<n;q++)
		        {
			        printf("%d ",s[q].roll_no);
		        }
					printf("\t\t");
					printf("%d\t\t%d\t\n",swaps,cmp);
	   }
	            printf("total swaps are %d\n",w);
				printf("total comparisons are %d\n",m);
				if(w==0)
				printf("best case algorithm\n");
				else if(m==(n*(n-1))/2)
				printf("worst case algorithm\n");
				else
				printf("average case algorithm\n");
   }


//								OUTPUT OF THE CODE
/*
g9@c30402-OptiPlex-3010:~/23141/PL/sortAndSearch/src$ gcc sortAndSearch.c
g9@c30402-OptiPlex-3010:~/23141/PL/sortAndSearch/src$ ./a.out
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::1
enter the no of students to create database :: 4
Enter the name of students    ::weginwar
Enter the Roll Number of the student	::	22314
Enter the percentage::
89
Enter the name of students    ::medhavi
Enter the Roll Number of the student	::	22334
Enter the percentage::
96
Enter the name of students    ::nikita
Enter the Roll Number of the student	::	23142
Enter the percentage::
95
Enter the name of students    ::akash
Enter the Roll Number of the student	::	21128
Enter the percentage::
98
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::2
-----------------------------------
|NAME      |ROLL NO  |PERCENTAGE  |
-----------------------------------
|  weginwar| 22314   |  89.000000  |
|  medhavi | 22334   |  96.000000  |
|  nikita  | 23142   |  95.000000  |
|  akash   | 21128   |  98.000000  |
-----------------------------------
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::3
pass	list			swap	comparisons	
0	22314 22334 23142 21128 		0	0	
1	22314 22334 21128 23142 		1	3	
2	22314 21128 22334 23142 		1	2	
3	21128 22314 22334 23142 		1	1	
total swaps are 3
total comparisons are 6
worst case algorithm
enter choice
1 for non-recursive binary search
2 for recursive binary search
3)exit2
Enter the rollno to be search 
22314
pass	first	last	mid	s[mid]	comparisons
1	0	3	1	22314	1
BINARY SEARCH ANALYSIS
TOTAL DATABASE::4
Total comparisons::1
record found at 2 location
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::7
selection sort by name is
pass	list			swap		comparisons	
0	akash  weginwar  medhavi  nikita  		0	0	
1		weginwar  akash  medhavi  nikita  		1		3
2		weginwar  nikita  medhavi  akash  		1		2
3		weginwar  nikita  medhavi  akash  		1		1
total swaps are 3
total comparisons are 6
worst case algorithm
After sorting the database is::
|  weginwar| 22314   |  89.000000  |
|  nikita  | 23142   |  95.000000  |
|  medhavi | 22334   |  96.000000  |
|  akash   | 21128   |  98.000000  |
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::6
insertion sort is
After sorting the database is::
pass	list			swap		comparisons	
0	22314 23142 22334 21128 		0	0	
1		22314 23142 22334 21128 		0		0	
2		22314 22334 23142 21128 		1		1	
3		21128 22314 22334 23142 		3		3	
total swaps are 4
total comparisons are 4
average case algorithm
|  akash   | 21128   |  98.000000  |
|  weginwar| 22314   |  89.000000  |
|  medhavi | 22334   |  96.000000  |
|  nikita  | 23142   |  95.000000  |
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::5
selection sort is
pass	list			swap	comparisons	
0	21128 22314 22334 23142 		0	0	
1		21128 22314 22334 23142 		1		3	
2		21128 22314 22334 23142 		1		2	
3		21128 22314 22334 23142 		1		1	
total swaps are 3
total comparisons are 6
worst case algorithm
After sorting the database is::
|  akash   | 21128   |  98.000000  |
|  weginwar| 22314   |  89.000000  |
|  medhavi | 22334   |  96.000000  |
|  nikita  | 23142   |  95.000000  |
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::4
bubble sort is
pass	list			swap	comparisons	
0	21128 22314 22334 23142 		0	0	
1	21128 22314 22334 23142 		0	3	
total swaps are 0
total comparisons are 3
average case algorithm
After sorting the database is::
|  akash   | 21128   |  98.000000  |
|  weginwar| 22314   |  89.000000  |
|  medhavi | 22334   |  96.000000  |
|  nikita  | 23142   |  95.000000  |
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::9
Enter valid choice
Menu
1)Create Database
2)Display Database
3)bin search
4)bubble sort
5)selection sort
6)insertion sort
7)selection sort using name
8)exit
Enter your choice::8
EXITg9@c30402-OptiPlex-3010:~/23141/PL/sortAndSearch/src$ 

*/
