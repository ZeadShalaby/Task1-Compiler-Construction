#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8


// all inputs i need it in system //
struct users {
char fullname[50];
char email[50];
char password[50];
char username[50];
char phone[50];
char sex[50];
char confirmpass[50];
char logservice[50];
char passlog[50];


};

// remove / and add 0 in end //
void takeinputs(char ch[50]){
//fgets() is a function in the C programming language that reads a limited number of characters from a given file stream source into an array of characters//
fgets(ch,50,stdin);
ch[strlen(ch) -1] = 0;
}

// Take the input from the users and add the name from the email to login //
void generatename(char email[50],char username[50]){
     //user12@gmail.com//
    // filter this email and take name before "@" //
    for(int i=0;i<strlen(email);i++){
        if(email[i]=='@') break;
        else username[i] = email[i];
    }
}


// take the inputpassword from users and hashing it **** //
void takepassword(char pass[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pass[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pass[i++] = ch;
			printf("* \b");
		}
	}
}



int main()
{
    system("color 0D");

	FILE *ze;
    int opts,userfound = 0;
    struct users users;

    printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
    printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t\t||   Welcome to Authentication System   ||\n");
    printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
    printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
    printf("\n Choice Your Operation Sir\n");
    printf("\n *1-Signup\n");
    printf("\n *2-Login\n");
    printf("\n *3-Exit\n");
    printf("\n Your Choice Sir : ");

    scanf("%d",&opts);
    fgetc(stdin);

    switch(opts){
    case 1:
        system("cls");
        printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
        printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
        printf("\n\t\t\t\t\t||   Welcome to Authentication System   ||\n");
        printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
        printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t\n");

        printf("*#* Enter Your FullName Sir :  ");
        takeinputs(users.fullname);
        printf("*#* Enter Your Email Sir :  ");
        takeinputs(users.email);
        printf("*#* Enter Your Contact Phone Sir :  ");
        takeinputs(users.phone);
        printf("*#* Enter Your password Sir :");
        takepassword(users.password);
        printf("\n*#* Confirm Your password Sir :");
        takepassword(users.confirmpass);
     if(!strcmp(users.password,users.confirmpass)){
        generatename(users.email,users.username);
        ze  = fopen("SystemUsers.dat","a+");
        fwrite(&users,sizeof(struct users),1,ze);

        if(fwrite !=0) printf("\n\n User Register success, \n your name is %s ",users.username);
        else printf("\n Errors Something Went Wrong:(");
     }
     else{
      printf("\n Errors Password Try Again ");
      Beep(523,800);
     }
    break;

    case 2:
        system("cls");
        printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
        printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
        printf("\n\t\t\t\t\t||   Welcome to Authentication System   ||\n");
        printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
        printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t\n");

        printf("\nEnter your username :\t");
        takeinputs(users.logservice);
        printf("Enter your password :\t");
        takepassword(users.passlog);
        ze = fopen("SystemUsers.dat","r");
        while(fread(&users,sizeof(struct users),1,ze)){

            if(!strcmp(users.username,users.logservice)){
                    if(!strcmp(users.password,users.passlog)){
                    system("cls");
                    printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
                    printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
                    printf("\n\t\t\t\t\t\t   Welcome Sir %s",users.fullname  );
                    printf("\n\t\t\t\t\t------------------------------------------\t\t\t\t\n");
                    printf("\t\t\t\t\t------------------------------------------\t\t\t\t\n");

                    printf("\n\n|Full Name:\t%s",users.fullname);
                    printf("\n|Email:\t\t%s",users.email);
                    printf("\n|Username:\t%s",users.username);
                    printf("\n|Contact no.:\t%s",users.phone);

        }else {
                printf("\n\nInvalid Password!");
                Beep(523,800);
      }
       userfound = 1;

    }}
    if(!userfound){
				printf("\n\nUser is not registered!");
				Beep(523,800);
			}
			fclose(ze);
			break;
    case 3:
        printf("Ciao ,Au revoir  Sir :)");
        Beep(800,300);
			return 0;
        }
    return 0;

    }
