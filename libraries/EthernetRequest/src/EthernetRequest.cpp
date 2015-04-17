/*
 * EthernetRequest.cpp - EthernetRequest library
 * Copyright (C) 2015-2016 Elton Faust  All rights reserved.
 */

//******************************************************************************
//* Includes
//******************************************************************************

#include "EthernetRequest.h"

//******************************************************************************
//* Constructors
//******************************************************************************

EthernetRequest::EthernetRequest() : server(80)
{
	this->currentUrl = "";
	this->currentMethod = EthernetRequest::UNKNOWN;
	this->answerValue = "";
}
//******************************************************************************
//* Public Methods
//******************************************************************************

void EthernetRequest::begin(byte mac[], byte ip[]) 
{
	Ethernet.begin(mac, ip);
	this->server.begin();
	Serial.println("Started");
}

bool EthernetRequest::isAvailable() 
{
	this->client = this->server.available();
	
	if(!this->client || !this->client.connected()) {
		return false;
	}
	
	this->currentUrl = "";
	this->currentMethod = EthernetRequest::UNKNOWN;
	this->answerValue = "";
	
	this->processRequest();
	
	return true;
}

uint8_t EthernetRequest::getMethod() 
{
	return this->currentMethod;
}

int EthernetRequest::getParam(uint8_t paramSeq) 
{
	if(paramSeq == 0 || paramSeq > 2)
		return 0;

	return this->params[paramSeq - 1];
}


void EthernetRequest::addString(String varName, String varValue) 
{
	this->addValue(varName, "\"" + varValue + "\"");
}

void EthernetRequest::addInt(String varName, int varValue) 
{
	this->addValue(varName, String(varValue));
}

void EthernetRequest::sendAnswer() 
{
	if (this->client.connected()) {
		this->client.println("HTTP/1.1 200 OK");
		this->client.println("Access-Control-Allow-Origin: *");
		this->client.println("Content-Type: text/html");
		this->client.println();
		
		if(this->answerValue != "") {
			this->client.print("{");
			this->client.print(this->answerValue);
			this->client.println("}");
		}
	
		delay(10);
		this->client.stop();
	}
}

//******************************************************************************
//* Private Methods
//******************************************************************************

void EthernetRequest::processRequest() 
{
	bool startedUrlRead = false;

	while (this->client.connected()) {
		if (this->client.available()) {
			char c = this->client.read();

			if(c == ' ') {
				if (!startedUrlRead) {
					startedUrlRead = true;
				} else {
					
					if (this->currentUrl.startsWith("/toggle")) {
						this->currentMethod = EthernetRequest::TOGGLE;
						this->currentUrl = this->currentUrl.substring(8);
						
					} else if(this->currentUrl.startsWith("/motion")) {
						this->currentMethod = EthernetRequest::MOTION;
						this->currentUrl = this->currentUrl.substring(8);
					} else if(this->currentUrl == "/status") {
						this->currentMethod = EthernetRequest::CHECK_STATUS;
						this->currentUrl = this->currentUrl.substring(8);
					} else {
						this->currentUrl = this->currentUrl.substring(1);
					}
					
					uint8_t lastParam = 0;
					String paramValue = "";
					bool isSeparator = false;
					
					int currentUrlLength = this->currentUrl.length();
					
					if (currentUrlLength > 0) {
						
						for (int cc = 0; cc < currentUrlLength; cc++) {
							
							isSeparator = this->currentUrl[cc] == '/';
							
							if (!isSeparator) {
								paramValue += this->currentUrl[cc];
							}
							
							if (isSeparator || (cc + 1) == currentUrlLength) {
								this->params[lastParam] = paramValue.toInt();
								
								paramValue = "";
								lastParam++;
								
								if (lastParam == 2) {
									break;
								}
								
							}
						}
						
						this->client.flush();
						break;
					}	
				}
			} else if (startedUrlRead) {
				this->currentUrl += c;
			}
		}
	}
}


void EthernetRequest::addValue(String varName, String varValue) 
{
	if(this->answerValue != "") {
		this->answerValue.concat(",");
	}
	
	this->answerValue.concat("\"" + varName + "\":" + varValue);
}

