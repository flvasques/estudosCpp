cls
g++ -c main.cpp arvoreavl.h arvoreavl.cpp
g++ main.o arvoreavl.o -o "com_arvores"
del *.o
del *.gch
pause
com_arvores.exe