/*Create an exam result generator system at University level application using C programming language. */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void adminchoice1();
void studentchoice1(char *);
void adminchoice3();
void adminchoice4();
void studentchoice3(char *);
void studentchoice4(char *);
int checkstudent(char*,char*);
int checkAdmin(char *,char *);
FILE *fp,*fp1,*fp2,*fp3,*fp4;
int count,count1;
struct teachers
{
	int regno;
	char name[30];
	int marks[3];
	int total;
	float percentage;
	char grade[5];
	
};
struct teachers *details,*details1;
void display()
{
	printf("-----UNIVERSITY LEVEL APPLICATION-----\n");
	printf("Press 1 to login as Admin\n");
	printf("Press 2 to login as Student\n");
	printf("Press 3 to exit the Application\n");
}
void adminchoice1()
{
	printf("Welcome Admin\n");
	printf("-----ADMIN PAGE-----\n");
	printf("press 1 to add a student in semester 7\n");
	printf("press 2 to add a student in semester 8\n");
	printf("press 3 to view students in semester 7\n");
	printf("press 4 to view students in semester 8\n");
	printf("press 5 to log out\n");
	int Adminchoice;
	printf("enter your choice:");
	scanf("%d",&Adminchoice);
	switch(Adminchoice)
	{
		case 1:
			printf("Add a student marks in semester 7\n");
			fp=fopen("add_students.txt","a");
			
			printf("enter reg no of the student:");
			scanf("%d",&details[count].regno);
			printf("enter name of the student:");
			scanf("%s",&details[count].name);
			printf("enter marks of the student");
			for(int i=1;i<=3;i++)
			{
				printf("mark%d:",i);
				scanf("%d",&details[count].marks[i-1]);
			}
			int total=0;
			for(int i=0;i<3;i++)
			{
				total=total+details[count].marks[i];
			}
			details[count].total=total;
			float percentage=(float)total/3;
			details[count].percentage=percentage;
			if(total>90)
			{
				strcpy(details[count].grade,"A");
			}
			else if(total>50)
			{
				strcpy(details[count].grade,"B");
			}
			else
			{
				strcpy(details[count].grade,"C");
			}
			fprintf(fp,"Reg No:%d\n",details[count].regno);
			fprintf(fp,"Name:%s\n",details[count].name);
			for(int i=0;i<3;i++)
			{
				fprintf(fp,"Mark%d:%d\n",i+1,details[count].marks[i]);
			}
			fprintf(fp,"Total:%d\n",details[count].total);
			fprintf(fp,"Percentage:%f\n",details[count].percentage);
			fprintf(fp,"Grade:%s\n",details[count].grade);
			count++;
			fp1=fopen("count.txt","w");
			fprintf(fp1,"%d",count);
			
			fclose(fp);
			fclose(fp1);
			adminchoice1();
			break;
		case 2:
			printf("Add a student marks in semester 8\n");
			fp=fopen("add_students1.txt","a");
			
			printf("enter reg no of the student:");
			scanf("%d",&details1[count1].regno);
			printf("enter name of the student:");
			scanf("%s",&details1[count1].name);
			printf("enter marks of the student");
			for(int i=1;i<=3;i++)
			{
				printf("mark%d:",i);
				scanf("%d",&details1[count1].marks[i-1]);
			}
			total=0;
			for(int i=0;i<3;i++)
			{
				total=total+details1[count1].marks[i];
			}
			details1[count1].total=total;
			percentage=(float)total/3;
			details1[count1].percentage=percentage;
			if(total>90)
			{
				strcpy(details1[count1].grade,"A");
			}
			else if(total>50)
			{
				strcpy(details1[count1].grade,"B");
			}
			else
			{
				strcpy(details1[count1].grade,"C");
			}
			fprintf(fp,"Reg No:%d\n",details1[count1].regno);
			fprintf(fp,"Name:%s\n",details1[count1].name);
			for(int i=0;i<3;i++)
			{
				fprintf(fp,"Mark%d:%d\n",i+1,details1[count1].marks[i]);
			}
			fprintf(fp,"Total:%d\n",details1[count1].total);
			fprintf(fp,"Percentage:%f\n",details1[count1].percentage);
			fprintf(fp,"Grade:%s\n",details1[count1].grade);
			count1++;
			fp1=fopen("count1.txt","w");
			fprintf(fp1,"%d",count1);
			
			fclose(fp);
			fclose(fp1);
			adminchoice1();
			break;
		case 3:
			printf("Student details in semester 7\n");
			adminchoice3();
			printf("\n");
			adminchoice1();
			break;
		case 4:
			printf("Student details in semester 8\n");
			adminchoice4();
			printf("\n");
			adminchoice1();
			break;
		case 5:
			printf("Successfully Logged out\n");
			break;
		default:
			printf("you pressed a wrong key.press a proper key\n");
			adminchoice1();
			printf("\n");
	}	
	
}
void adminchoice3()
{
	fp2=fopen("add_students.txt","r");
	printf("    Reg No  |   Student Name  |  Mark1  |  Mark2  |  Mark 3  |  total  |  percentage  |  grade\n");
	char str[50];
	char *p;
	int i=0;
	while(fgets(str,sizeof(str),fp2)!=NULL)
	{
		str[strcspn(str,"\n")]=0;
		p=strtok(str,":");
		p=strtok(NULL," ");
		printf("     %s   ",p);
		i++;
		if(i==8)
		{
			printf("\n");
			i=0;
		}
	}
	fclose(fp2);
}
void adminchoice4()
{
	fp2=fopen("add_students1.txt","r");
	printf("    Reg No  |   Student Name  |  Mark1  |  Mark2  |  Mark 3  |  total  |  percentage  |  grade\n");
	char str[50];
	char *p;
	int i=0;
	while(fgets(str,sizeof(str),fp2)!=NULL)
	{
		str[strcspn(str,"\n")]=0;
		p=strtok(str,":");
		p=strtok(NULL," ");
		printf("     %s   ",p);
		i++;
		if(i==8)
		{
			printf("\n");
			i=0;
		}
	}
	fclose(fp2);
}
int checkAdmin(char *str1,char *str2)
{
	char str[50],copy[50];
	fp2=fopen("Teachers.txt","r");
	while(1)
	{
		if(fgets(str,sizeof(str),fp2))
		{
			str[strcspn(str,"\n")]=0;
			strcpy(copy,"Username:");
			strcat(copy,str1);
			if(strcmp(copy,str)==0)
			{
				printf("username:%s\n",str1);
				fgets(str,sizeof(str),fp2);
				str[strcspn(str,"\n")]=0;
				strcpy(copy,"Password:");
				strcat(copy,str2);
				if(strcmp(copy,str)==0)
				{
					printf("password:%s\n",str2);
					printf("user exists\n");
					return 1;
				}
				else
				{
					printf("invalid password\n");
					return 0;
				}
					
					
			}
		}
		else
		{
			return 0;
		}
		
	}fclose(fp2);
}
void studentchoice1(char *student)
{
	printf("Welcome Student\n");
	printf("-----STUDENT PAGE-----\n");
	printf("press 1 to view marks in semester 7\n");
	printf("press 2 to view marks in semester 8\n");
	printf("press 3 to log out\n");
	int studentchoice;
	printf("enter your choice:");
	scanf("%d",&studentchoice);
	switch(studentchoice)
	{
		case 1:
			printf("Student details in semester 7\n");
			studentchoice3(student);
			printf("\n");
			studentchoice1(student);
			break;
		case 2:
			printf("Student details in semester 8\n");
			studentchoice4(student);
			printf("\n");
			studentchoice1(student);
			break;
		case 3:
			printf("Successfully Logged out\n");
			break;
		default:
			printf("you pressed a wrong key.press a proper key\n");
			studentchoice1(student);
			printf("\n");
	}	
	
}
void studentchoice3(char * student)
{
	
	fp4=fopen("add_students.txt","r");
	char str[50],ch[50];
	printf("    Reg No  |   Student Name  |  Mark1  |  Mark2  |  Mark 3  |  total  |  percentage  |  grade\n");
	int i=0;
	char *p,*p1;
	while(fgets(str,sizeof(str),fp4))
	{
		strcpy(ch,str);
		ch[strcspn(ch,"\n")]=0;
		p1=strtok(ch,":");
		p1=strtok(NULL," ");
		fgets(str,sizeof(str),fp4);
		str[strcspn(str,"\n")]=0;
		p=strtok(str,":");
		p=strtok(NULL," ");
		int x=2,y=0;
		if(!(strcmp(p,student)))
		{
			printf("    %s   ",p1);
			i++;
			while(x<9)
			{
				printf("     %s   ",p);
				fgets(str,sizeof(str),fp4);
				str[strcspn(str,"\n")]=0;
				p=strtok(str,":");
				p=strtok(NULL," ");
				x++;
			}
			break;
			
		}
		while(y<6)
		{
			fgets(str,sizeof(str),fp4);
			y++;
		}
		
	}
	fclose(fp4);
	
}
void studentchoice4(char *student)
{
	fp4=fopen("add_students1.txt","r");
	char str[50],ch[50];
	printf("    Reg No  |   Student Name  |  Mark1  |  Mark2  |  Mark 3  |  total  |  percentage  |  grade\n");
	int i=0;
	char *p,*p1;
	while(fgets(str,sizeof(str),fp4))
	{
		strcpy(ch,str);
		ch[strcspn(ch,"\n")]=0;
		p1=strtok(ch,":");
		p1=strtok(NULL," ");
		fgets(str,sizeof(str),fp4);
		str[strcspn(str,"\n")]=0;
		p=strtok(str,":");
		p=strtok(NULL," ");
		int x=2,y=0;
		if(!(strcmp(p,student)))
		{
			printf("    %s   ",p1);
			i++;
			while(x<9)
			{
				printf("     %s   ",p);
				fgets(str,sizeof(str),fp4);
				str[strcspn(str,"\n")]=0;
				p=strtok(str,":");
				p=strtok(NULL," ");
				x++;
			}
			break;
			
		}
		while(y<6)
		{
			fgets(str,sizeof(str),fp4);
			y++;
		}
		
	}
	fclose(fp4);
}
int checkstudent(char *str1,char *str2)
{
	char str[50],copy[50];
	fp2=fopen("Students.txt","r");
	while(1)
	{
		if(fgets(str,sizeof(str),fp2))
		{
			str[strcspn(str,"\n")]=0;
			strcpy(copy,"Username:");
			strcat(copy,str1);
			if(strcmp(copy,str)==0)
			{
				printf("username:%s\n",str1);
				fgets(str,sizeof(str),fp2);
				str[strcspn(str,"\n")]=0;
				strcpy(copy,"Password:");
				strcat(copy,str2);
				if(strcmp(copy,str)==0)
				{
					printf("password:%s\n",str2);
					printf("user exists\n");
					return 1;
				}
				else
				{
					printf("invalid password\n");
					return 0;
				}
					
					
			}
		}
		else
		{
			return 0;
		}
	}fclose(fp2);
}
int main()
{
	details=malloc(sizeof(struct teachers)*100);
	
	details1=malloc(sizeof(struct teachers)*100);
	char ch[50];
	fp2=fopen("count.txt","r");
	fgets(ch,sizeof(ch),fp2);
	count=atoi(ch);
	fclose(fp2);
	
	fp2=fopen("count1.txt","r");
	fgets(ch,sizeof(ch),fp2);
	count1=atoi(ch);
	fclose(fp2);
	
	fp2=fopen("add_students.txt","r");
	char str[50];
	for(int i=0;i<count;i++)
	{
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		details[i].regno=atoi(str);
		
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		strcpy(details[i].name,str);
		
		for(int j=0;j<3;j++)
		{
			fgets(str,sizeof(str),fp2);
			str[strcspn(str,"\n")]=0;
			details[i].marks[j]=atoi(str);
		}
		
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		details[i].total=atoi(str);
		
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		details[i].percentage=atoi(str);
		
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		strcpy(details[i].grade,str);
		
	
	}
	fclose(fp2);
	fp2=fopen("add_students1.txt","r");
	for(int i=0;i<count1;i++)
	{
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		details1[i].regno=atoi(str);
		
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		strcpy(details1[i].name,str);
		
		for(int j=0;j<3;j++)
		{
			fgets(str,sizeof(str),fp2);
			str[strcspn(str,"\n")]=0;
			details1[i].marks[j]=atoi(str);
		}
		
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		details1[i].total=atoi(str);
		
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		details1[i].percentage=atoi(str);
		
		fgets(str,sizeof(str),fp2);
		str[strcspn(str,"\n")]=0;
		strcpy(details1[i].grade,str);
		
	
	}
	fclose(fp2);
	printf("-----UNIVERSITY LEVEL APPLICATION-----\n");
	printf("Press 1 to login as Admin\n");
	printf("Press 2 to login as Student\n");
	printf("Press 3 to exit the Application\n");
	int choice;
	do
	{
		printf("enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("you chose to login as Admin\n");
			char admin[50],password1[50];
			printf("enter username:");
			scanf("%s",admin);
			printf("enter password:");
			scanf("%s",password1);
			if(checkAdmin(admin,password1))
			{	
				adminchoice1();
			}
			else
			{
				printf("Invalid Admin credentials\n");
			}
			display();
			break;
		case 2:
			printf("you chose to login as Student\n");
			char student[50],password2[50];
			printf("enter username:");
			scanf("%s",student);
			printf("enter password:");
			scanf("%s",password2);
			if(checkstudent(student,password2))
			{	
				studentchoice1(student);
			}
		 	else
			{
				printf("Invalid Student credentials\n");
			}
			display();
			break;
		case 3:
			printf("You chose exit\nThank you for using our Application\n");
			exit(0);
		default:
			printf("you pressed a wrong key.press a proper key\n");
			display();
		}
	}while(choice!=3);
	return 0;
}