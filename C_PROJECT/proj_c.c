/***
 * @file    : proj_c.c
 * @author  : Bassel Yasser
 * @details : Bank Sataement functions implementation
 * @date    : 26/12/2022
*/




#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "proj_h.h"

#define passwordGenerate						5
#define N										passwordGenerate
#define MAX_NO_Bank_AccountID_Generator			8

/***
 * @brief	: creation Node for intialization
 * @param 	: str_nodeInfo_t : take database
*/
void create_node(str_nodeInfo_t* strPtr)
{
    str_nodeInfo_t* pn = strPtr;
    pn -> head = NULL;
    pn -> size = 0;
}
/*************************************************************************************************************/
/*************************************************************************************************************/


/***
 * @brief	: creation data
 * @param 	: str_nodeInfo_t : take database
 * 			: Uint8_t : generated password
 * 			: Uint8_t : generated bank ID
*/
void create_data(str_nodeInfo_t* strPtr1, Uint8_t* pass, Uint8_t* u8BankAccountID)
{
	Uint8_t local_u8NationalID[15];
    str_node_t* pn = (str_node_t*) malloc(sizeof(str_node_t));

    strcpy(pn->accountStatus, "active");
    strcpy(pn->password, pass);
    strcpy(pn->bankAccountID, u8BankAccountID);

	printf("Enter your name             >> ");
    fflush(stdin);
    scanf("%[^\n]s", &pn->name); 
    fflush(stdin);
    fflush(stdout);
    printf("Enter your address          >> ");
    scanf("%[^\n]s", &pn->addr);
    fflush(stdin);
    fflush(stdout);
    printf("Enter your age              >> ");
    scanf("%u", &pn->age);

    if(pn->age < 21)
    {
		
        printf("Enter Gurdian National ID   >> ");
		scanf ("%s", local_u8NationalID);
		while (strlen(local_u8NationalID) != 14)
		{
			printf("Enter Gurdian National ID cosist of 14 digits  >> ");
			scanf ("%s", local_u8NationalID);	
		}
		strcpy(pn->GurdianID, local_u8NationalID);
        
        // scanf("%u", &pn->GurdianID);
    }
    else if(pn->age >= 21)
    {
        printf("Enter National ID           >> ");
		scanf ("%s", local_u8NationalID);
		while (strlen(local_u8NationalID) != 14)
		{
			printf("Enter your National ID cosist of 14 digits  >> ");
			scanf ("%s", local_u8NationalID);	
		}
		strcpy(pn->NationalID, local_u8NationalID);
    }
    else 
    {
        /* do nothing */
    }
     printf("Enter your Account balance  >> ");
    scanf("%u", &pn->balance);

    pn->next = strPtr1->head;
    strPtr1->head  = pn;

    strPtr1->size+=1;
}
/*************************************************************************************************************/
/*************************************************************************************************************/


/***
 * @brief	: to search if username exist or not
 * @param 	: str_nodeInfo_t : take database
 * 			: Uint8_t : take your username
 * @return  : return username exists return its password , return NULL if not
*/
Uint8_t* Is_userNameFound(str_nodeInfo_t* nd, Uint8_t* name)
{
    Uint8_t* password = "";
    str_node_t* count = nd->head;
    while(count)
    {
        if(!strcmp(count->name, name))
        {
            password = count->password;
            break;
        }
        else if(strcmp(count->name, name) != 0)
        {
            password = NULL;
            count = count->next;
        }
        else
        {
            /* do nothing */
        } 
    }

    return password;
}
/*************************************************************************************************************/
/*************************************************************************************************************/


