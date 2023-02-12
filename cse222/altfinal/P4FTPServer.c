#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/sendfile.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(int argc,char *argv[])
{
        struct sockaddr_in server, client;
        struct stat obj;

        int socket1, socket2;

        char buf[100], command[5], filename[20];

        int k, i, size, len, c;

        int filehandle;
        
        socket1 = socket(AF_INET, SOCK_STREAM, 0);
        if(socket1 == -1)
        {
                printf("Socket creation failed");
                exit(1);
        }
        server.sin_port = atoi(argv[1]);
        server.sin_addr.s_addr = 0;
        k = bind(socket1,(struct sockaddr*)&server,sizeof(server));
        if(k == -1)
        {
                printf("Binding error");
                exit(1);
        }
        k = listen(socket1,1);
        if(k == -1)
        {
                printf("Listen failed");
                exit(1);
        }
        len = sizeof(client);
        socket2 = accept(socket1,(struct sockaddr*)&client, &len);
        i = 1;
        while(1)
        {
                recv(socket2, buf, 100, 0);
                sscanf(buf, "%s", command);
                if(!strcmp(command, "ls"))
                {
                        system("ls >temps.txt");
                        i = 0;
                        stat("temps.txt",&obj);
                        size = obj.st_size;
                        send(socket2, &size, sizeof(int),0);
                        filehandle = open("temps.txt", O_RDONLY);
                        sendfile(socket2,filehandle,NULL,size);
                }
                else if(!strcmp(command,"get"))
                {
                        sscanf(buf, "%s%s", filename, filename);
                        stat(filename, &obj);
                        filehandle = open(filename, O_RDONLY);
                        size = obj.st_size;
                        if(filehandle == -1)
                                size = 0;
                                send(socket2, &size, sizeof(int), 0);
                        if(size)
                                sendfile(socket2, filehandle, NULL, size);

                }
                else if(!strcmp(command, "put"))
                {
                        int c = 0, len;
                        char *f;
                        sscanf(buf+strlen(command), "%s", filename);
                        recv(socket2, &size, sizeof(int), 0);
                        i = 1;
                        while(1)
                        {
                                filehandle = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0666);
                                if(filehandle == -1)
                                {
                                        sprintf(filename + strlen(filename), "%d", i);
                                }
                                else
                                        break;
                        }
                        f = malloc(size);
                        recv(socket2, f, size, 0);
                        c = write(filehandle, f, size);
                        close(filehandle);
                        send(socket2, &c, sizeof(int), 0);
                }
                else if(!strcmp(command, "pwd"))
                {
                        system("pwd>temp.txt");
                        i = 0;
                        FILE*f = fopen("temp.txt","r");
                        while(!feof(f))
                        buf[i++] = fgetc(f);
                        buf[i-1] = '\0';
                        fclose(f);
                        send(socket2, buf, 100, 0);
                }
                else if(!strcmp(command, "cd"))
                {
                        if(chdir(buf+3) == 0)
                                c = 1;
                        else
                                c = 0;
                        send(socket2, &c, sizeof(int), 0);
                }


                else if(!strcmp(command, "bye") || !strcmp(command, "quit"))
                {
                        printf("FTP server quitting..\n");
                        i = 1;
                        send(socket2, &i, sizeof(int), 0);
                        exit(0);
                }
        }
        return 0;
}
