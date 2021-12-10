#include <iostream>
#include "GraphicsClient.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>


using namespace std;

GraphicsClient::GraphicsClient(){

URLname = "";
port = 0;
sockfd = 0;

}

/*Constructor with parameters*/
GraphicsClient::GraphicsClient (std::string URL, int portNum){

	URLname = URL;
	port = portNum;
	//Converts std to char*
	char* temp = &(URLname[0]);
	
	/*Connect to graphics server*/
    if (sockfd < 0)
    {
        fprintf( stderr, "Error creating socket\n");
        exit(-1);
        
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portNum);
    
    
    //Error Checking 
    if(inet_pton(AF_INET, temp, &serv_addr.sin_addr)<=0)
    {
        fprintf(stderr, "Invalid address/ Address not supported, terminate program and re-run! \n");
        
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "Connection Failed, terminate program and re-run!  \n");


    }
	
	
}

/*Copy Constructor*/
GraphicsClient::GraphicsClient (const GraphicsClient& origObj){
	
	port = origObj.port;
	URLname = origObj.URLname;
}

/*Destructor*/
GraphicsClient::~GraphicsClient(){
//cout << "Called";
close(this->sockfd);
}

/*Background Color*/
void GraphicsClient::setBackgroundColor(int R, int G, int B){



char message[100];
	
    //Initial Message with length and action	 
    message[0] = 0xFF;
    message[1] = 0x00;
    message[2] = 0x00;
    message[3] = 0x00;
    message[4] = 0x07;
    message[5] = 0x02;
    
    //"Converts" RGB to hex according to document
    message[6] = (R >> 4) & 0x0F;
    message[7] = R & 0x0F;
    message[8] = (G >> 4) & 0x0F;
    message[9] = G & 0x0F;
    message[10] = (B >> 4) & 0x0F;
    message[11] = B & 0x0F;
  

    send(this->sockfd, message, 12, 0);
    


    //close(sockfd);

}

/*Draw Color*/
void GraphicsClient::setDrawingColor(int R, int G, int B){
	 
    char message[100];
    //Initial Message with length and action	 
    message[0] = 0xFF;
    message[1] = 0x00;
    message[2] = 0x00;
    message[3] = 0x00;
    message[4] = 0x07;
    message[5] = 0x06;
    
    //"Converts" RGB to hex according to document
  
    message[6] = (R >> 4) & 0x0F;
    message[7] = R & 0x0F;
    message[8] = (G >> 4) & 0x0F;
    message[9] = G & 0x0F;
    message[10] = (B >> 4) & 0x0F;
    message[11] = B & 0x0F;

    send(this->sockfd, message, 12, 0);


}

/*Called after when changing background color*/
void GraphicsClient::clear(){

	//Initial Message with length and action
	 char message[100];
	 message[0] = 0xFF;
	 message[1] = 0x00;
	 message[2] = 0x00;
	 message[3] = 0x00;
	 message[4] = 0x01;
	 message[5] = 0x01;
	 send(this->sockfd, message, 6, 0);
 
}

/*Set Pixel at location*/
void GraphicsClient::setPixel (int x, int y, int R, int G, int B){

	//Initial Message with length and action
	char message [100];
	message[0] = 0xFF;
	message[1] = 0x00;
	message[2] = 0x00;
	message[3] = 0x00;
	message[4] = 0x0F;
	
	message[5] = 0x03;
	
	
	
	//Converts x and y coordinates along with RGB to nibbles and sends to graphic server at pos(x,y)
	message[6] = (x >> 12) & 0x0F;
	message[7] = (x >> 8) & 0x0F;
	message[8] = (x >> 4) & 0x0F;
	message[9] = x & 0x0F;
	

	message[10] = (y >> 12) & 0x0F;
	message[11] = (y >> 8) & 0x0F;
	message[12] = (y >> 4) & 0x0F;
	message[13] = y & 0x0F;
	
	message[14] = (R >> 4) & 0x0F;
    	message[15] = R & 0x0F;
   	message[16] = (G >> 4) & 0x0F;
   	message[17] = G & 0x0F;
   	message[18] = (B >> 4) & 0x0F;
   	message[19] = B & 0x0F;
   	
   	
	
	send(this->sockfd, message, 30, 0);
	

}

