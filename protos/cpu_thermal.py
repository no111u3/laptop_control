#!/usr/bin/python3

import json
import re
import subprocess

def get_cpu_temp(data):
    for item in data:
        if 'coretemp' in item:
            return item, data[item]

def parse_core_temp(data):
    result = {}
    for item in data:
        item_clear = re.sub(r'temp[0-9]+_', '', item) # refactor to simplify
        result[item_clear] = data[item]
    
    return result

def get_cores_temp(data):
    cores = {}
    for item in data:
        if 'Core' in item:
            name, number = item.split()
            cores[int(number)] = {'name': item, 'temp': parse_core_temp(data[item])}
    
    return cores

def get_core_temp(cores, number):
    item = cores[number]
    return item['name'], item['temp']

sense_raw_json = subprocess.Popen('sensors -j', shell=True, stdout=subprocess.PIPE).stdout.read()
sense_json = json.loads(sense_raw_json)
adapter_name, cpu_temp = get_cpu_temp(sense_json)
print(adapter_name)
cores = get_cores_temp(cpu_temp)
core_name, core_temp = get_core_temp(cores, 0)
print("for %s temp is: %f" % (core_name, core_temp['input']))
