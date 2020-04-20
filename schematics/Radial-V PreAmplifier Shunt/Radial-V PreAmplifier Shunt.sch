EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "PreAmplifier Shunt"
Date "2020-04-20"
Rev "1"
Comp "RADIAL-V"
Comment1 "To lower the output audio signal"
Comment2 "Can replace the PreAmplifier board"
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x10 J1
U 1 1 5E9D9D0E
P 4250 3550
F 0 "J1" V 4375 3496 50  0000 C CNN
F 1 "Edge Connector 1x10" V 4466 3496 50  0000 C CNN
F 2 "MesModules:PCB_Edge_1x10" H 4250 3550 50  0001 C CNN
F 3 "~" H 4250 3550 50  0001 C CNN
	1    4250 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	3950 3000 3950 3350
Wire Wire Line
	4450 3000 4450 3350
Wire Wire Line
	4650 3000 4650 3350
Wire Wire Line
	3850 3350 3850 2550
Wire Wire Line
	3850 2550 4050 2550
Wire Wire Line
	4050 2550 4050 3350
Text Label 4350 2500 0    50   ~ 0
AudioLeft
Text GLabel 3750 1850 1    50   Input ~ 0
GND
Text GLabel 4450 3000 1    50   Input ~ 0
GND
Text GLabel 4650 3000 1    50   Input ~ 0
GND
Text GLabel 3950 3000 1    50   Input ~ 0
GND
Wire Wire Line
	4350 3350 4350 2550
Wire Wire Line
	4350 2550 4550 2550
Wire Wire Line
	4550 2550 4550 3350
Text Label 3850 2500 0    50   ~ 0
AudioRight
NoConn ~ 4150 2900
Wire Wire Line
	4250 2050 4250 3350
Text Label 4150 3250 1    50   ~ 0
12v
Wire Wire Line
	4150 2900 4150 3350
$Comp
L Connector:TestPoint_Flag TP4
U 1 1 5E9DCFD6
P 4350 2250
F 0 "TP4" H 4600 2300 50  0000 L CNN
F 1 "TestPoint" H 4350 2400 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D2.5mm_Drill1.2mm" H 4550 2250 50  0001 C CNN
F 3 "~" H 4550 2250 50  0001 C CNN
	1    4350 2250
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint_Flag TP1
U 1 1 5E9DE7A9
P 3850 2250
F 0 "TP1" H 4100 2300 50  0000 L CNN
F 1 "TestPoint" H 3850 2400 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D2.5mm_Drill1.2mm" H 4050 2250 50  0001 C CNN
F 3 "~" H 4050 2250 50  0001 C CNN
	1    3850 2250
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint_Flag TP2
U 1 1 5E9DECA5
P 3750 2050
F 0 "TP2" H 4000 2100 50  0000 L CNN
F 1 "TestPoint" H 3750 2200 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D2.5mm_Drill1.2mm" H 3950 2050 50  0001 C CNN
F 3 "~" H 3950 2050 50  0001 C CNN
	1    3750 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 2250 3850 2550
Connection ~ 3850 2550
Wire Wire Line
	4350 2250 4350 2550
Connection ~ 4350 2550
Wire Wire Line
	3750 1850 3750 2050
Connection ~ 3750 2050
Wire Wire Line
	3750 2050 3750 3350
$Comp
L Connector:TestPoint_Flag TP3
U 1 1 5E9DBF07
P 4250 2050
F 0 "TP3" H 4500 2100 50  0000 L CNN
F 1 "TestPoint" H 4250 2200 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D2.5mm_Drill1.2mm" H 4450 2050 50  0001 C CNN
F 3 "~" H 4450 2050 50  0001 C CNN
	1    4250 2050
	1    0    0    -1  
$EndComp
Text Label 4250 3250 1    50   ~ 0
0v
$EndSCHEMATC