/*Draw a rectangle*/
void GraphicsClient::drawRectangle(int x, int y, int width, int height){
	//Initial Message with length and action
	char message [100];
	message[0] = 0xFF;
	message[1] = 0x00;
	message[2] = 0x00;
	message[3] = 0x01;
	message[4] = 0x01;
	message[5] = 0x07;
	
	
	
	//Converts x and y coordinates along with width and height to nibbles and sends to graphic server
	message[6] = (x >> 12) & 0x0F;
	message[7] = (x >> 8) & 0x0F;
	message[8] = (x >> 4) & 0x0F;
	message[9] = x & 0x0F;
	

	message[10] = (y >> 12) & 0x0F;
	message[11] = (y >> 8) & 0x0F;
	message[12] = (y >> 4) & 0x0F;
	message[13] = y & 0x0F;
	
	message[14] = (width >> 12) & 0x0F;
	message[15] = (width >> 8) & 0x0F;
	message[16] = (width >> 4) & 0x0F;
	message[17] = width & 0x0F;
	
	message[18] = (height >> 12) & 0x0F;
	message[19] = (height >> 8) & 0x0F;
	message[20] = (height >> 4) & 0x0F;
	message[21] = height & 0x0F;
	
	send(this->sockfd, message, 22, 0);
	
	

}

/*Fill in a drawn rectangle*/
void GraphicsClient::fillRectangle(int x, int y, int width, int height){

	//Initial Message with length and action
	char message [100];
	message[0] = 0xFF;
	message[1] = 0x00;
	message[2] = 0x00;
	message[3] = 0x01;
	message[4] = 0x01;
	message[5] = 0x08;
	
	
	
	//Fills a rectangle at x and y coordinates along with width and height to nibbles and sends to graphic server, usually used after drawRectangle()
	message[6] = (x >> 12) & 0x0F;
	message[7] = (x >> 8) & 0x0F;
	message[8] = (x >> 4) & 0x0F;
	message[9] = x & 0x0F;
	

	message[10] = (y >> 12) & 0x0F;
	message[11] = (y >> 8) & 0x0F;
	message[12] = (y >> 4) & 0x0F;
	message[13] = y & 0x0F;
	
	message[14] = (width >> 12) & 0x0F;
	message[15] = (width >> 8) & 0x0F;
	message[16] = (width >> 4) & 0x0F;
	message[17] = width & 0x0F;
	
	message[18] = (height >> 12) & 0x0F;
	message[19] = (height >> 8) & 0x0F;
	message[20] = (height >> 4) & 0x0F;
	message[21] = height & 0x0F;
	
	send(this->sockfd, message, 22, 0);
	
}

/*Clear whatever is in rectangle*/
void GraphicsClient::clearRectangle(int x, int y, int width, int height){

	//Initial Message with length and action
	char message [100];
	message[0] = 0xFF;
	message[1] = 0x00;
	message[2] = 0x00;
	message[3] = 0x01;
	message[4] = 0x01;
	message[5] = 0x09;
	
	
	
	//Clears a rectangle at x and y coordinates along with width and height to nibbles and sends to graphic server
	message[6] = (x >> 12) & 0x0F;
	message[7] = (x >> 8) & 0x0F;
	message[8] = (x >> 4) & 0x0F;
	message[9] = x & 0x0F;
	

	message[10] = (y >> 12) & 0x0F;
	message[11] = (y >> 8) & 0x0F;
	message[12] = (y >> 4) & 0x0F;
	message[13] = y & 0x0F;
	
	message[14] = (width >> 12) & 0x0F;
	message[15] = (width >> 8) & 0x0F;
	message[16] = (width >> 4) & 0x0F;
	message[17] = width & 0x0F;
	
	message[18] = (height >> 12) & 0x0F;
	message[19] = (height >> 8) & 0x0F;
	message[20] = (height >> 4) & 0x0F;
	message[21] = height & 0x0F;
	
	send(this->sockfd, message, 22, 0);
}

/*Draw an empty oval*/
void GraphicsClient::drawOval(int x, int y, int width, int height){

	//Initial Message with length and action
	char message [100];
	message[0] = 0xFF;
	message[1] = 0x00;
	message[2] = 0x00;
	message[3] = 0x01;
	message[4] = 0x01;
	message[5] = 0xA;
	
	
	
	//Creates an oval at x and y coordinates along with width and height to nibbles and sends to graphic server
	message[6] = (x >> 12) & 0x0F;
	message[7] = (x >> 8) & 0x0F;
	message[8] = (x >> 4) & 0x0F;
	message[9] = x & 0x0F;
	

	message[10] = (y >> 12) & 0x0F;
	message[11] = (y >> 8) & 0x0F;
	message[12] = (y >> 4) & 0x0F;
	message[13] = y & 0x0F;
	
	message[14] = (width >> 12) & 0x0F;
	message[15] = (width >> 8) & 0x0F;
	message[16] = (width >> 4) & 0x0F;
	message[17] = width & 0x0F;
	
	message[18] = (height >> 12) & 0x0F;
	message[19] = (height >> 8) & 0x0F;
	message[20] = (height >> 4) & 0x0F;
	message[21] = height & 0x0F;
	
	send(this->sockfd, message, 22, 0);
}

