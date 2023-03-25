import pandas as pd
df = pd.read_csv("input.csv", sep = ',')

for col in df.columns:
    flag = False
    for i in range(len(df[col])):
        if type(df[col][i]) == str:
            flag = True
            break
    if flag:
        continue

    '''if any(type(df[col][i]) == str for i in range(len(df[col]))):
        continue'''

    df[col] = (df[col] - min(df[col])) / (max(df[col]) - min(df[col]))
    df[col] = round(df[col], 2)

df.to_csv("output.csv", index = False)
