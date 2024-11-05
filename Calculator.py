import tkinter as tk
from tkinter import messagebox

# fuunctions
def calculate():
    expression = dialog_box.get()
    try:
        result = eval(expression,{__builtins__:None},{}) # calculate the expression
        dialog_box.delete(0, tk.END) # clear the dialog box
        dialog_box.insert(tk.END, result) # output the result
    except(ZeroDivisionError, SyntaxError, NameError, TypeError, ValueError):
        dialog_box.delete(0, tk.END)
        dialog_box.insert(0, "Invalid Input")

# input numbers with the buttons
def input_num_click(number,text):
    current_number=number.get()
    number.delete(0,tk.END) # clear the dialog box
    number.insert(0, current_number + text) # insert the number

# clear the dialog box
def cleaning(content):
    content.delete(0, tk.END)

# Create a window
window = tk.Tk()
window.title("Calculator") # Naming the window
window.geometry("370x550") # sizing the window
window.resizable(0,0) # making the window non-resizable



# dialog box
dialog_box = tk.Entry(window, font=("Times New Rome", 30), width=20)
dialog_box.pack(pady=40) # vertical indicator

#create keyboard

# numbers
button0 = tk.Button(window, text="0", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "0"))
button0.place(x=8, y=135)
button1 = tk.Button(window, text="1", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "1"))
button1.place(x=8, y=200)
button2 = tk.Button(window, text="2", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "2"))
button2.place(x=98, y=200)
button3 = tk.Button(window, text="3", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "3"))
button3.place(x=188, y=200)
button4 = tk.Button(window, text="4", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "4"))
button4.place(x=8, y=270)
button5 = tk.Button(window, text="5", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "5"))
button5.place(x=98, y=270)
button6 = tk.Button(window, text="6", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "6"))
button6.place(x=188, y=270)
button7 = tk.Button(window, text="7", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "7"))
button7.place(x=8, y=340)
button8 = tk.Button(window, text="8", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "8"))
button8.place(x=98, y=340)
button9 = tk.Button(window, text="9", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "9"))
button9.place(x=188, y=340)


# operators
button_plus = tk.Button(window, text="+", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "+"))
button_plus.place(x=278, y=135)
button_minus = tk.Button(window, text="-", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "-"))
button_minus.place(x=278, y=200)
button_multiply = tk.Button(window, text="*", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "*"))
button_multiply.place(x=278, y=270)
button_divide = tk.Button(window, text="/", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "/"))
button_divide.place(x=278, y=340)
button_delete = tk.Button(window, text="C", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: cleaning(dialog_box))
button_delete.place(x=98, y=135)
button_equal = tk.Button(window, text="=", width=6, height=2, font=("Times New Rome", 14,"bold"), command=calculate)
button_equal.place(x=188, y=135)
button_mod = tk.Button(window, text="%", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "%"))
button_mod.place(x=278, y=410)
button_sine = tk.Button(window, text="sin", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "sin("))
button_sine.place(x=8, y=410)
button_cosine = tk.Button(window, text="cos", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "cos("))
button_cosine.place(x=98, y=410)
button_tangent = tk.Button(window, text="tan", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "tan("))
button_tangent.place(x=188, y=410)
button_bracket = tk.Button(window, text=")", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, ")"))
button_bracket.place(x=278, y=480)
button_cosecond = tk.Button(window, text="csc", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "cosec("))
button_cosecond.place(x=8, y=480)
button_sec = tk.Button(window, text="sec", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "sec("))
button_sec.place(x=98, y=480)
button_cot = tk.Button(window, text="cot", width=6, height=2, font=("Times New Rome", 14,"bold"), command=lambda: input_num_click(dialog_box, "cot("))
button_cot.place(x=188, y=480)

# open the window
window.mainloop()
