#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>


int password();

void addrecord();

void viewrecord();

void editrecord();

void editpassword();

void deleterecord();


struct record

{

    char time[6];

    char name[30];

    char place[25];

    char duration[10];

    char note[500];

} ;


int main()

{

    int ch;

    printf("\n\n\t***********************************\n");

    printf("\t*PASSWORD SYSTEM PERSONAL DIARY*\n");

    printf("\t***********************************");


   while(1)


        {

                printf("\n\n\t\tMAIN MENU:");

                printf("\n\n\tADD RECORD\t[1]");

                printf("\n\tVIEW RECORD\t[2]");

                printf("\n\tEDIT RECORD\t[3]");

                printf("\n\tDELETE RECORD\t[4]");

                printf("\n\tEDIT PASSWORD\t[5]");

                printf("\n\tEXIT\t\t[6]");

                printf("\n\n\tENTER YOUR CHOICE:");

                scanf("%d",&ch);


            switch(ch)

                    {

                            case 1:

                            addrecord();

                            break;


                            case 2:

                            viewrecord();

                            break;


                            case 3:

                            editrecord();

                            break;


                            case 4:

                            deleterecord();

                            break;


                            case 5:

                            editpassword();

                            break;


                            case 6:

                            printf("\n\n\t\tCreated By Hridoy Das");

                            getch();

                            exit(0);


                            default:

                            printf("\nEntered wrong choice");

                            printf("\nPress any key and try again");

                            getch();

                            break;

                    }

                system("cls");

        }

            return 0;

}

void addrecord( )

{

                system("cls");

                FILE *fp ;

                char another = 'Y' ,time[10];

                struct record e ;

                char filename[15];

                int choice;

                printf("\n\n\t\t***************************\n");

                printf("\t\t* Welcome to Add Menu *");

                printf("\n\t\t***************************\n\n");

                printf("\n\n\tEnter Recording Date:[yyyy-mm-dd]:");

                fflush(stdin);

                gets(filename);

                fp = fopen (filename, "ab+" ) ;

                if ( fp == NULL )

                {

                fp=fopen(filename,"wb+");

                if(fp==NULL)

                {

                    printf("\nSYSTEM ERROR...");

                    printf("\nPress any key to exit");

                    getch();

                    return ;

                }

                }



                while ( another == 'Y'|| another=='y' )

                {

                    choice=0;

                    fflush(stdin);

                printf ( "\n\tEnter Time:[hh:mm]:");

                scanf("%s",time);

                rewind(fp);

                while(fread(&e,sizeof(e),1,fp)==1)

                {

                    if(strcmp(e.time,time)==0)

                    {

                        printf("\n\tThis record already exist.\n");

                        choice=1;

                    }

                }

                    if(choice==0)

                    {

                        strcpy(e.time,time);

                        printf("\tEnter Name:");

                        fflush(stdin);

                        gets(e.name);

                        fflush(stdin);

                        printf("\tEnter Place:");

                        gets(e.place);

                        fflush(stdin);

                        printf("\tEnter Duration:");

                        gets(e.duration);

                        fflush(stdin);

                        printf("\tNOTE:");

                        gets(e.note);

                        fwrite ( &e, sizeof ( e ), 1, fp ) ;

                        printf("\nYour record is added\n");

                    }

                        printf ( "\n\tWant to add another record?(Y/N): " ) ;

                        fflush ( stdin ) ;

                        another = getchar( ) ;

                }


                fclose ( fp ) ;

                printf("\n\n\tPress any key to Exit");

                getch();

    }


void viewrecord( )

