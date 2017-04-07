SRC = 01-introductions.tex example.tex
OBJ = $(SRC:.tex=.aux) $(SRC:.tex=.log) $(SRC:.tex=.out) $(SRC:.tex=.vrb) $(SRC:.tex=.nav) $(SRC:.tex=.snm) $(SRC:.tex=.toc)

all:
	xelatex -shell-escape $(SRC)

clean:
	rm -rf $(OBJ) $(SRC:.tex=.pdf)

.PHONY: all clean
