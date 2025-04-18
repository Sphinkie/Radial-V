EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "MP3 Audio Adapter"
Date "2020-03-14"
Rev "1"
Comp "RADIAL-V"
Comment1 "Reason: MP3 audio GND (GNDBUF) must not be connected to Power GND."
Comment2 "MP3 shield line-out needs to be adapted."
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5E6CDAED
P 1550 2350
F 0 "J1" H 1550 2150 50  0000 C CNN
F 1 "MP3 Audio IN" H 1550 2550 50  0000 C CNN
F 2 "" H 1550 2350 50  0001 C CNN
F 3 "~" H 1550 2350 50  0001 C CNN
	1    1550 2350
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5E6CE624
P 5250 2250
F 0 "J3" H 5200 2450 50  0000 L CNN
F 1 "MP3 Audio Out" H 5000 2050 50  0000 L CNN
F 2 "" H 5250 2250 50  0001 C CNN
F 3 "~" H 5250 2250 50  0001 C CNN
	1    5250 2250
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5E6CF058
P 1550 3050
F 0 "J2" H 1550 2850 50  0000 C CNN
F 1 "CNX_SPARE" H 1600 3250 50  0000 C CNN
F 2 "" H 1550 3050 50  0001 C CNN
F 3 "~" H 1550 3050 50  0001 C CNN
	1    1550 3050
	-1   0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 5E6CF8AB
P 2650 2350
F 0 "R2" V 2857 2350 50  0000 C CNN
F 1 "100" V 2766 2350 50  0000 C CNN
F 2 "" V 2580 2350 50  0001 C CNN
F 3 "~" H 2650 2350 50  0001 C CNN
	1    2650 2350
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R1
U 1 1 5E6CFFCC
P 2650 1600
F 0 "R1" V 2857 1600 50  0000 C CNN
F 1 "100" V 2766 1600 50  0000 C CNN
F 2 "" V 2580 1600 50  0001 C CNN
F 3 "~" H 2650 1600 50  0001 C CNN
	1    2650 1600
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R3
U 1 1 5E6D070E
P 3500 2600
F 0 "R3" H 3570 2646 50  0000 L CNN
F 1 "10k" H 3570 2555 50  0000 L CNN
F 2 "" V 3430 2600 50  0001 C CNN
F 3 "~" H 3500 2600 50  0001 C CNN
	1    3500 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5E6D0A51
P 3950 1850
F 0 "R4" H 4020 1896 50  0000 L CNN
F 1 "10k" H 4020 1805 50  0000 L CNN
F 2 "" V 3880 1850 50  0001 C CNN
F 3 "~" H 3950 1850 50  0001 C CNN
	1    3950 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2350 2500 2350
Wire Wire Line
	2250 1600 2500 1600
Wire Wire Line
	2250 1600 2250 2250
Wire Wire Line
	2250 2250 1750 2250
Wire Wire Line
	2800 1600 3000 1600
Wire Wire Line
	3300 1600 3950 1600
Wire Wire Line
	3950 1600 3950 1700
Wire Wire Line
	2800 2350 3000 2350
Wire Wire Line
	3300 2350 3500 2350
Wire Wire Line
	3500 2350 3500 2450
Wire Wire Line
	3950 1600 4350 1600
Wire Wire Line
	4350 1600 4350 2150
Wire Wire Line
	4350 2150 5050 2150
Connection ~ 3950 1600
Wire Wire Line
	3500 2350 4350 2350
Wire Wire Line
	4350 2350 4350 2250
Wire Wire Line
	4350 2250 5050 2250
Connection ~ 3500 2350
$Comp
L power:GNDD #PWR0101
U 1 1 5E6D7F0C
P 3950 2100
F 0 "#PWR0101" H 3950 1850 50  0001 C CNN
F 1 "GNDD" H 3954 1945 50  0000 C CNN
F 2 "" H 3950 2100 50  0001 C CNN
F 3 "" H 3950 2100 50  0001 C CNN
	1    3950 2100
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0102
U 1 1 5E6D82E0
P 3500 2850
F 0 "#PWR0102" H 3500 2600 50  0001 C CNN
F 1 "GNDD" H 3504 2695 50  0000 C CNN
F 2 "" H 3500 2850 50  0001 C CNN
F 3 "" H 3500 2850 50  0001 C CNN
	1    3500 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0103
U 1 1 5E6D862E
P 4500 3400
F 0 "#PWR0103" H 4500 3150 50  0001 C CNN
F 1 "GNDD" H 4504 3245 50  0000 C CNN
F 2 "" H 4500 3400 50  0001 C CNN
F 3 "" H 4500 3400 50  0001 C CNN
	1    4500 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2000 3950 2100
Wire Wire Line
	3500 2750 3500 2850
Wire Wire Line
	5050 2350 4500 2350
Wire Wire Line
	4500 2350 4500 3400
Text Label 4550 2150 0    50   ~ 0
LeftOut
Text Label 4550 2250 0    50   ~ 0
RightOut
Text Label 4550 2350 0    50   ~ 0
GNDout
NoConn ~ 2050 3150
NoConn ~ 2050 2950
$Comp
L power:GNDD #PWR0104
U 1 1 5E6DB3AE
P 2800 3400
F 0 "#PWR0104" H 2800 3150 50  0001 C CNN
F 1 "GNDD" H 2804 3245 50  0000 C CNN
F 2 "" H 2800 3400 50  0001 C CNN
F 3 "" H 2800 3400 50  0001 C CNN
	1    2800 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2050 2950 1750 2950
Wire Wire Line
	2050 3150 1750 3150
Wire Wire Line
	2800 3400 2800 3050
Text Label 1900 2250 0    50   ~ 0
Left
Text Label 1900 2350 0    50   ~ 0
Right
NoConn ~ 2250 2450
Wire Wire Line
	2250 2450 1750 2450
Text Label 1900 2450 0    50   ~ 0
GNDbuf
Text Label 1850 3050 0    50   ~ 0
GND
Text Label 1850 3150 0    50   ~ 0
D49
Text Label 1850 2950 0    50   ~ 0
Vcc
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5E6DF037
P 2800 3050
F 0 "#FLG0101" H 2800 3125 50  0001 C CNN
F 1 "PWR_FLAG" H 2800 3223 50  0000 C CNN
F 2 "" H 2800 3050 50  0001 C CNN
F 3 "~" H 2800 3050 50  0001 C CNN
	1    2800 3050
	1    0    0    -1  
$EndComp
Connection ~ 2800 3050
Wire Wire Line
	2800 3050 1750 3050
$Comp
L Device:CP C1
U 1 1 5E6E06B8
P 3150 1600
F 0 "C1" V 3405 1600 50  0000 C CNN
F 1 "4.7uF" V 3314 1600 50  0000 C CNN
F 2 "" H 3188 1450 50  0001 C CNN
F 3 "~" H 3150 1600 50  0001 C CNN
	1    3150 1600
	0    -1   -1   0   
$EndComp
$Comp
L Device:CP C2
U 1 1 5E6E16FB
P 3150 2350
F 0 "C2" V 3405 2350 50  0000 C CNN
F 1 "4.7uF" V 3314 2350 50  0000 C CNN
F 2 "" H 3188 2200 50  0001 C CNN
F 3 "~" H 3150 2350 50  0001 C CNN
	1    3150 2350
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
