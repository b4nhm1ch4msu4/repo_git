import tkinter as tk
from tkinter import ttk, Frame, PhotoImage

def generate_output():
    output_text.config(state=tk.NORMAL)  # Enable the widget for writing
    result = "Your text output goes here." + '\n'  # Replace with your actual output
    output_text.insert(tk.END, result)
    output_text.config(state=tk.DISABLED)  # Disable the widget for editing

def clearOutputSession():
    output_text.config(state=tk.NORMAL)  # Enable the widget for writing
    output_text.delete(1.0, tk.END)  # Clear existing text
    output_text.config(state=tk.DISABLED)  # Disable the widget for editing
    
    
root = tk.Tk()
root.title("Instrument Controller")
root.geometry('800x600+3+3')

# __________Navigation frame__________
nav_fr = Frame(root)

connect_btn = ttk.Button(nav_fr,text= 'Connect',)
connect_btn.pack(side='left')

interact_btn = ttk.Button(nav_fr, text= "Interact",)
interact_btn.pack(side="left")

help_btn = ttk.Button(nav_fr, text= "Help",)
help_btn.pack(side= 'left')

nav_fr.pack(anchor='w', padx= 20)
separator = ttk.Separator(root, orient='horizontal')
separator.pack(fill='x')
# __________Navigation frame__________

#____________________________________________________________________________________________________________________________

#__________common Command frame__________
commomCommand_fr = Frame()

errorImg = PhotoImage(file='F:\Mike\Common\Control_Equiment\Assets\message.png')
_error_btn = ttk.Button(commomCommand_fr, text="SYST:ERR?", image= errorImg, compound='top')
_error_btn.pack(side = 'left',fill= 'y')

clrImg = PhotoImage(file='F:\Mike\Common\Control_Equiment\Assets\dust.png')
clrHistory_btn = ttk.Button(
    commomCommand_fr,
    text= 'Clear History',image= clrImg, compound='top', command= clearOutputSession)
clrHistory_btn.pack(side='left',fill= 'y')

optionImg = PhotoImage(file='F:\Mike\Common\Control_Equiment\Assets\choice.png')
option_btn = ttk.Button(commomCommand_fr, text= 'Option', image=optionImg, compound='top')
option_btn.pack(side='left',fill= 'y')

commomCommand_fr.pack(anchor='w', padx= 20)
#__________common Command frame__________

#____________________________________________________________________________________________________________________________

#__________Command entry frame__________
commandEntry_fr = Frame(root)

command_Label = ttk.Label(commandEntry_fr, text='Command: ')
command_Label.pack(side='left',ipadx= 3)

command_entry = ttk.Entry(commandEntry_fr, width=50)
command_entry.pack(side='left')

commandEntry_fr.pack(anchor='w', pady= 10, padx= 20)
#__________Command entry frame__________

#____________________________________________________________________________________________________________________________

# __________Function button frame__________
funcBtn_fr = Frame(root)


send_btn = ttk.Button(funcBtn_fr, text= 'Send Command')
send_btn.pack(side='left', padx= 5)

read_btn = ttk.Button(funcBtn_fr, text= 'Read Respond', command= generate_output)
read_btn.pack(side='left', padx= 5)

query_btn = ttk.Button(funcBtn_fr, text= ' Query command')
query_btn.pack(side= 'left', padx= 5)

funcBtn_fr.pack(anchor='w', padx= 20)
# __________Function button frame__________

#____________________________________________________________________________________________________________________________

#__________output frame__________
output_fr = Frame()


output_label = ttk.Label(output_fr, text= 'Instrument session history: ')
output_label.pack(anchor= 'w')

# Create a Text widget and set it to read-only (disabled)
output_text = tk.Text(output_fr, wrap=tk.WORD, state=tk.DISABLED)
output_text.pack(anchor= 'w')

output_fr.pack(anchor= 'w', pady= 10, padx= 20)
#__________output frame__________

root.mainloop()