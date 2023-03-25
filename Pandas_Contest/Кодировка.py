import pandas as pd
df = pd.read_csv("input.csv", sep = ',')

cur = df.loc[:, 'Onshore/Offshore'].unique()
cur.sort()
df['Onshore/Offshore'] = df['Onshore/Offshore'].map({'OFFSHORE' : '0', 'ONSHORE' : '1', 'ONSHORE-OFFSHORE' : '2'})
df['Onshore/Offshore'].to_csv("output.csv", index = False)
