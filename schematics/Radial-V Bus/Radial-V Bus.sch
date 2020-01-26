EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "RADIAL-V : Bus Board"
Date "2020-01-19"
Rev "2"
Comp "David"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 7500 5100 1    50   ~ 0
SCL
Text Label 3900 4350 0    47   ~ 0
SCL
Wire Wire Line
	2950 4350 2450 4350
Text Label 7600 5100 1    50   ~ 0
SDA
Text Label 2450 4350 0    50   ~ 0
SDA
Wire Wire Line
	2950 3450 900  3450
Text Label 5950 1350 0    50   ~ 0
A14
Text Label 2300 3250 0    50   ~ 0
A14
Wire Wire Line
	2950 3550 900  3550
Text Label 4150 3350 0    50   ~ 0
A12
Text Label 5750 2850 0    50   ~ 0
D51-MOSI
Wire Wire Line
	6250 4350 6000 4350
Wire Wire Line
	6000 4350 6000 4700
Wire Wire Line
	6000 4700 7050 4700
Text Label 7700 3050 0    50   ~ 0
5V
Wire Wire Line
	6250 3750 4850 3750
Wire Wire Line
	4850 3750 4850 2450
Wire Wire Line
	4850 2450 1850 2450
Wire Wire Line
	1850 2450 1850 3950
Wire Wire Line
	1850 3950 2950 3950
Text Label 5750 3750 0    50   ~ 0
D33
Text Label 2350 3950 0    50   ~ 0
D33
Wire Wire Line
	6250 3650 4600 3650
Wire Wire Line
	4600 3650 4600 3950
Wire Wire Line
	4600 3950 3550 3950
Text Label 5750 3650 0    50   ~ 0
D35
Text Label 3900 3950 0    47   ~ 0
D35
Wire Wire Line
	900  3850 2950 3850
Wire Wire Line
	6250 3450 4550 3450
Wire Wire Line
	4550 3450 4550 3850
Wire Wire Line
	3550 3850 4550 3850
Text Label 5750 3450 0    50   ~ 0
D39
Text Label 3900 3850 0    47   ~ 0
D39
Wire Wire Line
	6250 3350 4650 3350
Wire Wire Line
	4650 3350 4650 2550
Wire Wire Line
	4650 2550 2050 2550
Wire Wire Line
	2050 2550 2050 3750
Wire Wire Line
	2050 3750 2950 3750
Text Label 5750 3350 0    50   ~ 0
D41
Text Label 2350 3750 0    50   ~ 0
D41
Wire Wire Line
	4500 3550 4500 3250
Wire Wire Line
	3550 3550 4500 3550
Wire Wire Line
	6250 3250 4500 3250
Text Label 5750 3250 0    50   ~ 0
D43
Text Label 3900 3550 0    47   ~ 0
D43
Wire Wire Line
	6250 3150 4450 3150
Wire Wire Line
	4450 3150 4450 3450
Wire Wire Line
	3550 3450 4450 3450
Text Label 5750 3150 0    50   ~ 0
D45
Text Label 3900 3450 0    47   ~ 0
D45
Wire Wire Line
	2150 3050 2150 3350
Wire Wire Line
	2150 3350 2950 3350
Text Label 5750 3050 0    50   ~ 0
D47
Text Label 2350 3350 0    50   ~ 0
D47
Wire Wire Line
	6250 3850 4650 3850
Wire Wire Line
	4650 3850 4650 4050
Wire Wire Line
	3550 4050 4650 4050
Text Label 5750 3850 0    50   ~ 0
D31
Text Label 3900 4050 0    47   ~ 0
D31
Wire Wire Line
	6250 3950 4950 3950
Wire Wire Line
	4950 3950 4950 2350
Wire Wire Line
	4950 2350 1750 2350
Wire Wire Line
	1750 2350 1750 4050
Wire Wire Line
	1750 4050 2950 4050
Text Label 5750 3950 0    50   ~ 0
D29
Text Label 2350 4050 0    50   ~ 0
D29
Wire Wire Line
	6250 4050 4700 4050
Wire Wire Line
	4700 4050 4700 4150
Wire Wire Line
	3550 4150 4700 4150
Text Label 5750 4050 0    50   ~ 0
D27
Text Label 3900 4150 0    47   ~ 0
D27
Wire Wire Line
	6250 4150 5050 4150