/***
 * @brief	: to search if bank ID exist or not
 * @param 	: str_nodeInfo_t : take database
 * 			: Sint8_t  : take your bank ID 
 * 			: Uint32_t : amount of money that you want to transfer to this bank ID
 * @return  : void
*/
void Is_BankAccountIDFound(str_nodeInfo_t* str_nd, Sint8_t* s8_BankAccountIDCopy, Uint32_t u32_MoneyAmountCopy)
{
    // Uint8_t* local_pu8AccountStatus = "";
    str_node_t* local_strCount = str_nd->head;
    Uint16_t flag = 0;
    Uint8_t local_pu8MyBankID[15];
    str_node_t* local_strCurrntNode;

    printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);

    local_strCurrntNode = CurrentNode(str_nd, local_pu8MyBankID);
    
    while(local_strCount)
    {
        if( ( !strcmp(local_strCount->bankAccountID, s8_BankAccountIDCopy) ) && ( local_strCurrntNode->balance > u32_MoneyAmountCopy ) )
        {
            flag = 1;
            // strcpy(local_pu8AccountStatus , local_strCount->accountStatus);
            if (!strcmp(local_strCount->accountStatus, "active"))
            {
                local_strCount->balance += u32_MoneyAmountCopy;
                local_strCurrntNode->balance -= u32_MoneyAmountCopy;
            }
            else if(!strcmp(local_strCount->accountStatus, "restricted"))
            {
                printf("this account is restricted you can't transfer money\n");
            }
            else if (!strcmp(local_strCount->accountStatus, "closed"))
            {
                printf("this account is closed you can't transfer money\n");
            }
            else 
            {
                /* do nothing */
            }
            break;
        }
        else
            local_strCount = local_strCount->next;
    }
    if (flag == 0)
    {
        printf("Account ID doesn't exist");
    }

    // return local_pu8AccountStatus;

}
/*************************************************************************************************************/
/*************************************************************************************************************/



// void delete_data(str_nodeInfo_t* nd, Uint32_t num)
// {
    // str_node_t* current = nd->head;
    // str_node_t* prev = nd->head;
    // str_node_t* temp;
    // Uint8_t flag = 0;
    // while(current)
    // {
        // if(current->data == num && !flag)
        // {
            // temp = current;
           // current = current->next;
           // nd->head = current;
            // free(temp);
            // flag = 1;
            // nd->size-=1;
            // break;
        // }
        // else if(current->data == num && flag)
        // {
            // printf("200\n");
            // temp = current ;
            // prev->next = current->next;
            // free(temp);
            // nd->size-=1;
            // break;
        // }
        // else 
        // {
            // prev = current;
            // current = current->next;
            // flag = 1;
        // }
    // }
// }



/***
 * @brief	: to dispay all client information
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void display_AccountInfo(str_nodeInfo_t* str_nodeCopy)
{
    str_node_t* local_strCount = str_nodeCopy->head;
    Uint8_t local_u8Count = 0;
    while(local_strCount != NULL)
    {
        local_u8Count += 1;
        printf("----------------------------------- client %d information -----------------------------\n ", local_u8Count);
        printf("Name                : %s \n ",  local_strCount->name );
        printf("Address             : %s \n ",  local_strCount->addr);
        printf("Bank Account Status : %s \n ", local_strCount->accountStatus);
        printf("Bank Account ID     : %s \n ",  local_strCount->bankAccountID);
		printf("Bank Password 		: %s \n", local_strCount->password);
        printf("Age                 : %u \n ", local_strCount->age);
        if(local_strCount->age < 21)
        {
            printf("Gurdian national ID : %u \n ", local_strCount->GurdianID);
        }
        else if(local_strCount->age >= 21)
        {
            printf("National ID         : %u \n ", local_strCount->NationalID);
        }
        else {/* do noyhing */}

        printf("Account balance     : %u \n ", local_strCount->balance);

        printf("---------------------------------------------------------------------------------------\n\n ");
        
        local_strCount = local_strCount->next;
    } 
}
/*************************************************************************************************************/
/*************************************************************************************************************/



/***
 * @brief	: to dispay all client IDs
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void display_BankAccountIDS(str_nodeInfo_t* str_nodeCopy)
{
  	str_node_t* local_strCount = str_nodeCopy->head;
    Uint8_t local_u8Count = 0;

    while(local_strCount)
    {
        local_u8Count += 1;
        printf("----------------------------------- client %d ID and his balance -----------------------------\n", local_u8Count);
        printf("%s Banck Account ID is %s \n", local_strCount->name ,local_strCount->bankAccountID);
        printf("%s 's balance on his account is %u \n",local_strCount->name , local_strCount->balance);
        printf("---------------------------------------------------------------------------------------\n\n");
        local_strCount = local_strCount->next;
    }  
}
/*************************************************************************************************************/
/*************************************************************************************************************/



/***
 * @brief	: user write his password
 * @return  : return his written password
*/
Uint8_t* enter_password()
{
	Uint8_t i = 0;
	Uint8_t ch;
	static Uint8_t pwd[10];
	
	// printf("enter your password: ");
	
	while ( (ch = _getch()) != 13 )
	{
		pwd[i] = ch;
		i++;
		printf("*");
	}
	pwd[i] = '\0';
	
	return pwd;
}
/*************************************************************************************************************/
/*************************************************************************************************************/



