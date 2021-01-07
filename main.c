#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Company.h"
#include "AirportManager.h"
#include "General.h"
#include "main.h"

const char* str[eNofOptions] = { "Add Flight", "Add Airport",
"PrintCompany", "Print all Airports",
	"Print flights between origin-destination",
"Sort Flights", "Search Flight" };


int main(int argc, char* argV[])
{
	if (argc != 3)
		return 0;//Error in main parmeters 
	char* airportManager_flieName = argV[1];
	char* company_fileName = argV[2];

	AirportManager	manager;
	Company			company;

	initManagerAndCompany(&manager, &company, airportManager_flieName, company_fileName);

	int option;
	int stop = 0;
	
	do
	{
		option = menu();
		switch (option)
		{
		case eAddFlight:
			if (!addFlight(&company, &manager))
				printf("Error adding flight\n");
			break;


		case eAddAirport:
			if (!addAirport(&manager))
				printf("Error adding airport\n");
			break;

		case ePrintCompany:
			printCompany(&company);
			break;

		case ePrintAirports:
			printAirports(&manager);
			break;
		
		case ePrintFlightOrigDest:
			printFlightsCount(&company);
			break;
		
		case eSortFlights:
			sortFlight(&company);
			break;

		case eSearchFlight:
			findFlight(&company);
			break;

		case EXIT:
			printf("Bye bye\n");
			stop = 1;
			break;

		default:
			printf("Wrong option\n");
			break;
		}
	} while (!stop);


	saveManagerToFile(&manager, airportManager_flieName);
	saveCompanyToFile(&company, company_fileName);

	freeManager(&manager);
	freeCompany(&company);

	system("pause");
	return 1;
}

int menu()
{
	int option;
	printf("\n\n");
	printf("Please choose one of the following options\n");
	for(int i = 0 ; i < eNofOptions ; i++)
		printf("%d - %s\n",i,str[i]);
	printf("%d - Quit\n", EXIT);
	scanf("%d", &option);
	
	//clean buffer
	char tav;
	scanf("%c", &tav);
	return option;
}

int initManagerAndCompany(AirportManager* pManager ,Company* pCompany, char* airportManager_flieName, char* company_fileName)
{
	int res = initManager(pManager, airportManager_flieName);
	if (!res)
	{
		printf("error init manager\n");
		return 0;
	}

	if (res == FROM_FILE)
		return initCompanyFromFile(pCompany,pManager, company_fileName);
	else
		initCompany(pCompany, pManager);
	return 1;
}