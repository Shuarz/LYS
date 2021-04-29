import pandas as pd

excel1 = "e1.xlsx"
excel2 = "e2.xlsx"

df1 = pd.read_excel(excel1)
df2 = pd.read_excel(excel2)

print(df1)
print(df2)

values1 = df1[["caso1", "caso2", "caso3"]]
values2 = df2[["caso1", "caso2", "caso3"]]

dataframes = [values1,values2]

join = pd.concat(dataframes)

join.to_excel("pruebaexcel.xlsx")