 CC      = gcc
CFLAGS  = -Wall -Wextra -std=c11
TARGET  = edugraph
SRCS    = main.c materi.c linked_list.c bst.c tree.c ui.c
OBJS    = $(SRCS:.c=.o)
 
all: $(TARGET)
 
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo ""
	@echo " [OK] Build berhasil! Jalankan dengan: ./$(TARGET)"
	@echo ""
 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJS) $(TARGET)
	@echo " [OK] File build dihapus."

rebuild: clean all
 
.PHONY: all clean rebuild