Wire Wire Line
	5050 4150 5050 2250
Wire Wire Line
	5050 2250 1650 2250
Wire Wire Line
	1650 2250 1650 4150
Wire Wire Line
	1650 4150 2950 4150
Text Label 5750 4150 0    50   ~ 0
D25
Wire Wire Line
	6250 4250 3550 4250
Text Label 5750 4250 0    50   ~ 0
D23
Text Label 3900 4250 0    47   ~ 0
D23
Wire Wire Line
	6750 2750 7450 2750
Wire Wire Line
	7450 2750 7450 3450
Text Label 6800 2750 0    50   ~ 0
D52-SCLK
Wire Wire Line
	6750 2850 7350 2850
Wire Wire Line
	7350 2850 7350 3550
Text Label 6850 2850 0    50   ~ 0
D50-MISO
Wire Wire Line
	7050 2300 6000 2300
Wire Wire Line
	6000 2300 6000 2650
Wire Wire Line
	6250 2650 6000 2650
Wire Wire Line
	7050 2650 6750 2650
Text Label 7650 2300 0    50   ~ 0
GND-ARD
Wire Wire Line
	2950 4250 1650 4250
Text Label 2350 4250 0    50   ~ 0
D17
Text Label 8700 5100 1    47   ~ 0
D3
Text Label 3900 3650 0    47   ~ 0
D3
Text Label 3900 4450 0    47   ~ 0
3V3
Wire Wire Line
	1250 3650 2950 3650
Text Label 2350 3650 0    50   ~ 0
D18
Text Label 7800 5100 1    50   ~ 0
D18
Wire Wire Line
	4250 3750 3550 3750
Text Label 3900 3750 0    47   ~ 0
D19
Text Label 7700 5100 1    50   ~ 0
D19
$Comp
L Radial-V_Bus-eagle-import:DINA4_L #FRAME1
U 1 1 DF320C81
P 1100 7300
F 0 "#FRAME1" H 1100 7300 50  0001 C CNN
F 1 "RADIAL-V BUS BOARD" H 1100 7300 50  0001 C CNN
F 2 "" H 1100 7300 50  0001 C CNN
F 3 "" H 1100 7300 50  0001 C CNN
	1    1100 7300
	1    0    0    -1  
$EndComp
$Comp
L Radial-V_Bus-eagle-import:26H PL1
U 1 1 7AA41272
P 3250 3850
F 0 "PL1" H 3200 4550 59  0000 L BNN
F 1 "Nappe" H 3100 3050 59  0000 L BNN
F 2 "MesModules:HE10-26P" H 3250 3850 50  0001 C CNN
F 3 "" H 3250 3850 50  0001 C CNN
	1    3250 3850
	1    0    0    -1  
$EndComp
NoConn ~ 2950 4450
NoConn ~ 7050 1550
NoConn ~ 7550 1550
NoConn ~ 7650 1550
NoConn ~ 7750 1550
NoConn ~ 8150 1550
NoConn ~ 8250 1550
NoConn ~ 8350 1550
NoConn ~ 8450 1550
NoConn ~ 8550 1550
NoConn ~ 8650 1550
NoConn ~ 8750 1550
NoConn ~ 8850 1550
NoConn ~ 9850 1550
NoConn ~ 9850 950 
NoConn ~ 9750 950 
NoConn ~ 9650 950 
Wire Wire Line
	9450 950  9450 1550
Wire Wire Line
	9350 950  9350 1550
NoConn ~ 9150 950 
NoConn ~ 9250 950 
NoConn ~ 9550 950 
NoConn ~ 9150 1550
Text Label 10400 1350 0    50   ~ 0
RESET
Wire Wire Line
	9250 1550 9250 1250
Text Label 9250 1500 1    50   ~ 0
GND
Text Label 9350 1500 1    50   ~ 0
GND
Text Label 9450 1500 1    50   ~ 0
5V
Wire Wire Line
	9650 1550 9650 1350
NoConn ~ 9750 1550
Wire Wire Line
	9550 1550 9550 1300
Wire Wire Line
	9550 1300 10250 1300
