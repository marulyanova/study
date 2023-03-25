import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

link = 'https://raw.githubusercontent.com/rfordatascience/tidytuesday/master/data/2023/2023-01-17/artists.csv'
df = pd.read_csv(link)

print(df) 
print(df.columns) 

names = df.drop_duplicates('artist_name')

gender = names.artist_gender.value_counts()

gender['Undefined'] = names.artist_gender.isna().sum()
print(gender)

if len(names.artist_gender) == sum(gender): print(True)


sns.set(rc = {'figure.figsize': (15,8) }) # Настройка размеров графика

graph1 = sns.barplot(x = gender.index, y = gender.values)
graph1.bar_label(graph1.containers[0])
plt.show()

country = names.artist_nationality.value_counts()

graph2 = sns.barplot(x = country.index, y = country.values)
graph2.set_xticklabels(graph2.get_xticklabels(), rotation = 90)
graph2.bar_label(graph2.containers[0])
plt.show()
