#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include <ctype.h>

#define N 150


int k=0, R=0, L=0, P=0;
int t;
int x=0;
float current_sum = 0;
int Size = 0;



char AA[4] = "A+";	// for graded
char BB[4] = "A";
char CC[4] = "A-";
char DD[4] = "B+";
char EE[4] = "B";
char FF[4] = "B-";
char GG[4] = "C+";
char HH[4] = "C";
char WW[4] = "C-";
char UU[4] = "D";
char ZZ[4] = "F";


//---------------------------------------------        S      T      R      U       C       T      ---------------------------------------------------------------------//


struct GPA
{
	float overall_gpa;
	int num_of_semester_sofar;
	float individual_gpa [10];
};

struct Credit_hours
{
	int max;
	int finished;
	int current;
	int remaining;
};

	struct FMarks
		{
			int fseven_mark;
			int ftwelve_mark;
			int fyear_work;
			int ffinal_exam_mark;
			int fsum_of_marks;
		};

	struct	FCourse_tutors
		{
			char flecturer_first[15];
			char flecturer_middle[15];
			char flecturer_last[15];

			char fgta_first[15];
			char fgta_middle[15];
			char fgta_last[15];

			char flab_gta_first[15];
			char flab_gta_middle[15];
			char flab_gta_last[15];
		};

	struct Finished_course
	{
		char fcode [15];
		char fcourse_name [20];
		int fcourse_credit_hours;
		int ftimes_take_course;
		int fsemester;
		int fyear;
		struct	FCourse_tutors fcourse_tutors;
		struct FMarks fmarks;
		char fgrade[5];
		float fpoint;
		float fabsence;
	};

	struct Finished
	{
		int fnum_of_courses;
		float sum;
		int ftotal_credit_hours;
		struct Finished_course finished_course[100];
	};



	struct Marks
		{
			int seven_mark;
			int twelve_mark;
			int year_work;
			int final_exam_mark;
			int sum_of_marks;
		};

	struct	Course_tutors
		{
			char lecturer_first[15];
			char lecturer_middle[15];
			char lecturer_last[15];

			char gta_first[15];
			char gta_middle[15];
			char gta_last[15];

			char lab_gta_first[15];
			char lab_gta_middle[15];
			char lab_gta_last[15];
		};

	struct Current_course
	{
		char code [15];
		char course_name [20];
		int course_credit_hours;
		int times_take_course;
		int semester;
		int year;
		struct	Course_tutors course_tutors;
		struct Marks marks;
		char grade [5];
		float point;
		float absence;
	};

	struct Current
	{
		int num_of_courses;
		int total_credit_hours;
		float sum;
		struct Current_course current_course[8];
	};

struct Courses
{
	struct Finished finished;
	struct Current current;
	int j;
};




struct Date_payment
{
	int day;
	int month;
	int year;
};


struct Details
{
	double amount;
	int trans_no;
	char bank [15];
	double percentage;
    double amount_deducted;
	struct Date_payment date_payment;

};

struct Payment
{
	char type [20];
	int no_pay_done;
	double total_paid;
	struct Details details[20];
	int j;

};



struct Contact
{
	char email[30];
	char phone_no [15];
	char mobile [15];
};

struct Birth
{
	int day;
	int month;
	int year;
};

struct mailing_address
{
	int mflat;
	int mhouse;
	char mstreet[20];
	char marea[20];
	char mcity[20];
	char mgovernorate[20];
	char mcountry[20];
	int mpostal;
};

struct home_address
{
	int flat;
	int house;
	char street[20];
	char area[20];
	char city[20];
	char governorate[20];
	char country[20];
	int postal;
};


struct Student
	{
	char first[15];
	char middle[15];
	char last[15];
	char regist[15];
	char nationality[10];

	char tutor_name[15];
	char tutor_code[15];

	char type[20];
	int no;
	int validity;
	
	struct mailing_address mail;
	struct home_address home;
	char gender[10];
	struct Birth birth;
	int AGES;
	int first_enrol_term;
	int first_enrol_year;
	int curr_term;
	char dept[20];
	
	struct Contact contact;
	struct Payment payment;
	struct Courses courses;
	struct Credit_hours credit_hours;
	struct GPA gpa;
	}Student [N];

//-----------------------------------------------------        A        D        D        -----------------------------------------------------------------------------------------------//


void GPA(int i)
{
	int j;

	float finished_sum = 0;

	finished_sum = finished_sum + Student[i].courses.finished.sum;
	//for(j=0 ; j < 100; j++)
	//{
		//Student[i].courses.current.current_course[j].point = 0;
	//}

//	individual_gpa[R] = current_sum / Student[i].credit_hours.current;


	Student[i].gpa.overall_gpa = finished_sum / Student[i].credit_hours.finished;


}

void add_marks(int i,int j, int m)
{
	int h;

	printf("\n\t\t\t\t\tName : %s %s %s ",Student[i].first,Student[i].middle,Student[i].last);
	printf("\n\t\t\t\t\tcourse : %s",Student[i].courses.current.current_course[j].course_name);
	printf("\n\t\t\t\t\t-------------------------\n");


	loop1:
	printf("\n\t\t\t\t\tEnter 7th mark : ");
    scanf("%d", &Student[i].courses.current.current_course[j].marks.seven_mark);
    fflush(stdin);
    if(Student[i].courses.current.current_course[j].marks.seven_mark > 30 || Student[i].courses.current.current_course[j].marks.seven_mark <0 )
    {
    	printf("\n\t\t\t\t\tNOT CORRECT");
    	printf("\n\t\t\t\t\tTry again");
   		getch();
   		system("cls");
   		goto loop1;
	}



	loop2:
    printf("\n\t\t\t\t\tEnter 12th mark : ");
    scanf("%d", &Student[i].courses.current.current_course[j].marks.twelve_mark);
    fflush(stdin);
    if(Student[i].courses.current.current_course[j].marks.twelve_mark > 20 || Student[i].courses.current.current_course[j].marks.twelve_mark < 0 )
    {
    	printf("\n\t\t\t\t\tNOT CORRECT");
    	printf("\n\t\t\t\t\tTry again");
   		getch();
   		system("cls");
   		goto loop2;
	}

     if (m==1)
	{
		loop3:
    printf("\n\t\t\t\t\tEnter year work mark : ");
    scanf("%d", &Student[i].courses.current.current_course[j].marks.year_work);
    fflush(stdin);
    
    if(Student[i].courses.current.current_course[j].marks.year_work > 10 || Student[i].courses.current.current_course[j].marks.year_work < 0 )
    {
    	printf("\n\t\t\t\t\tNOT CORRECT");
    	printf("\n\t\t\t\t\tTry again");
   		getch();
   		system("cls");
   		goto loop3;
	}


    	loop4:
	printf("\n\t\t\t\t\tEnter final exam mark : ");
    scanf("%d", &Student[i].courses.current.current_course[j].marks.final_exam_mark);
    fflush(stdin);
    
	if(Student[i].courses.current.current_course[j].marks.final_exam_mark > 40 || Student[i].courses.current.current_course[j].marks.final_exam_mark < 0 )
    {
    	printf("\n\t\t\t\t\tNOT CORRECT");
    	printf("\n\t\t\t\t\tTry again");
   		getch();
   		system("cls");
   		goto loop4;
	}
	printf("\n\t\t\t\t\tEnter student percentage absence during the course : ");
	scanf("%f",&Student[i].courses.current.current_course[j].absence);
		Student[i].courses.current.current_course[j].marks.sum_of_marks = Student[i].courses.current.current_course[j].marks.seven_mark + Student[i].courses.current.current_course[j].marks.twelve_mark + Student[i].courses.current.current_course[j].marks.year_work + Student[i].courses.current.current_course[j].marks.final_exam_mark;
	
		if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 94 )
    	{
			strcpy( Student[i].courses.current.current_course[j].grade, AA);
			Student[i].courses.current.current_course[j].point = 12;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 89 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, BB);;
    		Student[i].courses.current.current_course[j].point = 11.5;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 84 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, CC);
    		Student[i].courses.current.current_course[j].point = 11;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 79 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, DD);
    		Student[i].courses.current.current_course[j].point = 10;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 74 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, EE);
    		Student[i].courses.current.current_course[j].point = 9;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 69 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, FF);
    		Student[i].courses.current.current_course[j].point = 8;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 64 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, GG);
    		Student[i].courses.current.current_course[j].point = 7;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 59 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, HH);
    		Student[i].courses.current.current_course[j].point = 6;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 54 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, WW);
    		Student[i].courses.current.current_course[j].point = 5;
		}
	
		else if(Student[i].courses.current.current_course[j].marks.sum_of_marks > 49 )
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, UU);
    		Student[i].courses.current.current_course[j].point = 4;
		}
	
		else
    	{
    		strcpy( Student[i].courses.current.current_course[j].grade, ZZ);
    		Student[i].courses.current.current_course[j].point = 0;
    		Student[i].courses.current.current_course[j].times_take_course = Student[i].courses.current.current_course[j].times_take_course + 1;
		}

		finished_courses(i);
		x++;
		L = L + 1;
		GPA(i);
		P++;

	Loop10:
	printf("\n\t\t\t\t\tDid you fill ALL COURSES MARKS ??");
	printf("\n\t\t\t\t\t1. YES\n\t\t\t\t\t0. NO\n\t\t\t\t\t");
    scanf("%d",&h);
    
	if(h == 1)
    {
    	Student[i].gpa.num_of_semester_sofar = Student[i].gpa.num_of_semester_sofar + 1;
    	Student[i].curr_term = Student[i].first_enrol_term + 1;
    
		for(j=0 ; j < 8; j++)
		{
			current_sum	= current_sum + Student[i].courses.current.current_course[j].point;
		}
    	x=0;
    	Student[i].gpa.individual_gpa[R] = current_sum / Student[i].credit_hours.current;
    	current_sum = 0;
    
		for(j=0;j<8;j++)
    	{
    		char e[5] = "NULL";
    		 Student[i].courses.current.current_course[j].point = 0;
    		 strcpy(Student[i].courses.current.current_course[j].code,e);
		}

		R++;
	}
    
	else if (h==0)
    {
    	printf("\n\t\t\t\t\tPress any key\n\t\t\t\t\t");
		getch();
	}
	
	else {

		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto Loop10;

		}

	}


}



