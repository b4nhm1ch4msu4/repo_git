from enum import Enum

CSVExportStatus = Enum(
    "CSVExportStatus", ["PENDING", "PROCESSING", "SUCCESS", "FAILURE"]
)


def get_csv_status(status, data):
    match status:
        case CSVExportStatus.PENDING:
            return ("Pending...",list(map(lambda x:list(map(lambda y:str(y),x)),data))) 
        case CSVExportStatus.PROCESSING:
            return ("Processing...",'\n'.join(','.join(row) for row in data))
        case CSVExportStatus.SUCCESS:
            return ("Success!",data)
        case CSVExportStatus.FAILURE:
            data = list(map(lambda x:map(lambda y:str(y),x),data))
            data = '\n'.join(','.join(row) for row in data)
            return ("Unknown error, retrying...", data)
        case _:
            raise Exception("unknown export status")
