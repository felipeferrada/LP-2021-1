import re

"""
POST
------------------------
data: str
archivo: str
------------------------

"""
def POST (data, archivo):
    txt = open(archivo, "a")
    txt.write("\n")
    txt.write("{"+data+"}")
    txt.close()
    print("Consulta POST realizada!")
    
"""
GET
------------------------
data: str
archivo: str
------------------------

"""
def GET (data, archivo):
    txt = open(archivo, "r")
    for linea in txt:
        if data in linea:
            print(linea)

"""
DELETE
------------------------
data: str
archivo: str
------------------------

"""
def DELETE (data, archivo):
    if data == "" or data == " ":
        txt = open(archivo, "w")
        txt.close()
    else:
        txt = open(archivo, "r")
        contenido = ""
        for linea in txt:
            if data not in linea:
                contenido += linea
        txt.close()

        new_txt = open(archivo, "w")
        new_txt.write(contenido)
            
        print("Consulta DELETE realizada!")
        new_txt.close()


patConsulta = r"\{\n\tdata\:\s\{((\"([a-zA-Z0-9]\s*)*\"\:\s(\"([a-zA-Z0-9]\s*)*\"|[0-9]*|\[([0-9]*(,\s)*)*\]|diccionario recursivo)(\,\s)*)*)\}\,\n\ttype\:\s\"(POST|GET|DELETE)\"\,\n\turl\:\s\"(ejemplo.txt)\"\n\}"

entrada = open("entrada.txt", "r")

concatenacion = ""                                         # Se trabaja el archivo como string
    
for linea in entrada:
    if "-----" not in linea:
        concatenacion += linea
    else:
        if re.match(patConsulta, concatenacion) != None:
            match = re.match(patConsulta, concatenacion)
            if match.group(9) == "GET":
                #GET
                GET(match.group(1), match.group(10))

            elif match.group(9) == "POST":
                #POST
                POST(match.group(1), match.group(10))

            elif match.group(9) == "DELETE":
                #DELETE
                DELETE(match.group(1), match.group(10))
        else:
            print("Consulta mal escrita!")
        concatenacion = ""

entrada.close()