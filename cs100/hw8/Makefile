all: itClient itServer conClient conServer


itClient: itClient.o
	g++ itClient.o -o itClient
	
itClient.o: itClient.cc
	g++ -c itClient.cc
	
itServer: itServer.o
	g++ itServer.o -o itServer
	
itServer.o: itServer.cc
	g++ -c itServer.cc
	
conClient: conClient.o
	g++ conClient.o -o conClient

conClient.o: conClient.cc
	g++ -c conClient.cc
	
conServer: conServer.o
	g++ conServer.o -o conServer

conServer.o: conServer.cc
	g++ -c conServer.cc

clean: 
	rm itClient itClient.o itServer itServer.o conClient conClient.o conServer conServer.o
	
