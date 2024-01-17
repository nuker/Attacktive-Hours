CC := x86_64-w64-mingw32-gcc

CFLAGS := -Wl,-s -O2 -static-libgcc
CFLAGS := $(CFLAGS) -fmerge-all-constants -fdata-sections
CFLAGS := $(CFLAGS) -ffunction-sections -DNDEBUG

SRC := src
OBJ := obj
BIN := bin

SRC_FILES := $(wildcard $(SRC)/*.c)
OBJ_FILES := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRC_FILES))

DONE := ActiveHours.exe

$(BIN)/$(DONE): $(OBJ_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ)/%.o: $(SRC)/%.c $(OBJ) $(BIN)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ):
	mkdir $@

$(BIN):
	mkdir $@

clean:
	rm -rf $(OBJ) $(BIN)
