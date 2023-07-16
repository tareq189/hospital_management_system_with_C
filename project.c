#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct patient
{
    char name[100],address[100],disease[100],department[100],date[50],phone[100],doctor[50];
    char age[100],serial[100],room[100],bill[100];
    int situation;
};

int login()
{
    char id[100],pass[100],ID[100],PASS[100];
    int flag=0;

    printf("Enter your user name:\n");
    gets(id);
    strcat(id,"\n");

    printf("Enter your password:\n");
    gets(pass);
    strcat(pass,"\n");

    FILE *f1;
    f1=fopen("admin","r");
    while(fgets(ID,100,f1)!=NULL)
    {
        fgets(PASS,100,f1);
        if(strcmp(ID,id)==0&&strcmp(PASS,pass)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        printf("access granted\n\n");
        return 1;
    }
    fclose(f1);
}


void info()
{

    char d[1];
    struct patient a;
    a.situation=1;
    gets(d);
    printf("Enter Patient's Serial No:\n");
    gets(a.serial);
    printf("Enter Patient's Name:\n");
    gets(a.name);
    printf("Enter Patient's Address:\n");
    gets(a.address);
    printf("Enter Patient's Age:\n");
    gets(a.age);
    printf("Enter Patient's Phone Number:\n");
    gets(a.phone);
    printf("Enter Disease:\n");
    gets(a.disease);
    printf("Enter Department:\n");
    gets(a.department);
    printf("Doctor's Name:\n");
    gets(a.doctor);
    printf("Enter Room No:\n");
    gets(a.room);
    printf("Bill:\n");
    gets(a.bill);
    printf("Date :\n");
    gets(a.date);

    FILE *f2;
    f2=fopen("patient","a");
    fputs(a.serial,f2);
    fprintf(f2,"\n");
    fputs(a.name,f2);
    fprintf(f2,"\n");
    fputs(a.address,f2);
    fprintf(f2,"\n");
    fputs(a.age,f2);
    fprintf(f2,"\n");
    fputs(a.phone,f2);
    fprintf(f2,"\n");
    fputs(a.disease,f2);
    fprintf(f2,"\n");
    fputs(a.department,f2);
    fprintf(f2,"\n");
    fputs(a.doctor,f2);
    fprintf(f2,"\n");
    fputs(a.room,f2);
    fprintf(f2,"\n");
    fputs(a.bill,f2);
    fprintf(f2,"\n");
    fputs(a.date,f2);
    fprintf(f2,"\n");
    fprintf(f2,"%d",a.situation);
    fprintf(f2,"\n\n");

    fclose(f2);
}
void search()
{
    struct patient srch;
    char t[100],d[1];
    printf("Input Serial No:\n");
    gets(d);
    gets(t);
    strcat(t,"\n");
    FILE *f3=fopen("patient","r");
    while(fgets(srch.serial,100,f3)!=NULL)
    {
        fgets(srch.name,100,f3);
        fgets(srch.address,100,f3);
        fgets(srch.age,100,f3);
        fgets(srch.phone,100,f3);
        fgets(srch.disease,100,f3);
        fgets(srch.department,100,f3);
        fgets(srch.doctor,50,f3);
        fgets(srch.room,100,f3);
        fgets(srch.bill,100,f3);
        fgets(srch.date,50,f3);
        fscanf(f3,"%d",&srch.situation);
        fscanf(f3,"\n");
        fscanf(f3,"\n");
        if(strcmp(srch.serial,t)==0)
        {
            printf("Patient Information:-\nSerial No: ");
            puts(srch.serial);
            printf("Name: ");
            puts(srch.name);
            printf("Address: ");
            puts(srch.address);
            printf("Age: ");
            puts(srch.age);
            printf("Phone No: ");
            puts(srch.phone);
            printf("Disease: ");
            puts(srch.disease);
            printf("Department: ");
            puts(srch.department);
            printf("Doctor's Name: ");
            puts(srch.doctor);
            printf("Room: ");
            puts(srch.room);
            printf("Bill: ");
            puts(srch.bill);
            printf("Admit Date: ");
            puts(srch.date);
            if(srch.situation==1)
            {
                printf("On Going Patient\n\n");
            }
            if(srch.situation==2)
            {
                printf("Released Patient\n\n");
            }
        }
    }
    fclose(f3);
}

void release()
{
    struct  patient database[1000];
    char t[100],d[1];
    int i=0;
    printf("Input Serial No:\n");
    gets(d);
    gets(t);
    strcat(t,"\n");
    FILE *f4=fopen("patient","r");
    while(fgets(database[i].serial,100,f4)!=NULL)
    {
        fgets(database[i].name,100,f4);
        fgets(database[i].address,100,f4);
        fgets(database[i].age,100,f4);
        fgets(database[i].phone,100,f4);
        fgets(database[i].disease,100,f4);
        fgets(database[i].department,100,f4);
        fgets(database[i].doctor,50,f4);
        fgets(database[i].room,100,f4);
        fgets(database[i].bill,100,f4);
        fgets(database[i].date,50,f4);
        fscanf(f4,"%d",&database[i].situation);
        if(strcmp(database[i].serial,t)==0)
        {
            database[i].situation=2;
        }
        fscanf(f4,"\n");
        fscanf(f4,"\n");
        i++;
    }
    fclose(f4);
    int j=i;
    FILE *f5=fopen("patient","w");
    for(i=0;i<j;i++)
    {
        fputs(database[i].serial,f5);
        fputs(database[i].name,f5);
        fputs(database[i].address,f5);
        fputs(database[i].age,f5);
        fputs(database[i].phone,f5);
        fputs(database[i].disease,f5);
        fputs(database[i].department,f5);
        fputs(database[i].doctor,f5);
        fputs(database[i].room,f5);
        fputs(database[i].bill,f5);
        fputs(database[i].date,f5);
        fprintf(f5,"%d\n\n",database[i].situation);

    }
    fclose(f5);
}

int main()
{
     for(;;)
        {
            int n,z;
            printf("\n************************************************************************************************************************");
            printf("                                         \"1\" Admin Log in.\n");
            printf("                                         \"2\" Close Programme.\n");
            printf("************************************************************************************************************************");
            scanf("%d",&n);
            char d[1];
            gets(d);
            if(n==1)
            {
                z=login();
                if(z==1)
                {
                    for(;;)
                    {
                        int m;
                        printf("\n************************************************************************************************************************");
                        printf("                                          \"1\" Admit Patient.\n");
                        printf("                                          \"2\" Realease Patient.\n");
                        printf("                                          \"3\" Patient Information.\n");
                        printf("                                          \"4\" Log Out\n");
                        printf("\n************************************************************************************************************************");
                        scanf("%d",&m);
                        if(m==1)
                        {
                            info();
                        }
                        else if(m==2)
                        {
                            release();
                            printf("Patient Released\n");
                        }
                        else if(m==3)
                        {
                            search();
                        }
                        else if(m==4)
                        {
                            break;
                        }
                        else
                        {
                            printf("Invalid Option");
                        }
                    }
                }
                else
                {
                    printf("Access Denied\n");
                }
            }
            else if(n==2)
            {
                break;
            }
            else
            {
                printf("access denied\n\n");
            }

        }
}



