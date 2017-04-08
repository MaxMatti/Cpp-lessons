SRC = 01-introductions.tex example.tex
OBJ = $(SRC:.tex=.aux) $(SRC:.tex=.log) $(SRC:.tex=.out) $(SRC:.tex=.vrb) $(SRC:.tex=.nav) $(SRC:.tex=.snm) $(SRC:.tex=.toc)

all:
	for f in $(SRC); do \
		xelatex -shell-escape $$f; \
	done

clean:
	rm -rf $(OBJ) $(SRC:.tex=.pdf) _minted*

.PHONY: all clean
