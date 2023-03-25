import pandas as pd
df = pd.read_csv("input.csv", sep = ',')
v = df[df['Статус'] == 'ВЫП']
st = df[df['Статус'] == 'СТ']
print(len(st['STD_ID'].unique()))
print(len(v['STD_ID'].unique()))

m = df[df['Пол'] == 'М']
m = m.loc[:, 'направление (специальность)'].mode()
print(m[0])

j = df[df['Пол'] == 'Ж']
j1 = j['направление (специальность)'].value_counts()
print(j1[j1 <= min(j1)].index[0])

na = df[df['Пол'].isnull() & df['Статус'].isnull()]
print(na.loc[:, 'STD_ID'].value_counts().index[0])

np = df['направление (специальность)'].unique()
print(len(np) - 1)

s = df['Пол'].value_counts()
print(s.index[0])
