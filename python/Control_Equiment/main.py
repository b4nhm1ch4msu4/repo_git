import tkinter as tk
from tkinter import ttk
from Log_config import *
from model import Instrument
from tkinter import filedialog as fd
from frames.output_frame import output_frame
from frames.func_btn_frame import func_btn_frame
from frames.command_entry_frame import command_entry_frame
from frames.common_commands_frame import common_commands_frame
from tkinter.messagebox import showerror, showwarning, showinfo
from frames.instrument_type_selector_frame import select_type_frame
     
              
class MainFr(ttk.Frame):
    def __init__(self, container):
        super().__init__(container)
        self._select_type_frame = select_type_frame(self)
        self._common_commands_frame = common_commands_frame(self)
        self._command_entry_frame = command_entry_frame(self)
        self._func_btn_frame = func_btn_frame(self)
        self._output_frame = output_frame(self)
        
        # Binding buttons event
        self._event_handler = Event_handle(self)
        
        self._select_type_frame.Binding_btn_command(self._event_handler.Connect_btn_clicked)
        
        self._common_commands_frame.Binding_btn_command(self._event_handler.Check_error_btn_clicked, 
                                                        self._event_handler.Clear_btn_clicked, 
                                                        self._event_handler.Option_btn_clicked)
         
        self._func_btn_frame.Binding_btn_command(self._event_handler.Write_btn_clicked, 
                                                 self._event_handler.Read_btn_clicked, 
                                                 self._event_handler.Query_btn_clicked, 
                                                 self._event_handler.Send_list_btn_clicked)
        
        self.pack(anchor='w', expand= True, fill= 'y')


class Event_handle:
    def __init__(self, main_frame: MainFr) -> None:
        self.Main_frame = main_frame
    
    # __________Connect button click event# __________
    def Connect_btn_clicked(self):
        Visa_address =  self.Main_frame._select_type_frame.Get_visa_address()
        logging.info(f'visa address: {Visa_address}')
        
        if Visa_address == "":
            logging.error('Visa address is empty!')
            showwarning(title='Warning', 
                        message='Visa Address is empty! \nPlease select visa address!')
            return
        
        self._controller = Instrument(Visa_address)
        
        if self._controller.isConnected == True:
            logging.info("Connect to Instrument successfully")
            showinfo(title="Information", 
                     message='Connect to Instrument successfully')
        else:
            logging.error('Connect to Instrument fail!!!')
            showerror(title='Error', 
                      message="Can't connect to Instrument.\nPlease check cable and choose right visa address!!!")

    # __________Send command button click event# __________
    def Write_btn_clicked(self):
        command = self.Main_frame._command_entry_frame.Get_text()
        self._controller.Write_command(command) 
        logging.info(f'Send command {command} to Instrument')
        
        self.Main_frame._output_frame.Insert_text('>>>Send command: ' + command + '\n')
    
    # __________Read respond button click event# __________
    def Read_btn_clicked(self):
        Res = self._controller.Read_response()
        logging.info(f'Get respond: {Res}')
        
        if not Res:
            logging.error("Read respond Fail!!!")
            self.Main_frame._output_frame.Insert_text("Error!!! Can't read respond!!!\n")
            return
        
        self.Main_frame._output_frame.Insert_text('<<<Respond: ' + Res + '\n')
    
    # __________Send & Read button click event# __________    
    def Query_btn_clicked(self):
        command = self.Main_frame._command_entry_frame.Get_text()
        Res = self._controller.Query_command(command)
        logging.info(f"Send command {command} to Instrument")
        self.Main_frame._output_frame.Insert_text('>>>Send command: ' + command + '\n')
        
        if Res:
            self.Main_frame._output_frame.Insert_text('<<<Respond: ' + Res + '\n')
            logging.info(f"Get respond: {Res}")
        else:
            self.Main_frame._output_frame.Insert_text("Error!!! Can't query " + command + " command!!!\n")
            logging.error(f"Can't query command: {command}")

    # __________SYST:ERR? button click event# __________
    def Check_error_btn_clicked(self):
        Res = self._controller.Query_command('SYSTem:ERRor?')
        
        self.Main_frame._output_frame.Insert_text('>>>Send command: ' + 'SYSTem:ERRor?' + '\n')
        self.Main_frame._output_frame.Insert_text('<<<Respond: ' + Res + '\n')
        
        logging.info(f'Check error: {Res}')
    
    # __________Clearn history button click event# __________    
    def Clear_btn_clicked(self):
        self.Main_frame._output_frame.Clear_text()
        logging.info("Clear output screen.")
    
    # __________Send commands from file button click event# __________    
    def Send_list_btn_clicked(self):
        # config file types
        file_types = (('text files', '*.txt'), ('All files', '*.*'))
        
        # get file path
        file_name = fd.askopenfilename(title='Open a file', initialdir='/', filetypes=file_types)
        
        # send command and write result into output frame
        if self._controller.Write_commands_from_file(file_name):
            self.Main_frame._output_frame.Insert_text('>>>Send commands from file: ' + file_name +' SUCCESS!!! SUCCESS!!! SUCCESS' +'\n')
            logging.info(f"Send commands from file {file_name} success")
        else:
            logging.error(f"Send commands from file {file_name} fail!!!")
            self.Main_frame._output_frame.Insert_text('>>>Send commands from file: ' + file_name +' Fail!! FAIL!!! FAIL!!!' +'\n')
    
    def Option_btn_clicked():
        pass 

    
if __name__ == '__main__':
    root = tk.Tk()
    root.title("Instrument Controller")
    root.geometry('800x600+3+3')
    
    app = MainFr(root)
    root.mainloop()
