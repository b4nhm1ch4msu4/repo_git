from tkinter import ttk

class func_btn_frame(ttk.Frame):
    def __init__(self, container):
        super().__init__(container)
        
        self._write_btn = ttk.Button(self, text= 'Send Command')
        self._write_btn.pack(side='left', padx= 5)

        self._read_btn = ttk.Button(self, text= 'Read Respond',)
        self._read_btn.pack(side='left', padx= 5)

        self._query_btn = ttk.Button(self, text= ' Send & Read')
        self._query_btn.pack(side= 'left', padx= 5)
        
        self._send_list_btn = ttk.Button(self, text='Send commands from file')
        self._send_list_btn.pack(side= 'left', padx= 5)

        self.pack(anchor='w', padx= 20)
        
    def Binding_btn_command(self, write_command, read_command, query_command, send_list_command):
        self._write_btn['command'] = write_command
        self._read_btn['command'] = read_command
        self._query_btn['command'] = query_command
        self._send_list_btn['command'] = send_list_command