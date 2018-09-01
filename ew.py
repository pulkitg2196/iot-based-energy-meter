from time import sleep
import serial
from twilio.rest import Client 
 
ser = serial.Serial('/dev/ttyACM0',9600)
account_sid = 'ACd5f91dbd4231e431bbe657575e63b1c7' 
auth_token = 'b9bacc04fb690d16e1f7aa6785b4e139' 
client = Client(account_sid, auth_token) 
i=0
while True:
	a = ser.readline()
	b = ser.readline()
	c = a.decode('utf-8')
	d = b.decode('utf-8')
	print c
	print d
	if i==30:
		message = client.messages.create( 
                              from_='+17727636674',  
                              body='Your units consumed are : '+ str(c)+'\nYour bill is : '+str(d),      
                              to='+919041621721')
		i=0
	i=i+1
sleep(1)