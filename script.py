import os
import numpy as np
import csv

OUT_DIR = 'output'

stats = []
firstLine = [
    'Tipo de QuickSort',
    'Tipo de vetor',
    'Tamanho do vetor',
    'Mediana do tempo',
    'Media de comparacoes',
    'Media de trocas'
]
stats.append(firstLine)

for filename in os.listdir(OUT_DIR):
    info_execution = filename.split('.')[0].split('_')
    print(info_execution)
    qs_type = info_execution[0]
    arr_type = info_execution[1]
    arr_size = info_execution[2]
    print(qs_type, arr_type, arr_size)

    times_list = []
    comparisons_list = []
    swaps_list = []


    f = open(OUT_DIR + '/' + filename, 'r')
    for i in range(20):
        data = f.readline().split()
        comparisons = data[3].strip()
        swaps = data[4].strip()
        comparisons_list.append(int(comparisons))
        print(comparisons)
        swaps_list.append(int(swaps))
        print(swaps)
        time = data[5].strip()
        times_list.append(float(time))
        print(time)
        print()

    exec_data = []
    exec_data.append(qs_type)
    exec_data.append(arr_type)
    exec_data.append(arr_size)
    exec_data.append(np.median(np.array(times_list)))
    exec_data.append(np.array(comparisons_list).mean())
    exec_data.append(np.array(swaps_list).mean())

    stats.append(exec_data)

with open('data.csv', 'w', newline='') as csvFile:
    writer = csv.writer(csvFile)
    writer.writerows(stats)