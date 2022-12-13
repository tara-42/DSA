cls

@echo.
@echo ------ TEST1 ------
@echo ------ TEST1 ------
@echo ------ TEST1 ------
gcc -std=c99 -o a.exe test1.c parse.c
a.exe


@echo.
@echo ------ TEST2 ------
@echo ------ TEST2 ------
@echo ------ TEST2 ------
gcc -std=c99 -o b.exe test2.c infix.c stack.c parse.c
b.exe

@echo.
@echo ------ TEST3 ------
@echo ------ TEST3 ------
@echo ------ TEST3 ------
gcc -std=c99 -o c.exe test3.c prefix.c stack.c parse.c
c.exe

echo ------ CLEANUP------

del a.exe
del b.exe
del c.exe
