#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
struct main
{
    char name[20];
    char phone_no[20];
    char address[50];
    int train_no;
    int ticket_no[106];
    char bogey[10];
    char seat_no[106];
    int n;
    int date, month, year;
} s,c;
void view();
void menu();
void reserve();
void cancel();
void form();
void view_ticket();
void switches();
void main()
{
    system("color b");
    int pin;
    printf("\t\t\t\t\t ---------------------------------------");
    printf("\n\t \t\t\t\t |WELCOME TO RAILWAY RESERVATION SYSTEM|");
    printf("\t\t\t\t\t\t\t\t\t\t ---------------------------------------\n\n\n\n\n\n\n\n\n");
    system("pause");
    system("cls");
    while(pin!=1122)
    {
        system("color b");
        printf("\n\t\t\t\t\t    ENTER SECRET CODE TO ACCESS \n\n");
        scanf("%d", &pin);
        fflush(stdin);
        system("cls");
        if(pin!=1122)
            printf("\n\n\t\t\t\t\t Please Enter a Valid a Secret Code \n\t\t");
    }
    system("cls");
    menu();
}
void menu()
{
    printf("\t-------------------\t--------------------\t-------------------\t----------------\t--------");
    printf("\n\t|1.VIEW ALL TRAINS|");
    printf("\t|2.RESERVE A TICKET|");
    printf("\t|3.CANCEL A TICKET|");
    printf("\t|4.VIEW TICKETS|");
    printf("\t|5.EXIT|\n ");
    printf("\t-------------------\t--------------------\t-------------------\t----------------\t--------");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tEnter your choice: ");
    switches();
}
void switches()
{
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        view();
        switches();
        break;
    case 2:
        reserve();
        switches();
        break;
    case 3:
        cancel();
        switches();
        break;
    case 4:
        view_ticket();
        switches();
        break;
    case 5:
        break;
    default:
        printf("Enter valid choice:::");
        system("cls");

    }
}
void view()
{
    system("cls");
    system("color b");
    printf("*TRAIN NO*  *********ROUTE********       ***TRAIN NAME***              *DEPARTURE*  ");
    printf("\n  730\t    DHAKA     to  SAIDPUR        NIL SAGOR EXPRESS              06:30 am   ");
    printf("\n  731\t    SAIDPUR   to  DHAKA          NIL SAGOR EXPRESS              12:00 pm   ");
    printf("\n  732\t    DHAKA     to  RAJSHAHI       PADMA EXPRESS                  02:30 pm   ");
    printf("\n  733\t    KHULNA    to  SAIDPUR        RUPSHA EXPRESS                 06:00 pm   ");
    printf("\n  734\t    DHAKA     to  SYLET          PARABOT EXPRESS                08:00 pm   ");
    printf("\n  735\t    DHAKA     to  CHITTAGONG     SONAR BANGLA EXPRESS           07:00 am   ");
    printf("\n  736\t    DINAJPUR  to  DHAKA          EKOTA EXPRESS                  07:00 pm   ");
    printf("\n  737\t    SHYLET    to  DHAKA          UPABAN EXPRESS                 03:30 am   ");
    printf("\n  738\t    RANGPUR   to  DHAKA          RANGPUR EXPRESS                08:30 am   ");
    printf("\n  739\t    RAJSHAHI  to  Dhaka          SILK CITY EXPRESS              11:00 am   ");
    printf("\n  740\t    SAIDPUR   to  RAJSHAHI       VARENDRA EXPRESS               07:10 am   ");
    printf("\n  741\t    RAJSHAHI  to  SAIDPUR        TITUMIR EXPRESS                06:20 am   ");
    printf("\n  742\t    KHULNA    to  RAJSHAHI       KOPATTKHO EXPRESS              07:10 am   ");
    printf("\n  743\t    RAJSHAHI  to  KHULNA         SAGORDARI EXPRESS              09:10 pm  \n ");
    //printf("\n\nEnter the new choice: ");
    system("pause");
    system("cls");
    menu();
}
void reserve()
{
    int total_seats=105,reserved=0,s_class;
    if(reserved<=total_seats)
    {
        reserved++;
        system("color b");
        printf("\n\nEnter Date (DD MM YYYY): ");
        scanf("%d %d %d", &s.date, &s.month, &s.year);
        printf("\nHow many seats: ");
        scanf("%d",&s.n);
        printf("\nEnter train no: ");
        scanf("%d",&s.train_no);
        if(s.train_no==730||s.train_no==731||s.train_no==732||s.train_no==733||s.train_no==734||s.train_no==735||s.train_no==736||s.train_no==737||s.train_no==738||s.train_no==739||s.train_no==740||s.train_no==741||s.train_no==742||s.train_no==743)
        {
            printf("\n 1.First class(  fare  TK.1000)");
            printf("\n 2.Second class( fare  TK.700)");
            printf("\n 3.Shovon Chair(fare  TK.500)");
            printf("\n\n Enter the new choice: ");
            scanf("%d",&s_class);
            if(s_class==1)
            {
                printf("\n\nYour fair is TK.%d only",s.n*1000);
                form();
                menu();
            }
            else if(s_class==2)
            {
                printf("Your fair is TK.%d",s.n*700);
                form();
                menu();
            }
            else if(s_class==3)
            {
                printf("Your fair is TK.%d",s.n*500);
                form();
                menu();
            }
            else
            {
                printf("Enter valid choice(1,2 or 3):::");
                menu();
            }
        }
        else
            printf("WARNING!YOU HAVE ENTERED THE WRONG CODE\a \n Try again\n");
        system("color c");
    }
}
void form()
{
    int i,j,s_ticket_no[105], flag = 0;
    FILE *out;
    printf("\n\nEnter name: ");
    scanf("%s",&s.name);
    printf("\nEnter phone number: ");
    scanf("%s",&s.phone_no);
    printf("\nEnter address: ");
    scanf("%s",&s.address);
    printf("Enter bogey: ");
    scanf("%s",&s.bogey);
    for(i=0; i<s.n; i++)
    {
        do
        {
            out=fopen("Output.txt","r");
            flag = 0;

            printf("\nEnter seat no %d: ", i+1);
            scanf("%d",&s.ticket_no[i]);

            while(s.ticket_no[i]>=105)
            {
                printf("It's beyond limit\n\n");
                printf("Enter seat no %d: ", i+1);
                scanf("%d",&s.ticket_no[i]);
            }
            for(j=0; j<i; j++)
            {
                while(s.ticket_no[i] == s.ticket_no[j])
                {
                    printf("Booked in this Ticket\n\n");
                    printf("Enter seat no %d: ", i+1);
                    scanf("%d",&s.ticket_no[i]);
                }
            }
            while(fscanf(out,"%s %s %s %d %d %d %d %s %d",&c.name, &c.phone_no, &c.address, &c.date, &c.month, &c.year, &c.train_no, &c.bogey, &c.n) != EOF)
            {
                for(j=0; j<c.n; j++)
                {
                    fscanf(out, "%d", &c.ticket_no[j]);

                    if(strcmp(s.bogey,c.bogey) == 0 && s.ticket_no[i] == c.ticket_no[j] && s.date == c.date && s.month == c.month && s.year == c.year && s.train_no == c.train_no)
                    {
                        flag = 1;
                    }
                }
                if (flag == 1)
                    break;
            }
            if(flag == 1)
            {
                printf("Seat has been taken..\n");
            }
            fclose(out);
        }
        while(flag == 1);
    }
    out=fopen("Output.txt","a+");
    system("color b");
    printf("######SUCCESS#######");
    MessageBox(0,"Ticket Has Confirmed","congratulation",1);
    system("cls");
    fprintf(out,"%s %s %s %d %d %d %d %s %d ",s.name, s.phone_no, s.address, s.date, s.month, s.year, s.train_no, s.bogey, s.n);
    for(i=0; i<s.n; i++)
        fprintf(out,"%d ",s.ticket_no[i]);
    fprintf(out,"\n");
    fclose(out);
}
void cancel()
{
    FILE *out,*temp;
    char search[80],ch;
    int i,flag=0,search_tn;
    out=fopen("Output.txt","r");
    printf("Enter Phone No: ");
    scanf("%s", &search);
    printf("Enter Train No: ");
    scanf("%d", &search_tn);
    printf("Enter Date (DD MM YYYY): ");
    scanf("%d %d %d", &c.date, &c.month, &c.year);
    while(fscanf(out,"%s %s %s %d %d %d %d %s %d",&s.name, &s.phone_no, &s.address, &s.date, &s.month, &s.year, &s.train_no, &s.bogey, &s.n) != EOF)
    {
        for(i=0; i<s.n; i++)
        {
            fscanf(out, "%d", &s.ticket_no[i]);
        }
        if(strcmp(search,s.phone_no) == 0 && s.train_no == search_tn && c.date == s.date && c.month == s.month && c.year == s.year)
        {
            flag = 1;
            printf("Found!!\n");
            printf("Name: %s\n", s.name);
            printf("Phone: %s\n", s.phone_no);
            printf("Address: %s\n", s.address);
            printf("Date: %d-%d-%d\n", s.date, s.month, s.year);
            printf("Train No: %d\n", s.train_no);
            printf("Bogey: %s\n", s.bogey);
            printf("Seat No: ", s.ticket_no[i]);
            for(i=0; i<s.n; i++)
                printf("%d ", s.ticket_no[i]);
            printf("\n\n");
            printf("Cancel this ticket? (y/n): ", ch);
            scanf(" %c", &ch);
            break;
        }
    }
    if(flag == 0)
        printf("Not Found\n\n");
    fclose(out);

    if(ch == 'y' || ch == 'Y')
    {
        out=fopen("Output.txt","r");
        temp=fopen("Temp.txt","w+");

        while(fscanf(out,"%s %s %s %d %d %d %d %s %d",&s.name, &s.phone_no, &s.address, &s.date, &s.month, &s.year, &s.train_no, &s.bogey, &s.n) != EOF)
        {
            for(i=0; i<s.n; i++)
            {
                fscanf(out, "%d", &s.ticket_no[i]);
            }

            if(strcmp(search,s.phone_no) == 0 && s.train_no == search_tn)
                printf("Delete Success!!\n");

            else
            {
                fprintf(temp,"%s %s %s %d %d %d %d %s %d ",s.name, s.phone_no, s.address, s.date, s.month, s.year, s.train_no, s.bogey, s.n);
                for(i=0; i<s.n; i++)
                    fprintf(temp,"%d ",s.ticket_no[i]);
                fprintf(temp,"\n");
            }
        }
        fclose(out);
        fclose(temp);
        remove("Output.txt");
        rename("temp.txt","Output.txt");
    }
    else
    {
        system("cls");
        menu();
    }

    printf("Press any key. ");
    getch();
    printf("\nEnter new choice: ");
}
void view_ticket()
{
    FILE*fp;
    char ch;
    fp=fopen("Output.txt","r");
    while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
            break;
        printf("%c",ch);
    }
    printf("\n");
    fclose(fp);
    {
        system("pause");
        system("cls");
        menu();
    }
    printf("\nEnter new choice: ");
}
