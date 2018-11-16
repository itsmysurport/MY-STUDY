from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import pymysql

conn = pymysql.connect(host='localhost', user='root', password='12345678', db='mydb', charset='utf8')
curs = conn.cursor()
sql = "SELECT * FROM table1;"

def onClick():
    conn = pymysql.connect(host='localhost', user='root', password='12345678', db='mydb', charset='utf8')
    curs = conn.cursor()
    sql = "SELECT * FROM table1;"
    curs.execute(sql)
    rs = curs.fetchall()
    print(rs)

    for r in range (len(rs)):
        for c in range (0, 4):
            lbl = Label(root, text=rs[r][c])
            lbl.grid(row=r+2, column=c)

root = Tk()

# SET GUI
btn = Button(root, text="Refresh", width = 10, command=onClick)
btn.grid(row=0, column=0)
lbl = Label(root, text="ID")
lbl.grid(row=1, column=0)
lbl = Label(root, text="Name")
lbl.grid(row=1, column=1)
lbl = Label(root, text="Contents")
lbl.grid(row=1, column=2)
lbl = Label(root, text="Time")
lbl.grid(row=1, column=3)

# Create GUI


root.mainloop()
