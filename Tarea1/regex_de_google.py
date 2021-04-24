# coding=utf8
# the above tag defines encoding for this document and is for Python 2.x compatibility

import re

regex = r"\{\n\tdata\:\s\{((\"([a-zA-Z0-9]\s*)*\"\:\s(\"([a-zA-Z0-9]\s*)*\"|[0-9]*|\[([0-9]*(,\s)*)*\]|(\{(\"[A-Za-z0-9\s]*\"\:\s(\"([a-zA-Z0-9\s]*)*\"|[0-9]*|\[([0-9]+(,\s)*)*\]|(\{(\"[A-Za-z0-9\s]*\"\:\s(\"([a-zA-Z0-9\s]*)*\"|[0-9]*|\[([0-9]+(,\s)*)*\]|otro diccionario...)*(\,\s)*)*\}))*(\,\s)*)*\}))(\,\s)*)*)\}\,\n\ttype\:\s\"(POST|GET|DELETE)\"\,\n\turl\:\s\"([a-zA-Z0-9\_]*.txt)\"\n\}"

test_str = ("{\n"
	"	data: {\"casa2\": 9856, \"dict1\": {\"alo\": 5465, \"dict2\": {\"listo\": [654, 654]}}},\n"
	"	type: \"DELETE\",\n"
	"	url: \"ejemplo.txt\"\n"
	"}\n"
	"-----\n"
	"{\n"
	"	data: {\"nombre1\": \"jaja\"},\n"
	"	type: \"GE\",\n"
	"	url: \"ejemplo.txt\"\n"
	"}\n"
	"-----\n"
	"{\n"
	"	data: {\"nombre\": \"jaja1\"},\n"
	"	type: \"POST\",\n"
	"	url: \"pos_teo.txt\"\n"
	"}\n"
	"-----\n"
	"{\n"
	"	data: {\"nombre\": \"jjdsjd ql gei aja\"},\n"
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
