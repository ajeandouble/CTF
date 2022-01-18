import socket
import sys
import time
import math

server = "irc.root-me.org"
#channel = "#channel"
botnick = "adouble_"

irc = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("connecting to:"+server)
irc.connect((server, 6667))
print("connected")
data = "USER " + botnick + " " + botnick + " " + botnick + " yoo\n"
irc.send(data.encode())
print(data + " <- sent")
data = "NICK "+ botnick + "\n"
irc.send(data.encode())
data = "PRIVMSG nickserv :iNOOPE\r\n"
irc.send(data.encode())


time.sleep(1)
data = "PRIVMSG Candy : !ep1\n"
irc.send(data.encode())
text = irc.recv(2040)  #receive the text
print("PRIVMSG+" + text.decode())   #print text to console
#irc.send("JOIN "+ channel +"\n")        #join the chan

while 1:    #puts it in a loop
	text = irc.recv(2040)  #receive the text
	decoded = text.decode()
	print(decoded)
	last_col = decoded.split(':')[2]
	splitted = last_col.split()

	print("last_col=" + last_col)
	if len(splitted) > 2 and splitted[1] == '/':
		#print("splitted= " + splitted)
		print(splitted)
		result = round(math.sqrt(int(splitted[0])) * int(splitted[2]), 2)
		print(result)
		data = "PRIVMSG Candy : !ep1 -rep " + str(result) + "\n"
		irc.send(data.encode())
		text = irc.recv(2040)  #receive the text
		decoded = text.decode()
		print(decoded)

	#print("PRIVMSG+" + text.decode())   #print text to console
	