/*
 * Copyright (C) 2007 Tadeus Prastowo
 * Copyright (C) 2017 - 2020 Rahmat M. Samik-Ibrahim
 * http://rahmatm.samik-ibrahim.vlsm.org/
 * This program is free script/software. This program is distributed in the 
 * hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * REV04 Sun May  3 07:59:57 WIB 2020
 * REV03 Wed Feb 27 19:21:44 WIB 2019
 * REV02 Wed Aug 29 20:54:25 WIB 2018
 * REV01 Wed Nov  8 20:00:02 WIB 2017
 * START 2007
 *
 * This program serves as both a client and a server. Three modes of
 * operation are available:
 *  - initiating mode
 *  - bridging mode
 *  - terminating mode
 *
 * The following are how to run thisprogram for each mode:
 *  - Initiating mode:  client_server null ANOTHER_HOST ANOTHER_PORT
 *  - Bridging mode:    client_server CURRENT_PORT ANOTHER_HOST ANOTHER_PORT
 *  - Terminating mode: client_server CURRENT_PORT null null
 *
 * The program having the initiating mode _MUST_ run last after all other
 * instances of this program with other operational modes has been started.
 *
 * In initiating mode, this program just simply sends a hello message to
 * another instance of this program that operates either as a bridge or
 * as a terminator that this program points to as specified in
 * ANOTHER_HOST and ANOTHER_PORT. After that this program will quit
 * without printing out any message.
 *
 * In bridging mode, this program just simply waits for an incoming hello
 * message in CURRENT_PORT. Once it receives a hello message, it prints
 * out the message in a certain format. Next, this program forwards the
 * modified message to another instance of this program that acts either as
 * a bridge or as a terminator that this program points to as specified
 * in ANOTHER_HOST and ANOTHER_PORT. After that this program will quit.
 *
 * In terminating mode, this program just simply waits for an incoming hello
 * message in CURRENT_PORT. Once it receives a hello message, it prints out
 * the message in a certain format, and then quits.
 *
 * The following illustrates the idea above:
 * 192.168.10.18 (alvin)
 * $ ./client_server 8888 localhost 7777
 * 192.168.10.18 (user)$
 * $ ./client_server 7777 null null
 * 192.168.12.17 (eus)$
 * $ ./client_server null 192.168.10.18 8888
 * The print out will be:
 * 192.168.10.18 (alvin):
 *   From eus to alvin: Hello
 * 192.168.10.18 (user):
 *   From eus to alvin to user: Hello
 */


char pesan[]="[FROM SERVER] ACK MESSAGE...\n";
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct sockaddr    sockad;
typedef struct sockaddr_in sockadin;
typedef struct hostent     shostent;

void error(char *msg){
   perror(msg);
   exit(0);
}

#define BUFFER_SIZE 4096

int main(int argc, char *argv []) {
   int sockfd, newsockfd, portno, clilen, count, nn, sysup;
   char buffer [BUFFER_SIZE], temp_buffer [BUFFER_SIZE], *colon_pos;
   struct sockaddr_in serv_addr, cli_addr;
   struct hostent *server;
   struct timeval tval;

   if (argc < 4) {
      fprintf (stderr,"\nUsage: %s this_port  next_sever next_server_port\n\n"
               "Start the chain with `this_port' = `null'\n\n"
               "Terminte the chain with `next_server' = `next_server_port'"
               " = `null'\n\n", argv [0]);
      exit (1);
   }
   if (strcmp (argv [1], "null") == 0) {
      portno = atoi   (argv [3]);
      sockfd = socket (AF_INET, SOCK_STREAM, 0);
      if (sockfd < 0) {
         error ("ERROR opening socket");
      }
      int enable = 1;
      if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, 
         &enable, sizeof(int)) < 0)
         error("setsockopt(SO_REUSEADDR) failed");
      server = gethostbyname(argv[2]);
      if (server == NULL) {
         fprintf (stderr, "ERROR, no such host\n");
         exit (1);
      }
      memset (&serv_addr, 0, sizeof (serv_addr));
      serv_addr.sin_family = AF_INET;
      memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
      serv_addr.sin_port = htons(portno);
      if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))< 0){
         error ("ERROR connecting");
      }
      /* Begin: action */
      memset (buffer, 0, BUFFER_SIZE);
      gettimeofday(&tval,NULL);
      sysup = 0x0000FFFF & (int) (tval.tv_sec * 1000 + tval.tv_usec / 1000);
      snprintf (buffer, BUFFER_SIZE, "From\n%s[%d]:", getenv ("USER"), sysup);
      nn = write (sockfd, buffer, strlen (buffer));
      if (nn < 0) {
        error ("ERROR writing to socket");
      }
      /* End: action */
      exit (0);
   }

   sockfd = socket(AF_INET,SOCK_STREAM,0);
   if (sockfd < 0) {
      error ("ERROR opening socket");
   }
   int enable = 1;
   if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, 
      &enable, sizeof(int)) < 0)
      error("setsockopt(SO_REUSEADDR) failed");
   memset(&serv_addr,0,sizeof(serv_addr));
   portno = atoi (argv [1]);
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons (portno);
   if (bind (sockfd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
      error ("ERROR on binding");
   }
   listen (sockfd, 5);
   clilen    = sizeof (cli_addr);
   newsockfd = accept (sockfd, (struct sockaddr *) &cli_addr,
               (socklen_t *) &clilen);
   if (newsockfd < 0) {
      error ("ERROR on accept");
   }
   memset (buffer, 0, BUFFER_SIZE);
   nn = read(newsockfd,buffer,BUFFER_SIZE-1);
   if (nn < 0) {
      error ("ERROR reading from socket");
   }
   /* Modify buffer's message */
   colon_pos = strchr (buffer, ':');
   nn        = colon_pos - buffer;
   memset (temp_buffer, 0, BUFFER_SIZE);
   strncpy (temp_buffer, buffer, nn);
   memset (buffer, 0, BUFFER_SIZE);
   strncpy (buffer, temp_buffer, nn);
   for (long ii=0; ii<5000000L; ii++)
      ; // delay
   gettimeofday(&tval,NULL);
   sysup = 0x0000FFFF & (int) (tval.tv_sec * 1000 + tval.tv_usec / 1000);
   snprintf (buffer + nn, BUFFER_SIZE-nn, " to\n%s[%d]:\nEndOfMessage!", getenv ("USER"), sysup);
   /*End of modifying buffer's message*/
   if (strcmp (argv [2], "null") != 0 && strcmp (argv [3], "null") != 0) {
      portno = atoi (argv [3]);
      sockfd=socket(AF_INET,SOCK_STREAM,0);
      if (sockfd < 0) {
         error ("ERROR opening socket");
      }
      server = gethostbyname (argv [2]);
      if (server == NULL) {
         fprintf (stderr, "ERROR, no such host\n");
         exit (1);
      }
      serv_addr.sin_family = AF_INET;
      memcpy (&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
      serv_addr.sin_port = htons (portno);
      if (connect (sockfd,(struct sockaddr *)&serv_addr,sizeof (serv_addr))<0){
         error ("ERROR connecting");
      }
      /* Begin: action */
      printf ("%s\n", buffer);
      nn=write(sockfd,buffer,strlen(buffer));
      if (nn < 0) {
        error ("ERROR writing to socket");
      }
      /* End: action */
   } else {
      printf ("%s\n", buffer);
   }
   return 0;
}
