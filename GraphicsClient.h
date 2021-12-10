#ifndef GC_H
#define GC_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>


using namespace std;

class GraphicsClient {

public:
	GraphicsClient();
	GraphicsClient(std::string, int);
	GraphicsClient(const GraphicsClient& origObj);
	~GraphicsClient();
	GraphicsClient& operator=(const GraphicsClient& objCopy);
	void setBackgroundColor(int, int, int);
	void setDrawingColor(int, int, int);
	void clear();
	void setPixel (int, int, int, int, int);
	void drawRectangle(int, int, int, int);
	void fillRectangle(int, int, int, int);
	void clearRectangle(int, int, int, int);
	void drawOval(int, int, int, int);
	void fillOval(int, int, int, int);
	void drawLine(int, int, int, int);
	void drawString(int, int, string);
	void repaint();
	void mousePress();
	void fileMessage();
	int getX(){return x;};
	int getY(){return y;};
	bool inRectangle(int, int, int, int);
	char* getFileName(){return fileName;};
	void setX(int xC){ x = xC;}; 
	void setY(int yC){ y =yC;};
	int getsockfd(){return sockfd;};
	
	
private:
	int port;
	std::string URLname;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//GraphicsClient GC;
	int x,y, mouseType, countM;
	char* fileName;
	
	
	

};

#endif
