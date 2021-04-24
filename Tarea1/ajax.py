import re

"""
POST
------------------------
data: str
archivo: str
------------------------
Escribe la data recibida al final del archivo.
Si el archivo no existe en el mismo directorio que el archivo de entrada,
lo crea y escribe la data en el archivo.
No tiene retorno.
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
Si encuentra la data en el archivo, la imprime por pantalla.
Si el archivo no existe en el mismo directorio que el archivo de entrada,
la consulta no es válida.
No tiene retorno.
"""
def GET (data, archivo):
    try:
        open(archivo, "r")
    except:
        print("Consulta mal escrita! (El archivo no existe)")

    txt = open(archivo, "r")
    for linea in txt:
        if data in linea:
            print(linea)
    txt.close()

"""
DELETE
------------------------
data: str
archivo: str
------------------------
Si encuentra la data recibida en el archivo, la borra, 
pero si recibe una data vacía, borra todo el archivo.
Si el archivo no existe en el mismo directorio que el archivo de entrada,
la consulta no es válida.
No tiene retorno.
"""
def DELETE (data, archivo):
    try:
        open(archivo, "r")
        if data == "" or data == " ":
            txt = open(archivo, "w")
            txt.close()
            print("Consulta DELETE realizada!")
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
    except:
        print("Consulta mal escrita! (El archivo no existe)")

#                                                              (     string     |  numero  |  #lista_num     |       diccionario                                                                             )                                    
patConsulta = r"\{\n\tdata\:\s\{((\"([a-zA-Z0-9]\s*)*\"\:\s(\"([a-zA-Z0-9]\s*)*\"|[0-9]*|\[([0-9]*(,\s)*)*\]|(\{(\"[A-Za-z0-9\s]*\"\:\s(\"([a-zA-Z0-9\s]*)*\"|[0-9]*|\[([0-9]+(,\s)*)*\]|(\{(\"[A-Za-z0-9\s]*\"\:\s(\"([a-zA-Z0-9\s]*)*\"|[0-9]*|\[([0-9]+(,\s)*)*\]|otro diccionario...)*(\,\s)*)*\}))*(\,\s)*)*\}))(\,\s)*)*)\}\,\n\ttype\:\s\"(POST|GET|DELETE)\"\,\n\turl\:\s\"([a-zA-Z0-9\_]*.txt)\"\n\}"

entrada = open("entrada.txt", "r")

concatenacion = ""                                             # Se trabajan las consultas de forma individual en un string

for linea in entrada:
    if "-----" not in linea:
        concatenacion += linea
    else:
        if re.match(patConsulta, concatenacion) != None:
            match = re.match(patConsulta, concatenacion)
            if match.group(23) == "GET":
                #GET
                GET(match.group(1), match.group(24))

            elif match.group(23) == "POST":
                #POST
                POST(match.group(1), match.group(24))

            elif match.group(23) == "DELETE":
                #DELETE
                DELETE(match.group(1), match.group(24))
        else:
            print("Consulta mal escrita!")
        concatenacion = ""

entrada.close()

#sin """recursion"""
#data grupo 1 
#funcion grupo 9 
#archivo grupo 10

#con """recursion"""
#data grupo 1 
#funcion grupo 23
#archivo grupo 24