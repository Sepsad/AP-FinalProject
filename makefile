CC := g++ --std=c++11

all: main.out



main.out : main.o Comment.o DataBase.o Money.o 
	${CC} main.o Comment.o DataBase.o Money.o User.o Publisher.o Tools.o Film.o Network.o Notification.o Rate.o Request.o RequestReader.o RequestHandler.o POSTHandler.o POSTHandleTools.o DELETEHandler.o GETHandler.o PUTHandler.o -o main.out


main.o : main.cpp Execute/Execute.h
	${CC} -c main.cpp -o main.o

Comment.o : Comment/Comment.h Comment/Reply.h User/User.h Film/Film.h Comment/Comment.cpp
	${CC} -c Comment/Comment.cpp -o Comment.o

DataBase.o : DataBase/DataBase.h DataBase/DataBase.cpp  Exceptions/Exceptions.h User/User.h Film/Film.h Money/Money.h DataBase/DataBase.cpp
	${CC} -c DataBase/DataBase.cpp -o DataBase.o

Money.o : User/User.h Film/Film.h Money/Money.h Money/Money.cpp
	${CC} -c Money/Money.cpp -o Money.o

User.o : User/User.h Film/Film.h Exceptions/Exceptions.h Notification/Notification.h User/User.cpp
	${CC} -c User/User.cpp -o User.o

Publisher.o : User/Publisher.h User/User.h Exceptions/Exceptions.h User/Publisher.cpp
	${CC} -c User/Publisher.cpp -o Publisher.o

Tools.o : Tools/Tools.h Exceptions/Exceptions.h Tools/Tools.cpp
	${CC} -c Tools/Tools.cpp -o Tools.o

Film.o : User/Publisher.h User/User.h Comment/Reply.h Comment/Comment.h Rate/Rate.h Tools/Tools.h Exceptions/Exceptions.h Film/Film.cpp
	${CC} -c Film/Film.cpp -o Film.o

Network.o :	Network/Network.h DataBase/DataBase.h User/User.h Network/Network.cpp
	${CC} -c Network/Network.cpp -o Network.o

Notification.o : Notification/Notification.h Notification/Notification.cpp
	${CC} -c Notification/Notification.cpp -o Notification.o

Rate.o : Rate/Rate.h User/User.h Rate/Rate.cpp
	${CC} -c Rate/Rate.cpp -o Rate.o

Request.o : Request/Request.h Request/Request.cpp
	${CC} -c Request/Request.cpp -o Request.o

RequestReader.o : Request/RequestReader/RequestReader.h Request/Request.h Exceptions/Exceptions.h Tools/Tools.h Request/RequestReader/RequestReader.cpp
	${CC} -c Request/RequestReader/RequestReader.cpp -o RequestReader.o

RequestHandler.o : Request/RequestHandler/RequestHandler.h Request/RequestHandler/POSTHandler/POSTHandler.h Request/RequestHandler/GETHandler/GETHandler.h Request/RequestHandler/PUTHandler/PUTHandler.h Request/RequestHandler/DELETEHandler/DELETEHandler.h Request/Request.h DataBase/DataBase.h Network/Network.h Request/RequestHandler/RequestHandler.cpp
	${CC} -c Request/RequestHandler/RequestHandler.cpp -o RequestHandler.o

POSTHandler.o : Request/RequestHandler/POSTHandler/POSTHandler.h Rate/Rate.h Notification/Notification.h Comment/Reply.h Comment/Comment.h  Money/Money.h Film/Film.h Network/Network.h User/User.h User/Publisher.h  Request/RequestHandler/POSTHandler/POSTHandler.cpp
	${CC} -c Request/RequestHandler/POSTHandler/POSTHandler.cpp -o POSTHandler.o

POSTHandleTools.o : Request/RequestHandler/POSTHandler/POSTHandleTools/POSTHandleTools.h Rate/Rate.h Notification/Notification.h Comment/Reply.h Comment/Comment.h  Money/Money.h Film/Film.h Network/Network.h User/User.h User/Publisher.h  Request/RequestHandler/POSTHandler/POSTHandleTools/POSTHandleTools.cpp
	${CC} -c Request/RequestHandler/POSTHandleTools/POSTHandler/POSTHandleTools.cpp -o POSTHandleTools.o

DELETEHandler.o : Request/RequestHandler/DELETEHandler/DELETEHandler.h  Rate/Rate.h Notification/Notification.h Comment/Reply.h Comment/Comment.h  Money/Money.h Film/Film.h Network/Network.h User/User.h User/Publisher.h Request/RequestHandler/DELETEHandler/DELETEHandler.cpp  
	${CC} -c Request/RequestHandler/DELTEHandler/DELETEHandler.cpp -o DELETEHandler.o

GETHandler.o : Request/RequestHandler/GETHandler/GETHandler.h  Rate/Rate.h Notification/Notification.h Comment/Reply.h Comment/Comment.h  Money/Money.h Film/Film.h Network/Network.h User/User.h User/Publisher.h Request/RequestHandler/GETHandler/GETHandler.cpp  
	${CC} -c Request/RequestHandler/DELTEHandler/GETHandler.cpp -o GETHandler.o

PUTHandler.o : Request/RequestHandler/PUTHandler/PUTHandler.h  Rate/Rate.h Notification/Notification.h Comment/Reply.h Comment/Comment.h  Money/Money.h Film/Film.h Network/Network.h User/User.h User/Publisher.h Request/RequestHandler/PUTHandler/PUTHandler.cpp  
	${CC} -c Request/RequestHandler/DELTEHandler/PUTHandler.cpp -o PUTHandler.o











	




clean:
	rm *.o 
	rm main.out