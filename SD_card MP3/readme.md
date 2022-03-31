# RADIAL-V

## SD Card MP3

![carte microSD](microSD.jpg)

La carte doit avoir un *file system* FAT16 ou FAT32, et des noms de fichier au format 8.3.

* **/Preparation** - Ce repository contient les éléments nécessaires pour la carte SD du shield **MP3 Player**:
  
  * Fichier audio utilisé par le programme (`NOISE.MP3`)
* Scripts et utilitaires pour générer le fichier `Catalog.ndx` utilisé par le programme.
  
* **/SD_Card** - Contenu typique de la carte SD: le fichier `Catalog.ndx` , un répertoire `Music`contenant tous les fichiers MP3 au format 8.3 et les patches VLSI pour le chipset audio.

  

## PlugIns pour la carte MP3 Player Shield

Les fichiers `*.053` sont des patchs correctifs du chipset audio, fournis par Sparkfun.

**Pour que les plugIns soient pris en compte à chaque reset du chipset, il faut les placer dans la racine de la carte SD**, sinon un message d'erreur `code 6: Patch was not loaded successfully` apparait au démarrage.

Dans la classe du player MP3 **SFEMP3Shield**, les plugins (surtout `patches.053`) sont chargés automatiquement par la méthode `VSLoadUserCode()` appelée par `begin()`.

Voir aussi la [documentation de référence de la carte MP3 player shield](http://mpflaga.github.io/Sparkfun-MP3-Player-Shield-Arduino-Library/index.html#Plug_Ins).

