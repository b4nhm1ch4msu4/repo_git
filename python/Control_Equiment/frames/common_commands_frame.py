from tkinter import ttk, PhotoImage

class common_commands_frame(ttk.Frame):
    def __init__(self, container):
        super().__init__(container)

        self._error_img = PhotoImage(file='.\Assets\message.png')
        self._error_btn = ttk.Button(self, text="SYST:ERR?", image= self._error_img, compound='top')
        self._error_btn.pack(side = 'left',fill= 'y')

        self._clr_img = PhotoImage(file='.\Assets\dust.png')
        self._clr_history_btn = ttk.Button(self,text= 'Clear History', image= self._clr_img, compound='top',)
        self._clr_history_btn.pack(side='left',fill= 'y')

        self._option_img = PhotoImage(file='.\Assets\choice.png')
        self._option_btn = ttk.Button(self, text= 'Option', image=self._option_img, compound='top',state= 'disabled')
        self._option_btn.pack(side='left',fill= 'y')

        self.pack(anchor='w', padx= 20)
        
    def Binding_btn_command(self, error_command, clr_command, option_command):
        self._error_btn['command'] = error_command
        self._clr_history_btn['command'] = clr_command
        self._option_btn['command'] = option_command