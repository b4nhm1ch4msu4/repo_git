from tkinter import ttk
import tkinter as tk

class output_frame(ttk.Frame):
    def __init__(self, container):
        super().__init__(container)
        self._output_label = ttk.Label(self, text= 'Instrument session history: ', font=('TkDefaultFont', 12))
        self._output_label.pack(anchor= 'w')

        # Create a Text widget and set it to read-only (disabled)
        self._output_text = tk.Text(self, wrap=tk.WORD, state=tk.DISABLED)
        self._output_text.pack(anchor= 'w', expand= True, fill= 'y')

        self.pack(anchor= 'w', pady= 10, padx= 20, expand= True, fill= 'y')
        
    def Insert_text(self, text):
        self._output_text['state'] = tk.NORMAL
        self._output_text.insert('end', text)
        self._output_text['state']= tk.DISABLED

    def Clear_text(self):
        self._output_text['state'] = tk.NORMAL
        self._output_text.delete("1.0", "end")
        self._output_text['state'] = tk.DISABLED