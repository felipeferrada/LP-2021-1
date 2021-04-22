import re

#Listas

lista = '''
[65, 89, 99], [7, 8, 65687], [987, 54, 3245645634]
'''

patLista = re.compile(r'\[([0-9]+(,\s)*)*\]')

matches = patLista.finditer(lista)

for m in matches:
    print(m)


#strings

string = '''
"poto", "kjshfds", "kk", "jajajajajajaaj"
'''

patStr = re.compile(r'\"([a-zA-Z0-9] *)+\"')

match = patStr.finditer(string)

print("~"*50)

#dicc

diccionario = '''
{
    data: {"nombre": "jaja"},
    type: "DELETE",
    url: "ejemplo.txt"
}
'''

patDict = re.compile(r'\{(\"[A-Za-z0-9]+\"\: (\"([a-zA-Z0-9] *)+\"|[0-9]+|\[([0-9]+(, )*)+\]|)+(\, )*)+\}')

matchhh = patDict.finditer(diccionario)

for m in matchhh:
    print(m)

print("~"*50)

#string con salto de linea

texto = '''

"esto es algo
con un salto de linea"

"esta wea 
tambien"

'''

patTxt = re.compile("\"([a-zA-Z0-9] *(\n)*)+\"")

maxx = patTxt.finditer(texto)

for m in maxx:
    print(m)

print("~"*50)

#la tarea culia

consulta = '''
{
	data: {"nombre": "jaja"},
	type: "DELETE",
	url: "entrada.txt"
}
'''

patConsulta = re.compile(r"\{\n\tdata\:\s(\{(\"([a-zA-Z0-9]\s*)*\"\:\s(\"([a-zA-Z0-9]\s*)*\"|[0-9]*|\[([0-9]*(,\s)*)*\]|diccionario recursivo)(\,\s)*)*\})\,\n\ttype\:\s\"(POST|GET|DELETE)\"\,\n\turl\:\s(\"entrada.txt\")\n\}")

patron = patConsulta.finditer(consulta)

for m in patron:
    print(m) 

print("~"*50)