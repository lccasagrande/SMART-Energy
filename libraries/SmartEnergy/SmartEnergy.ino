#include <SPI.h>
#include <Ethernet.h>
#include <EthernetRequest.h>
#include <VoltageSensor.h>
#include <RelayShield.h>
#include <Config.h>
#include <CurrentSensor.h>
#include <MotionSensor.h>

CurrentSensor currentSensor;
VoltageSensor voltageSensor;
MotionSensor motionSensor;

RelayShield relayShield;
EthernetRequest request;

void setup()
{
	Serial.begin(9600);
	
	// Inicializa o RelayShield
	int relayOutput[] = RELAY_OUTPUT;
	relayShield.begin(relayOutput);
	
	// Inicializa o CurrentSensor
	currentSensor.begin(CURRENT_SENSOR_INPUT);

	// Inicializa o VoltageSensor
	voltageSensor.begin(VOLTAGE_SENSOR_INPUT);

	// Inicializa o MotionSensor
	motionSensor.begin(MOTION_SENSOR_INPUT);

	// Inicializa a interface de comunicação
	byte mac[] = MAC_ADDRESS;
	byte ip[] = IP_ADDRESS;
	request.begin(mac, ip);

	// Delay de inicializacão
	delay(250);
}

void loop()
{
	// Atualiza o sensor de corrente
	currentSensor.update();
	
	// Atualiza o sensor de tensão
	voltageSensor.update();
	
	// Atualiza o sensor de movimento
	motionSensor.update();
	
	
	// Verifica se alguma ação é necessária em relação ao sensor de movimento
	if (motionSensor.read()) {
		relayShield.getRelay(motionSensor.getRelay())->toggleState();
		motionSensor.stop();
	}
	
	// Verifica se alguma requisição foi recebida
	if (request.isAvailable()) {
		
		switch(request.getMethod()) {
			
			case EthernetRequest::CHECK_STATUS:
				
				request.addInt("v", voltageSensor.read());
				
				if (relayShield.anyRelayActivated()) {
					request.addInt("c", currentSensor.read());
				} else {
					request.addInt("c", 0);
				}
				
				request.addInt("m", motionSensor.getRelay() > 0 ? 1 : 0);
				
				for (int i = 1; i <= MAX_RELAY_QUANTITY; i++) {
					request.addInt("r" + String(i), relayShield.getRelay(i)->activated() ? 1 : 0);
				}
				
				break;
				
			case EthernetRequest::TOGGLE:
			
				if (relayShield.acceptableRelayIndex(request.getParam(1))) {
					
					if (motionSensor.getRelay() == request.getParam(1)) {
						motionSensor.stop();
					}
					
					request.addInt("s", relayShield.getRelay(request.getParam(1))->toggleState() ? 1 : 0);
				} else {
					request.addInt("error", 1);
				}
				
				break;
				
			case EthernetRequest::MOTION:
			
				if (request.getParam(1) == 0) {
					
					motionSensor.stop();
					request.addInt("s", 0);
					
				} else if(relayShield.acceptableRelayIndex(request.getParam(1)) && request.getParam(2) > 0) {
					
					motionSensor.start(request.getParam(2), request.getParam(1));
					request.addInt("s", 1);
					
				} else {
					request.addInt("error", 1);
				}
			
				break;
				
			case EthernetRequest::UNKNOWN:
			
				request.addInt("error", 1);
			
				break;
		}
		
		request.sendAnswer();
	}
	
}
