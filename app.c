#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define concession_fees 500

void availablity_checking();
void train_booking();
void train_cancellation();
void train_chart();

struct Train
{

  struct Passenger
  {
    char fname[14], lname[7];
    char *gender;
    int age;
  }pass_details[10];

  int train_id, train_no;
  int no_of_passengers;
  int dd, mm, yyyy;
  char *train_class, *train_name, *train_time;
  char *origin, *destination;

}tr;

void main ()
{
  int choice;
  system("cls");
  printf("\n\t__________________________________________________________\n");
  printf("\n\t\t\t RAILWAY RESERVATION SYSTEM \n");
  printf("\n\t__________________________________________________________\n\n");
  printf("\n\t\t\t Welcome to Indian Railways\n");
  printf("\n\tBy IRCTC - Indian Railway Catering and Tourism Corporation\n\n");
  printf("\n\t__________________________________________________________\n");
  printf("\n\t\t\tCopyrights reserved @ %s", __DATE__ + 7);
  printf("\n\t__________________________________________________________\n");
  printf("\n\n\n\tPress Any Key To Continue...");
  getch();
  system("cls");
  do
  {
    printf("\t\t___________________________");
    printf("\n\n\t\t    Reservation System    ");
    printf("\n\t\t___________________________");
    printf("\n\n\t\t------------------------");
    printf("\n\t\t 1) Train Availability");
    printf("\n\t\t------------------------");
    printf("\n\t\t 2) Booking");
    printf("\n\t\t------------------------");
    printf("\n\t\t 3) Cancellation");
    printf("\n\t\t------------------------");
    printf("\n\t\t 4) View Chart");
    printf("\n\t\t------------------------");
    printf("\n\t\t 5) Exit");
    printf("\n\t\t------------------------");
    printf("\n\nPlease Enter Your Option [1/2/3/4/5] : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
	availablity_checking();
	printf("\n\n\n Press Any Key to Continue...");
	getch();
	system("cls");
	break;
      case 2:
	train_booking();
	system("cls");
	break;
      case 3:
	system("cls");
	train_cancellation();
	break;
      case 4:
	train_chart();
	printf("\n\nPress Any Key to Go Main Menu...");
	getch();
	system("cls");
	break;
      case 5:
	exit(0);
	break;
      default:
	printf("\nInvalid Option\nPlease Enter Valid Option [1/2/3/4/5]\nPress Enter to Continue...");
	getch();
	system("cls");
    }

  }while(choice);

}

void availablity_checking()
{

  system("cls");
  printf("\n--------------------------------AVAILABLE TRAINS--------------------------------\n");
  printf("________________________________________________________________________________");
  printf("\n Tr.Id\tTr.No\tTrain Name\t\tOrigin     Destination\tTime\tCharges\n");
  printf("________________________________________________________________________________");
  printf("\n  1\t10001\tVaigai SF Express\tMadurai     Chennai\t09:00\t1000");
  printf("\n  2\t10002\tCoimbatore Express\tChennai     Coimbatore\t13:00\t1000");
  printf("\n  3\t10003\tCoimbatore Express\tRameswaram  Coimbatore\t08:00\t1000");
  printf("\n  4\t10004\tCoimbatore Express\tNagercoil   Coimbatore\t23:00\t1000");
  printf("\n  5\t10005\tVaigai SF Express\tChennai     Madurai\t18:00\t1000");
  printf("\n  6\t10006\tPune Indore Express\tPune        Indore\t09:30\t1000");
  printf("\n  7\t10007\tBangalore Express\tChennai     Bangalore\t13:00\t1000");
  printf("\n  8\t10008\tRajdhani Express\tBanglore    New Delhi\t16:00\t1000");
}

