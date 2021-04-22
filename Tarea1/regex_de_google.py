# coding=utf8
# the above tag defines encoding for this document and is for Python 2.x compatibility

import re

regex = r"\{\n\tdata\:\s\{((\"([a-zA-Z0-9]\s*)*\"\:\s(\"([a-zA-Z0-9]\s*)*\"|[0-9]*|\[([0-9]*(,\s)*)*\]|diccionario recursivo)(\,\s)*)*)\}\,\n\ttype\:\s\"(POST|GET|DELETE)\"\,\n\turl\:\s(\"ejemplo.txt\")\n\}"

test_str = ("{\n"
	"	data: {\"casa2\": 9856, \"sdfsd\": \"sdfs\"},\n"
	"	type: \"DELETE\",\n"
	"	url: \"ejemplo.txt\"\n"
	"}\n"
	"-----\n"
	"{\n"
	"	data: {\"nombre\": \"jaja\"},\n"
	"	type: \"GE\",\n"
	"	url: \"entrada.txt\"\n"
	"}\n"
	"-----\n"
	"{\n"
	"	data: {\"nombre\": \"jaja\"},\n"
	"	type: \"POST\",\n"
	"	url: \"ejemplo.txt\"\n"
	"}\n"
	"-----\n"
	"{\n"
	"	data: {\"nombre\": \"jaja\"},\n"
	"	type: \"GET\",\n"
	"	url: \"ejemplo.txt\"\n"
	"}")

matches = re.finditer(regex, test_str)

for matchNum, match in enumerate(matches, start=1):
    
    print ("Match {matchNum} was found at {start}-{end}: {match}".format(matchNum = matchNum, start = match.start(), end = match.end(), match = match.group()))
    
    for groupNum in range(0, len(match.groups())):
        groupNum = groupNum + 1
        
        print ("Group {groupNum} found at {start}-{end}: {group}".format(groupNum = groupNum, start = match.start(groupNum), end = match.end(groupNum), group = match.group(groupNum)))

# Note: for Python 2.7 compatibility, use ur"" to prefix the regex and u"" to prefix the test string and substitution.
