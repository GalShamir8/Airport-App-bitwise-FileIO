#ifndef __COMP__
#define __COMP__

#include "Flight.h"
#include "AirportManager.h"
#include "GeneralList.h"
#include "MyMacros.h"

#define DETAIL_PRINT
#define SIZE_OF_COMPRESS 3

typedef enum { eNone, eHour, eDate,eSorceCode,eDestCode, eNofSortOpt } eSortOption;
static const char* sortOptStr[eNofSortOpt];

typedef unsigned char BYTE;

typedef struct
{
	char*		name;
	int			flightCount;
	Flight**	flightArr;
	eSortOption	sortOpt;
	LIST		flighDateList;
}Company;

int		initCompanyFromFile(Company* pComp, AirportManager* pManaer, const char* fileName);
void	initCompany(Company* pComp, AirportManager* pManaer);
void	initDateList(Company* pComp);
int		isUniqueDate(const Company* pComp, int index);
int		addFlight(Company* pComp,const AirportManager* pManager);

void	printCompany(const Company* pComp);
void	printFlightsCount(const Company* pComp);

int		saveCompanyToFile(const Company* pComp, const char* fileName);
int		loadCompanyFromFile(Company* pComp, const AirportManager* pManager, const char* fileName);

void	sortFlight(Company* pComp);
void	findFlight(const Company* pComp);
eSortOption showSortMenu();

void	freeCompany(Company* pComp);
/*printCompanyVardic
*	combining unknown strings split by '_';
*   breaking point = NULL
*/
void printCompanyVardic(char* str, ...);

int	saveCompanyToFileCompressed(const Company* pComp, const char* fileName);



#endif

