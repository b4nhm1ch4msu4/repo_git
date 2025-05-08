from pathlib import Path
import os
import shelve

shelve_file = shelve.open('shelve_test')
shelve_file['key1'] = 'value1'
shelve_file['key2'] = 'value2'
shelve_file.close()

shelve_file = shelve.open('shelve_test')
print(shelve_file['key1'])
print(shelve_file['key2'])
shelve_file.close()

