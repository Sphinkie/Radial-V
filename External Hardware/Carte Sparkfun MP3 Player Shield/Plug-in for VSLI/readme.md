# RADIAL-V

## PlugIns pour le shield MP3

Les plugIns sont des patchs correctifs du chipset Audio, généralement fournis par le fabriquant sous forme de fichiers .plg sur son [site web](http://www.vlsi.fi/en/support/software.html).
Ils doivent être compilés sous forme binaire (fichiers .053) par les utilitaires perl *vs_plg_to_bin.pl* et *vs_plg_to_bin.bat*. Ceci est inutile ici car Sparkfun fournit les plugins sous forme déjà précompilée.

**Pour que les plugIns soient pris en compte à chaque reset du chipset, il faut les placer dans la racine de la carte SD**, sinon un message d'erreur `code 6: Patch was not loaded successfully` apparait au démarrage.

Dans la classe du player MP3 `SFEMP3Shield`, les plugins (surtout **Patches.053**) sont chargés automatiquement par la méthode `VSLoadUserCode()` appelée par `begin()`.

Voir aussi la [documentation de référence](http://mpflaga.github.io/Sparkfun-MP3-Player-Shield-Arduino-Library/index.html#Plug_Ins).



------------------------
Plug-Ins and Patches
------------------------

The **VS10xx chips** are DSP's that run firmware out of ROM, that is internal to the VS10xx chip itself. Where the VSdsp's RAM can additionally be loaded with externally provided firmware and executed, also known as patches or plug-ins, over the SPI port and executed. This allows the VSdsp to have a method for both fixing problems that may exist in the factory ROM's firmware and or add new features provided by VLSI's website. It is even possible to write your own custom VSdsp code, using there Integrated Development Tools (VSIDE).

**vs_plg_to_bin.pl** is a perl script, that is provided in this library to run on your PC, to read and digest the .plg files converting them to raw binary as to be read by `SFEMP3Shield::VSLoadUserCode()` from the SDcard. Allowing updates to the VSDsp into its volatile memory after each reset. These updates may be custom features or accumulated patches.

By storing them on the SDcard these plug-ins do not consume the Arduino's limited Flash spaces

Below are pre-compiled binary's of corresponding provided VSLI patches/plugins. The filenames are kept short as SdCard only support 8.3.

- .\pcm.053                 .\vs1053-pcm110\vs1053pcm.plg
- .\admxleft.053         .\vs1053b-admix130\admix-left.plg
- .\admxmono.053    .\vs1053b-admix130\admix-mono.plg
- .\admxrght.053       .\vs1053b-admix130\admix-right.plg
- .\admxster.053        .\vs1053b-admix130\admix-stereo.plg
- .\admxswap.053     .\vs1053b-admix130\admix-swap.plg
- .\patchesf.053         .\vs1053b-patches195\vs1053b-patches-flac.plg
- .\patches.053           .\vs1053b-patches195\vs1053b-patches.plg
- .\rtmidi.053              .\vs1053b-rtmidistart\rtmidistart.plg
- .\eq5.053                  .\vs1053b-eq5-090\vs1053b-eq5.plg