/***
 * @brief	: generate random password
 * @return  : Sint8_t* : return generated password
*/
Sint8_t* randomPasswordGeneration()
{
    // Initialize counter
    Uint32_t i = 0;
  
    Sint32_t randomizer = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((Sint32_t)(time(NULL)));
  
    // Array of numbers
    Sint8_t numbers[] = "0123456789";
  
    // Array of small alphabets
    Sint8_t letter[] = "abcdefghijklmnoqprstuvwyzx";
  
    // Array of capital alphabets
    Sint8_t LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
    // Array of all the special symbols
    // Sint8_t symbols[] = "!@#$^&*?";
  
    // Stores the random password
    static Sint8_t password[N];
  
    // To select the randomizer
    // inside the loop
    randomizer = rand() % 3;
  
    // Iterate over the range [0, N]
    for (i = 0; i < N; i++) {
  
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
        }
        // else if (randomizer == 2) {
        //     password[i] = symbols[rand() % 8];
        //     randomizer = rand() % 4;
        // }
        else if (randomizer == 2) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 4;
        }
    }

	return password;
}
/*************************************************************************************************************/
/*************************************************************************************************************/



/***
 * @brief	: generate random AccountID
 * @return  : Sint8_t* : return generated password
*/
Sint8_t* randomAccountIDGeneration()
{
	    // Initialize counter
    Sint32_t i = 0;
  
    // Seed the random-number generator
    // with current time so that the
    // numbers will be different every time
    srand((Sint8_t)(time(NULL)));
  
    // Array of numbers
    Sint8_t numbers[] = "0123456789";

    // Stores the random AccountID
    static Sint8_t AccountID[MAX_NO_Bank_AccountID_Generator];
  
    // To select the randomizer
    // inside the loop
    // randomizer = rand() % 3;
  
    // Iterate over the range [0, N]
    for (i = 0; i < MAX_NO_Bank_AccountID_Generator; i++) 
	{
		AccountID[i] = numbers[rand() % 10];
    }

	return AccountID;
}
/*************************************************************************************************************/
/*************************************************************************************************************/



/***
 * @brief	: making head points to specific node
 * @param 	: str_nodeInfo_t : take database
 * 			: Uint8_t*		 : bank ID
 * @return  : str_node_t*	 : return specfic node
*/
str_node_t* CurrentNode(str_nodeInfo_t* strNode, Uint8_t* u8BankIDCopy)
{
	str_node_t* local_strCurrntNode = strNode->head;
	Uint8_t local_u8Flag = 0;

	while(local_strCurrntNode)
	{

		if(!strcmp(local_strCurrntNode->bankAccountID,u8BankIDCopy))
		{
			local_u8Flag = 1;
			return local_strCurrntNode;
		}
		else 
		{
			local_strCurrntNode = local_strCurrntNode->next;
		}
	}
	if (local_u8Flag == 0) { return NULL; }
}
/*************************************************************************************************************/
/*************************************************************************************************************/




/***
 * @brief	: to change account status  to {active or restricted or closed}
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidChangeAccountStatus(str_nodeInfo_t* strNode)
{
	Uint8_t local_pu8AccountStatus[15];
	Uint8_t local_pu8MyBankID[15];
	str_node_t* local_strCurrntNode;

	printf("choose the following status 				\n");
	printf("<active> 		Active your account  		\n");
	printf("<restricted>		Restrict your account   	\n");
	printf("<closed> 		Close your account 			\n");
	printf("Account status >> ");
	
	

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);
	printf("Change the status to >> ");
    scanf("%s", local_pu8AccountStatus);

	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);
	strcpy(local_strCurrntNode->accountStatus, local_pu8AccountStatus);
}
/*************************************************************************************************************/
/*************************************************************************************************************/



/***
 * @brief	: new account creation
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void createNewAccount(str_nodeInfo_t* strNode)
{
	Uint8_t* myPass;
	Uint8_t* bankAccount_ID;
	myPass = randomPasswordGeneration(); 
	bankAccount_ID = randomAccountIDGeneration();
	create_data(strNode, myPass, bankAccount_ID);
	printf("you sucessfully created new account :) and \n");
	printf("your password is: %s \n", myPass);
	printf("your Bank Account ID is: %s \n", bankAccount_ID);
}
/*************************************************************************************************************/
/*************************************************************************************************************/