{

        FILE *fpte ;

        system("cls");

        struct record customer ;

        char time[6],choice,filename[14];

        int ch;

        printf("\n\n\t\t*******************************\n");

        printf("\t\t* Records Viewing Menu*");

        printf("\n\t\t*******************************\n\n");

        choice=password();

        if(choice!=0)

            {

                return ;

            }

        do

            {

                    printf("\n\tEnter the date to view the record:[yyyy-mm-dd]:");

                    fflush(stdin);

                    gets(filename);


                    fpte = fopen ( filename, "rb" ) ;

                    if ( fpte == NULL )

                            {

                                puts ( "\nSorry! The following record does not exist\n" ) ;

                                printf("Press any key to exist");

                                getch();

                                return ;

                            }

                            system("cls");

                printf("\n\tHow would you like to view?\n");

                printf("\n\t1.Whole record of the day?");

                printf("\n\t2.Record of fixed time?");

                printf("\n\t\tEnter your choice. Press 1 or 2.");

                scanf("%d",&ch);

                switch(ch)

                {

                    case 1:

                            printf("\nThe whole record for %s is:",filename);

                         while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

                         {

                            printf("\n");

                            printf("\nTime: %s",customer.time);

                            printf("\nMeeting with: %s",customer.name);

                            printf("\nMeeting at: %s",customer.place);

                            printf("\nDuration: %s",customer.duration);

                            printf("\nNote: %s",customer.note);

                            printf("\n");

                         }

                         break;


                    case 2:

                            fflush(stdin);

                            printf("\nEnter Time:[hh:mm]:");

                            gets(time);

                            while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )


                            {

                                if(strcmp(customer.time,time)==0)

                                {

                                    printf("\nYOUR RECORD IS:");

                                    printf("\nTime: %s",customer.time);

                                    printf("\nMeeting with: %s",customer.name);

                                    printf("\nMeeting at: %s",customer.place);

                                    printf("\nDuration: %s",customer.duration);

                                    printf("\nNote: %s",customer.note);

                                }

                            }

                            break;


                    default: printf("\nYou typed something else\n");

                             break;

                }


               printf("\n\nWould you like to continue you view?(Y/N):");

               fflush(stdin);

            scanf("%c",&choice);

        }while(choice=='Y'||choice=='y');

            fclose ( fpte ) ;

            return ;

}

void editrecord()

{

        system("cls");

        FILE *fpte ;

        struct record customer ;

        char time[6],choice,filename[14];

        int num,count=0;

        printf("\n\n\t\t*******************************\n");

        printf("\t\t* Welcome to Editing Menu *");

        printf("\n\t\t*******************************\n\n");

        choice=password();

        if(choice!=0)

            {

                return ;

            }

        do

            {

                    printf("\n\tEnter the date of record you edited:[yyyy-mm-dd]:");

                    fflush(stdin);

                    gets(filename);

                    printf("\n\tEnter Time:[hh:mm]:");

                    gets(time);

                    fpte = fopen ( filename, "rb+" ) ;

                    if ( fpte == NULL )

                            {

                                printf( "\nRecord does not exist:" ) ;

                                printf("\nPress any key to go back");

                                getch();

                                return;

                            }

                    while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )

                    {

                        if(strcmp(customer.time,time)==0)

                        {

                            printf("\nYour old record was:");

                            printf("\nTime: %s",customer.time);

                            printf("\nMeeting with: %s",customer.name);

                            printf("\nMeeting at: %s",customer.place);

                            printf("\nDuration: %s",customer.duration);

                            printf("\nNote: %s",customer.note);


                            printf("\n\n\t\tWhat would you like to edit?");

                                printf("\n1.Time.");

                                printf("\n2.Meeting person.");

                                printf("\n3.Mrrting place.");

                                printf("\n4.Duration.");

                                printf("\n5.Note.");

                                printf("\n6.Whole records.");

                                printf("\n7.Go back to Main Menu.");

                                do

                                {

                                        printf("\n\tEnter your choice:");

                                        fflush(stdin);

                                        scanf("%d",&num);

                                        fflush(stdin);

                                        switch(num)

                                        {

                                            case 1: printf("\nEnter the new data:");

                                                    printf("\nNew Time:[hh:mm]:");

                                                    gets(customer.time);

                                                    break;


                                            case 2: printf("\nEnter the new data:");

                                                    printf("\nNew Meeting Person:");

                                                    gets(customer.name);

                                                    break;


                                            case 3: printf("\nEnter the new data:");

                                                    printf("\nNew Meeting Place:");

                                                    gets(customer.place);

                                                    break;


                                            case 4: printf("\nEnter the new data:");

                                                    printf("\nDuration:");

                                                    gets(customer.duration);

                                                    break;


                                            case 5: printf("Enter the new data:");

                                                    printf("\nNote:");

                                                    gets(customer.note);

                                                    break;


                                            case 6:  printf("\nEnter the new data:");

                                                     printf("\nNew Time:[hh:mm]:");

                                                     gets(customer.time);

                                                     printf("\nNew Meeting Person:");

                                                     gets(customer.name);

                                                     printf("\nNew Meeting Place:");

                                                     gets(customer.place);

                                                     printf("\nDuration:");

                                                     gets(customer.duration);

                                                     printf("\nNote:");

                                                     gets(customer.note);

                                                     break;


                                            case 7: printf("\nPress any key to go back\n");

                                                    getch();

                                                    return ;

                                                    break;


                                            default: printf("\nYou typed something else. Please try again.\n");

                                                     break;

                                        }


                                }while(num<1||num>8);

                            fseek(fpte,-sizeof(customer),SEEK_CUR);

                            fwrite(&customer,sizeof(customer),1,fpte);

                            fseek(fpte,-sizeof(customer),SEEK_CUR);

                            fread(&customer,sizeof(customer),1,fpte);

                            choice=5;

                            break;

                        }

                    }

                    if(choice==5)

                    {

                    system("cls");

                    printf("\n\t\tEditing completed...\n");

                    printf("--------------------\n");

                    printf("The new record is:\n");

                    printf("--------------------\n");

                    printf("\nTime: %s",customer.time);

                    printf("\nMeeting with: %s",customer.name);

                    printf("\nMeeting at: %s",customer.place);

                    printf("\nDuration: %s",customer.duration);

                    printf("\nNote: %s",customer.note);

                    fclose(fpte);

                    printf("\n\n\tWould you like to edit another record?(Y/N): ");

                    scanf("%c",&choice);

                    count++;

                    }

                    else

                    {

                        printf("\nThe record does not exist:\n");

                        printf("\nWould you like to try again?(Y/N): ");

                        scanf("%c",&choice);

                    }


            }while(choice=='Y'||choice=='y');

            fclose ( fpte ) ;


            if(count==1)

            printf("\n%d File is edited...\n",count);

            else if(count>1)

            printf("\n%d Files are edited...\n",count);

            else

            printf("\nNo files edited...\n");

            printf("\tPress Enter to exit Editing Menu.");

            getch();

}

