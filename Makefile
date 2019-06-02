CFLAGS=-c -I Include

LFLAGS=

all : testAfficheGraphe testLectureGraphe testaStar

testAfficheGraphe : testAfficheGraphe.o lectureGraphe.o afficheGraphe.o  
	gcc -o $@ $^  $(LFLAGS)

testLectureGraphe : testLectureGraphe.o lectureGraphe.o afficheGraphe.o
	gcc -o $@ $^  $(LFLAGS)

testaStar: testaStar.o lectureGraphe.o afficheGraphe.o aStar.o
	gcc -o $@ $^  $(LFLAGS)

%.o : %.c
	gcc $(CFLAGS) $<

clean:
	rm -rf *.o