void train_booking()
{

  int i, ch, charges, train_class_type, fc_type, fc_count = 0;
  char confirm;

  FILE *fb;
  system("cls");
  fb = fopen("tickets_reserved.txt","a");
  printf("\n\tClasses Available:\n\n\t1)Seater A/C\n\t2)Seater Non A/C\n\t3)Sleeper A/C\n\t4)Sleeper Non A/C\n\nPlease Select Your Class : ");
  scanf("%d",&train_class_type);
  system("cls");

  switch(train_class_type)
  {
    case 1:
      tr.train_class = "Seater A/C";
      printf("\nEnter Number of Seats : ");
      scanf("%d",&tr.no_of_passengers);
      break;
    case 2:
      tr.train_class = "Seater N.A/C";
      printf("\nEnter Number of Seats : ");
      scanf("%d",&tr.no_of_passengers);
      break;
    case 3:
      tr.train_class = "Sleeper A/C";
      printf("\nEnter Number of Berths : ");
      scanf("%d",&tr.no_of_passengers);
      break;
    case 4:
      tr.train_class = "SleeperN.A/C";
      printf("\nEnter Number of Berths : ");
      scanf("%d",&tr.no_of_passengers);
      break;
  }

  Details :
  for( i = 0; i < tr.no_of_passengers; i++)
  {
    system("cls");
    printf("\n\nPlease Enter the Details of Passenger %d : \n", i+1);
    printf("\n First Name\t: ");
    scanf("%s", &tr.pass_details[i].fname);
    printf(" Last Name\t: ");
    scanf("%s", &tr.pass_details[i].lname);
    printf(" Gender [M/F]\t: ");
    scanf(" %c", &tr.pass_details[i].gender);
    printf(" Age\t\t: ");
    scanf("%d", &tr.pass_details[i].age);
    printf("\n Fee Concession Type :\n  1) Senior Citizen\n  2) Age Below 5 Years\n  3) None\n");
    printf("\n Fee Concession Type :");
    if(tr.pass_details[i].age >= 60)
    {
	  fc_type = 1;
	  printf("  Senior Citizen");
    }
    else if(tr.pass_details[i].age <= 5)
    {
      fc_type = 1;
      printf("  Age Below 5 Years");
    }
    else
      printf("  None");
    if(fc_type == 1)
    {
      fc_count++;
      printf("\n Press any key to continue . . .");
      getch();
    }
  }

  Id:
  system("cls");
  availablity_checking();
  printf("\n\n Select Your Train ID : ");
  scanf("%d",&tr.train_id);
  switch(tr.train_id)
  {
    case 1:
      tr.train_no = 10001;
      tr.train_time = "09:00";
      tr.train_name ="Vaigai SF Express";
      tr.origin = "Madurai Junction";
      tr.destination = "Chennai Egmore";
      break;
    case 2:
      tr.train_no = 10002;
      tr.train_time = "13:00";
      tr.train_name ="Coimbatore Express";
      tr.origin = "Chennai Central";
      tr.destination = "Coimbatore Junction";
      break;
    case 3:
      tr.train_no = 10003;
      tr.train_time = "08:00";
      tr.train_name ="Coimbatore Express";
      tr.origin = "Rameswaran Junction";
      tr.destination = "Coimbatore Junction";
      break;
    case 4:
      tr.train_no = 10004;
      tr.train_time = "23:00";
      tr.train_name ="Coimbatore Express";
      tr.origin = "Nagercoil Junction";
      tr.destination = "Coimbatore Juntion";
      break;
    case 5:
      tr.train_no = 10005;
      tr.train_time = "18:00";
      tr.train_name ="Vaigai SF Express";
      tr.origin = "Chennai Egmore";
      tr.destination = "Madurai Junction";
      break;
    case 6:
      tr.train_no = 10006;
      tr.train_time = "09:30";
      tr.train_name ="Pune Indore Express";
      tr.origin = "Pune Junction";
      tr.destination = "Indore Junction Bg";
      break;
    case 7:
      tr.train_no = 10007;
      tr.train_time = "13:00";
      tr.train_name ="Bangalore Express";
      tr.origin = "Chennai Central";
      tr.destination = "Bangalore Junction";
      break;
    case 8:
      tr.train_no = 10008;
      tr.train_time = "16:00";
      tr.train_name ="Rajdhani Express";
      tr.origin = "Bangalore Junction";
      tr.destination = "New Delhi Junction";
      break;
    default:
      printf("\n Sorry, Invalid Train Id\tPlease Enter Correct Train Id...");
      getch();
      system("cls");
      goto Id;
  }

  printf("\n Enter Date of Journey [DD/MM/YYYY]: ");
  scanf("%d/%d/%d", &tr.dd, &tr.mm, &tr.yyyy);

  printf("\n\n Tickets Need to be Confirmed...\t\tPress Any Key to Continue...");
  getch();
  system("cls");

  charges = (tr.no_of_passengers-fc_count) * 1000 + (fc_count*concession_fees);

  printf(" \n\nCharges per Ticket : Rs.1000 \t\t Fee Concession [If Applicable] : Rs.500\n");
  printf("Train No \t: %d \t\t Train Name \t : %s\n", tr.train_no, tr.train_name);
  printf("Class \t\t: %s \t\t Date of Journey : %d/%d/%d\n", tr.train_class, tr.dd, tr.mm, tr.yyyy);
  printf("Origin \t\t: %s \t Destination \t : %s\n", tr.origin, tr.destination);
  printf("Total Charges \t: %d \t\t\t Arrival Time  \t : %s", charges,tr.train_time);
  printf("\n\t\t________________________________________________\n");
  printf("\n\t\t\tName\t\tAge\tGender");
  printf("\n\t\t________________________________________________\n");
  for( i = 0; i < tr.no_of_passengers; i++)
  {
    printf("\n\t\t\t%s %s\t%d\t %c", tr.pass_details[i].fname, tr.pass_details[i].lname, tr.pass_details[i].age, tr.pass_details[i].gender);
  }
  printf("\n\t\t________________________________________________\n");
  printf("\n Do you want to Confirm Your Ticker [y/n]\t: ");
  scanf(" %c",&confirm);
  printf(" %c",confirm);
  if(confirm == 'y' || confirm == 'Y')
  {
    system("cls");
    for( i = 0; i < tr.no_of_passengers; i++)
    {
      fprintf(fb,"%d\t%s %s\t%d\t %c\t%d/%d/%d\n", tr.train_no, tr.pass_details[i].fname, tr.pass_details[i].lname, tr.pass_details[i].age, tr.pass_details[i].gender, tr.dd, tr.mm, tr.yyyy);
    }
    printf("\n\t\t________________________________________________\n");
    printf("\n\t\t\tName\t\tAge\tGender\n");
    printf("\t\t________________________________________________\n");
    for( i = 0; i < tr.no_of_passengers; i++)
    {
      printf("\n\t\t\t%s %s\t%d\t %c", tr.pass_details[i].fname, tr.pass_details[i].lname, tr.pass_details[i].age, tr.pass_details[i].gender);
    }
    printf("\n\t\t________________________________________________\n");
    printf("\n\t\t\tYour Tickets are Confirmed!\n\t\t     Thank You for Travelling with us!");
    printf("\n\n\nPress Any Key to Go to Main Menu...");
    getch();
  }
  else
  {
    system("cls");
    printf("\n\n\tWhat Do You Want to Change ? :\n");
    printf("\n\t\t1)Details of Passengers\n\t\t2)Train Id & Date of Journey\n\t\t3)Cancel Ticket\n\n\tEnter Your Choice [1/2/3] : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
	goto Details;
      case 2:
	goto Id;
      case 3:
	break;
    }
  }
  fclose(fb);
  fc_count = 0;

}

