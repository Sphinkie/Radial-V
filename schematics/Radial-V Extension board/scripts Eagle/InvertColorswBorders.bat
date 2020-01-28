
convert  Layer-Top.png    -negate -bordercolor black -border 4       Layer-Top.png
convert  Layer-Bottom.png -negate -bordercolor black -border 4 -flop Layer-Bottom.png
convert  Components.png   -negate -bordercolor black -border 4       Layer-Components.png

rem : sans cadre
rem convert  Layer-Top.png    -negate       Layer-Top.png
rem convert  Layer-Bottom.png -negate -flop Layer-Bottom.png
rem convert  Components.png   -negate       Layer-Components.png

