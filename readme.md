### compile
- simply compile the client and the server project. Try to ignore the useless stuff


### features
- dynamically encrypted client-server communication over TCP sockets
- loader version check
- license only login system (with expiration and hwid binding)
- hwid blacklisting system
- easy license management
- Nice Design

### todo
- Delete The useless files(doesnt work for me)
- safer pid transfer
- security thread
- secured dll transfer
- more license management features
- add option to add time to all licenses at once
- better server UI
- type help in the server (for the idiots)

### setup
1. extract shared.rar
2. setup IP, port and version in includes.h (client) and includes.h (server)
3. add your application code in program.cpp
4. you may add another communication and stuff, well at this point you are good to go

### disclaimer
This was created as a fun project when I was bored over christmas, some code may be trash, feel free to change as you want. As mentioned in the code, only reason for not using an actual database is that not everyone knows how to work with sql.. Will add it later anyways.

### credits
- https://github.com/ex-ref/printa

### updates
- Next patch: fix anti reversing methods