int password()

{

        char pass[15]={0},check[15]={0},ch;

        FILE *fpp;

        int i=0,j;

        printf("::For Secuirity Perpose::");

        printf("::Only three trials are allowed::");

        for(j=0;j<3;j++)

        {

                        i=0;

                        printf("\n\n\tEnter the password:");

                        pass[0]=getch();

                        while(pass[i]!='\r')

                        {

                            if(pass[i]=='\b')

                            {

                                i--;

                                printf("\b");

                                printf(" ");

                                printf("\b");

                                pass[i]=getch();

                            }

                            else

                            {

                                printf("*");

                                i++;

                                pass[i]=getch();

                            }

                        }

                        pass[i]='\0';

                        fpp=fopen("SE","r");

                        if (fpp==NULL)

                        {

                            printf("\nError!...[File Missing]\n");

                            getch();

                            return 1;

                        }

                        else

                        i=0;

                        while(1)

                        {

                            ch=fgetc(fpp);

                            if(ch==EOF)

                            {

                                check[i]='\0';

                                break;

                            }

                            check[i]=ch-5;

                            i++;

                        }

                        if(strcmp(pass,check)==0)

                        {

                            printf("\n\n\tACCESS GRANTED...\n");

                            return 0;

                        }

                        else

                        {

                            printf("\n\n\tWrong Password..\n\n\tAccess Denied...\n");

                        }

        }

        printf("\n\n\t::Sorry! You entered wrong password::Your are not allowed to access any file::\n\n\tPRESS ANY KEY TO GO BACK...");

        getch();

        return 1;

}

void editpassword()

