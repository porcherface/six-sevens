REQUIREMENTS FIRST!!

pip3 install matplotlib
pip3 install numpy
pip3 install pygame

SMALL DESCRIPTION
each module has its own driver code in the main section: you can understand what the file does by checking each main.
the most important are
1) islands.py shows what bsq is, with a ugly terminal printer
2) analyze.py does N bsq alghoritms and does some (for now) simple analysis
3) parprocess.py is a multithread analysis (this may speed up as slow down your code, and may even not work)
   if parprocess.y gives problems you can still return to serialized processing, changing the process call in the file
4) animate.py drives parprocess into a small animation sandbox (use arrowUp and arrowDown to navigate between slices)

0) life.py is a bonus
