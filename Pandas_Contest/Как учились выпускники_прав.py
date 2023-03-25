import pandas as pd
stud = pd.read_csv("students_info.csv")
exam = pd.read_csv("exams_info.csv")

exam = exam.merge(stud[["STD_ID", "Статус"]])
ans = exam[exam["Статус"] == "ВЫП"]
ans = ans.groupby("STD_ID").agg({"mark" : "mean"})
ans.sort_index()
ans = ans.reset_index()[["STD_ID", "mark"]]
ans.to_csv("output.csv", index = False)
