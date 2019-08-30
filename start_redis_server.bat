set BASE_DIR=%~dp0
%BASE_DIR:~0,2%
cd %BASE_DIR%
::call cmd.exe
.\redis-server.exe --service-stop
.\redis-server.exe --service-uninstall
.\redis-server.exe --service-install .\redis.windows-service.conf --loglevel verbose
.\redis-server.exe --service-start
pause