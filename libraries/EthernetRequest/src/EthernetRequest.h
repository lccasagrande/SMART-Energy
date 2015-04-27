/**
 * \class EthernetRequest
 * \brief This class allows a interface management to do communication by ethernet
 * with an Arduino or any kind of micro controller.
 *
 *
 * \author Elton Faust
 * \version 1.0
 * \since 2015-04-11
**/


#include <SPI.h>
#include <Ethernet.h>

#ifndef ETHERNET_REQUEST_H
#define ETHERNET_REQUEST_H

class EthernetRequest{
	private:
		void processRequest();
		void addValue(String varName, String varValue);
		
		EthernetServer server; /*!< Holds the ethernet server */
		EthernetClient client; /*!< Holds the ethernet client */
		
		String currentUrl; 
		uint8_t currentMethod; 
		int params[2]; /*!< Holds the parameters passed on request */
		
		String answerValue; /*!< Holds the formatted response to the request */
		
	public:
		EthernetRequest();
		/*! \fn EthernetRequest()
			\brief Initializes the variables \a.
		*/
		
		void begin(byte mac[], byte ip[]);
		/*! \fn void begin()
			\brief Start the communication with the parameters specified \a.
			\param mac - The mac address.
			\param ip - The IP.
		*/
		bool isAvailable();		
		uint8_t getMethod();
		int getParam(uint8_t paramSeq);
		void addString(String varName, String varValue);
		void addInt(String varName, int varValue);		
		void sendAnswer();
		
		enum{UNKNOWN, CHECK_STATUS, TOGGLE, MOTION};
};

#endif
