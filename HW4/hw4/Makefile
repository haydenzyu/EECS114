CC = g++
CFLAGS =
COPTFLAGS = -O3 -g
LDFLAGS =

d1: d1_driver.o d1.o
	$(CC) $(COPTFLAGS) -o $@ $^

d2: d2_driver.o d2.o

%.o: %.cpp
	$(CC) $(CFLAGS) $(COPTFLAGS) -o $@ -c $<

clean:
	rm -f core *.o *~ d1 d2
# eof
#
