from enum import Enum

Color = Enum('Kolor', ['RED', 'GREEN', 'BLUE'])
print(Color.RED)  # this works, prints 'Color.RED'
# print(Color.TEAL) # this raises an exception
