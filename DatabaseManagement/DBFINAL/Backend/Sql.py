import pyodbc


MSA_conn_str = (
    r'Driver={ODBC Driver 13 for SQL Server};'
    r'Server=tcp:cs374.database.windows.net,1433;'
    r'Database=ScratchDatabase;Uid=SeanG;Pwd=Erman123;'
    r'Encrypt=yes;'
    r'TrustServerCertificate=no;'
    r'Connection Timeout=30;'
    )
    

def ex01():
    cnxn = pyodbc.connect(MSA_conn_str)
    crsr = cnxn.cursor()
    sql = "SELECT Song "
    sql = sql + "FROM Song"
    rows = crsr.execute(sql)

    output = []
    count = 0
    for row in rows:
        if count != 5:
            output.append(str(row[0]))
        else:
            break
        
    return output

