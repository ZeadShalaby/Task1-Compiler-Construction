#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define ENTER 13
#define TAB 9
#define BCKSPC 8


struct users{
	char fullname[50] ;
	char username[50];
	char email[50];
	char phone[50];
	char sex[50];
	char password[50];
	char confirmpass[50];
};

// remove / and add 0 in end //
void takeinput(char ch[50]){
    //fgets() is a function in the C programming language that reads a limited number of characters from a given file stream source into an array of characters//
	fgets(ch,50,stdin);
	ch[strlen(ch)-1]=0;
}

// Take the input from the users and add the name from the email to login //
char generateUsername(char email[50] , char username[50]){
    //user12@gmail.com//
    // filter this email and take name before "@" //
	for(int i = 0 ; i<strlen(email) ; i++){
		if(email[i] == '@') break;
		else username[i] = email[i];
	}
}

// take the inputpassword from users and hashing it **** //
void takePassword(char pwd[50]){
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch ;
			printf("* \b");
		}

	}
}


int main() {
    system("color 0D");

	FILE *fp;
	int opts , usrfound=0;
	struct users user;

	char username[50] , pword[50];
	struct users usr;


    printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
    printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
    printf("\n\t\t\t\t\t||   Welcome to Authentication System   ||\n");
    printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
    printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
    printf("\n Choice Your Operation Sir\n");
    printf("\n *1-Signup\n");
    printf("\n *2-Login\n");
    printf("\n *3-Exit\n");
    printf("\n Your Choice Sir : ");;
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
		    takeinput(user.fullname);

            printf("*#* Enter Your Email Sir :  ");
		    takeinput(user.email);

            printf("*#* Enter Your Sex Sir :  ");
		    takeinput(user.sex);

            printf("*#* Enter Your Contact Phone Sir :  ");
		    takeinput(user.phone);

            printf("*#* Enter Your password Sir :");
		    takePassword(user.password);

            printf("\n*#* Confirm Your password Sir :");
		    takePassword(user.confirmpass);

		    if(!strcmp(user.password , user.confirmpass)){
		    	printf("\nYour password matched");
		    	generateUsername(user.email , user.username);
		    	fp = fopen("SystemUsers.dat","a+");
		    	fwrite(&user,sizeof(struct users),1,fp);
		    	if(fwrite != 0){
                    printf("\n\n User Register success, \n your name is %s ",user.username);
				}else{
					printf("\n Errors Something Went Wrong:(");
				}

			}else{
				printf("\nPassword donot matched");
                Beep(523,800);//window h
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
            takeinput(username);

		    printf("Enter Your Password : \t");
		    takePassword(pword);

		    fp = fopen("SystemUsers.dat" , "r");
		    while(fread(&usr ,sizeof(struct users),1,fp)){
		    	if(!strcmp(usr.username , username)){
		    		if(!strcmp(usr.password , pword)){

                        system("cls");
                        printf("\t\t\t\t\t------------------------------------------\t\t\t\t");
                        printf("\t\t\t\t\t\t\t------------------------------------------\t\t\t\t");
                        printf("\n\t\t\t\t\t\t   Welcome Sir %s",usr.fullname  );
                        printf("\n\t\t\t\t\t------------------------------------------\t\t\t\t\n");
                        printf("\t\t\t\t\t------------------------------------------\t\t\t\t\n");

		    			printf("\n\n |FullName : \t%s" , usr.fullname);
		    			printf("\n |Email : \t%s" , usr.email);
		    			printf("\n |UserName : \t%s" , usr.username);
		    			printf("\n |Contact no : \t%s" , usr.phone);

					}
					else{
						printf("\n Invalid Password !");
                        Beep(523,800);
					}
					usrfound = 1 ;
				}
			}

			if(!usrfound){
				printf("\n\n User us not registerd ");
				Beep(523,800);
			}
        fclose(fp);
	    break;


	    case 3:

		   printf("Ciao ,Au revoir  Sir :)");
           Beep(800,300);
			return 0;

	}


	return 0;
}
