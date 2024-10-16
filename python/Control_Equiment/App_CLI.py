import pyvisa
from enum import Enum

class InstrumentType(Enum):
    Aligent6631B = 1
    Aligent34461A = 2
    CMW500 = 3
    N4010A = 4

class OutputType(Enum):
    string = 0
    int = 1
    boolean = 2
    
    
class Instrument:
    def __init__(self,type:InstrumentType):
        self.type = type
        self.rm = pyvisa.ResourceManager()
        
    def getVisaAddr(self):
        if self.type ==InstrumentType.Aligent6631B.value:
            return 'GPIB0::11::INSTR'
        if self.type == InstrumentType.Aligent34461A.value:
            return 'USB0::0x2A8D::0x1301::MY57213238::0::INSTR'
        if self.type == InstrumentType.CMW500.value:
            return 'GPIB0::20::INSTR'
        if self.type == InstrumentType.N4010A.value:
            return "TCPIP0::199.199.0.2::inst0::INSTR"

    def connect(self):
        """connect to Instrument"""
        try:
            self.visaAddr = self.getVisaAddr()
            self.Controller = self.rm.open_resource(self.visaAddr)
            self.IsConnectSuccess = True
            print(self.Controller.query("*IDN?"))
            print("Connect to instrument successfully!!!")
        except:
            print("_____Can't connect to Instrument_____")
            print()
            print("_____check your connection again and reconnect!!!!_____")
            self.IsConnectSuccess = False
            
            print()
            print()
            input("****press Enter to continue... ***")
            print()
            print()
            
    def writeCommand(self, command):
        """use with commands those have no respond"""
        self.Controller.write(command)
        print("write command to Instrument: " + command)
        
    
    def readResponse(self):
        """read the respond of last command"""
        res =self.Controller.read()
        print("_____Response: " + res)

        
    def queryCommand(self, command):
        """write command to Instrument and print the respond"""
        res = self.Controller.query(command)
        print("_____Response: " + res)        
   
def getUserInput(outputType:OutputType = OutputType.string):
    userInput = input()
    if(len(userInput) == 0):
        return
    if(outputType == OutputType.string):
        return userInput
    elif(outputType == OutputType.int):
        try:
            output = int(userInput)
            return output
        except:
            return 0
    elif(outputType == OutputType.boolean):
        pass
    

def chooseInstrumentTypeUI():
    print("__________Choose Type of Instrument__________")
    print()
    print("     1.Aligent6631B")
    print("     2.Aligent34461A")
    print("     3.CMW500")
    print("     4.N4010A")
    print("     5.QUIT!!!")
    print()
    print("*********************************************")
    
def sendCommandUI():
    print("_____send Command to Instrument")
    print()
    print("     1. write command")
    print("     2. read respond")
    print("     3. query (write and read)")
    print("     4. Break!!!!")
    print()

if __name__== "__main__":
    isContinute = True
    while(isContinute):
        chooseInstrumentTypeUI()
        print("input: ",end='')
        instrumentType = getUserInput(OutputType.int)
        if(instrumentType == 5):
            isContinute = False
            break
        elif(0 < instrumentType < 5):
            obj = Instrument(instrumentType)
            obj.connect()
            while(obj.IsConnectSuccess):
                sendCommandUI()
                print("input: ",end='')
                commandType = getUserInput(OutputType.int)
                print("Command: ",end='')
                userCommand = getUserInput()
                if(commandType == 1):
                    obj.writeCommand(userCommand)
                elif(commandType == 2):
                    obj.readResponse()
                elif(commandType == 3):
                    obj.queryCommand(userCommand)
                elif(commandType == 4):
                    break
                else:
                    print("___Invail input, please choose again!___")      
                    print("___Invail input, please choose again!___")      
                    print("___Invail input, please choose again!___")
                input("Continue...")
        else:
            
            print("___Invail input, please choose again!___")      
            print("___Invail input, please choose again!___")      
            print("___Invail input, please choose again!___")
