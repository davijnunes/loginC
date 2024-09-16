#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIGNUP 1
#define SHOW_USER 2
#define EXIT 3

#define SIZE 40

// Structs to use of user
typedef struct{
    char street[SIZE];
    char city[SIZE];
    char cep[SIZE];
    char state[SIZE];

}Address;

typedef struct{

    char firstName[SIZE];
    char lastName[SIZE];
    char email[SIZE];
    char phone[SIZE];
    Address address;

}User;

User user1;

// Prototype
void signup();
void showUser();
void toChoose(int to);
void clearBuffer();
void removeNewLine(char *str);
void capitalize(char *str);

int main(){

    printf("\n");

    int to = 0;
    
    do{
        printf("\n\t1-to signup\n\t2-to show user\n\t3-to exit\n\tchoose: ");
        scanf("%d",&to);
        toChoose(to);

    }while(to != EXIT);

    printf("\n");

    return 0;
}

void signup(){

    printf("\n");

    clearBuffer();

    do{
        printf("Enter a first name: ");
        fgets(user1.firstName,sizeof(user1.firstName),stdin);
        removeNewLine(user1.firstName);

        printf("Enter a last name: ");
        fgets(user1.lastName,sizeof(user1.lastName),stdin);
        removeNewLine(user1.lastName);

    }while(strlen(user1.firstName) == 0 || strlen(user1.lastName) == 0);
 

    printf("Enter a email: ");
    fgets(user1.email,sizeof(user1.email),stdin);

    printf("Enter a phone: ");
    fgets(user1.phone,sizeof(user1.phone),stdin);


    do{
        printf("Enter a street: ");
        fgets(user1.address.street,sizeof(user1.address.street),stdin);
        removeNewLine(user1.address.street);

    }while(strlen(user1.address.street) == 0);
    
    do{
        printf("Enter a city: ");
        fgets(user1.address.city,sizeof(user1.address.city),stdin);
        removeNewLine(user1.address.city);
    }while(strlen(user1.address.city) == 0);

    do{
        printf("Enter a state: ");
        fgets(user1.address.state,sizeof(user1.address.state),stdin);
        removeNewLine(user1.address.state);
    }while(strlen(user1.address.state) == 0);
    

    do{
         printf("Enter a cep: ");
         fgets(user1.address.cep,sizeof(user1.address.cep),stdin);
         removeNewLine(user1.address.cep);
    }while(strlen(user1.address.cep) == 0);
   
    system("cls");
    printf("\n");

}

void showUser(){

    printf("\n");


    printf("FIELDS:\n");

    if(user1.firstName[0] >= 'a' && user1.firstName[0] <= 'z')capitalize(user1.firstName);
    printf("\n---------------------------------------\n");
    printf("First name: %s\n",user1.firstName);
    printf("\n---------------------------------------\n");

    if(user1.lastName[0] >= 'a' && user1.lastName[0] <= 'z')capitalize(user1.lastName);
    printf("Last name: %s\n",user1.lastName);
    printf("\n---------------------------------------\n");

    printf("Email: %s\n",user1.email);
    printf("\n---------------------------------------\n");

    printf("Phone: %s\n",user1.phone);
    printf("\n---------------------------------------\n");

    printf("Street: %s\n",user1.address.street);
    printf("\n---------------------------------------\n");

    printf("City: %s\n",user1.address.city);
    printf("\n---------------------------------------\n");

    printf("State: %s\n",user1.address.state);
    printf("\n---------------------------------------\n");

    printf("Cep: %s\n",user1.address.cep);
    printf("\n---------------------------------------\n");

    printf("\n");

}
void toChoose(int to){

    switch(to){
        case SIGNUP:
            signup();
            break;
        case SHOW_USER:
            showUser();
            break;
    }



}
void capitalize(char *str){

    *str = *str - 32;


}
void clearBuffer(){

    int c;

    while((c = getchar()) != '\n' && EOF);
}

void removeNewLine(char *str){

    size_t len = strlen(str);

    if(len > 0 && str[len - 1] == '\n'){
        
        str[len - 1] = '\0';
    }
}