Text Label 9550 1500 1    50   ~ 0
3V3
$Comp
L Connector_Generic:Conn_01x08 ARD-C5
U 1 1 5E33688A
P 7900 4650
F 0 "ARD-C5" V 8000 4200 50  0000 L CNN
F 1 "D21-D14" V 8000 4650 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 7900 4650 50  0001 C CNN
F 3 "~" H 7900 4650 50  0001 C CNN
	1    7900 4650
	0    1    -1   0   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 ARD-C6
U 1 1 5E337C9F
P 8700 4650
F 0 "ARD-C6" V 8800 4200 50  0000 L CNN
F 1 "D0-D7" V 8800 4750 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 8700 4650 50  0001 C CNN
F 3 "~" H 8700 4650 50  0001 C CNN
	1    8700 4650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8700 4850 8700 5600
NoConn ~ 8000 4850
NoConn ~ 8100 4850
NoConn ~ 8200 4850
NoConn ~ 8400 4850
NoConn ~ 8500 4850
$Comp
L Connector_Generic:Conn_01x08 MP3-C3
U 1 1 5E40624D
P 8700 6350
F 0 "MP3-C3" V 8800 5900 50  0000 L CNN
F 1 "I/O" V 8800 6550 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 8700 6350 50  0001 C CNN
F 3 "~" H 8700 6350 50  0001 C CNN
	1    8700 6350
	0    -1   1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 MP3-C4
U 1 1 5E4079B6
P 9650 6350
F 0 "MP3-C4" V 9750 5900 50  0000 L CNN
F 1 "COMMS" V 9750 6450 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 9650 6350 50  0001 C CNN
F 3 "~" H 9650 6350 50  0001 C CNN
	1    9650 6350
	0    -1   1    0   
$EndComp
NoConn ~ 8400 6150
NoConn ~ 8500 6150
NoConn ~ 8900 6150
Wire Wire Line
	9100 4850 9100 6150
Wire Wire Line
	9000 4850 9000 6150
Wire Wire Line
	8800 4850 8800 6150
NoConn ~ 8900 4850
NoConn ~ 8700 6150
Text Label 8600 6050 1    50   ~ 0
MP3-DREQ
Text Label 8800 6050 1    50   ~ 0
GPIO1
Text Label 9000 6050 1    50   ~ 0
MP3-CS
Text Label 9100 6050 1    50   ~ 0
MP3-DCS
Wire Wire Line
	9350 4850 9350 6150
Wire Wire Line
	9450 4850 9450 6150
$Comp
L Connector_Generic:Conn_01x08 ARD-C7
U 1 1 5E3DA56A
P 9650 4650
F 0 "ARD-C7" V 9750 4200 50  0000 L CNN
F 1 "D8-D13" V 9750 4700 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 9650 4650 50  0001 C CNN
F 3 "~" H 9650 4650 50  0001 C CNN
	1    9650 4650
	0    -1   -1   0   
$EndComp
NoConn ~ 9550 4850
NoConn ~ 9650 4850
NoConn ~ 9750 4850
NoConn ~ 9850 4850
Wire Wire Line
	9950 4850 9950 6150
NoConn ~ 10050 4850
Text Label 9950 6100 1    50   ~ 0
GND
NoConn ~ 10050 6150
Wire Wire Line
	7500 4850 7500 5200
Wire Wire Line
	7500 5200 4700 5200
Wire Wire Line
	8600 4850 8600 6150
Text Label 7900 5100 1    50   ~ 0
D17
NoConn ~ 6750 2950
NoConn ~ 6750 3050
NoConn ~ 6750 3150
NoConn ~ 6750 3250
NoConn ~ 6750 3350
NoConn ~ 6750 3450
NoConn ~ 6750 3550
NoConn ~ 6750 3650
NoConn ~ 6750 3750
NoConn ~ 6750 3850
NoConn ~ 6750 3950
NoConn ~ 6750 4050
NoConn ~ 6750 4150
Wire Wire Line
	10250 1300 10250 5700
Wire Wire Line
	2450 4350 2450 5300
Wire Wire Line
	7600 4850 7600 5300
Wire Wire Line
	7600 5300 2450 5300
Wire Wire Line
	1650 4250 1650 5800
Wire Wire Line
	4250 5400 4250 3750
Wire Wire Line
	1250 3650 1250 5500
Wire Wire Line
	4250 5400 7700 5400
Wire Wire Line
	7700 4850 7700 5400
