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
		/*! \fn void processRequest()
			\brief Processes all the request. Resolve the expected return and determines what to send back. \a.
		*/
		void addValue(String varName, String varValue);
		/*! \fn void addInt()
			\brief Add the name and value of the expected return to the response of requisition \a.
			\param varName - The return expected.
			\param varValue - The value readout.
		*/
		
		EthernetServer server; /*!< Holds the ethernet server */
		EthernetClient client; /*!< Holds the ethernet client */
		
		String currentUrl; /*!< Holds all the request */
		uint8_t currentMethod; /*!< Holds the method("what to do") passed on request */
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
		/*! \fn bool isAvailable()
			\brief Verify if the server is available \a.
			\return True if the server is available.
		*/
		
		uint8_t getMethod();
		int getParam(uint8_t paramSeq);
		/*! \fn int getParam()
			\brief Get the parameter passed on the requisition \a.
			\param paramSeq - The index of the array of parameters passed.
			\return The parameter passed on the requisition.
		*/
		
		void addString(String varName, String varValue);
		/*! \fn void addString()
			\brief Add a string with the name and value separated by "\" of the expected return to the  requisition \a.
			\param varName - The return expected.
			\param varValue - The value readout.
		*/
		void addInt(String varName, int varValue);
		/*! \fn void addInt()
			\brief Add the name and value of the expected return to the response of requisition \a.
			\param varName - The return expected.
			\param varValue - The value readout.
		*/
		
		void sendAnswer();
		/*! \fn void sendAnswer()
			\brief Send the answer of the requisition \a.
		*/
		
		enum{UNKNOWN, CHECK_STATUS, TOGGLE, MOTION};
};

#endif
