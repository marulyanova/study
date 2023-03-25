import pandas as pd
df = pd.read_csv("input.csv", sep = ',')

stud = df[df['STD_ID'] == 99125]
stud = stud[stud['АТТЕСТАЦИЯ'] == 'Экзамен']
print(len(stud))

sred = stud.loc[:, 'mark']
print(round(sum(sred) / len(stud), 2))