Wire Wire Line
	1250 5500 7800 5500
Wire Wire Line
	7800 4850 7800 5500
Wire Wire Line
	8250 2650 8250 3050
$Comp
L Connector_Generic:Conn_01x08 MP3-C1
U 1 1 5E588ECC
P 9450 750
F 0 "MP3-C1" V 9550 300 50  0000 L CNN
F 1 "POWER" V 9550 800 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x08_P2.54mm_Vertical" H 9450 750 50  0001 C CNN
F 3 "~" H 9450 750 50  0001 C CNN
	1    9450 750 
	0    -1   -1   0   
$EndComp
NoConn ~ 6750 4250
Text Label 9650 6100 1    50   ~ 0
MOSI
Text Label 9750 6100 1    50   ~ 0
MISO
Wire Wire Line
	9650 5850 9650 6150
NoConn ~ 9550 6150
Wire Wire Line
	9850 6150 9850 5900
Text Label 9850 6100 1    50   ~ 0
SCLK
$Comp
L Connector_Generic:Conn_01x08 ARD-C1
U 1 1 5E5E81E0
P 9550 1750
F 0 "ARD-C1" V 9650 1300 50  0000 L CNN
F 1 "POWER" V 9650 1850 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 9550 1750 50  0001 C CNN
F 3 "~" H 9550 1750 50  0001 C CNN
	1    9550 1750
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 ARD-C2
U 1 1 5E5F1F04
P 8550 1750
F 0 "ARD-C2" V 8650 1300 50  0000 L CNN
F 1 "A7-A0" V 8650 1850 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 8550 1750 50  0001 C CNN
F 3 "~" H 8550 1750 50  0001 C CNN
	1    8550 1750
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 ARD-C3
U 1 1 5E5F2EEE
P 7450 1750
F 0 "ARD-C3" V 7550 1300 50  0000 L CNN
F 1 "A15-A8" V 7550 1850 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 7450 1750 50  0001 C CNN
F 3 "~" H 7450 1750 50  0001 C CNN
	1    7450 1750
	0    1    1    0   
$EndComp
$Comp
L Connector_Generic:Conn_02x18_Odd_Even ARD-C4
U 1 1 5E5F46C1
P 6550 3550
F 0 "ARD-C4" H 6600 2425 50  0000 C CNN
F 1 "D22-D53" H 6600 2516 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x18_P2.54mm_Vertical" H 6550 3550 50  0001 C CNN
F 3 "~" H 6550 3550 50  0001 C CNN
	1    6550 3550
	-1   0    0    1   
$EndComp
Wire Wire Line
	8250 2650 10750 2650
Wire Wire Line
	7050 2300 8250 2300
Wire Wire Line
	6750 4350 7050 4350
Wire Wire Line
	7050 4350 7050 3050
Wire Wire Line
	7050 3050 8250 3050
Connection ~ 7050 4350
Wire Wire Line
	7050 4350 7050 4700
Connection ~ 7050 2300
Wire Wire Line
	7050 2300 7050 2650
Wire Wire Line
	10750 2550 8250 2550
Wire Wire Line
	8250 2550 8250 2300
Wire Wire Line
	7150 1550 7150 1350
Wire Wire Line
	7350 1550 7350 1250
NoConn ~ 7250 1550
NoConn ~ 7450 1550
Wire Wire Line
	5950 1350 7150 1350
Wire Wire Line
	5950 1250 7350 1250
Wire Wire Line
	4700 4350 4700 5200
Wire Wire Line
	3550 4350 4700 4350
Wire Wire Line
	4200 5600 4200 3650
Wire Wire Line
	4200 3650 3550 3650
Wire Wire Line
	4200 5600 8700 5600
Wire Wire Line
	4150 4450 4150 5700
Wire Wire Line
	4150 4450 3550 4450
Wire Wire Line
	4150 5700 10250 5700
Wire Wire Line
	5550 5850 9650 5850
Wire Wire Line
	10650 5900 9850 5900
Wire Wire Line
	10650 3450 7450 3450
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5E2B59C0
P 10950 1250
F 0 "J2" V 10914 1062 50  0000 R CNN
F 1 "Conn_Reset" V 11050 1400 50  0000 R CNN
F 2 "Connector_JST:JST_EH_B2B-EH-A_1x02_P2.50mm_Vertical" H 10950 1250 50  0001 C CNN
F 3 "~" H 10950 1250 50  0001 C CNN
	1    10950 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 1350 10750 1350
