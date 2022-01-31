---
title: "CONTROLLO TEMPERATURA DI UN PICCOLO AMBIENTE"
permalink: /
layout: default
---

# Sensore LM35
- Alimentazione **5V**
- Sensibilità **10mV/ °C**
- Precisione **0,5°C**
- C1 **47µF**
- C2 **110nF**


# Circuito di condizionamento
- Filtro passa basso RC con ft **7Hz**
	- R1 **10KΩ**
	- C3 **2,2nf**
- Amplificatore non invertente con amplificazione A **6,25**
	- Amplificatore operazionale **MCP6022**
	- RF **4,7KΩ**
	- R2 **1KΩ**
	- Trimmer **2KΩ**


# Micro controllore e display
- µC usato **PIC18F26K22**
- ADC da **8 bit**
- Tensione fondo scala ADC **5V**
- R8 **220Ω**


# Attuatore e ventola
- Ventola
	- Alimentazione **12V**
	- Corrente **600mA**
- Tranasistor **TIP122**
	- hFE min **1000**
	- Ib **10µA**
	- Rb **500KΩ**
