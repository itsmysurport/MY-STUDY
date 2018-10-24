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
    contents = entryComp.get()
    time = time.strftime('%H:%M:%S')
    curs.execute(sql, ('i', 'name', 'contents', 'time'))
    i = i + 1
    txt = "Your content was saved!"
    messagebox.showinfo("My SQL DB", txt)

class MyFrame(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)

        self.master = master
        self.master.title("Questbook using MySQL")
        self.pack(fill=BOTH, expand=True)

        # 성명
        frame1 = Frame(self)
        frame1.pack(fill=X)

        lblName = Label(frame1, text="Name : ", width=10)
        lblName.pack(side=LEFT, padx=10, pady=10)

        entryName = Entry(frame1)
        entryName.pack(fill=X, padx=10, expand=True)

        # 내용
        frame2 = Frame(self)
        frame2.pack(fill=X)

        lblComp = Label(frame2, text="Connect :", width=10)
        lblComp.pack(side=LEFT, padx=10, pady=10)

        entryComp = Text(frame2)
        entryComp.pack(fill=X, padx=10, expand=True)

        # 저장
        frame4 = Frame(self)
        frame4.pack(fill=X)
        btnSave = Button(frame4, text="Submit", width = 10, command=onClick)
        btnSave.pack(side=LEFT, padx=100, pady=10)


def main():
    root = Tk()
    root.geometry("600x400+100+100")
    app = MyFrame(root)
    root.mainloop()


if __name__ == '__main__':
    main()
