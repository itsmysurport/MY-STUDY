from tkinter import *
from tkinter.ttk import *


root = Tk()
# Time  Name    Contents
btnSave = Button(root, text="Refresh")
btnSave.grid(row=0, column=0)
lblName = Label(frame1, text="Time")
lblName.pack(side=LEFT, padx=50, pady=30)
lblName1 = Label(frame1, text="Name", width=5)
lblName1.pack(side=LEFT, padx=20, pady=30)
lblName2 = Label(frame1, text="Contetns", width=100)
lblName2.pack(side=LEFT, padx=100, pady=30)

root.mainloop()
