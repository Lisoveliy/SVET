<p align="center">
  <img src="https://github.com/Lisoveliy/SVET/blob/master/logo-sized.png?raw=true" alt="logotype: SVET" width="50%" height="50%"/>
</p>

### Super-Visor ESP Tools - library add-on for ESP to create a simple web infrastructure, work with Wi-Fi, Web and EEPROM(flash) (you can call it CMS)
  
## What is it?/Что это?

#### EN
SVET(sweet/SVIET) is a library for simplifying the creation of smart home devices or devices that need a Wi-Fi connection and a Web interface. It provides interfaces for creating your own Web environment, making it easier to connect to Wi-Fi and work with device states.
<hr>

#### RU
SVET(свит/свет) это библиотека для упрощения создания устройств умного дома или устройств которым нужно подключение по Wi-Fi и Web-интерфейс. Она предоставляет интерфейсы для создания своего Web окружения, упрощения подключению к Wi-Fi и работы с состояниями устройства.


## Library structure/Устройство библиотеки

<p align="center">
  <img src="https://github.com/Lisoveliy/SVET/blob/master/docs/MainArchitecture.drawio.svg?raw=true" alt="Main Architecture"/>
</p>

Для подробной информации о работе библиотеки и начала работы обратитесь к [глоссарию](/docs/ru/misc/glossary.md)!

## Requirements and Limitations/Требования и ограничения

#### EN
SVET is being written and tested on <strong>ESP8266(NodeMCU v3 (ESP-12E))</strong> in the PlatformIO environment and using the <strong>Arduino framework</strong> (More about the Arduino framework for ESP - https://github.com/esp8266/Arduino). This means that full stability is possible if the following requirements are met:

- Development on the PlatformIO IDE
- Using <Arduino.h> (https://github.com/esp8266/Arduino)
- ESP8266 (Preferably ESP-12E)

Problems related to this stack will be considered more priority than when using other microcontrollers, programmers, firmware, IDE, SDK, etc.
<hr>

#### RU
SVET пишется и тестируется на <strong>ESP8266(NodeMCU v3 (ESP-12E))</strong> в окружении PlatformIO и с использованием <strong>фреймворка Arduino</strong>(Подробнее о фреймворке Arduino под ESP - https://github.com/esp8266/Arduino). Это означает что полная работоспособность возможна при соблюдении следующих требований:

- Разработка под PlatformIO IDE
- Использование <Arduino.h> (https://github.com/esp8266/Arduino)
- ESP8266 (Желательно ESP-12E)

Проблемы связанные с данным стеком будут рассматриваться приоритетнее чем при использовании других микроконтроллеров, программаторов, прошивальщиков, IDE, SDK и прочее.

