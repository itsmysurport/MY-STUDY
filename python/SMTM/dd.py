from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import pymysql

i = 1
conn = pymysql.connect(host='localhost', user='root', password='12345678', db='mydb', charset='utf8')
curs = conn.cursor()
sql = "insert into table1 values (%s, %s, %s, %s)"

def onClick():
    global i
    name = entryName.get()
    contents = entryComp.get("1.0", END)
    time = time.strftime('%H:%M:%S')
    curs.execute(sql, ('i', 'name', 'contents', 'time'))
    i = i + 1
    txt = "Your content was saved!"
    messagebox.showinfo("My SQL DB", txt)

root = Tk()
root.geometry("600x400+100+100")


root.title("Questbook using MySQL")

frame1 = Frame(root)
frame1.pack(fill=X)

lblName = Label(frame1, text="Name : ", width=10)
lblName.pack(side=LEFT, padx=10, pady=10)

entryName = Entry(frame1)
entryName.pack(fill=X, padx=10, expand=True)

# 내용
frame2 = Frame(root)
frame2.pack(fill=X)

lblComp = Label(frame2, text="Connect :", width=10)
lblComp.pack(side=LEFT, padx=10, pady=10)

entryComp = Text(frame2)
entryComp.pack(fill=X, padx=10, expand=True)

# 저장
frame4 = Frame(root)
frame4.pack(fill=X)
btnSave = Button(frame4, text="Submit", width = 10, command=onClick)
btnSave.pack(side=LEFT, padx=100, pady=10)

root.mainloop()
