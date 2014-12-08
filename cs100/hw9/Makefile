all: multThreadClient threadRequestServ leaderFollowServ threadPoolServ


#servers
leaderFollowServ: leaderFollowServ.o
	g++ -pthread leaderFollowServ.o -o leaderFollowServ
	
leaderFollowServ.o: leaderFollowServ.cc
	g++ -c leaderFollowServ.cc

#=========================================================

threadRequestServ: threadRequestServ.o
	g++ -pthread threadRequestServ.o -o threadRequestServ
	
threadRequestServ.o: threadRequestServ.cc
	g++ -c threadRequestServ.cc

#=========================================================

threadPoolServ: threadPoolServ.o
	g++ -pthread threadPoolServ.o -o threadPoolServ
	
threadPoolServ.o: threadPoolServ.cc
	g++ -c threadPoolServ.cc
	
#=========================================================

#client
multThreadClient: multThreadClient.o
	g++ -pthread multThreadClient.o -o multThreadClient
	
multThreadClient.o: multThreadClient.cc timer.h
	g++ -c multThreadClient.cc 
	

clean:
	rm -r testdir* threadPoolServ threadPoolServ.o leaderFollowServ leaderFollowServ.o multThreadClient multThreadClient.o threadRequestServ threadRequestServ.o 
