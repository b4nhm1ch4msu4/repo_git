from tkinter import ttk
    
class command_entry_frame(ttk.Frame):
    def __init__(self, container):
        super().__init__(container)

        self._command_label = ttk.Label(self, text='Command: ',font=('TkDefaultFont', 12))
        self._command_label.pack(side='left',ipadx= 3)

        self.command_entry = ttk.Entry(self, width=50)
        self.command_entry.pack(side='left')

        self.pack(anchor='w', pady= 10, padx= 20)
        
    def Get_text(self):
        return self.command_entry.get()