Wire Wire Line
	9250 1250 10750 1250
Wire Wire Line
	10650 3450 10650 5900
Wire Wire Line
	10550 5800 10550 3550
Wire Wire Line
	9750 5800 10550 5800
Wire Wire Line
	9750 5800 9750 6150
Wire Wire Line
	2150 3050 6250 3050
Wire Wire Line
	5550 2850 5550 5850
Wire Wire Line
	5550 2850 6250 2850
Wire Wire Line
	7900 4850 7900 5800
Wire Wire Line
	7900 5800 1650 5800
Text Label 2350 4150 0    50   ~ 0
D25
Wire Wire Line
	6250 2950 5750 2950
Wire Wire Line
	4150 3350 3550 3350
Wire Wire Line
	4300 2650 4300 3250
Wire Wire Line
	4300 3250 3550 3250
Connection ~ 6000 2650
Text Label 5750 2950 0    50   ~ 0
D49
Wire Wire Line
	2300 3250 2950 3250
NoConn ~ 6250 2750
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 5E4E56BA
P 10950 2550
F 0 "J1" V 10914 2362 50  0000 R CNN
F 1 "Conn_Alim" V 11050 2700 50  0000 R CNN
F 2 "MesModules:Molex_KK-254_AE-6410-02A_1x02_P2.54mm_Horizontal" H 10950 2550 50  0001 C CNN
F 3 "~" H 10950 2550 50  0001 C CNN
	1    10950 2550
	1    0    0    -1  
$EndComp
Text Label 2350 3850 0    50   ~ 0
RESET
Text GLabel 900  3850 0    50   Input ~ 0
RESET
Wire Wire Line
	7350 3550 10550 3550
Wire Wire Line
	4300 2650 6000 2650
Text Label 3900 3250 0    50   ~ 0
GND-ARD
Text Label 3550 3450 0    24   ~ 0
X1-3
Text Label 3550 3550 0    24   ~ 0
X1-4
Text Label 2700 3450 0    24   ~ 0
X1-16
Text Label 2700 4150 0    24   ~ 0
X1-23
Text Label 3550 4150 0    24   ~ 0
X1-10
Text Label 2700 4050 0    24   ~ 0
X1-22
Text Label 3550 4050 0    24   ~ 0
X1-9
Text Label 2700 3950 0    24   ~ 0
X1-21
Text Label 3550 3950 0    24   ~ 0
X1-8
Text Label 3550 3250 0    24   ~ 0
X1-1
Text Label 3550 3350 0    24   ~ 0
X1-2
Text Label 2700 3350 0    24   ~ 0
X1-15
Text Label 2700 3550 0    24   ~ 0
X1-17
Text Label 3550 3650 0    24   ~ 0
X1-5
Text Label 2700 3650 0    24   ~ 0
X1-18
Text Label 3550 3750 0    24   ~ 0
X1-6
Text Label 2700 3850 0    24   ~ 0
X1-20
Text Label 3550 3850 0    24   ~ 0
X1-7
Text Label 2700 3750 0    24   ~ 0
X1-19
Text Label 3550 4250 0    24   ~ 0
X1-11
Text Label 3550 4450 0    24   ~ 0
X1-13
Text Label 2700 4250 0    24   ~ 0
X1-24
Text Label 2700 4350 0    24   ~ 0
X1-25
Text Label 3550 4350 0    24   ~ 0
X1-12
Text Label 2700 3250 0    24   ~ 0
X1-14
Text Notes 2900 4800 0    50   ~ 0
To Extension Board
Wire Notes Line
	10150 1050 10150 5350
Wire Notes Line
	10150 5350 5400 5350
Wire Notes Line
	5400 5350 5400 1050
Wire Notes Line
	5400 1050 10150 1050
Text Notes 7600 1150 0    50   ~ 0
Arduino Mega
Text Label 5950 1250 0    50   ~ 0
A12
Text Label 900  3450 0    50   ~ 0
D49
Text Label 5750 3550 0    50   ~ 0
D37
Text Label 900  3550 0    50   ~ 0
D37
Wire Wire Line
	6250 3550 5750 3550
$EndSCHEMATC
