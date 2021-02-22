cls
g++ -c main.cpp arvorebin.h arvorebin.cpp
g++ main.o arvorebin.o -o "com_arvores"
del *.o
del *.gch
pause
com_arvores.exe