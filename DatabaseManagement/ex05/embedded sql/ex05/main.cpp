#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>
#include <string>
using namespace std;

//#define SQLSERVER
// string stConnect = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\\Users\\Aaron\\Desktop\\school\\DatabaseManagement\\Northwind.accdb;";


const int MAX_DATA=100;
void runQuery(int qNum);
string GetQuery(int qNum);

int main() {
	int myQuery = 0;
	cout << "What query would you like to execute (1-10): ";
	cin >> myQuery;
	cout << endl;
	
	while (myQuery != -1) {
		if (myQuery >= 1 && myQuery <= 10) {
			runQuery(myQuery);
			myQuery = -1;
		}
		else {
			cout << "Enter a number from 1-10 to select a query to run, or enter -1 to exit: ";
			cin >> myQuery;
		}
	}
	
	return 0;
}

void runQuery(int qNum) {
	RETCODE rc;
	HENV henv;
	HDBC hdbc;
	HSTMT hstmt;
	char szData[MAX_DATA];
	string stSQL;
	SQLLEN cbData;
	char szPrice[10];
	
	_gcvt_s(szPrice, 10, 6);

	SQLAllocEnv(&henv); //allocate an odbc environment
	SQLAllocConnect(henv, &hdbc); //allocate an odbc connection

	SQLCHAR szConnectOut[1024];
	SQLSMALLINT cchConnect;
#ifdef SQLSERVER
	//Check out http://www.devlist.com/ConnectionStringsPage.aspx for example connection strings
	string stConnect = "Driver={SQL Server};Server=CS1;";
	stConnect += "Database=Northwind;Trusted_Connection=yes;";
#else //SQLSERVER
	//connect to a real database (access northwind)
	string stConnect = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=C:\\Users\\Aaron\\Desktop\\school\\DatabaseManagement\\Northwind.accdb;";
#endif
	stSQL = GetQuery(qNum);

	//open a cursor on the SQL
	rc = SQLDriverConnect(hdbc, NULL, (SQLCHAR *) stConnect.c_str(), stConnect.length(), szConnectOut, 1024, &cchConnect, SQL_DRIVER_NOPROMPT);
	if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
	{
		SQLTCHAR state[255], error[255];
		SQLINTEGER code;
		SQLSMALLINT cb;
		SQLError(henv, hdbc, NULL, state, &code, error, 255, &cb);
		cout << error << endl;
		exit(0);
	}
	SQLAllocStmt(hdbc, &hstmt); //prepare a statement object to execute query
	cout << stSQL << endl;
	rc = SQLExecDirect(hstmt, (SQLCHAR*) stSQL.c_str(), SQL_NTS);
	if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO))
	{
		SQLTCHAR state[255], error[255];
		SQLINTEGER code;
		SQLSMALLINT cb;
		SQLError(henv, hdbc, hstmt, state, &code, error, 255, &cb);
		cout << error << endl;
		exit(0);
	}

	if (qNum == 1) { //works
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);//get the next tuple
			//SQLGetData - get Data from the specified column (in this case column 1) of the specified type (SQL_C_CHAR)
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Product: " << szData << " ";
			}
			//SQLGetData - get Data from the specified column (in this case column 2) of the specified type (SQL_C_CHAR)
			if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "10% increase: " << szData;
			}
			cout << endl;
		}
	}
	else if (qNum == 2) { //works!
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "MAX: " << szData << " ";
			}
			//SQLGetData - get Data from the specified column (in this case column 2) of the specified type (SQL_C_CHAR)
			if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Min: " << szData << " ";
			}
			//SQLGetData - get Data from the specified column (in this case column 3) of the specified type (SQL_C_CHAR)
			if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Average: " << szData << " ";
			}
			cout << endl;
		}
	}
	else if (qNum == 3) { //works!
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Discontinued Items: " << szData << " ";
			}
			cout << endl;
		}
	}
	else if (qNum == 4) { //works (didnt work before because sql uses % and access uses *, I was using access syntax)
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Items containing dried: " << szData << " ";
			}
			cout << endl;
		}
	}
	else if (qNum == 5) { //works!
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Available Beverages: " << szData << " ";
			}
			cout << endl;
		}
	}
	else if (qNum == 6) { //works!
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Shippers whose shipped orders had fees of > 100: " << szData << " ";
			}
			cout << endl;
		}
	}
	else if (qNum == 7) { //works!
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Employee name: " << szData << " ";
			}
			if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << szData << " -- ";
			}
			if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Job title: " << szData << " ";
			}
			cout << endl;
		}
	}
	else if (qNum == 8) { //works!
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Ship date: " << szData << " -- ";
			}
			if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Assigned employee: " << szData << " ";
			}
			if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << szData << " ";
			}
			cout << endl;
		}
	}
	else if (qNum == 9) { //works!
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Maximum price: " << szData << " ";
			}
			if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Minimum price: " << szData << " ";
			}
			if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Average price: " << szData << " ";
			}
			cout << endl;
		}
	}
	else if (qNum == 10) { //works!
		while (rc == SQL_SUCCESS) {
			rc = SQLFetch(hstmt);
			if (SQLGetData(hstmt, 1, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Category: " << szData << " ";
			}
			if (SQLGetData(hstmt, 2, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Max price: " << szData << " ";
			}
			if (SQLGetData(hstmt, 3, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Min price: " << szData << " ";
			}
			if (SQLGetData(hstmt, 4, SQL_C_CHAR, szData, sizeof(szData), &cbData) == SQL_SUCCESS) {
				cout << "Average price: " << szData << " ";
			}
			cout << endl;
		}
	}

	//clean up after ourselves
	SQLFreeStmt(hstmt, SQL_DROP);
	SQLDisconnect(hdbc);
	SQLFreeConnect(hdbc);
	SQLFreeEnv(henv);
}
//=================
//GETQUERY FUNCTION
//=================
string GetQuery(int qNum) {
#ifdef SQLSERVER
	string stSQL = "SELECT C.CompanyName, E.LastName ";
	stSQL += "FROM Customers C, Employees E, Orders O ";
	stSQL += "WHERE E.EmployeeID = O.EmployeeID AND C.CustomerID = O.CustomerID AND O.Freight < 20.5 ";
	stSQL += "ORDER BY O.Freight";
#else
	string stSQL = "";
	if (qNum == 1) {
		stSQL += "SELECT P.[ProductName], 1.10*(P.[List Price]) AS [List Price + 10%] ";
		stSQL += "FROM Products P";
	}
	else if (qNum == 2) {
		stSQL += "SELECT MAX(P.[Target Level]) AS [Max Target Level], MIN(P.[Target Level]) AS [Minimum Target Level], AVG(P.[Target Level]) AS [Average Target Level] ";
		stSQL += "FROM Products P";
	}
	else if (qNum == 3) {
		stSQL += "SELECT COUNT(*) AS [Discontinued Products] ";
		stSQL += "FROM Products P ";
		stSQL += "WHERE P.[Discontinued] = true";
	}
	else if (qNum == 4) {
		stSQL += "SELECT P.[ProductName] ";
		stSQL += "FROM Products P ";
		stSQL += "WHERE P.[ProductName] LIKE \'%dried%\'";
	}
	else if (qNum == 5) {
		stSQL += "SELECT P.[ProductName] ";
		stSQL += "FROM Products P " ;
		stSQL += "WHERE P.Category = \'Beverages\' AND P.Discontinued = false";
	}
	else if (qNum == 6) {
		stSQL += "SELECT S.Company ";
		stSQL += "FROM Orders O, Shippers S ";
		stSQL += "WHERE O.ShipperID = S.ID AND O.[Shipping Fee] > 100";
	}
	else if (qNum == 7) {
		stSQL += "SELECT E.[First Name], E.[Last Name], E.[Job Title] ";
		stSQL += "FROM Employees E ";
	}
	else if (qNum == 8) {
		stSQL += "SELECT O.[Shipped Date], E.[First Name], E.[Last Name] ";
		stSQL += "FROM Orders O, Employees E ";
		stSQL += "WHERE O.EmployeeID = E.ID";
	}
	else if (qNum == 9) {
		stSQL += "SELECT MAX(P.[List Price]) AS [Max Price], MIN(P.[List Price]) AS [Min Price], AVG(P.[List Price]) AS [Average Price] ";
		stSQL += "FROM Products P";
	}
	else if (qNum == 10) {
		stSQL += "SELECT P.Category, MAX(P.[List Price]) AS[Max Price], MIN(P.[List Price]) AS[Min Price], AVG(P.[List Price]) AS[Average price] ";
		stSQL += "FROM Products P ";
		stSQL += "GROUP BY P.[Category]";
	}
	else {
		cout << "invalid query number!" << endl;
	}
	/*string stSQL = "SELECT C.Company, E.[Last Name] ";
	stSQL += "FROM Customers C, Employees E, Orders O ";
	stSQL += "WHERE E.ID = O.[Employee ID] AND C.ID = O.[Customer ID] AND ";
	stSQL += "O.[Shipping Fee] < ";
	stSQL += szFee;
	stSQL += " ORDER BY O.[Shipping Fee]";
	*/
#endif
	return stSQL;
}
