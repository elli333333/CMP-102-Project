#!/bin/sh
# mptopdf UMLDiagram.mp
latexmk DartsWriteUp.tex -lualatex
rm *.aux
rm *.fls
rm *.log
rm *.fdb_latexmk
rm *.1