SMART Energy
================================================

Descrição do Projeto
------------
Este é um projeto para automatizar o controle do consumo de energia elétrica.

Documentação da API
------------
A documentação completa da API em html pode ser encontrada em https://github.com/ElCasagrande/SMART-Energy/blob/master/doc/Documentation/html/ 

Utilizando a API.
------------
Para realizar a comunicação com nossa API ambos (Eg. Cliente e Servidor) devem estar em uma mesma conexão ethernet onde 
deve ser realizado uma requisição em formato JSON para poder ser processada por nossa API. 

A seguir uma descrição detalhada:

O retorno de todas as requisições é enviado em formato JSON, caso a requisição seja inválida, o seguinte retorno será enviado:
```json
{ "error": 1 }
```

# /status
Retorna a leitura do sensor de corrente, do sensor de tensão e o estado atual do sensor de movimento e dos relés.
* Parâmetros:
    - Não aceita nenhum parâmetro adicional
* Retorno:
```json
{ "v": 220, "c": 1250, "m": 0, "r1": 0, "r2": 1, "r3": 0, "r4": 0 }
```
* Onde:
    - v = Tensão do sistema
    - c = Corrente que o sistema está consumindo, em mA
    - m = Estado do sensor de movimento (1 = Ativo, 0 = Desativado)
    - rX = Estado do relé X (1 = Ativo, 0 = Desativado)

# /toggle
Inverte o estado de um relé.
> Obs: Ao inverter o estado de um relé que está associado ao sensor de movimento, o sensor de movimento é desativado.

* Parâmetros:
    - Número do relé que terá o seu estado invertido.
* Retorno:
```json
{ "s": 0 }
```
* Onde:
    - s = Estado atual do relé após a inversão (1 = Ativo, 0 = Desativado)
* Exemplo:
    - /toggle/3 = Inverte o estado do relé 3

# /motion
Ativa/desativa o sensor de movimento.
  
* Parâmetros:
    - Número do relé que terá o seu estado invertido após passar o período de tempo definido sem detectar nenhum movimento
    - Período de tempo (em segundos) para que a ação seja tomada        
* Retorno:
```json
{ "s": 0 }
```

* Onde:
    - s = Estado atual do sensor de movimento (1 = Ativo, 0 = Desativado)

* Exemplo:
    - /motion/0 = Desativa o sensor de movimento
    - /motion/1/10 = Ativa o sensor de movimento para o relé 1. Ação será tomada 10 segundos após a detecção do último movimento.
    - /motion/4/60 = Ativa o sensor de movimento para o relé 4. Ação será tomada 1 minuto após a detecção do último movimento.


Contact
-------

Lucas Casagrande  	(Github profile: https://github.com/ElCasagrande)

Guilherme Engler  	(Github profile: https://github.com/Engler)

Lucien Bartsch    	(Github profile: https://github.com/lucbart)

Andre Nass	    	(Github profile: https://github.com/AndreNass)

Elton Faust       	(Github profile: https://github.com/EltonFaust)

Geovani Figueira  	(Github profile: https://github.com/DJhova)

Rafael Cardoso 		(Github profile: )