void train_cancellation()
{
  int i = 0, count = 0, flag = 0;
  char cfname[14], clname[7], ch, option;
  FILE *fb, *fb_temp;
  fb = fopen("tickets_reserved.txt","r");
  fread(&tr, sizeof(tr), 1, fb);
  Invalid:
  train_chart();
  if(fb == NULL || tr.train_no == 0)
  {
  printf("\n\n Press any key to Go Main Menu...");
  getch();
  }
  else
  {

  printf("\n\t\tType of Cancellation : \n");
  printf("\n\t\t\t1) Full Cancelltion [All Tickets will be Cancelled]");
  printf("\n\t\t\t2) Partial Cancellation");
  printf("\n\t\t\t3) Exit");
  printf("\n\n\tEnter Your Option [1/2/3]: ");
  scanf(" %c",&option);
  rewind(fb);
  for(i = getc(fb); i !=EOF; i = getc(fb))
  {
	if (i == '\n')
		count++;
  }

  switch(option)
  {
    case '1':

      system("cls");

      train_chart();
      printf("\n\n\tAll %d Tickets will be Cancelled!", count);
      printf("\n\tDo you want to Continue to Cancel Tickets ? [y/n] : ");
      scanf(" %c", &ch);
      system("cls");

      fclose(fb);
      
      if(ch == 'y' || ch == 'Y')
      {
	remove("tickets_reserved.txt");
	train_chart();
	printf("\n\n\tAll the Tickets were Cancelled! Thank You for Joining Us");
	printf("\n\n Press Any Key to Continue...");
	getch();
      }
      else if (ch == 'n' || ch == 'N')
      {
	printf("\n\n\t\tNo Tickets were Cancelled!");
	printf("\n\t Press Any Key to Continue...");
	getch();
      }
      break;

    case '2':

      fb_temp = fopen("temp.txt","a");
      system("cls");
      train_chart();
      printf("\n\n   Enter the Name of the Cancelling Ticket : ");
      scanf("%s %s", cfname, clname);
      rewind(fb);
      for(i = getc(fb); i != EOF; i = getc(fb))
      {
	fscanf(fb, "%d\t%s %s\t%d\t %c\t%d/%d/%d\n", &tr.train_no, tr.pass_details[i].fname, tr.pass_details[i].lname, &tr.pass_details[i].age, &tr.pass_details[i].gender, &tr.dd, &tr.mm, &tr.yyyy);
	if(strcmp(tr.pass_details[i].fname, cfname) == 0 && strcmp(tr.pass_details[i].lname, clname) == 0)
	  flag = 1;
      }

      if(flag == 1)
      {
	if(count==1)
	{
	  fclose(fb);
	  fclose(fb_temp);

	  remove("tickets_reserved.txt");

	  system("cls");

	  train_chart();
	  printf("\n\n\n\n\t\t The Ticket Named %s %s was Cancelled",cfname, clname);
	  printf("\n\n\n\t\t Please Reload the Program and Run");
	  printf("\n\n\n\n\n\tPress Any Key to Continue...");
	  fclose(fb);
	  getch();
	}

	else
	{
	  rewind(fb);
	  while(!feof(fb))
	  {
	    fscanf(fb, "%d\t%s %s\t%d\t %c\t%d/%d/%d\n", &tr.train_no, tr.pass_details[i].fname, tr.pass_details[i].lname, &tr.pass_details[i].age, &tr.pass_details[i].gender, &tr.dd, &tr.mm, &tr.yyyy);
	    if(strcmp(tr.pass_details[i].fname, cfname) != 0)
	      fprintf(fb_temp, "%d\t%s %s\t%d\t %c\t%d/%d/%d\n", tr.train_no, tr.pass_details[i].fname, tr.pass_details[i].lname, tr.pass_details[i].age, tr.pass_details[i].gender, tr.dd, tr.mm, tr.yyyy);
	  }

	  fclose(fb);
	  fclose(fb_temp);
	  remove("tickets_reserved.txt");
	  rename("temp.txt","tickets_reserved.txt");
	  system("cls");

	  train_chart();
	  printf("\n\n\tThe Ticket Named %s %s was Cancelled",cfname, clname);
	  printf("\n\tPress Any Key to Continue...");
	  getch();
	}

      }

      else
      {
	    printf("\n\t No Ticket Named %s %s", cfname, clname);
		printf("\n\n\t Press any key to Go Main Menu...");
		getch();
		remove("temp.txt");
      }

      break;

    case '3':
      fclose(fb_temp);
      fclose(fb);
      break;

    default:
      printf("\n\tInvalid Option\n\tPlease Choose Option [1/2/3]\n\tPress Any Key to Continue Again...");
      fclose(fb_temp);
      getch();
      system("cls");
      goto Invalid;

  }
  }
  system("cls");

}

