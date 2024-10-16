from tkinter import ttk
from enum import Enum

class visa_addr(Enum):
    _aligent_6631b = 'GPIB0::11::INSTR'
    _aligent_34461a = 'USB0::0x2A8D::0x1301::MY57213238::0::INSTR'
    _cmw_500 = 'GPIB0::20::INSTR'
    _n4010a = 'TCPIP0::199.199.0.2::inst0::INSTR'
    
class select_type_frame(ttk.Frame):
    def __init__(self, container):
        super().__init__(container)
        
        self._visa_label = ttk.Label(self, text= 'Instrument Types: ',font=('TkDefaultFont', 13))
        self._visa_label.pack(side='left', anchor='nw', pady= 10, padx= 5,)

        self._types_combobox = ttk.Combobox(self,takefocus= True)
        self._types_combobox['values'] = ('Aligent6631B', 'Aligent34461A', 'CMW500', 'N4010A')
        self._types_combobox.pack(side= 'left', anchor='nw', pady= 10, padx= 5)

        self._connect_btn = ttk.Button(self, text= 'Connect',)
        self._connect_btn.pack(side= 'left', anchor='nw',pady= 10, padx= 5)
        
        self.pack(anchor='w', padx= 20)
        
    def Get_visa_address(self):
        self._type = self._types_combobox.get()
        
        if self._type =='Aligent6631B':
            return visa_addr._aligent_6631b.value
        elif self._type == 'Aligent34461A':
            return visa_addr._aligent_34461a.value
        elif self._type == 'CMW500':
            return visa_addr._cmw_500.value
        elif self._type == 'N4010A':
            return visa_addr._n4010a.value
        else:
            return""
    
    def Binding_btn_command(self, connect_command):
        self._connect_btn['command'] = connect_command