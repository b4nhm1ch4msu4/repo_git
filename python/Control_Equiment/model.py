from Log_config import *
import pyvisa
import time
    
class Instrument:
    def __init__(self,visa_address):
        self._rm = pyvisa.ResourceManager()
        """connect to Instrument"""
        try:
            self._controller = self._rm.open_resource(visa_address)
            self.isConnected = True
        except:
            self.isConnected = False
        
    def Write_command(self, command):
        """use with commands those have no respond"""
        try:
            self._controller.write(command)
            return True
        except:
            return False
        
    def Read_response(self):
        """read the respond of last command"""
        try:
            res =self._controller.read()
            return res
        except:
            return False
        
    def Query_command(self, command):
        """write command to Instrument and print the respond"""
        try:
            res = self._controller.query(command)
            return res
        except:
            return False
        
    def Write_commands_from_file(self,file_location):
        try:
            with open(file_location, 'r') as file:
                logging.info(f'Open file {file} successful.')
                commands = file.readlines()
                
                for command in commands:
                    command = command.strip()
                    if command.startswith('\\'):
                        continue
                    elif command.endswith('?'):
                        res = self.Query_command(command)
                    else:
                        res = self.Write_command(command)
                    logging.info(f"check response:  {res}")
                    
                    if res == False:
                        logging.error(f"Fail to send command {command} !!!")
                        return False
                    
                    logging.info(f"Send command {command}")
                    if not isinstance(res, bool):
                        logging.info(f'Get respond: {res}')
                    time.sleep(1) #sleep 1s after each command
                    
                #check Error
                check_error = self._controller.query('SYST:ERR?')
                logging.info(f'Check error: ' + check_error)
                check_error = str(check_error).lower()
                if not 'no error' in check_error:
                    return False
                return True
        except FileNotFoundError:
            logging.error(f"Can't open file {file_location} !!!")
            return False