void train_chart()
{
  FILE *fb;
  int i = 0;
  system("cls");

  fb = fopen("tickets_reserved.txt","r");
  printf("\n    __________________________________________________________________________\n");
  printf("\n\tTr.No \t Name\t\t\tAge\tGender\tDate of Journey\n");
  printf("    __________________________________________________________________________\n\n");

  fscanf(fb,"%d\t%s %s\t%d\t %c\t%d/%d/%d\n", &tr.train_no, tr.pass_details[i].fname, tr.pass_details[i].lname, &tr.pass_details[i].age, &tr.pass_details[i].gender, &tr.dd, &tr.mm, &tr.yyyy);
  if(tr.train_no == 0 || fb == NULL)
  {
    printf("\n\t\t\tNo Tickets Reserved or Booked\n\n");
  }
  else
  {
    rewind(fb);
    while(!feof(fb))
    {
      fscanf(fb,"%d\t%s %s\t%d\t %c\t%d/%d/%d\n", &tr.train_no, tr.pass_details[i].fname, tr.pass_details[i].lname, &tr.pass_details[i].age, &tr.pass_details[i].gender, &tr.dd, &tr.mm, &tr.yyyy);
      printf("\t%d\t%s %s\t\t%d\t %c\t%d/%d/%d\n", tr.train_no, tr.pass_details[i].fname, tr.pass_details[i].lname, tr.pass_details[i].age, tr.pass_details[i].gender, tr.dd, tr.mm, tr.yyyy);
    }
  }
  printf("    __________________________________________________________________________\n");
  fclose(fb);

}