/*Fill an oval*/
void GraphicsClient::fillOval(int x, int y, int width, int height){

	//Initial Message with length and action
	char message [100];
	message[0] = 0xFF;
	message[1] = 0x00;
	message[2] = 0x00;
	message[3] = 0x01;
	message[4] = 0x01;
	message[5] = 0xB;
	
	
	
	//Fills in an oval at x and y coordinates along with width and height to nibbles and sends to graphic server
	message[6] = (x >> 12) & 0x0F;
	message[7] = (x >> 8) & 0x0F;
	message[8] = (x >> 4) & 0x0F;
	message[9] = x & 0x0F;
	

	message[10] = (y >> 12) & 0x0F;
	message[11] = (y >> 8) & 0x0F;
	message[12] = (y >> 4) & 0x0F;
	message[13] = y & 0x0F;
	
	message[14] = (width >> 12) & 0x0F;
	message[15] = (width >> 8) & 0x0F;
	message[16] = (width >> 4) & 0x0F;
	message[17] = width & 0x0F;
	
	message[18] = (height >> 12) & 0x0F;
	message[19] = (height >> 8) & 0x0F;
	message[20] = (height >> 4) & 0x0F;
	message[21] = height & 0x0F;
	
	send(this->sockfd, message, 22, 0);
}

/*Create a line*/
void GraphicsClient::drawLine(int x1, int y1, int x2, int y2){

	//Initial Message with length and action
	char message [100];
	message[0] = 0xFF;
	message[1] = 0x00;
	message[2] = 0x00;
	message[3] = 0x01;
	message[4] = 0x01;
	message[5] = 0xD;
	
	//Sends a draw message to the server, creates a line from (x1, y1) to (x2, y2)
	message[6] = (x1 >> 12) & 0x0F;
	message[7] = (x1 >> 8) & 0x0F;
	message[8] = (x1 >> 4) & 0x0F;
	message[9] = x1 & 0x0F;
	

	message[10] = (y1 >> 12) & 0x0F;
	message[11] = (y1 >> 8) & 0x0F;
	message[12] = (y1 >> 4) & 0x0F;
	message[13] = y1 & 0x0F;
	
	message[14] = (x2 >> 12) & 0x0F;
	message[15] = (x2 >> 8) & 0x0F;
	message[16] = (x2 >> 4) & 0x0F;
	message[17] = x2 & 0x0F;
	
	message[18] = (y2 >> 12) & 0x0F;
	message[19] = (y2 >> 8) & 0x0F;
	message[20] = (y2 >> 4) & 0x0F;
	message[21] = y2 & 0x0F;
	
	send(this->sockfd, message, 22, 0);

}

/*Insert a string on the board*/
void GraphicsClient::drawString(int x, int y, string word){

 char message[100];
 int length = (2 * word.length()) + 9;
 
 //i,j is set after for messages after x,y coordinates
 int i = 14;
 int j = 15;
 int a = 0;
 
   //Sends a string at location (x,y) to the graphics server
   message[0] = 0xFF;
   
   message[1] = (length >> 12) & 0x0F;
   message[2] = (length >> 8) & 0x0F;
   message[3] = (length >> 4) & 0x0F;
   message[4] = length & 0x0F;
   
   message[5] = 0x05;
   
   //Sets location for string at pos (x,y)
   message[6] = (x >> 12) & 0x0F;
   message[7] = (x >> 8) & 0x0F;
   message[8] = (x >> 4) & 0x0F;
   message[9] = x & 0x0F;
	

   message[10] = (y >> 12) & 0x0F;
   message[11] = (y >> 8) & 0x0F;
   message[12] = (y >> 4) & 0x0F;
   message[13] = y & 0x0F;
  
   
   //Splits string into 2 bytes and sends to graphic server 
   for (char &c : word){
   message[i++] = (c >> 4) & 0x0F;
   i++;
   message[j++] = c & 0x0F;
   j++;
   }
   
   send(this->sockfd, message, (j - 1), 0);
 
	
}

/*Method to make the image on the board/canvas*/
void GraphicsClient::repaint(){

   char message[100];
 
   //Sends a repaint message to the server, displaying contents of called actions
   message[0] = 0xFF;
   message[1] = 0x00;
   message[2] = 0x00;
   message[3] = 0x00;
   message[4] = 0x01;
   message[5] = 0x0C;
   send(this->sockfd, message, 6, 0);
 
}


void GraphicsClient::fileMessage(){
   char message1[100];
 
   //Sends a "file browser" message to server
   message1[0] = 0xFF;
   message1[1] = 0x00;
   message1[2] = 0x00;
   message1[3] = 0x00;
   message1[4] = 0x01;
   message1[5] = 0x0E;
   
   send(this->sockfd, message1, 6, 0);
   
}

bool GraphicsClient::inRectangle(int x1, int y1, int x2, int y2){
if (this->x > x1 && this->x < x2 && this->y > y1 && this->y < y2){
return true;
}
return false;
}






