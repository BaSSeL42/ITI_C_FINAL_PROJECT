/***
 * @headerfile  : proj_h.h
 * @author  	: Bassel Yasser
 * @details 	: Bank Sataement functions prototypes
 * @date    	: 26/12/2022
*/

#ifndef FINAL_PROJ_H_
#define FINAL_PROJ_H_
/*************************************************************************************************************/
/**  										INCLUDES			 											**/
/*************************************************************************************************************/
#include "std_types.h"

/*************************************************************************************************************/
/**  										USER_DEFINED_TYPES	 											**/
/*************************************************************************************************************/
typedef struct node
{
	Uint8_t name[50];
	Uint8_t addr[50];
	Uint8_t accountStatus[20];
	Uint8_t password[11];
	Sint8_t bankAccountID[11];
	Uint32_t age;
	Uint32_t NationalID;
	Uint32_t GurdianID;
	Uint32_t balance;
	

	struct node* next;
}str_node_t;


typedef struct 
{
	str_node_t* head;
	Uint32_t size;
	
}str_nodeInfo_t;


/*************************************************************************************************************/
/**  										FUNCTION PROTOTYPES	 											**/
/*************************************************************************************************************/

/***
 * @brief	: creation Node for intialization
 * @param 	: str_nodeInfo_t : take database
*/
void create_node(str_nodeInfo_t* );
/*************************************************************************/

/***
 * @brief	: creation data
 * @param 	: str_nodeInfo_t : take database
 * 			: Uint8_t : generated password
 * 			: Uint8_t : generated bank ID
*/
void create_data(str_nodeInfo_t*, Uint8_t*, Uint8_t* );
/*************************************************************************/


/***
 * @brief	: to search if username exist or not
 * @param 	: str_nodeInfo_t : take database
 * 			: Uint8_t : take your username
 * @return  : return username exists return its password , return NULL if not
*/
Uint8_t* Is_userNameFound(str_nodeInfo_t* , Uint8_t* );
/*************************************************************************/


/***
 * @brief	: to search if bank ID exist or not
 * @param 	: str_nodeInfo_t : take database
 * 			: Sint8_t  : take your bank ID 
 * 			: Uint32_t : amount of money that you want to transfer to this bank ID
 * @return  : void
*/
void Is_BankAccountIDFound(str_nodeInfo_t* , Sint8_t* ,Uint32_t);
/*************************************************************************/



/**/
// void delete_data(str_nodeInfo_t* , Uint32_t );


/***
 * @brief	: to dispay all client information
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void display_AccountInfo(str_nodeInfo_t* );
/*************************************************************************/


/***
 * @brief	: to dispay all client IDs
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void display_BankAccountIDS(str_nodeInfo_t* );
/*************************************************************************/


/***
 * @brief	: user write his password
 * @return  : return his written password
*/
Uint8_t* enter_password();
/*************************************************************************/


/***
 * @brief	: generate random password
 * @return  : Sint8_t* : return generated password
*/
Sint8_t* randomPasswordGeneration();
/*************************************************************************/


/***
 * @brief	: generate random AccountID
 * @return  : Sint8_t* : return generated password
*/
Sint8_t* randomAccountIDGeneration();
/*************************************************************************/


/***
 * @brief	: to change account status  to {active or restricted or closed}
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidChangeAccountStatus(str_nodeInfo_t* );
/*************************************************************************/


/***
 * @brief	: new account creation
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void createNewAccount(str_nodeInfo_t* );
/*************************************************************************/


/***
 * @brief	: to open existing account on admin window
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidLogin(str_nodeInfo_t*);
/*************************************************************************/


/***
 * @brief	: to open existing account on client window
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidClientLogin(str_nodeInfo_t*);
/*************************************************************************/


/***
 * @brief	: making head points to specific node
 * @param 	: str_nodeInfo_t : take database
 * 			: Uint8_t*		 : bank ID
 * @return  : str_node_t*	 : return specfic node
*/
str_node_t* CurrentNode(str_nodeInfo_t* , Uint8_t* );
/*************************************************************************/


/***
 * @brief	: making some cash operation
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidGetCash(str_nodeInfo_t* );
/*************************************************************************/


/***
 * @brief	: making deposit to your account
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidDeposit(str_nodeInfo_t* );
/*************************************************************************/


/***
 * @brief	: tranfer money from your account balance to another account ID balance {making transaction operation}
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidMakeTransaction(str_nodeInfo_t*);
/*************************************************************************/


/***
 * @brief	: to change user's password {on client window}
 * @param 	: str_nodeInfo_t : take database
 * @return  : void
*/
void vidChangePasswordNod(str_nodeInfo_t*);
/*************************************************************************/



#endif /*FINAL_PROJ_H_*/