import pyodbc

MSA_conn_str = (
    r'DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};'
    r'DBQ=C:\Users\delap\Documents\Northwind.accdb;'
    )

def ex01():
    cnxn = pyodbc.connect(MSA_conn_str)
    crsr = cnxn.cursor()
    sql = "SELECT [Product Name], [List Price], [List Price] * .10 + [List Price] AS [Price Increase]"
    sql = sql + "FROM Products"
    rows = crsr.execute(sql)

    count = 0
    output = ''
    #print('\nProduct Name\t\t\t     List Price->10% Increase')
    
    for row in rows: 
        if count != 1:
            output = output + str(row[0]) + '\n'
            count += 1 
        else:
            break

    return output