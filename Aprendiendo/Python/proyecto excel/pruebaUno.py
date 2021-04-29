import xlrd

filePath = "Escritorio\\Libro1.xlsx"

openFile = xlrd.open_workbook(filePath)

sheet = openFile.sheet_by_name("Hoja1")

print("Numero de filas", sheet.nrows)