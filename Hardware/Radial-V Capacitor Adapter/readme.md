# Radial-V

## Mini-Carte "Capacitor Adapter"

Cette minicarte réalise une adaptation pour les charges et décharges de la capacité variable, nécessaire à sa mesure. Grace à des jumpers, elle permet de sélectionner une (ou deux) capas parmi les 4 que comporte la capacité variable du Tuning.

*La carte a été fabriquée sur un Veroboard (pas de PCB).*

![Radial-V MP3 Audio Adapter](Radial-V%20Capacitor%20Adapter.png)

## Algorithme

La valeur de 1MΩ a été calculée de façon à ce que C soit mesurable par l'Arduino, quelle que soit la position du Tuning.

* Application d'une tension de 5volts (=début de la charge)
* Attente de 0,1ms
* Mesure de la tension
* Décharge

Pour R = 1MΩ, et une valeur de C qui varie entre 100pF et 400pF, on a :

- un temps de charge à 63% de T=RC qui se situe entre 0.1ms et 0.4ms.
- une tension au bout de 0.1ms qui se situe entre 3v et 1.1v 