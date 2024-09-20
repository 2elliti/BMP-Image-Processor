DEST_FILE := build
SRC_FILE := src

all: $(DEST_FILE)/converter

$(DEST_FILE)/converter: $(SRC_FILE)/converter.c $(SRC_FILE)/colored.c $(SRC_FILE)/sepia.c $(SRC_FILE)/grayscale.c

	gcc $(SRC_FILE)/converter.c $(SRC_FILE)/colored.c $(SRC_FILE)/sepia.c $(SRC_FILE)/grayscale.c -o $(DEST_FILE)/converter

