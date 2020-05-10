# RADIAL-V

## Extension Board

<img src="Radial-V-Ext-3Dview.png" alt="Radial-V-Ext-3Dview" style="zoom:50%" />

Cette carte regroupe tous les capteurs et actuateurs (boutons, LEDs, etc) du système et les envoie sur une nappe 25 fils vers l'Arduino.

<img src="Radial-V-Ext-Layer-Components.png" style="zoom:33%" />

Le circuit intégré 74HC14 est un *trigger de Schmitt inversé* qui, associé aux capacités, supprime les rebonds des boutons poussoirs, et transforme les impulsions en signaux carrés propres inversés (*active high*).