void finished_courses(int i)
{
	int j;
	Student[i].courses.finished.finished_course[L].ftimes_take_course = Student[i].courses.current.current_course[x].times_take_course;
	Student[i].courses.finished.finished_course[L].fpoint = Student[i].courses.current.current_course[x].point;
	//Student[i].courses.current.current_course[L].point = 0;
	//Student[i].courses.finished.sum = Student[i].courses.current.sum; //
	Student[i].courses.finished.finished_course[L].fmarks.fsum_of_marks = Student[i].courses.current.current_course[x].marks.sum_of_marks;
	Student[i].courses.current.current_course[L].marks.sum_of_marks = 0;

	strcpy(Student[i].courses.finished.finished_course[L].fcode, Student[i].courses.current.current_course[x].code);
	strcpy(Student[i].courses.finished.finished_course[L].fcourse_name , Student[i].courses.current.current_course[x].course_name);
	Student[i].courses.finished.finished_course[L].fcourse_credit_hours = Student[i].courses.current.current_course[x].course_credit_hours;
	Student[i].courses.finished.finished_course[L].fsemester = Student[i].courses.current.current_course[x].semester;
	Student[i].courses.finished.finished_course[L].fyear = Student[i].courses.current.current_course[x].year;
	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.flecturer_first , Student[i].courses.current.current_course[x].course_tutors.lecturer_first);
	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.flecturer_middle , Student[i].courses.current.current_course[x].course_tutors.lecturer_middle);
	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.flecturer_last , Student[i].courses.current.current_course[x].course_tutors.lecturer_last);

	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.fgta_first, Student[i].courses.current.current_course[x].course_tutors.gta_first);
	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.fgta_middle , Student[i].courses.current.current_course[x].course_tutors.gta_middle);
	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.fgta_last , Student[i].courses.current.current_course[x].course_tutors.gta_last);

	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.flab_gta_first , Student[i].courses.current.current_course[x].course_tutors.lab_gta_first);
	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.flab_gta_middle , Student[i].courses.current.current_course[x].course_tutors.lab_gta_middle);
	strcpy(Student[i].courses.finished.finished_course[L].fcourse_tutors.flab_gta_last , Student[i].courses.current.current_course[x].course_tutors.lab_gta_last);

	Student[i].courses.finished.finished_course[L].fmarks.fseven_mark = Student[i].courses.current.current_course[x].marks.seven_mark;
	Student[i].courses.finished.finished_course[L].fmarks.ftwelve_mark = Student[i].courses.current.current_course[x].marks.twelve_mark;
	Student[i].courses.finished.finished_course[L].fmarks.fyear_work = Student[i].courses.current.current_course[x].marks.year_work;
	Student[i].courses.finished.finished_course[L].fmarks.ffinal_exam_mark = Student[i].courses.current.current_course[x].marks.final_exam_mark;
	Student[i].courses.finished.finished_course[L].fabsence =	Student[i].courses.current.current_course[x].absence;

	strcpy(Student[i].courses.finished.finished_course[L].fgrade , Student[i].courses.current.current_course[x].grade);

		Student[i].courses.finished.ftotal_credit_hours  = Student[i].courses.finished.ftotal_credit_hours + Student[i].courses.finished.finished_course[L].fcourse_credit_hours;
		Student[i].courses.current.sum = 0;
	
	Student[i].courses.finished.sum  = Student[i].courses.finished.sum + Student[i].courses.finished.finished_course[L].fpoint;
	
	Student[i].credit_hours.finished = Student[i].courses.finished.ftotal_credit_hours;

	
	Student[i].credit_hours.remaining = Student[i].credit_hours.max - Student[i].credit_hours.finished -Student[i].credit_hours.current;
}

void marks()
{
	int i,l,j,m;
	loop0:
	printf("\n\t\t\t\t\tWill you add final marks ? ");
	printf("\n\t\t\t\t\t1. YES\n\t\t\t\t\t0. NO\n\t\t\t\t\t");
    scanf("%d",&m);

     if (m!=1 && m!=0)
     {
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto loop0;
	}

	loop_1:
	i = search();
	j = search_code(i);
	system("cls");
	add_marks(i, j, m);
	loop_2:
	printf("\n\t\t\t\t\t1. continue with the different student\n\t\t\t\t\t0. menu\n\t\t\t\t\t");
    scanf("%d",&l);

     if (l==1)
	{
    	goto loop_1;
	}

	else if(l==0)
	{
		system("cls");
		menu();
	}

	else
	{
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto loop_2;

		}
}

