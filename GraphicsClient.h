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
	
	
private:
	int port;
	std::string URLname;
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//GraphicsClient GC;
	
	
	

};

#endif
