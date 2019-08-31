cls
g++ -c main.cpp nodo.h nodo.cpp listaenc.h listaenc.cpp arvorebin.h arvorebin.cpp
g++ main.o nodo.o listaenc.o arvorebin.o -o "com_arvores"
del *.o
del *.gch
pause
com_arvores.exe