/***
 * @file    : proj.c
 * @author  : Bassel Yasser
 * @details : Main function
 * @date    : 26/12/2022
*/

/*************************************************************************************************************/
/**  											INCLUDES 													**/
/*************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "std_types.h"
#include "proj_h.h"

/*************************************************************************************************************/
/**  											MAIN FUNCTION												**/
/*************************************************************************************************************/
int main(void)
{
	Uint8_t myChoice[12];
	Uint8_t myChoice1[12];
	Uint8_t AdminPass;
	Uint8_t AdFlag=0 , counter = 0;
	str_nodeInfo_t dataBase1;

	create_node(&dataBase1);

	while(1)
	{
		system("cls");
		printf("\t\t---------------------- welcome to ITI bank ----------------------\n\n");
		printf("<admin>  to open Admin window\n");
		printf("<client> to open client window\n");
		printf("<exit> 	 to terminate system\n");
		printf(">> ");
		scanf("%s", myChoice);
		
		if (!strcmp(myChoice, "admin"))
		{
			printf("Please enter Admin Password: \n");
			printf("Password: ");
			scanf("%i", &AdminPass);
			if (AdminPass == 123)
			{
				AdFlag = 1;
			}
			while (AdminPass != 123 &&  counter < 3)
			{
				printf("Invalid Password..... please try again!!\n");
				printf("Password: ");
				scanf("%i", &AdminPass);
				if (AdminPass == 123)
				{
					AdFlag = 1;
				}
				counter++;
			}
			if (AdFlag == 1)
			{
				AdFlag == 0;
				while (1)
				{
					system("cls");
					printf("\t\t---------------------- welcome to ITI bank ----------------------\n\n");
					printf("\n");
					printf(">> <new> 	to create new account						\n");
					printf(">> <login> 	if u have already an existing account 		\n");
					printf(">> <disp> 	to display information of all bank members 	\n");
					printf(">> <exit>  	admin menu will be terminated				\n");
					printf(">> ");
					scanf("%s", myChoice1);
					if(!strcmp(myChoice1, "new"))
					{
						system("cls");
						createNewAccount(&dataBase1);
					}
					else if(!strcmp(myChoice1, "login"))
					{
						vidLogin(&dataBase1);
					}
					else if(!strcmp(myChoice1, "disp"))
					{
						display_AccountInfo(&dataBase1);
					}
					else if(!strcmp(myChoice1, "exit"))
					{
						break;
					}
					else 
					{
						/* do nothing */
					}
					//system("timeout /t 30");
					sleep(10);
					
				}
			}
			else if (AdFlag == 0)
			{
				printf("Account is blocked \n");
			}
			else 
			{
				/*do nothing*/
			}
		}
		else if(!strcmp(myChoice, "client"))
		{
			system("cls");
			while (1)
			{
				system("cls");
				printf("\n");
				printf(">> <login> 	to login to your account			 		\n");
				printf(">> <exit>  	client menu will be terminated				\n");
				printf(">> ");
				scanf("%s", myChoice1);
				if(!strcmp(myChoice1, "login"))
				{
					vidClientLogin(&dataBase1);
				}
				else if(!strcmp(myChoice1, "exit"))
				{
					break;
				}
				else 
				{
					/* do nothing */
				}
			}
		}
		else 
		{
			break;
		}
	}
	return 0;
}