{

    system("cls");

    printf("\n");

    char pass[15]={0},confirm[15]={0},ch;

    int choice,i,check;

    FILE *fp;

    fp=fopen("SE","rb");

    if(fp==NULL)

    {

        fp=fopen("SE","wb");

        if(fp==NULL)

        {

            printf("SYSTEM ERROR...");

            getch();

            return ;

        }

        fclose(fp);

        printf("\nSystem Restored...\nPress Enter to change Password\n\n");

        getch();

    }

        fclose(fp);

        check=password();

    if(check==1)

    {

        return ;

    }

    do

    {

        if(check==0)

                    {

                        i=0;

                        choice=0;

                        printf("\n\n\tEnter the new Password:");

                        fflush(stdin);

                        pass[0]=getch();

                        while(pass[i]!='\r')

                        {

                            if(pass[i]=='\b')

                            {

                                i--;

                                printf("\b");

                                printf(" ");

                                printf("\b");

                                pass[i]=getch();

                            }

                            else

                            {

                                printf("*");

                                i++;

                                pass[i]=getch();

                            }

                        }

                        pass[i]='\0';

                        i=0;

                        printf("\n\tConfirm Password:");

                        confirm[0]=getch();

                        while(confirm[i]!='\r')

                        {

                            if(confirm[i]=='\b')

                            {

                                i--;

                                printf("\b");

                                printf(" ");

                                printf("\b");

                                confirm[i]=getch();

                            }

                            else

                            {

                                printf("*");

                                i++;

                                confirm[i]=getch();

                            }

                        }

                        confirm[i]='\0';

                        if(strcmp(pass,confirm)==0)

                        {

                            fp=fopen("SE","wb");

                            if(fp==NULL)

                            {

                                printf("\n\t\tError!");

                                getch();

                                return ;

                            }

                            i=0;

                            while(pass[i]!='\0')

                            {

                                ch=pass[i];

                                putc(ch+5,fp);

                                i++;

                            }

                            putc(EOF,fp);

                            fclose(fp);

                        }

                        else

                        {

                            printf("\n\tThe New Password does not matched.");

                            choice=1;


                        }


                    }

}while(choice==1);


    printf("\n\n\tPassword Changed...\n\n\tPress any key to go back...");

    getch();

}


void deleterecord( )

{

                system("cls");

                FILE *fp,*fptr ;

                struct record file ;

                char filename[15],another = 'Y' ,time[10];;

                int choice,check;

                printf("\n\n\t\t*************************\n");

                printf("\t\t* Welcome To Delete Menu*");

                printf("\n\t\t*************************\n\n");

                check = password();

                    if(check==1)

                    {

                        return ;

                    }


                while ( another == 'Y' )

                {

                printf("\n\n\tHow would you like to Delete?");

                printf("\n\n\t1. Delete the whole record.");

                printf("\n\t2. Delete the particular record By time.");


                do

                {

                        printf("\n\t\tEnter your choice:");

                        scanf("%d",&choice);


                    switch(choice)

                        {

                            case 1:

                            printf("\n\tEnter the date of record to be deleted:[yyyy-mm-dd]:");

                            fflush(stdin);

                            gets(filename);

                            fp = fopen (filename, "wb" ) ;

                            if ( fp == NULL )

                            {

                                printf("\nThe file does not exist.");

                                printf("\nPress any key to go back...");

                                getch();

                                return ;

                            }

                            fclose(fp);

                            remove(filename);

                            printf("\nDeleted Successfully...");

                            break;


                            case 2:

                            printf("\n\tEnter the date of record:[yyyy-mm-dd]:");

                            fflush(stdin);

                            gets(filename);

                            fp = fopen (filename, "rb" ) ;

                            if ( fp == NULL )

                            {

                                printf("\nThe file does not exist");

                                printf("\nPess any key to go back...");

                                getch();

                                return ;

                            }

                            fptr=fopen("temp","wb");

                            if(fptr==NULL)

                            {

                                printf("\nSystem Error!");

                                printf("\nPress any key to go back...");

                                getch();

                                return ;

                            }

                            printf("\n\tEnter the time of record to be deleted:[hh:mm]:");

                            fflush(stdin);

                            gets(time);

                            while(fread(&file,sizeof(file),1,fp)==1)

                            {

                                if(strcmp(file.time,time)!=0)

                                fwrite(&file,sizeof(file),1,fptr);

                            }


                            fclose(fp);

                            fclose(fptr);

                            remove(filename);

                            rename("temp",filename);

                            printf("\nDeleted Successfully...");

                            break;


                    default:

                            printf("\n\tYou entered wrong chaoice.");

                            break;

                    }

                }while(choice<1||choice>2);



                    printf("\n\tDo you like to deleted another record?(Y/N): ");

                    fflush(stdin);

                    scanf("%c",&another);

                }

                printf("\n\n\tPress any key to exit...");

                getch();

}

