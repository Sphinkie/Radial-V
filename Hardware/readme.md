# RADIAL-V
## Schematics

Ce repository contient l'ingénérie des différents circuits imprimés réalisés.

##Fabrication des PCB

Pour générer avec [kiCad](https://kicad-pcb.org/ "open source CAO software" ) les fichiers à envoyer à [JLB PCB](https://jlcpcb.com/	"PCB assembly from 2$"):

**kiCad → Pcbnew → File → Plot...**

* Plot format: Gerber
* Output directory: Gerber\
* Included layers: F.Cu B.Cu F.SilkS B.SilkS F.Mask B.Mask Edge.Cuts
* Plot footprint values
* Plot footprint references
* Exclude PDB edge layer from other layers
* Exclude pads from silkscreen

**Plot**
* Generate Drill Files...
* Generate Drill Files