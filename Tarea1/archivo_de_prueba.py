import re

patConsulta = r"\{\n\tdata\:\s(\{(\"([a-zA-Z0-9]\s*)*\"\:\s(\"([a-zA-Z0-9]\s*)*\"|[0-9]*|\[([0-9]*(,\s)*)*\]|diccionario recursivo)(\,\s)*)*\})\,\n\ttype\:\s\"((POST|GET|DELETE))\"\,\n\turl\:\s\"(entrada.txt)\"\n\}"


entrada = open("entrada.txt", "r")

concatenacion = ""

for linea in entrada:
    while "-----" not in linea:
        concatenacion += linea
        break


    
entrada.close()