void add_courses(int i)
{
	int j= 0, y=0 ;

	printf("\n\t\t\t\t\tEnter number of courses : ");
    scanf("%d", &Student[i].courses.current.num_of_courses);
    fflush(stdin);
    /*printf("\n\t\t\t\t\tEnter Total number of credit hours for these courses : ");
    scanf("%d", &Student[i].courses.current.total_credit_hours);
    fflush(stdin);*/
    printf("\n\t\t\t\t\t*************************\n");

    while( j < Student[i].courses.current.num_of_courses )
    {
    printf("\n\t\t\t\t\t     Course number %d",j+1);
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\n\t\t\t\t\tEnter Course code : ");
    scanf("%s", &Student[i].courses.current.current_course[j].code);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter Course name : ");
    scanf("%[^\n]s",Student[i].courses.current.current_course[j].course_name);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter Course credit hours : ");
    scanf("%d", &Student[i].courses.current.current_course[j].course_credit_hours);
    fflush(stdin);

    Student[i].courses.current.sum = Student[i].courses.current.sum + Student[i].courses.current.current_course[j].course_credit_hours;  // sum of criedit hours

    Student[i].courses.current.current_course[j].times_take_course = y + 1;  //

    printf("\n\t\t\t\t\tEnter the semester : ");
    scanf("%d", &Student[i].courses.current.current_course[j].semester);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter the year : ");
    scanf("%d", &Student[i].courses.current.current_course[j].year);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\t     lecturer name");
	printf("\n\t\t\t\t\t-------------------------\n");

    printf("\n\t\t\t\t\tEnter lecturer first name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.lecturer_first);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter lecturer middle name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.lecturer_middle);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter lecturer last name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.lecturer_last);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\t     GTA name");
	printf("\n\t\t\t\t\t-------------------------\n");
    printf("\n\t\t\t\t\tEnter GTA first name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.gta_first);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter GTA middle name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.gta_middle);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter GTA last name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.gta_last);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\t     Lab GTA name");
	printf("\n\t\t\t\t\t-------------------------\n");
    printf("\n\t\t\t\t\tEnter lab GTA first name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.lab_gta_first);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter lab GTA middle name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.lab_gta_middle);
    fflush(stdin);
    printf("\n\t\t\t\t\tEnter lab GTA last name  : ");
    scanf("%s", &Student[i].courses.current.current_course[j].course_tutors.lab_gta_last);
    fflush(stdin);
    j++;
    printf("\n\t\t\t\t\t*************************\n");
	}
	printf("\n\t\t\t\t\t-------------------------\n");


    Student[i].credit_hours.current = Student[i].courses.current.sum;


}

void courses()
{
	int i,l;
	loop_1:
	i = search();
	system("cls");
	add_courses( i );
	loop_2:
	printf("\n\t\t\t\t\t1. continue with the different student\n\t\t\t\t\t0. menu\n\t\t\t\t\t");
    scanf("%d",&l);

     if (l==1)
	{
    	goto loop_1;
	}

	else if(l==0)
	{
		system("cls");
		menu();
	}

	else
	{
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto loop_2;

		}
}


void payment()
{
	int i,l;
	loop_2:
	i = search();
	printf("\n\t\t\t\t\tEnter the Type of funding : ");
    scanf("%s", &Student[i].payment.type);
    fflush(stdin);
	loop_1:

	system("cls");
	add_payment( i );

	Student[i].payment.j = Student[i].payment.j + 1;
	loop_3:
	printf("\n\t\t\t\t\t1. continue with the same student \n\t\t\t\t\t2. continue with the different student\n\t\t\t\t\t0. menu\n\t\t\t\t\t");
    scanf("%d",&l);

    if(l==1)
    {
    	goto loop_1;
	}

	else if (l==2)
	{
    	goto loop_2;
	}

	else if(l==0)
	{
		system("cls");
		menu();
	}

	else
	{
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto loop_3;

		}

}

int search_code(int i)
{
	int l,j;
	char code [15];
	loop:
	system("cls");
	printf("\n\t\t\t\t\tEnter code of the course : ");
	scanf("%s",&code);

	for(j=0; j < 100; j++)
	{

    if(strcmp(code , Student[i].courses.current.current_course[j].code) == 0 )
		{
			printf("\n\t\t\t\t\tName of course is : %s",Student[i].courses.current.current_course[j].course_name);
			t = 0;
        	return j;
        	break;
    	}

    else if(strcmp(code , Student[i].courses.finished.finished_course[j].fcode) == 0 )
		{
			printf("\n\t\t\t\t\tName of course is : %s",Student[i].courses.finished.finished_course[j].fcode);
			t=1;
        	return j;
        	break;
    	}

    else if (j == 100-1 && strcmp(code , Student[i].courses.current.current_course[j].code) != 0 && strcmp(code , Student[i].courses.finished.finished_course[j].fcode) != 0)
    {
    	printf("\n\t\t\t\t\tNOT FOUND");
    	loop7:
    printf("\n\t\t\t\t\t1. Try Again\n\t\t\t\t\t0. Menu\n\t\t\t\t\t");
    scanf("%d",&l);
    
    if(l==1)
    {
    	goto loop;
	}

	else if(l==0)
	{
		system("cls");
		menu();
	}

	else
	{
		system("cls");
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
    	goto loop7;

	}
	
	}
	}
   
}

int search()
{
	int i,l;
	char id [15];
	loop:
	system("cls");
	printf("\n\t\t\t\t\tEnter the ID : ");
	scanf("%s",&id);

	for(i=0; i < N; i++)
	{

    if(strcmp(id , Student[i].regist) ==0 )
		{
			//printf("\n\t\t\t\t\tName : %s %s %s ",Student[i].first,Student[i].middle,Student[i].last);
        	return i;
        	break;
    	}

    else if (i== N-1 && strcmp(id , Student[i].regist)!=0)
    {
    	printf("\n\t\t\t\t\tNOT FOUND");
    	loop7:
    printf("\n\t\t\t\t\t1. Try Again\n\t\t\t\t\t0. Menu\n\t\t\t\t\t");
    scanf("%d",&l);
    
    if(l==1)
    {
    	goto loop;
	}

	else if(l==0)
	{
		system("cls");
		menu();
	}

	else
	{
		system("cls");
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
    	goto loop7;

	}
	
	}
	}
   

  // printf("\n\t\t\t\t\t1. continue\n\t\t\t\t\t0. menu\n\t\t\t\t\t");
   // scanf("%d",&l);
//    if(l==1)
//    {
//    	goto loop;
//	}
//	else if(l==0)
//	{
//		system("cls");
//		menu();
//	}
//	else
//	{
//		printf("\n\t\t\t\t\tThe input is NOT correct\n");
//		printf("\n\t\t\t\t\tPlease try again.\n");
//		goto loop;
//
//		}

}

void add_payment(int i)
{
	printf("\n\t\t\t\t\tName : %s %s %s \n",Student[i].first,Student[i].middle,Student[i].last);
    Student[i].payment.no_pay_done = Student[i].payment.no_pay_done + 1;
	printf("\n\t\t\t\t\t*************************\n");
	printf("\t\t\t\t\tEnter the Amount paid: ");
    scanf("%lf", &Student[i].payment.details[Student[i].payment.j].amount);
    fflush(stdin);
    
    discount(i);
    
	Student[i].payment.total_paid = Student[i].payment.total_paid + Student[i].payment.details[Student[i].payment.j].amount;
    printf("\n\t\t\t\t\tEnter the Transaction number: ");
    scanf("%d", &Student[i].payment.details[Student[i].payment.j].trans_no);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the Bank of transaction : ");
    scanf("%s", &Student[i].payment.details[Student[i].payment.j].bank);
    fflush(stdin);
    add_invalid:
    printf("\t\t\t\t\tEnter date of transaction ( DD/MM/YYYY ) : ");
    scanf("%d/%d/%d", &Student[i].payment.details[Student[i].payment.j].date_payment.day ,&Student[i].payment.details[Student[i].payment.j].date_payment.month ,&Student[i].payment.details[Student[i].payment.j].date_payment.year);
    fflush(stdin);
    if(Student[i].payment.details[Student[i].payment.j].date_payment.day < 1 || Student[i].payment.details[Student[i].payment.j].date_payment.day >31 || Student[i].payment.details[Student[i].payment.j].date_payment.month < 1 || Student[i].payment.details[Student[i].payment.j].date_payment.month > 12 || Student[i].payment.details[Student[i].payment.j].date_payment.year < 1980 || Student[i].payment.details[Student[i].payment.j].date_payment.year >2019)
		{

		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto add_invalid;
        }

    printf("\n\t\t\t\t\t-------------------------\n");
}

void discount(int i)
{
	int m;
	double dis, per;
	loop0:
	printf("\n\t\t\t\t\tDoes the student have any discount ? ");
	printf("\n\t\t\t\t\t1. YES\n\t\t\t\t\t0. NO\n\t\t\t\t\t");
    scanf("%d",&m);
	if(m==1)
	{
		printf("\n\t\t\t\t\tEnter the discount percentage : ");
        scanf("%lf",&per);
        dis = Student[i].payment.details[Student[i].payment.j].amount * (per / 100);
        Student[i].payment.details[Student[i].payment.j].amount = Student[i].payment.details[Student[i].payment.j].amount - dis;
        Student[i].payment.details[Student[i].payment.j].percentage = per;
		Student[i].payment.details[Student[i].payment.j].amount_deducted = dis;
	}
	
	else if(m==0)
	{
		printf("\n");
		return;
	}
	
    else
    {
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto loop0;
	}
	
}

void age(int i, int birth_year, int birth_month)
{
	int current_month, current_year;
	SYSTEMTIME t;
	GetSystemTime(&t);

	current_month = t.wMonth;
	current_year = t.wYear;

    int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (birth_month > current_month)
	{
        current_year = current_year - 1;
    }

    int calculated_year = current_year - birth_year;

    Student[i].AGES = calculated_year;

    printf("\t\t\t\t\tHis/Her age is %d",Student[i].AGES);
    /* print the present age
    printf("Present Age\nYears: %d  Months: %d  Days:"
           " %d\n", calculated_year, calculated_month,
                                      calculated_day); */
}

void mailing (int i)
{
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\n\t\t\t\t\tThe mailing Address \n");
	printf("\n\t\t\t\t\t-------------------------\n");
    	printf("\n\t\t\t\t\tEnter the flat number : ");
    	scanf("%d", &Student[i].mail.mflat);
    	fflush(stdin);
    	printf("\t\t\t\t\tEnter the house number : ");
    	scanf("%d", &Student[i].mail.mhouse);
   		fflush(stdin);
    	printf("\t\t\t\t\tEnter the street name : ");
    	scanf("%s", &Student[i].mail.mstreet);
    	fflush(stdin);
    	printf("\t\t\t\t\tEnter the area name : ");
    	scanf("%s", &Student[i].mail.marea);
    	fflush(stdin);
    	printf("\t\t\t\t\tEnter the city name : ");
    	scanf("%s", &Student[i].mail.mcity);
    	fflush(stdin);
    	printf("\t\t\t\t\tEnter the governorate name : ");
    	scanf("%s", &Student[i].mail.mgovernorate);
    	fflush(stdin);
    	printf("\t\t\t\t\tEnter the country name : ");
    	scanf("%s", &Student[i].mail.mcountry);
    	fflush(stdin);
    	printf("\t\t\t\t\tEnter the postal code : ");
    	scanf("%d", &Student[i].mail.mpostal);
    	fflush(stdin);
}

void add_info(int i)
{
	int t, a;
	int S,D,re;
	Student[i].payment.j = 0;
	printf("\n\t\t\t\t\t     Student Number %d",i+1);
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\n\t\t\t\t\tThe First Name: ");
    scanf("%s", &Student[i].first);
    printf("\t\t\t\t\tThe Middle Name: ");
    scanf("%s", &Student[i].middle);
    printf("\t\t\t\t\tThe Last Name: ");
    scanf("%s", &Student[i].last);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the gender ( M / F ) : ");
    scanf("%s", &Student[i].gender);
    fflush(stdin);
    printf("\n\t\t\t\t\tFirst enrolment term : ");
    scanf("%d", &Student[i].first_enrol_term);
    fflush(stdin);
    printf("\t\t\t\t\tFirst enrolment year : ");
    scanf("%d", &Student[i].first_enrol_year);
    fflush(stdin);
	loopp:
	printf("\n\t\t\t  < Do you want Registration no. to be calculated automatically >\n");
    printf("\n\t\t\t\t\t\t 1. YES \t 2. NO\n\t\t\t\t\t\t ");
    scanf("%d",&a);
	    if(a == 1 )
		{
			S = Student[i].first_enrol_year - 2000;
			S = S * 100000;
			D = Student[i].first_enrol_term * 10000;
			re = S + D + i + 1;
			sprintf(Student[i].regist, "%d", re);
			printf("\t\t\t\t\tYOUR Regist NO. REMEMBER IT CARFULLY:  %s",Student[i].regist);
			getch();

		}
		else if(a == 2 )
		{
			printf("\n\t\t\t\t\tEnter the regist NO. : ");
		    scanf("%s", &Student[i].regist);
		    fflush(stdin);
		}
		else
		{
	    	printf("\n\t\t\t\t\tNOT CORRECT");
	    	printf("\n\t\t\t\t\tTry Again");
	   		getch();
	   		system("cls");
	   		goto loopp;
		}

    printf("\n\t\t\t\t\tEnter the nationality: ");
    scanf("%s", &Student[i].nationality);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the maximum required for the degree: ");
    scanf("%d", &Student[i].credit_hours.max);
    fflush(stdin);


    add_invalid:
    printf("\t\t\t\t\tEnter date of birth ( DD/MM/YYYY ) : ");
    scanf("%d/%d/%d", &Student[i].birth.day ,&Student[i].birth.month ,&Student[i].birth.year);
    fflush(stdin);
    if(Student[i].birth.day < 1 || Student[i].birth.day >31 || Student[i].birth.month < 1 || Student[i].birth.month > 12 || Student[i].birth.year < 1980 || Student[i].birth.year >2019)
		{

		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto add_invalid;
        }
    	age(i, Student[i].birth.year, Student[i].birth.month);


    Student[i].curr_term = Student[i].first_enrol_term;

	loop6:
    printf("\n\t\t\t\t\tEnter the department ( CAPITAL LETTER ) : ");
    scanf("%[^\n]s",Student[i].dept);
    fflush(stdin);
    int C =strlen(Student[i].dept);
    int s;
    
	for(s=0;s<C; s++ )
    {
    	if(Student[i].dept[s] <= 'A' && Student[i].dept[s] != ' '  || Student[i].dept[s] >='Z'  && Student[i].dept[s] != ' ')
		{
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto loop6;
        }
	}
    	
	
    
    printf("\n\t\t\t\t\tStudent tutor name : ");
    scanf("%s", &Student[i].tutor_name);
    fflush(stdin);
    printf("\t\t\t\t\tStudent tutor code : ");
    scanf("%s", &Student[i].tutor_code);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------\n");
    printf("\n\t\t\t\t\tEnter the type of ID : ");
    scanf("%s", &Student[i].type);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the ID Number : ");
    scanf("%d", &Student[i].no);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the Validity of the ID : ");
    scanf("%d", &Student[i].validity);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------\n");
    printf("\n\t\t\t\t\tHome Address \n");				// home address
    printf("\n\t\t\t\t\tEnter the flat number : ");
    scanf("%d", &Student[i].home.flat);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the house number : ");
    scanf("%d", &Student[i].home.house);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the street name : ");
    scanf("%s", &Student[i].home.street);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the area name : ");
    scanf("%s", &Student[i].home.area);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the city name : ");
    scanf("%s", &Student[i].home.city);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the governorate name : ");
    scanf("%s", &Student[i].home.governorate);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the country name : ");
    scanf("%s", &Student[i].home.country);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the postal code : ");
    scanf("%d", &Student[i].home.postal);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------\n");
    printf("\n\t\t\t  < Is the mailing address different form the home address >\n");
    addd_invalid:
    printf("\n\t\t\t\t\t\t 1. Different \n\t\t\t\t\t\t 2. Same\n\t\t\t\t\t\t ");
    scanf("%d",&t);

    if(t == 1)
    {
    	mailing (i);
	}
	
	else if(t == 2)
	{
		Student[i].mail.mflat = Student[i].home.flat;
		Student[i].mail.mhouse = Student[i].home.house;
		strcpy(Student[i].mail.mstreet , Student[i].home.street);
		strcpy(Student[i].mail.marea , Student[i].home.area);
		strcpy(Student[i].mail.mcity , Student[i].home.city);
		strcpy(Student[i].mail.mgovernorate , Student[i].home.governorate);
		strcpy(Student[i].mail.mcountry , Student[i].home.country);
		Student[i].mail.mpostal = Student[i].home.postal;

	}
	
	else
	{
		system("cls");
		goto addd_invalid;
	}

    printf("\n\t\t\t\t\t-------------------------\n");
    printf("\n\t\t\t\t\tStudent Contact \n");
	printf("\n\t\t\t\t\t-------------------------\n");
    printf("\n\t\t\t\t\tEnter the e-mail : ");
    scanf("%s", &Student[i].contact.email);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the home phone number : ");
    scanf("%s", &Student[i].contact.phone_no);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the mobile number : ");
    scanf("%s", &Student[i].contact.mobile);
    fflush(stdin);
    //int j=0;
    //add_payment(i ,j);

Size++;
}

void add_others()
{
	int i,l;
	i++;
	i = k;

	while(i<N)
	{
	system("cls");
	add_info(i);
	add_invalid:
    printf("\n\t\t\t\t\t1. continue\n\t\t\t\t\t0. menu\n\t\t\t\t\t");
    scanf("%d",&l);
    
	if(l==1)
    {
    	i++;
	}
	
	else if(l==0)
	{
		i++;
		k=i;
		system("cls");
		menu();
	}
	
	else
	{
		system("cls");
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
    	goto add_invalid;

	}
}
}

void add_student() //didn't use anymore
{
	system("cls");
	int i=0,l;
	while(i<N)
	{
	system("cls");
	add_info(i);
	add_invalid:
    printf("\n\t\t\t\t\t1. continue\n\t\t\t\t\t0. menu\n\t\t\t\t\t");
    scanf("%d",&l);
    
	if(l==1)
    {
    	i++;
	}
	
	else if(l==0)
	{
		i++;
		k=i;
		system("cls");
		menu();
	}
	
	else
	{
		system("cls");
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		goto add_invalid;

		}


    }

	printf("\n\n\t\t\t\t\tEnter any key to continue.\n\t\t\t\t\t");
    getch();
    system("cls");
	menu();
}

int search_course(int i)
{
	int l,j;
	char code [15];
	loop:
	system("cls");
	printf("\n\t\t\t\t\tEnter code of the course : ");
	scanf("%s",&code);
	for(j=0; j < 100; j++)
	{
	
	    if(strcmp(code , Student[i].courses.current.current_course[j].code) == 0 )
			{
				t = 0;
	        	return j;
	        	break;
	    	}
	
	    else if(strcmp(code , Student[i].courses.finished.finished_course[j].fcode) == 0 )
			{
				printf("\n\t\t\t\t\tName of course is : %s",Student[i].courses.finished.finished_course[j].fcode);
				t=1;
	        	return j;
	        	break;
	    	}
	
	    else if (j == 100-1 && strcmp(code , Student[i].courses.current.current_course[j].code) != 0 && strcmp(code , Student[i].courses.finished.finished_course[j].fcode) != 0)
	   		{
		    	printf("\n\t\t\t\t\tNOT FOUND");
			    	loop7:
			    printf("\n\t\t\t\t\t1. Try Again\n\t\t\t\t\t0. Menu\n\t\t\t\t\t");
			    scanf("%d",&l);
			    
			    if(l==1)
			    {
			    	goto loop;
				}
	
				else if(l==0)
				{
					system("cls");
					menu();
				}
	
				else
				{
					system("cls");
					printf("\n\t\t\t\t\tThe input is NOT correct\n");
					printf("\n\t\t\t\t\tPlease try again.\n");
			    	goto loop7;
			
				}
				
				}
				
	}
}

//--------------------------------------------------       S     H    O    W       --------------------------------------------------------------------------------------------------------------------------------------//

void show_courses(int i)
{
	int j;
	t = 0;
	j = search_course(i);
	system("cls");
	
	if (t==0)
	{

	printf("\n\t\t\t\t\tCourse code : %s",Student[i].courses.current.current_course[j].code);
    printf("\n\t\t\t\t\tCourse name : %s",Student[i].courses.current.current_course[j].course_name);
    printf("\n\t\t\t\t\tCourse credit hours : %d",Student[i].courses.current.current_course[j].course_credit_hours);
    printf("\n\t\t\t\t\tThe semester : %d",Student[i].courses.current.current_course[j].semester);
    printf("\n\t\t\t\t\tThe year : %d",Student[i].courses.current.current_course[j].year);
    printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tlecturer name : %s %s %s",Student[i].courses.current.current_course[j].course_tutors.lecturer_first,Student[i].courses.current.current_course[j].course_tutors.lecturer_middle,Student[i].courses.current.current_course[j].course_tutors.lecturer_last);
	printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tGTA name : %s %s %s",Student[i].courses.current.current_course[j].course_tutors.gta_first,Student[i].courses.current.current_course[j].course_tutors.gta_middle,Student[i].courses.current.current_course[j].course_tutors.gta_last);
    printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tLab GTA name : %s %s %s",Student[i].courses.current.current_course[j].course_tutors.lab_gta_first,Student[i].courses.current.current_course[j].course_tutors.lab_gta_middle,Student[i].courses.current.current_course[j].course_tutors.lab_gta_last);
	printf("\n\t\t\t\t\t-------------------------\n");
	}
	
	else if(t == 1 )
	{

	printf("\n\t\t\t\t\tCourse code2 : %s",Student[i].courses.finished.finished_course[j].fcode);
    printf("\n\t\t\t\t\tCourse name : %s",Student[i].courses.finished.finished_course[j].fcourse_name);
    printf("\n\t\t\t\t\tCourse credit hours : %d",Student[i].courses.finished.finished_course[j].fcourse_credit_hours);
    printf("\n\t\t\t\t\tThe semester : %d",Student[i].courses.finished.finished_course[j].fsemester);
    printf("\n\t\t\t\t\tThe year : %d",Student[i].courses.finished.finished_course[j].fyear);
    printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tlecturer name : %s %s %s",Student[i].courses.finished.finished_course[j].fcourse_tutors.flecturer_first,Student[i].courses.finished.finished_course[j].fcourse_tutors.flecturer_middle,Student[i].courses.finished.finished_course[j].fcourse_tutors.flecturer_last);
	printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tGTA name : %s %s %s",Student[i].courses.finished.finished_course[j].fcourse_tutors.fgta_first,Student[i].courses.finished.finished_course[j].fcourse_tutors.fgta_middle,Student[i].courses.finished.finished_course[j].fcourse_tutors.fgta_last);
    printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tLab GTA name : %s %s %s",Student[i].courses.finished.finished_course[j].fcourse_tutors.flab_gta_first,Student[i].courses.finished.finished_course[j].fcourse_tutors.flab_gta_middle,Student[i].courses.finished.finished_course[j].fcourse_tutors.flab_gta_last);
	printf("\n\t\t\t\t\t-------------------------\n");
	t=0;
	}
	getch();
    system("cls");
	show_list1(i);

}

void specific_mark(int i)
{
	int j;
	t =0;
	j = search_course(i);
	system("cls");

	if (t==0)
	{
	printf("\n\t\t\t\t\tName : %s %s %s ",Student[i].first,Student[i].middle,Student[i].last);
	printf("\n\t\t\t\t\tCourse : %s",Student[i].courses.current.current_course[j].course_name);
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\n\t\t\t\t\t7th mark : %d ",Student[i].courses.current.current_course[j].marks.seven_mark);
    printf("\n\t\t\t\t\t12th mark : %d",Student[i].courses.current.current_course[j].marks.twelve_mark);
	}
	
	else if(t == 1 )
	{
		printf("\n\t\t\t\t\tName : %s %s %s ",Student[i].first,Student[i].middle,Student[i].last);
		printf("\n\t\t\t\t\tCourse : %s",Student[i].courses.finished.finished_course[j].fcourse_name);
		printf("\n\t\t\t\t\t-------------------------\n");
		printf("\n\t\t\t\t\t7th mark : %d ",Student[i].courses.finished.finished_course[j].fmarks.fseven_mark);
	    printf("\n\t\t\t\t\t12th mark : %d",Student[i].courses.finished.finished_course[j].fmarks.ftwelve_mark);
	    printf("\n\t\t\t\t\tYear work mark : %d ",Student[i].courses.finished.finished_course[j].fmarks.fyear_work);
		printf("\n\t\t\t\t\tFinal exam mark : %d",Student[i].courses.finished.finished_course[j].fmarks.ffinal_exam_mark);
		printf("\n\t\t\t\t\tGrade :%s ",Student[i].courses.finished.finished_course[j].fgrade);
		printf("\n\t\t\t\t\tstudent percentage absence during the course :%0.1f% ",Student[i].courses.finished.finished_course[j].fabsence);
		printf("\n\t\t\t\t\tNumber of times taking the course :%d ",Student[i].courses.finished.finished_course[j].ftimes_take_course);
		t=0;
	}


}

void Show_marks(int i)
{
	int m, j;
	loop:
	system("cls");
	printf("\n\t\t\t\t\tCurrent semester : %d", Student[i].curr_term);
    printf("\n\t\t\t\t\tNumber of semesters finished so far. : %d\n",Student[i].gpa.num_of_semester_sofar);
    printf("\n\t\t\t\t\tGPA : ");
    printf("\n\t\t\t\t\tPrevious Achievement : %0.2f",Student[i].gpa.individual_gpa[R-2]);
    printf("\n\t\t\t\t\tCurrent Achievement : %0.2f",Student[i].gpa.individual_gpa[R-1]);
    printf("\n\t\t\t\t\tTotal Achievement : %0.2f",Student[i].gpa.overall_gpa);
    printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\t1. Show specific course\n\t\t\t\t\t2. Show all courses\n\t\t\t\t\t");
    scanf("%d",&m);

     if (m==1)
     {
	  	specific_mark(i);
	 }
	
	 else if(m==2)
	 {
		system("cls");
		printf("\n\t\t\t\t\tName : %s %s %s ",Student[i].first,Student[i].middle,Student[i].last);
		printf("\n\t\t\t\t\t-------------------------\n");
	
		for(j=0; j<P; j++)
		{

				printf("\n\t\t\t\t\tCourse : %s",Student[i].courses.finished.finished_course[j].fcourse_name);
				printf("\n\t\t\t\t\t-------------------------\n");
				printf("\n\t\t\t\t\t7th mark : %d ",Student[i].courses.finished.finished_course[j].fmarks.fseven_mark);
 			    printf("\n\t\t\t\t\t12th mark : %d",Student[i].courses.finished.finished_course[j].fmarks.ftwelve_mark);
  			    printf("\n\t\t\t\t\tYear work mark : %d ",Student[i].courses.finished.finished_course[j].fmarks.fyear_work);
				printf("\n\t\t\t\t\tFinal exam mark : %d",Student[i].courses.finished.finished_course[j].fmarks.ffinal_exam_mark);
				printf("\n\t\t\t\t\tGrade :%s ",Student[i].courses.finished.finished_course[j].fgrade);
				printf("\n\t\t\t\t\tstudent percentage absence during the course :%0.1f% ",Student[i].courses.finished.finished_course[j].fabsence);
				printf("\n\t\t\t\t\tNumber of times taking the course :%d ",Student[i].courses.finished.finished_course[j].ftimes_take_course);
				printf("\n\t\t\t\t\t-------------------------\n");

			}
		}


	 else
	 {
	 	printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		goto loop;
	 }

    getch();
    system("cls");
	show_list1(i);


}

void show_credit_hours(int i)
{
	system("cls");
	printf("\n\t\t\t\t\tMaximum required for the degree : %d \n",Student[i].credit_hours.max);
    printf("\n\t\t\t\t\tCredit hours finished : %d\n",Student[i].credit_hours.finished);
    printf("\n\t\t\t\t\tCredit hours current : %d\n",Student[i].credit_hours.current);
    printf("\n\t\t\t\t\tCredit hours remaining : %d\n\t\t\t\t\t",Student[i].credit_hours.remaining);
    getch();
    system("cls");
	show_list1(i);
}

void Show_Payment(int i)
{
	int j;
	system("cls");
		printf("\n\t\t\t\t\tNumber of payments done : %d",Student[i].payment.no_pay_done);
		printf("\n\t\t\t\t\tName : %s %s %s ",Student[i].first,Student[i].middle,Student[i].last);
  	    printf("\n\t\t\t\t\tType of funding : %s",Student[i].payment.type);
  	    printf("\n\t\t\t\t\tTotal amount paid so far : %0.2lf\n\n", Student[i].payment.total_paid);
  	    printf("\n\t\t\t\t\t*************************");
	
	for(j=0; j < Student[i].payment.j ; j++)
	{
		printf("\n\n\t\t\t\t\tDate of transaction : %d / %d / %d",Student[i].payment.details[j].date_payment.day ,Student[i].payment.details[j].date_payment.month ,Student[i].payment.details[j].date_payment.year);
		printf("\n\t\t\t\t\t*************************");
		printf("\n\t\t\t\t\tPrecentage of discount : %0.1lf %", Student[i].payment.details[j].percentage);
		printf("\n\t\t\t\t\tAmount of deducted: %0.2lf\n",Student[i].payment.details[j].amount_deducted);
		printf("\n\t\t\t\t\tThe Amount paid : %0.2lf", Student[i].payment.details[j].amount);
    	printf("\n\t\t\t\t\tThe Transaction number: %d",Student[i].payment.details[j].trans_no);
    	printf("\n\t\t\t\t\tBank of transaction : %s",Student[i].payment.details[j].bank);
    	printf("\n\t\t\t\t\t-------------------------\n");
	}
	getch();
    system("cls");
	show_list1(i);

}

void show_info(int i)
{
	system("cls");
	printf("\n\t\t\t\t\tName : %s %s %s ",Student[i].first ,Student[i].middle ,Student[i].last);
    printf("\n\t\t\t\t\tThe gender : %s",Student[i].gender);
    printf("\n\t\t\t\t\tThe regist NO. : %s",Student[i].regist);
    printf("\n\t\t\t\t\tNationality : %s ",Student[i].nationality);
    printf("\n\t\t\t\t\tThe maximum required for the degree : %d",Student[i].credit_hours.max);
    printf("\n\t\t\t\t\tDate of birth : %d / %d / %d ", Student[i].birth.day ,Student[i].birth.month ,Student[i].birth.year);
    printf("\n\t\t\t\t\tHis/Her Age is %d",Student[i].AGES);
	printf("\n\t\t\t\t\tFirst enrolment term : %d ", Student[i].first_enrol_term);
    printf("\n\t\t\t\t\tFirst enrolment year : %d ", Student[i].first_enrol_year);
    printf("\n\t\t\t\t\tThe department : %s", Student[i].dept);
    printf("\n\t\t\t\t\tCurrent term : %d", Student[i].curr_term);
    printf("\n\t\t\t\t\tStudent tutor name : %s", Student[i].tutor_name);
    printf("\n\t\t\t\t\tStudent tutor code : %s", Student[i].tutor_code);
    printf("\n\t\t\t\t\t-------------------------");
    
	printf("\n\t\t\t\t\tThe type of ID : %s",Student[i].type);
    printf("\n\t\t\t\t\tThe ID Number : %d", Student[i].no);
    printf("\n\t\t\t\t\tThe Validity of the ID : %d ",Student[i].validity);
    printf("\n\t\t\t\t\t-------------------------");
    
	printf("\n\t\t\t\t\tHome Address ");
	printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tThe flat number : %d ",Student[i].home.flat);
    printf("\n\t\t\t\t\tThe house number : %d ",Student[i].home.house);
    printf("\n\t\t\t\t\tThe street name : %s ",Student[i].home.street);
    printf("\n\t\t\t\t\tThe area name : %s",Student[i].home.area);
    printf("\n\t\t\t\t\tThe city name : %s",Student[i].home.city);
    printf("\n\t\t\t\t\tThe governorate name : %s",Student[i].home.governorate);
    printf("\n\t\t\t\t\tThe country name : %s", Student[i].home.country);
    printf("\n\t\t\t\t\tThe postal code : %d", Student[i].home.postal);
    printf("\n\t\t\t\t\t-------------------------");
	
	printf("\n\t\t\t\t\tThe mailing Address");
	printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tThe flat number : %d", Student[i].mail.mflat);
   	printf("\n\t\t\t\t\tThe house number : %d", Student[i].mail.mhouse);
    printf("\n\t\t\t\t\tThe street name : %s", Student[i].mail.mstreet);
   	printf("\n\t\t\t\t\tThe area name : %s", Student[i].mail.marea);
   	printf("\n\t\t\t\t\tThe city name : %s", Student[i].mail.mcity);
   	printf("\n\t\t\t\t\tThe governorate name : %s", &Student[i].mail.mgovernorate);
   	printf("\n\t\t\t\t\tThe country name : %s", Student[i].mail.mcountry);
   	printf("\n\t\t\t\t\tThe postal code : %d", Student[i].mail.mpostal);
    printf("\n\t\t\t\t\t-------------------------");
    
	printf("\n\t\t\t\t\tStudent Contact");
	printf("\n\t\t\t\t\t-------------------------");
    printf("\n\t\t\t\t\tThe e-mail : %s", Student[i].contact.email);
    printf("\n\t\t\t\t\tThe home phone number : %s", Student[i].contact.phone_no);
    printf("\n\t\t\t\t\tThe mobile number : %s", Student[i].contact.mobile);
    printf("\n\n\t\t\t\t\t-------------------------");
	printf("\n\n\t\t\t\t\tEnter any key to continue.\n\t\t\t\t\t");
    getch();
    system("cls");
	show_list1(i);
}

void show_list1(int i)
{
	system("color E");
	int v;
	system("cls");
	loop:
	printf("\n\t\t\t\t\t\tShow List");
	printf("\n\t\t\t\t\t-------------------------");
	printf("\n\t\t\t\t\tName: %s %s %s",Student[i].first ,Student[i].middle ,Student[i].last);
	printf("\n\t\t\t\t\tID: %s",Student[i].regist);
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\t1. Student information\n");
	printf("\t\t\t\t\t2. Payment\n");
	printf("\t\t\t\t\t3. Credit hours\n");
	printf("\t\t\t\t\t4. Marks\n");
	printf("\t\t\t\t\t5. Courses\n");	//current and finished
	printf("\t\t\t\t\t6. menu\n");
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\tEnter your choice: ");
	scanf("%d",&v);
	
	switch(v)
	{
		case 1:
		show_info(i);
        break;
        case 2:
        Show_Payment(i);
        break;
        case 3:
        show_credit_hours(i);
        break;
        case 4:
        Show_marks(i);
        break;
        case 5:
        show_courses(i);
        break;
        case 6:
        menu();
        break;

        default:
        printf("\n\t\t\t\t\tThe Input is NOT correct!! ");
        printf("\n\t\t\t\t\tPlease try again.\n");
        printf("\n\n\t\t\t\t\tEnter any key to continue.\n\t\t\t\t\t");
        getch();
        system("cls");
        goto loop;
        break;
    }

}

void show_list()
{
	int i;
	i = search();
	show_list1(i);

}


void menu()
{
	system("color B");
	system("cls");
	int a, k=0;
	printf("\n\t\t\t\t\t Student Record Program\n");
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\t1. Add Student\n");
	printf("\t\t\t\t\t2. Show the list\n");
	//printf("\t\t\t\t\t3. Add other students\n");
	//printf("\t\t\t\t\t4. Search Student\n");
	printf("\t\t\t\t\t3. Modify Student Record\n");
	printf("\t\t\t\t\t4. STUDENT PAYMENT\n");
	printf("\t\t\t\t\t5. Add courses\n");
	printf("\t\t\t\t\t6. Add Marks\n");
	printf("\t\t\t\t\t7. Sort BY GPA\n");

	printf("\t\t\t\t\t10. Exit\n");
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\tEnter your choice: ");
	scanf("%d",&a);
	
	switch(a)
	{
		case 1:
		add_others();
        break;
        case 2:
        show_list();
        break;
        /*case 3:
        add_others();
        break;*/
        case 3:
        mod_student();
        break;
        case 4:
        payment();
        break;
        case 5:
        courses();
        break;
        case 6:
        marks();
        break;
        case 7:
        sort_student();
        break;
        case 10:
        exit(0);
        break;
        default:
        printf("\n\t\t\t\t\tThe Input is NOT correct!! ");
        printf("\n\t\t\t\t\tPlease try again.\n");
        printf("\n\n\t\t\t\t\tEnter any key to continue.\n\t\t\t\t\t");
        getch();
        system("cls");
        menu();
        break;
	}

}

//---------------------------------------------------         E            D           I            T        ----------------------------------------------------------------------------------------------------//


void edit_info(int i)
{
	system("cls");
	printf("\n\t\t\t\t\tThe First Name: ");
    scanf("%s", &Student[i].first);
    printf("\t\t\t\t\tThe Middle Name: ");
    scanf("%s", &Student[i].middle);
    printf("\t\t\t\t\tThe Last Name: ");
    scanf("%s", &Student[i].last);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the gender ( M / F ) : ");
    scanf("%s", &Student[i].gender);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the regist NO. : ");
    scanf("%s", &Student[i].regist);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the nationality: ");
    scanf("%s", &Student[i].nationality);
    fflush(stdin);

    add_invalid:
    printf("\t\t\t\t\tEnter date of birth ( DD/MM/YYYY ) : ");
    scanf("%d/%d/%d", &Student[i].birth.day ,&Student[i].birth.month ,&Student[i].birth.year);
    fflush(stdin);
    if(Student[i].birth.day < 1 || Student[i].birth.day >31 || Student[i].birth.month < 1 || Student[i].birth.month > 12 || Student[i].birth.year < 1980 || Student[i].birth.year >2019)
		{
			printf("\n\t\t\t\t\tThe input is NOT correct\n");
			printf("\n\t\t\t\t\tPlease try again.\n");
			getch();
			system("cls");
			goto add_invalid;
        }
    	age(i, Student[i].birth.year, Student[i].birth.month);

    loop6:
    printf("\n\t\t\t\t\tEnter the department ( CAPITAL LETTER ) : ");
    scanf("%s", &Student[i].dept);
    fflush(stdin);
    int C =strlen(Student[i].dept);
    int s;
    
	for(s=0;s<C; s++ )
    {
    	if(Student[i].dept[s] <= 'A' && Student[i].dept[s] != ' '  || Student[i].dept[s] >='Z'  && Student[i].dept[s] != ' ')
		{
		printf("\n\t\t\t\t\tThe input is NOT correct\n");
		printf("\n\t\t\t\t\tPlease try again.\n");
		getch();
		system("cls");
		goto loop6;
        }
	}
    printf("\n\t\t\t\t\tStudent tutor name : ");
    scanf("%s", &Student[i].tutor_name);
    fflush(stdin);
    printf("\t\t\t\t\tStudent tutor code : ");
    scanf("%s", &Student[i].tutor_code);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------\n\t\t\t\t\t");
    getch();
    system("cls");
	mod_student1(i);

}

void edit_id(int i)
{
	system("cls");
	printf("\n\t\t\t\t\tEnter the type of ID : ");
    scanf("%s", &Student[i].type);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the ID Number : ");
    scanf("%d", &Student[i].no);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the Validity of the ID : ");
    scanf("%d", &Student[i].validity);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------\n\t\t\t\t\t");
    getch();
    system("cls");
	mod_student1(i);
}

void edit_home_address(int i)
{
	system("cls");
	printf("\n\t\t\t\t\tHome Address");
	printf("\n\t\t\t\t\t-------------------------\n");
    printf("\n\t\t\t\t\tEnter the flat number : ");
    scanf("%d", &Student[i].home.flat);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the house number : ");
    scanf("%d", &Student[i].home.house);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the street name : ");
    scanf("%s", &Student[i].home.street);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the area name : ");
    scanf("%s", &Student[i].home.area);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the city name : ");
    scanf("%s", &Student[i].home.city);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the governorate name : ");
    scanf("%s", &Student[i].home.governorate);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the country name : ");
    scanf("%s", &Student[i].home.country);
    fflush(stdin);
    printf("\t\t\t\t\tEnter the postal code : ");
    scanf("%d", &Student[i].home.postal);
    fflush(stdin);
    printf("\n\t\t\t\t\t-------------------------\n\t\t\t\t\t");
    getch();
    system("cls");
	mod_student1(i);
}


void edit_mailing_address(i)
{
	system("cls");
	printf("\n\t\t\t\t\tThe mailing Address");
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\n\t\t\t\t\tEnter the flat number : ");
	scanf("%d", &Student[i].mail.mflat);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the house number : ");
	scanf("%d", &Student[i].mail.mhouse);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the street name : ");
	scanf("%s", &Student[i].mail.mstreet);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the area name : ");
	scanf("%s", &Student[i].mail.marea);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the city name : ");
	scanf("%s", &Student[i].mail.mcity);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the governorate name : ");
	scanf("%s", &Student[i].mail.mgovernorate);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the country name : ");
	scanf("%s", &Student[i].mail.mcountry);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the postal code : ");
	scanf("%d", &Student[i].mail.mpostal);
	fflush(stdin);
	printf("\n\t\t\t\t\t-------------------------\n\t\t\t\t\t");
	getch();
	system("cls");
	mod_student1(i);
}


void edit_student_contact(int i)
{
	system("cls");
	printf("\n\t\t\t\t\tStudent Contact");
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\n\t\t\t\t\tEnter the e-mail : ");
	scanf("%s", &Student[i].contact.email);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the home phone number : ");
	scanf("%s", &Student[i].contact.phone_no);
	fflush(stdin);
	printf("\t\t\t\t\tEnter the mobile number : ");
	scanf("%s", &Student[i].contact.mobile);
	fflush(stdin);
	printf("\n\t\t\t\t\t-------------------------\n\t\t\t\t\t");
	getch();
	system("cls");
	mod_student1(i);
}


void mod_student1(int i)
{
	system("color A");
	int v;
	system("cls");
	loop:
	printf("\n\t\t\t\t\t    EDIT INFORMATION");
	printf("\n\t\t\t\t\t-------------------------");
	printf("\n\t\t\t\t\tName: %s %s %s",Student[i].first ,Student[i].middle ,Student[i].last);
	printf("\n\t\t\t\t\tID: %s",Student[i].regist);
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\t1. Edit Student information\n");
	printf("\t\t\t\t\t2. Edit the identity info.\n");
	printf("\t\t\t\t\t3. Edit Home address\n");
	printf("\t\t\t\t\t4. Edit mailing address\n");
	printf("\t\t\t\t\t5. Edit Student contact\n");
	printf("\t\t\t\t\t6. menu\n");
	printf("\n\t\t\t\t\t-------------------------\n");
	printf("\t\t\t\t\tEnter your choice: ");
	scanf("%d",&v);

	switch(v)
	{
		case 1:
		edit_info(i);
        break;
        case 2:
        edit_id(i);
        break;
        case 3:
        edit_home_address(i);
        break;
        case 4:
        edit_mailing_address(i);
        break;
        case 5:
        edit_student_contact(i);
        break;
        case 6:
        menu();
        break;

        default:
        printf("\n\t\t\t\t\tThe Input is NOT correct!! ");
        printf("\n\t\t\t\t\tPlease try again.\n");
        printf("\n\n\t\t\t\t\tEnter any key to continue.\n\t\t\t\t\t");
        getch();
        system("cls");
        goto loop;
        break;
    }

}

void mod_student()
{
	int i;
	i = search();
	mod_student1(i);

}


//---------------------------------------------------         S            O           R            T        ----------------------------------------------------------------------------------------------------//


void sort_student()
{
	system("color D");
char DEPT [20];
int TERM;
int arr[100] = {0};
int i, j , sum = 0, tmp, s , C;
int l;
loop6:	
    system("cls");
    printf("\n\t\t\t\t\tEnter the department ( CAPITAL LETTER ) : ");
    fflush(stdin);
    scanf("%[^\n]s",DEPT);
    fflush(stdin);
    
printf("\n\t\t\t\t\tEnter the semester : ");
scanf("%d",&TERM);
fflush(stdin);
for(i=0; i<Size; i++)
{
    if(Student[i].curr_term == TERM && strcmp(DEPT,Student[i].dept)==0)
    {
        arr[sum] = i;
		sum = sum + 1;
    }
	 
	
	
}

if(Student[arr[0]].curr_term != TERM   && arr[1]==0 && arr[2]==0 )
    {
    	printf("\n\t\t\t\t\tNOT FOUND");
    	loop7:
    printf("\n\t\t\t\t\t1. Try Again\n\t\t\t\t\t0. Menu\n\t\t\t\t\t");
    scanf("%d",&l);
    
	    if(l==1)
	    {
	    	goto loop6;
		}
		
		else if(l==0)
		{
			system("cls");
			menu();
		}
		
		else
		{
			system("cls");
			printf("\n\t\t\t\t\tThe input is NOT correct\n");
			printf("\n\t\t\t\t\tPlease try again.\n");
	    	goto loop7;
	
		}
	
	}

for (i = 0; i < sum; i++)                     //Loop for ascending ordering
	{
		for (j = 0; j < sum; j++)             //Loop for comparing other values
		{
		if (Student[ arr[j] ].gpa.overall_gpa > Student[ arr[i] ].gpa.overall_gpa)//Comparing other array elements
			{
				int tmp = arr[i];         //Using temporary variable for storing last value
				arr[i] = arr[j];            //replacing value
				arr[j] = tmp;             //storing last value
			}  
		}
	}
	int aa = 1;
	
    printf("\n\n\t\t\tno. \t\tName                \t\t    \t GPA\n");
	
	
	printf("\t\t\t======================================================================");
		
		
for (i = sum-1; i >= 0; i-- )    
	{
    
        printf("\n\t\t\t%-4d\t\t %-5s %-5s %-5s     \t\t %4.2f\n",aa,Student[arr[i]].first ,Student[arr[i]].middle, Student[arr[i]].last, Student[arr[i]].gpa.overall_gpa);
        printf("\t\t\t----------------------------------------------------------------------");
                     
		aa++;
	}

getch();

menu();
}


//---------------------------------------------------         M            A           I            N        ----------------------------------------------------------------------------------------------------//


int main()
{
	system("color 4");
	char pass[] = "anwar";
	char pass1[20];
	char user[] = "ahmed";
	char user1[30];
	loop:
	system("cls");
	printf("\n\n\t\t\t\t\tEnter the user name : ");
	scanf("%s",&user1);
	printf("\n\n\t\t\t\t\tEnter the password : ");
	scanf("%s",&pass1);

	if(strcmp(pass1,pass)==0 && strcmp(user1,user)==0)
	{
	printf("\n\n\t\t\t\t\tWelcome Ahmed! ");
	system("color 9");
	getch();
	system("cls");
	menu();
	}
	else
	{
		printf("\n\n\t\t\t\t\tThe user name or password is not correct!  ");
		printf("\n\t\t\t\t\tTry Again ");
		getch();
		goto loop;
	}
	return 0;
}
