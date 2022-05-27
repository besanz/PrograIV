gcc lib/sqlite3/sqlite3.c src/db/c/getData.c src/db/c/postData.c src/db/connect/connect.c -c

g++ src/main/start.cpp src/main/c/menu.cpp src/main/c++/getdata.cpp src/main/c++/postdata.cpp src/proyecto/cliente/MainCliente.cpp src/proyecto/cliente/Socket.cpp src/proyecto/servidor/Servidor.cpp -c -lws2_32

g++ sqlite3.o getData.o postData.c start.o menu.o MainCliente.o Socket.o Servidor.o -o main

del *.o

.\main