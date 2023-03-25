import pandas as pd
df = pd.read_csv("input.csv", sep = ',')

df = df.iloc[::, 5:6]
df['Tectonic regime'] = df['Tectonic regime'].apply(lambda x: x.split('/'))
df = df.explode('Tectonic regime')
df = df['Tectonic regime'].unique()
df.sort()
print(len(df))
print(*df, sep = '\n')