/***
 * @brief	: to open existing account on admin window
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidLogin(str_nodeInfo_t* strNode)
{
	Uint8_t userName[15];
	Uint8_t* passWord ;
	Uint8_t* myPass;
	Uint8_t Choice[12];
	Uint8_t count = 0, flag = 0;

	printf("Username >> ");
    fflush(stdin);
	scanf("%[^\n]s", userName);
	myPass = Is_userNameFound(strNode,userName);
	while (myPass == NULL)
	{
		printf("Invalid username \n");
		printf("Username >> ");
        fflush(stdin);
		scanf("%[^\n]s", userName);
		myPass = Is_userNameFound(strNode,userName);
	}
	printf("Password >> ");
	passWord = enter_password();
	while (count <= 3 && !flag)
	{
		count++;
		if(!strcmp(myPass, passWord))
		{
			system("cls");
			printf("\n\n------------------------------------------------------\n");
			printf("you are loggned in :) \n");
			printf("------------------------------------------------------\n\n");
			system("timeout /t 5");
			while (1)
			{
				system("cls");
                printf("\t\t---------------------- welcome to ITI bank ----------------------\n\n");
				printf(">> <transaction> 	to make transaction 		\n");
				printf(">> <change_status> 	to change account status 	\n");
				printf(">> <cash> 	\tto get cash 				\n");
				printf(">> <deposit> 		to deposite in account 		\n");
				printf(">> <return> 		return to main menu 		\n");
				printf(">> ");
				scanf("%s", Choice);

				if (!strcmp(Choice, "transaction"))
				{
					vidMakeTransaction(strNode);
				}
				else if(!strcmp(Choice, "change_status"))
				{
					vidChangeAccountStatus(strNode);
				}
				else if(!strcmp(Choice, "cash"))
				{
					vidGetCash(strNode);
				}
				else if(!strcmp(Choice, "deposit"))
				{
					vidDeposit(strNode);
				}
				else if(!strcmp(Choice, "return"))
				{
					break;
				}
				else {/* do nothing */}
				system("timeout /t 20");
			}

			flag = 1;
		}
		else if(strcmp(myPass, passWord) != 0 && count<3)
		{
			printf("\n----------Wrong password ..try again----------\n");
			printf("Password >> ");
			passWord = enter_password();
		}
	}

	if(count == 4){ printf("\n"); printf("\n #### your account is terminated #### \n"); }
}
/*************************************************************************************************************/
/*************************************************************************************************************/




/***
 * @brief	: to open existing account on client window
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidClientLogin(str_nodeInfo_t* strNode)
{
	Uint8_t userName[15];
	Uint8_t* passWord ;
	Uint8_t* myPass;
	Uint8_t Choice[12];
	Uint8_t count = 0, flag = 0;

	printf("Username >> ");
    fflush(stdin);
	scanf("%[^\n]s", userName);
	myPass = Is_userNameFound(strNode,userName);
	while (myPass == NULL)
	{
		printf("Invalid username \n");
        fflush(stdin);
		printf("Username >> ");
		scanf("%[^\n]s", userName);
		myPass = Is_userNameFound(strNode,userName);
	}
	printf("Password >> ");
	passWord = enter_password();
	while (count <= 3 && !flag)
	{
		count++;
		if(!strcmp(myPass, passWord))
		{
			system("cls");
			printf("\n\n------------------------------------------------------\n");
			printf("you are loggned in :) \n");
			printf("------------------------------------------------------\n\n");
			system("timeout /t 5");
			while (1)
			{
				system("cls");
                printf("\t\t---------------------- welcome to ITI bank ----------------------\n\n");
				printf(">> <transaction> 		to make transaction 		\n");
				printf(">> <changePassword>	 	to change password 			\n");
				printf(">> <cash> 	\tto get cash 				\n");
				printf(">> <deposit> 		to deposite in account 		\n");
				printf(">> <return> 		return to main menu 		\n");
				printf(">> ");
				scanf("%s", Choice);

				if (!strcmp(Choice, "transaction"))
				{
					vidMakeTransaction(strNode);
				}
				else if(!strcmp(Choice, "changePassword"))
				{
					vidChangePasswordNod(strNode);
				}
				else if(!strcmp(Choice, "cash"))
				{
					vidGetCash(strNode);
				}
				else if(!strcmp(Choice, "deposit"))
				{
					vidDeposit(strNode);
				}
				else if(!strcmp(Choice, "return"))
				{
					break;
				}
				else {/* do nothing */}
				system("timeout /t 20");
			}

			flag = 1;
		}
		else if(strcmp(myPass, passWord) != 0 && count<3)
		{
			printf("\n----------Wrong password ..try again----------\n");
			printf("Password >> ");
			passWord = enter_password();
		}
	}

	if(count == 4){ printf("\n"); printf("\n #### your account is terminated #### \n"); }
}
/*************************************************************************************************************/
/*************************************************************************************************************/



