import tkinter as tk
from tkinter import ttk
from Log_config import *
from Model import Instrument
from tkinter import filedialog as fd
from Frames.output_frame import output_frame
from Frames.func_btn_frame import func_btn_frame
from Frames.command_entry_frame import command_entry_frame
from Frames.common_commands_frame import common_commands_frame
from Frames.instrument_type_selector_frame import select_type_frame
from tkinter.messagebox import showerror, showwarning, showinfo

              
class MainFr(ttk.Frame): 
    def __init__(self, container):
        super().__init__(container)
        
        self._select_type_frame = select_type_frame(self)
        self._select_type_frame.Binding_btn_command(self.Connect_btn_clicked)
        
        self._common_commands_frame = common_commands_frame(self)
        self._common_commands_frame.Binding_btn_command(self.Check_error_btn_clicked, self.Clear_btn_clicked, 
                                                        self.Option_btn_clicked)
        
        self._command_entry_frame = command_entry_frame(self)
        
        self._func_btn_frame = func_btn_frame(self)
        self._func_btn_frame.Binding_btn_command(self.Write_btn_clicked, self.Read_btn_clicked, 
                                                 self.Query_btn_clicked, self.Send_list_btn_clicked)
        
        self._output_frame = output_frame(self)
        
        self.pack(anchor='w', expand= True, fill= 'y')
        
    # __________Connect button click event# __________
    def Connect_btn_clicked(self):
        self._address =  self._select_type_frame.Get_visa_address()
        logging.info(f'visa address: {self._address}')
        
        if self._address == "":
            logging.error('Visa address is empty!')
            showwarning(title='Warning', 
                        message='Visa Address is empty! \nPlease select visa address!')
            return
        
        self._controller = Instrument(self._address)
        
        if self._controller.Connect():
            logging.info("Connect to Instrument successfully")
            showinfo(title="Information", 
                     message='Connect to Instrument successfully')
            return
        else:
            logging.error('Connect to Instrument fail!!!')
            showerror(title='Error', 
                      message="Can't connect to Instrument.\nPlease check cable and choose right visa address!!!")
            return

    # __________Send command button click event# __________
    def Write_btn_clicked(self):
        command = self._command_entry_frame.Get_text()
        self._controller.Write_command(command)
        
        logging.info(f'Send command {command} to Instrument')
        
        self._output_frame.Insert_text('>>>Send command: ' + command + '\n')
    
    # __________Read respond button click event# __________
    def Read_btn_clicked(self):
        Res = self._controller.Read_response()
        
        if not Res:
            logging.error("Read respond Fail!!!")
            self._output_frame.Insert_text("Error!!! Can't read respond!!!\n")
            return
        
        logging.info(f'Get respond: {Res}')
        
        self._output_frame.Insert_text('<<<Respond: ' + Res + '\n')
    
    # __________Send & Read button click event# __________    
    def Query_btn_clicked(self):
        command = self._command_entry_frame.Get_text()
        Res = self._controller.Query_command(command)
        
        if not Res:
            logging.error(f"Can't query command: {command}")
            self._output_frame.Insert_text("Error!!! Can't query " + command + " command!!!\n")
            return
        
        logging.info(f"Send command {command} to Instrument")
        
        self._output_frame.Insert_text('>>>Send command: ' + command + '\n')
        
        logging.info(f"Get respond: {Res}")
        
        self._output_frame.Insert_text('<<<Respond: ' + Res + '\n')

    # __________SYST:ERR? button click event# __________
    def Check_error_btn_clicked(self):
        Res = self._controller.Query_command('SYSTem:ERRor?')
        
        self._output_frame.Insert_text('>>>Send command: ' + 'SYSTem:ERRor?' + '\n')
        self._output_frame.Insert_text('<<<Respond: ' + Res + '\n')
        
        logging.info(f'Check error: {Res}')
    
    # __________Clearn history button click event# __________    
    def Clear_btn_clicked(self):
        self._output_frame.Clear_text()
        
        logging.info("Clear output screen.")
    
    # __________Send commands from file button click event# __________    
    def Send_list_btn_clicked(self):
        # config file types
        file_types = (('text files', '*.txt'), ('All files', '*.*'))
        
        #get file path
        file_name = fd.askopenfilename(title='Open a file', initialdir='/', filetypes=file_types)
        
        # send command and write result into output frame
        if self._controller.Write_commands_from_file(file_name):
            self._output_frame.Insert_text('>>>Send commands from file: ' + file_name +' SUCCESS!!! SUCCESS!!! SUCCESS' +'\n')
            
            logging.info(f"Send commands from file {file_name} success")
        else:
            logging.error(f"Send commands from file {file_name} fail!!!")
            self._output_frame.Insert_text('>>>Send commands from file: ' + file_name +' Fail!! FAIL!!! FAIL!!!' +'\n')
    
    def Option_btn_clicked():
        pass
    
    
if __name__ == '__main__':
    root = tk.Tk()
    root.title("Instrument Controller")
    root.geometry('800x600+3+3')
    
    app = MainFr(root)
    root.mainloop()
