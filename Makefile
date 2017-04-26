# CPP-Lessons Makefile

SLDS := $(filter-out definitions.tex, $(wildcard *.tex))
XRCS := $(filter-out definitions.tex, $(wildcard exercises/tex/*.tex))

ALLSRC := $(SLDS) $(XRCS)

SLDSPDF := $(addprefix build/slides/,$(SLDS:.tex=.pdf))
XRCSPDF := $(addprefix build/exercises/,$(notdir $(XRCS:.tex=.pdf)))

ALLPDF := $(SLDSPDF) $(XRCSPDF)

RTFCTS := $(ALLPDF:.pdf=.aux) $(ALLPDF:.pdf=.log) $(ALLPDF:.pdf=.out) \
          $(ALLPDF:.pdf=.vrb) $(ALLPDF:.pdf=.nav) $(ALLPDF:.pdf=.snm) \
          $(ALLPDF:.pdf=.toc)

all: $(ALLPDF)

slides: $(SLDSPDF)

exercises: $(XRCSPDF)

clean:
	rm -rf $(ALLPDF) $(RTFCTS) _minted* exercises/tex/_minted*

build/slides/%.pdf: %.tex Makefile
	xelatex -shell-escape -output-directory=build/slides/ $<

build/exercises/%.pdf: exercises/tex/%.tex Makefile
	xelatex -shell-escape -output-directory=build/exercises $<

.PHONY: all slides exercises clean