/***
 * @brief	: making some cash operation
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidGetCash(str_nodeInfo_t* strNode)
{
	Uint32_t local_u16CashNo;
	Uint8_t local_u8Flag = 0;
	Uint8_t local_pu8MyBankID[15];
	str_node_t* local_strCurrntNode;

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);
	printf("What amount of money to be withdrawn >> ");
	scanf("%u", &local_u16CashNo);
	
	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);

	if(local_strCurrntNode == NULL)
	{
		printf("Invalid bank ID");
	}
	else 
	{
		if(local_strCurrntNode->balance >= local_u16CashNo)
		{
			local_strCurrntNode->balance -=  local_u16CashNo;
			printf("\nYou withdrawed : %u , and your Account balance : %u \n", local_u16CashNo, local_strCurrntNode->balance);
		}
		else if(local_strCurrntNode->balance < local_u16CashNo)
		{
			printf("you don't have enough money\n");
		}
		else 
		{
			/* do nothing */
		}
	}
}
/*************************************************************************************************************/
/*************************************************************************************************************/



/***
 * @brief	: making deposit to your account
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidDeposit(str_nodeInfo_t* strNode)
{
	Uint32_t local_u16DepNo;
	Uint8_t local_pu8MyBankID[15];
	Uint8_t local_u8Flag = 0;
	str_node_t* local_strCurrntNode;

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);
	printf("What amount of money to be deposited >> ");
	scanf("%u", &local_u16DepNo);
	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);

	if(local_strCurrntNode == NULL)
	{
		printf("Invalid bank ID");
	}
	else 
	{
		if(!strcmp(local_strCurrntNode->accountStatus, "active"))
		{
			local_strCurrntNode->balance += local_u16DepNo;
			printf("\nYou deposited : %u , and your Account balance : %u \n", local_u16DepNo, local_strCurrntNode->balance);
		}
		else if(!strcmp(local_strCurrntNode->accountStatus, "restricted"))
		{
			printf("this account is restricted");
		}
		else if(!strcmp(local_strCurrntNode->accountStatus, "closed"))
		{
			printf("this account is closed");
		}
		else 
		{
			/*  */
		}
	}
}
/*************************************************************************************************************/
/*************************************************************************************************************/




/***
 * @brief	: tranfer money from your account balance to another account ID balance {making transaction operation}
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/

void vidMakeTransaction(str_nodeInfo_t* strNode)
{
	Sint8_t local_pu8BankAccountID[MAX_NO_Bank_AccountID_Generator];
	// Uint8_t* local_pu8AccountStatus;
	Uint32_t local_u8MoneyAmount;

	printf("\t\tHello there :)\n\n");
	printf("There are all IDS on our system \n");
	printf("------------------------------------------\n");
	display_BankAccountIDS(strNode);
	printf("------------------------------------------\n");
	printf("please enter Bank Account ID that you want to transfer money to >> ");
	scanf("%s", local_pu8BankAccountID);
	printf("please enter amount of money >> ");
	scanf("%u", &local_u8MoneyAmount);
	Is_BankAccountIDFound(strNode, local_pu8BankAccountID, local_u8MoneyAmount);

	// printf("There are all IDS on our system \n");
	// printf("------------------------------------------\n");
	// display_BankAccountIDS(strNode);
	// printf("------------------------------------------\n");
}
/*************************************************************************************************************/
/*************************************************************************************************************/




/***
 * @brief	: to change user's password {on client window}
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidChangePasswordNod(str_nodeInfo_t* strNode)
{
	Uint8_t local_pu8MyBankID[15];
	Uint8_t local_u8MyNewPassword[15];
	str_node_t* local_strCurrntNode;

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);

	printf("What is your new password >> ");
	scanf("%s", local_u8MyNewPassword);
	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);

	strcpy(local_strCurrntNode->password, local_u8MyNewPassword);
}
/*************************************************************************************************************/
/*************************************************************************************************************/
