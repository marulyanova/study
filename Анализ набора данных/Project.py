# Использование библиотеки pandas для работы с данными
# Использование библиотеки seaborn для построения графиков
# Использование библиотеки matplotlib для отображения графиков
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

#Использование структуры данных DataFrame. Считвание по сслыке файла .csv
link = 'https://raw.githubusercontent.com/rfordatascience/tidytuesday/master/data/2023/2023-01-17/artists.csv'
df = pd.read_csv(link)


'''print(df) # Проверка, что файл считан
print(df.columns) # Вывод названий колонок, чтобы знать, какие величины можно рассчитать'''


''' У каждого артиста есть несколько строк с данными (разные года участия)
Оставляю для каждого артиста по одной строчке
(Чтобы каждое имя встречалось только один раз)
'''
names = df.drop_duplicates('artist_name')


''' В новый DataFrame gender записываю, сколько раз и какой пол встретился
Использую value.counts() для колонки artist_gender из names
'''
gender = names.artist_gender.value_counts()


''' Есть те, у кого не указан пол. Считаю, сколько в колонке artist_gender
пропусков с помощью isna().sum(). Добавляю это значение с индексом Undefined
'''
gender['Undefined'] = names.artist_gender.isna().sum()
print(gender)


# Проверка, что учли всех людей
if len(names.artist_gender) == sum(gender): print(True)


sns.set(rc = {'figure.figsize': (15,8) }) # Настройка размеров графика


''' График 1 - по dataframe gender. По горизонтали индексы, по вертикали 
значения. Следующая строка - вкл. отображение на графике значений столбцов
plt.show() - демонстрация графика
'''
graph1 = sns.barplot(x = gender.index, y = gender.values)
graph1.bar_label(graph1.containers[0])
plt.show()


''' В dataframe counrty записываю сколько артистов относятся к какой
национальности. К колонке artist_nationality dataframe names
применяю value_counts()
'''
country = names.artist_nationality.value_counts()


''' Аналогичное построение графика 2. 
Затем следуют настройки - поворот подписей в легенде на 90 градусов, 
иначе они будут наложены друг на друга.
И также подписи данных на столбцах
'''
graph2 = sns.barplot(x = country.index, y = country.values)
graph2.set_xticklabels(graph2.get_xticklabels(), rotation = 90)
graph2.bar_label(graph2.containers[0])
plt.show()
